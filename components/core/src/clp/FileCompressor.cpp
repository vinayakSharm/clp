#include "FileCompressor.hpp"

// C++ standard libraries
#include <algorithm>
#include <iostream>
#include <set>

// Boost libraries
#include <boost/algorithm/string.hpp>
#include <boost/filesystem/path.hpp>

// libarchive
#include <archive_entry.h>

// Project headers
#include "../ffi/ir_stream/decoding_methods.hpp"
#include "../ir/utils.hpp"
#include "../Profiler.hpp"
#include "utils.hpp"

using ir::has_ir_stream_magic_number;
using ir::LogEventDeserializer;
using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

// Local prototypes
/**
 * Computes empty directories as directories - parent_directories and adds them to the given archive
 * @param directories
 * @param parent_directories
 * @param parent_path Path that should be the parent of all added directories
 * @param archive
 */
static void compute_and_add_empty_directories (const set<string>& directories, const set<string>& parent_directories,
                                               const boost::filesystem::path& parent_path, streaming_archive::writer::Archive& archive);

/**
 * Writes the given message to the given encoded file
 * @param msg
 * @param archive
 * @param file
 */
static void write_message_to_encoded_file (const ParsedMessage& msg, streaming_archive::writer::Archive& archive);

static void compute_and_add_empty_directories (const set<string>& directories, const set<string>& parent_directories,
                                               const boost::filesystem::path& parent_path, streaming_archive::writer::Archive& archive)
{
    // Determine empty directories by subtracting parent directories
    vector<string> empty_directories;
    auto directories_ix = directories.cbegin();
    for (auto parent_directories_ix = parent_directories.cbegin();
         directories.cend() != directories_ix && parent_directories.cend() != parent_directories_ix;)
    {
        const auto& directory = *directories_ix;
        const auto& parent_directory = *parent_directories_ix;

        if (directory < parent_directory) {
            auto boost_path_for_compression = parent_path / directory;
            empty_directories.emplace_back(boost_path_for_compression.string());
            ++directories_ix;
        } else if (directory == parent_directory) {
            ++directories_ix;
            ++parent_directories_ix;
        } else {
            ++parent_directories_ix;
        }
    }
    for (; directories.cend() != directories_ix; ++directories_ix) {
        auto boost_path_for_compression = parent_path / *directories_ix;
        empty_directories.emplace_back(boost_path_for_compression.string());
    }
    archive.add_empty_directories(empty_directories);
}

static void write_message_to_encoded_file (const ParsedMessage& msg, streaming_archive::writer::Archive& archive) {
    if (msg.has_ts_patt_changed()) {
        archive.change_ts_pattern(msg.get_ts_patt());
    }

    archive.write_msg(msg.get_ts(), msg.get_content(), msg.get_orig_num_bytes());
}

namespace clp {
    bool FileCompressor::compress_file (size_t target_data_size_of_dicts, streaming_archive::writer::Archive::UserConfig& archive_user_config,
                                        size_t target_encoded_file_size, const FileToCompress& file_to_compress,
                                        streaming_archive::writer::Archive& archive_writer, bool use_heuristic) {
        std::string file_name = std::filesystem::canonical(file_to_compress.get_path()).string();

        PROFILER_SPDLOG_INFO("Start parsing {}", file_name)
        Profiler::start_continuous_measurement<Profiler::ContinuousMeasurementIndex::ParseLogFile>();

        m_file_reader.open(file_to_compress.get_path());

        // Check that file is UTF-8 encoded
        if (auto error_code = m_file_reader.try_refill_buffer_if_empty();
            ErrorCode_Success != error_code && ErrorCode_EndOfFile != error_code)
        {
            if (ErrorCode_errno == error_code) {
                SPDLOG_ERROR(
                        "Failed to read {} into buffer, errno={}",
                        file_to_compress.get_path(),
                        errno
                );
            } else {
                SPDLOG_ERROR(
                        "Failed to read {} into buffer, error={}",
                        file_to_compress.get_path(),
                        error_code
                );
            }
            return false;
        }
        char const* utf8_validation_buf{nullptr};
        size_t utf8_validation_buf_len{0};
        m_file_reader.peek_buffered_data(utf8_validation_buf, utf8_validation_buf_len);
        bool succeeded = true;
        if (is_utf8_sequence(utf8_validation_buf_len, utf8_validation_buf)) {
            if (use_heuristic) {
                parse_and_encode_with_heuristic(target_data_size_of_dicts, archive_user_config, target_encoded_file_size,
                                                file_to_compress.get_path_for_compression(),
                                                file_to_compress.get_group_id(), archive_writer, m_file_reader);
            } else {
                parse_and_encode(target_data_size_of_dicts, archive_user_config, target_encoded_file_size,
                                 file_to_compress.get_path_for_compression(),
                                 file_to_compress.get_group_id(), archive_writer, m_file_reader);
            }
        } else {
            if (false == try_compressing_as_archive(target_data_size_of_dicts, archive_user_config, target_encoded_file_size, file_to_compress,
                                                    archive_writer, use_heuristic))
            {
                succeeded = false;
            }
        }

        m_file_reader.close();

        Profiler::stop_continuous_measurement<Profiler::ContinuousMeasurementIndex::ParseLogFile>();
        LOG_CONTINUOUS_MEASUREMENT(Profiler::ContinuousMeasurementIndex::ParseLogFile)
        PROFILER_SPDLOG_INFO("Done parsing {}", file_name)

        return succeeded;
    }

