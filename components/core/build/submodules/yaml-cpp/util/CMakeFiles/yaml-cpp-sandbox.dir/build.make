# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/clp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/clp/build

# Include any dependencies generated for this target.
include submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/depend.make

# Include the progress variables for this target.
include submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/progress.make

# Include the compile flags for this target's objects.
include submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/flags.make

submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.o: submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/flags.make
submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.o: ../submodules/yaml-cpp/util/sandbox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/clp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.o"
	cd /mnt/clp/build/submodules/yaml-cpp/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.o -c /mnt/clp/submodules/yaml-cpp/util/sandbox.cpp

submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.i"
	cd /mnt/clp/build/submodules/yaml-cpp/util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/clp/submodules/yaml-cpp/util/sandbox.cpp > CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.i

submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.s"
	cd /mnt/clp/build/submodules/yaml-cpp/util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/clp/submodules/yaml-cpp/util/sandbox.cpp -o CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.s

# Object files for target yaml-cpp-sandbox
yaml__cpp__sandbox_OBJECTS = \
"CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.o"

# External object files for target yaml-cpp-sandbox
yaml__cpp__sandbox_EXTERNAL_OBJECTS =

submodules/yaml-cpp/util/sandbox: submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/sandbox.cpp.o
submodules/yaml-cpp/util/sandbox: submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/build.make
submodules/yaml-cpp/util/sandbox: submodules/yaml-cpp/libyaml-cpp.a
submodules/yaml-cpp/util/sandbox: submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/clp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sandbox"
	cd /mnt/clp/build/submodules/yaml-cpp/util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yaml-cpp-sandbox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/build: submodules/yaml-cpp/util/sandbox

.PHONY : submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/build

submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/clean:
	cd /mnt/clp/build/submodules/yaml-cpp/util && $(CMAKE_COMMAND) -P CMakeFiles/yaml-cpp-sandbox.dir/cmake_clean.cmake
.PHONY : submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/clean

submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/depend:
	cd /mnt/clp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/clp /mnt/clp/submodules/yaml-cpp/util /mnt/clp/build /mnt/clp/build/submodules/yaml-cpp/util /mnt/clp/build/submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : submodules/yaml-cpp/util/CMakeFiles/yaml-cpp-sandbox.dir/depend