    void FileCompressor::parse_and_encode (size_t target_data_size_of_dicts, streaming_archive::writer::Archive::UserConfig& archive_user_config,
                                           size_t target_encoded_file_size, const string& path_for_compression, group_id_t group_id,
                                           streaming_archive::writer::Archive& archive_writer, ReaderInterface& reader)
    {
        archive_writer.m_target_data_size_of_dicts = target_data_size_of_dicts;
        archive_writer.m_archive_user_config = archive_user_config;
        archive_writer.m_path_for_compression = path_for_compression;
        archive_writer.m_group_id = group_id;
        archive_writer.m_target_encoded_file_size = target_encoded_file_size;
        // Open compressed file
        archive_writer.create_and_open_file(path_for_compression, group_id, m_uuid_generator(), 0);
        m_log_parser->set_archive_writer_ptr(&archive_writer);
        m_log_parser->get_archive_writer_ptr()->old_ts_pattern.clear();
        try {
            m_log_parser->parse(reader);
        } catch (std::string const err) {
            if (err.find("Lexer failed to find a match after checking entire buffer") != std::string::npos) {
                close_file_and_append_to_segment(archive_writer);
                SPDLOG_ERROR(err);
            } else {
                throw (err);
            }
        }
        // TODO: separate variables from static text
        //Stopwatch close_file_watch("close_file_watch");
        //close_file_watch.start();
        close_file_and_append_to_segment(archive_writer);
        // archive_writer_config needs to persist between files
        archive_user_config = archive_writer.m_archive_user_config;
        //close_file_watch.stop();
        //close_file_watch.print();
    }

    void FileCompressor::parse_and_encode_with_heuristic (size_t target_data_size_of_dicts, streaming_archive::writer::Archive::UserConfig& archive_user_config,
                                                          size_t target_encoded_file_size, const string& path_for_compression, group_id_t group_id,
                                                          streaming_archive::writer::Archive& archive_writer, ReaderInterface& reader)
    {
        m_parsed_message.clear();

        // Open compressed file
        archive_writer.create_and_open_file(path_for_compression, group_id, m_uuid_generator(), 0);

        // Parse content from file
        while (m_message_parser.parse_next_message(true, reader, m_parsed_message)) {
            if (archive_writer.get_data_size_of_dictionaries() >= target_data_size_of_dicts) {
                split_file_and_archive(archive_user_config, path_for_compression, group_id, m_parsed_message.get_ts_patt(), archive_writer);
            } else if (archive_writer.get_file().get_encoded_size_in_bytes() >= target_encoded_file_size) {
                split_file(path_for_compression, group_id, m_parsed_message.get_ts_patt(), archive_writer);
            }

            write_message_to_encoded_file(m_parsed_message, archive_writer);
        }

        close_file_and_append_to_segment(archive_writer);
    }

    bool FileCompressor::try_compressing_as_archive (size_t target_data_size_of_dicts, streaming_archive::writer::Archive::UserConfig& archive_user_config,
                                                     size_t target_encoded_file_size, const FileToCompress& file_to_compress,
                                                     streaming_archive::writer::Archive& archive_writer, bool use_heuristic)
    {
        auto file_boost_path = boost::filesystem::path(file_to_compress.get_path_for_compression());
        auto parent_boost_path = file_boost_path.parent_path();

        // Determine path without extension (used if file is a single compressed file, e.g., syslog.gz -> syslog)
        std::string filename_if_compressed;
        if (file_boost_path.has_stem()) {
            filename_if_compressed = file_boost_path.stem().string();
        } else {
            filename_if_compressed = file_boost_path.filename().string();
        }

        // Check if it's an archive
        auto error_code = m_libarchive_reader.try_open(m_file_reader, filename_if_compressed);
        if (ErrorCode_Success != error_code) {
            SPDLOG_ERROR("Cannot compress {} - failed to open with libarchive.", file_to_compress.get_path().c_str());
            return false;
        }

        // Compress each file and directory in the archive
        bool succeeded = true;
        set<string> directories;
        set<string> parent_directories;
        while (true) {
            error_code = m_libarchive_reader.try_read_next_header();
            if (ErrorCode_Success != error_code) {
                if (ErrorCode_EndOfFile == error_code) {
                    break;
                }
                SPDLOG_ERROR("Failed to read entry in {}.", file_to_compress.get_path().c_str());
                succeeded = false;
                break;
            }

            // Determine what type of file it is
            auto file_type = m_libarchive_reader.get_entry_file_type();
            if (AE_IFREG != file_type) {
                if (AE_IFDIR == file_type) {
                    // Trim trailing slash
                    string directory_path(m_libarchive_reader.get_path());
                    directory_path.resize(directory_path.length() - 1);

                    directories.emplace(directory_path);

                    auto directory_parent_path = boost::filesystem::path(directory_path).parent_path().string();
                    if (false == directory_parent_path.empty()) {
                        parent_directories.emplace(directory_parent_path);
                    }
                } // else ignore irregular files
                continue;
            }
            auto file_parent_path = boost::filesystem::path(m_libarchive_reader.get_path()).parent_path().string();
            if (false == file_parent_path.empty()) {
                parent_directories.emplace(file_parent_path);
            }

            if (archive_writer.get_data_size_of_dictionaries() >= target_data_size_of_dicts) {
                split_archive(archive_user_config, archive_writer);
            }

            m_libarchive_reader.open_file_reader(m_libarchive_file_reader);

            // Check that file is UTF-8 encoded
            if (auto error_code = m_libarchive_file_reader.try_load_data_block();
                ErrorCode_Success != error_code && ErrorCode_EndOfFile != error_code)
            {
                SPDLOG_ERROR(
                        "Failed to load data block from {}, error={}",
                        file_to_compress.get_path(),
                        error_code
                );
                m_libarchive_file_reader.close();
                succeeded = false;
                continue;
            }
            char const* utf8_validation_buf{nullptr};
            size_t utf8_validation_buf_len{0};
            m_libarchive_file_reader.peek_buffered_data(
                    utf8_validation_buf,
                    utf8_validation_buf_len
            );
            string file_path{m_libarchive_reader.get_path()};
            if (is_utf8_sequence(utf8_validation_buf_len, utf8_validation_buf)) {
                auto boost_path_for_compression = parent_boost_path / file_path;
                if (use_heuristic) {
                    parse_and_encode_with_heuristic(target_data_size_of_dicts, archive_user_config, target_encoded_file_size,
                                                    boost_path_for_compression.string(), file_to_compress.get_group_id(), archive_writer,
                                                    m_libarchive_file_reader);
                } else {
                    parse_and_encode(target_data_size_of_dicts, archive_user_config, target_encoded_file_size, boost_path_for_compression.string(),
                                     file_to_compress.get_group_id(), archive_writer, m_libarchive_file_reader);
                }
            } else if (has_ir_stream_magic_number({utf8_validation_buf, utf8_validation_buf_len})) {
                // Remove .clp suffix if found
                static constexpr char cIrStreamExtension[] = ".clp";
                if (boost::iends_with(file_path, cIrStreamExtension)) {
                    file_path.resize(file_path.length() - strlen(cIrStreamExtension));
                }
                auto boost_path_for_compression = parent_boost_path / file_path;

                if (false == compress_ir_stream(
                            target_data_size_of_dicts,
                            archive_user_config,
                            target_encoded_file_size,
                            boost_path_for_compression.string(),
                            file_to_compress.get_group_id(),
                            archive_writer,
                            m_libarchive_file_reader
                    )) {
                    succeeded = false;
                }
            } else {
                SPDLOG_ERROR("Cannot compress {} - not an IR stream or UTF-8 encoded", file_path);
                succeeded = false;
            }

            m_libarchive_file_reader.close();
        }
        compute_and_add_empty_directories(directories, parent_directories, parent_boost_path, archive_writer);

        m_libarchive_reader.close();

        return succeeded;
    }

    bool FileCompressor::compress_ir_stream(
            size_t target_data_size_of_dicts,
            streaming_archive::writer::Archive::UserConfig& archive_user_config,
            size_t target_encoded_file_size,
            string const& path,
            group_id_t group_id,
            streaming_archive::writer::Archive& archive_writer,
            ReaderInterface& reader
    ) {
        bool uses_four_byte_encoding{false};
        auto ir_error_code = ffi::ir_stream::get_encoding_type(reader, uses_four_byte_encoding);
        if (ffi::ir_stream::IRErrorCode_Success != ir_error_code) {
            SPDLOG_ERROR("Cannot compress {}, IR error={}", path, static_cast<int>(ir_error_code));
            return false;
        }

        try {
            std::error_code error_code{};
            if (uses_four_byte_encoding) {
                auto result
                        = LogEventDeserializer<ffi::four_byte_encoded_variable_t>::create(reader);
                if (result.has_error()) {
                    error_code = result.error();
                } else {
                    error_code = compress_ir_stream_by_encoding(
                            target_data_size_of_dicts,
                            archive_user_config,
                            target_encoded_file_size,
                            path,
                            group_id,
                            archive_writer,
                            result.value()
                    );
                }
            } else {
                auto result
                        = LogEventDeserializer<ffi::eight_byte_encoded_variable_t>::create(reader);
                if (result.has_error()) {
                    error_code = result.error();
                } else {
                    error_code = compress_ir_stream_by_encoding(
                            target_data_size_of_dicts,
                            archive_user_config,
                            target_encoded_file_size,
                            path,
                            group_id,
                            archive_writer,
                            result.value()
                    );
                }
            }
            if (0 != error_code.value()) {
                SPDLOG_ERROR(
                        "Failed to compress {} - {}:{}",
                        path,
                        error_code.category().name(),
                        error_code.message()
                );
                return false;
            }
        } catch (TraceableException& e) {
            auto error_code = e.get_error_code();
            if (ErrorCode_errno == error_code) {
                SPDLOG_ERROR(
                        "Failed to compress {} - {}:{} {}, errno={}",
                        path,
                        e.get_filename(),
                        e.get_line_number(),
                        e.what(),
                        errno
                );
            } else {
                SPDLOG_ERROR(
                        "Failed to compress {} - {}:{} {}, error_code={}",
                        path,
                        e.get_filename(),
                        e.get_line_number(),
                        e.what(),
                        error_code
                );
            }
            return false;
        }

        return true;
    }

    template <typename encoded_variable_t>
    std::error_code FileCompressor::compress_ir_stream_by_encoding(
            size_t target_data_size_of_dicts,
            streaming_archive::writer::Archive::UserConfig& archive_user_config,
            size_t target_encoded_file_size,
            string const& path,
            group_id_t group_id,
            streaming_archive::writer::Archive& archive,
            LogEventDeserializer<encoded_variable_t>& log_event_deserializer
    ) {
        archive.create_and_open_file(path, group_id, m_uuid_generator(), 0);

        // We assume an IR stream only has one timestamp pattern
        auto timestamp_pattern = log_event_deserializer.get_timestamp_pattern();
        archive.change_ts_pattern(&timestamp_pattern);

        std::error_code error_code{};
        while (true) {
            auto result = log_event_deserializer.deserialize_log_event();
            if (result.has_error()) {
                auto error = result.error();
                if (std::errc::no_message_available != error) {
                    error_code = error;
                }
                break;
            }

            // Split archive/encoded file if necessary before writing the new event
            if (archive.get_data_size_of_dictionaries() >= target_data_size_of_dicts) {
                split_file_and_archive(
                        archive_user_config,
                        path,
                        group_id,
                        &timestamp_pattern,
                        archive
                );
            } else if (archive.get_file().get_encoded_size_in_bytes() >= target_encoded_file_size) {
                split_file(path, group_id, &timestamp_pattern, archive);
            }

            archive.write_log_event_ir(result.value());
        }

        close_file_and_append_to_segment(archive);
        return error_code;
    }

    // Explicitly declare template specializations so that we can define the
    // template methods in this file
    template std::error_code
    FileCompressor::compress_ir_stream_by_encoding<ffi::eight_byte_encoded_variable_t>(
            size_t target_data_size_of_dicts,
            streaming_archive::writer::Archive::UserConfig& archive_user_config,
            size_t target_encoded_file_size,
            string const& path,
            group_id_t group_id,
            streaming_archive::writer::Archive& archive,
            LogEventDeserializer<ffi::eight_byte_encoded_variable_t>& log_event_deserializer
    );
    template std::error_code
    FileCompressor::compress_ir_stream_by_encoding<ffi::four_byte_encoded_variable_t>(
            size_t target_data_size_of_dicts,
            streaming_archive::writer::Archive::UserConfig& archive_user_config,
            size_t target_encoded_file_size,
            string const& path,
            group_id_t group_id,
            streaming_archive::writer::Archive& archive,
            LogEventDeserializer<ffi::four_byte_encoded_variable_t>& log_event_deserializer
    );
}
