
// Generated from KQL.g4 by ANTLR 4.11.1


#include "KQLLexer.h"


using namespace antlr4;

using namespace kql;


using namespace antlr4;

namespace {

struct KQLLexerStaticData final {
  KQLLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  KQLLexerStaticData(const KQLLexerStaticData&) = delete;
  KQLLexerStaticData(KQLLexerStaticData&&) = delete;
  KQLLexerStaticData& operator=(const KQLLexerStaticData&) = delete;
  KQLLexerStaticData& operator=(KQLLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag kqllexerLexerOnceFlag;
KQLLexerStaticData *kqllexerLexerStaticData = nullptr;

void kqllexerLexerInitialize() {
  assert(kqllexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<KQLLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "AND", "OR", "NOT", "DATE_LITERAL", 
      "LITERAL", "QUOTED_STRING", "UNQUOTED_LITERAL", "QUOTED_CHARACTER", 
      "UNQUOTED_CHARACTER", "WILDCARD", "ESCAPED_KEYWORD", "KEYWORD", "RANGE_OPERATOR", 
      "ESCAPED_SPECIAL_CHARACTER", "ESCAPED_SPACE", "SPECIAL_CHARACTER", 
      "SPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "':'", "'{'", "'}'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "AND", "OR", "NOT", "DATE_LITERAL", "LITERAL", 
      "QUOTED_STRING", "UNQUOTED_LITERAL", "RANGE_OPERATOR", "SPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,14,154,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,5,1,6,1,6,
  	1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,4,8,75,8,8,11,8,12,
  	8,76,1,8,1,8,1,8,4,8,82,8,8,11,8,12,8,83,3,8,86,8,8,1,8,1,8,1,9,1,9,3,
  	9,92,8,9,1,10,1,10,5,10,96,8,10,10,10,12,10,99,9,10,1,10,1,10,1,11,4,
  	11,104,8,11,11,11,12,11,105,1,12,1,12,1,12,1,12,3,12,112,8,12,1,13,1,
  	13,1,13,1,13,1,13,3,13,119,8,13,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,
  	16,3,16,129,8,16,1,17,1,17,1,17,1,17,1,17,3,17,136,8,17,1,18,1,18,1,18,
  	1,19,1,19,1,19,1,19,1,19,1,19,3,19,147,8,19,1,20,1,20,1,21,1,21,1,21,
  	1,21,0,0,22,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,
  	25,0,27,0,29,0,31,0,33,0,35,13,37,0,39,0,41,0,43,14,1,0,11,2,0,65,65,
  	97,97,2,0,78,78,110,110,2,0,68,68,100,100,2,0,79,79,111,111,2,0,82,82,
  	114,114,2,0,84,84,116,116,1,0,34,34,11,0,9,10,13,13,32,32,34,34,40,41,
  	58,58,60,60,62,62,92,92,123,123,125,125,2,0,60,60,62,62,8,0,34,34,40,
  	42,58,58,60,60,62,62,92,92,123,123,125,125,3,0,9,10,13,13,32,32,163,0,
  	1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,
  	0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,
  	23,1,0,0,0,0,35,1,0,0,0,0,43,1,0,0,0,1,45,1,0,0,0,3,47,1,0,0,0,5,49,1,
  	0,0,0,7,51,1,0,0,0,9,53,1,0,0,0,11,55,1,0,0,0,13,59,1,0,0,0,15,62,1,0,
  	0,0,17,66,1,0,0,0,19,91,1,0,0,0,21,93,1,0,0,0,23,103,1,0,0,0,25,111,1,
  	0,0,0,27,118,1,0,0,0,29,120,1,0,0,0,31,122,1,0,0,0,33,128,1,0,0,0,35,
  	135,1,0,0,0,37,137,1,0,0,0,39,146,1,0,0,0,41,148,1,0,0,0,43,150,1,0,0,
  	0,45,46,5,58,0,0,46,2,1,0,0,0,47,48,5,123,0,0,48,4,1,0,0,0,49,50,5,125,
  	0,0,50,6,1,0,0,0,51,52,5,40,0,0,52,8,1,0,0,0,53,54,5,41,0,0,54,10,1,0,
  	0,0,55,56,7,0,0,0,56,57,7,1,0,0,57,58,7,2,0,0,58,12,1,0,0,0,59,60,7,3,
  	0,0,60,61,7,4,0,0,61,14,1,0,0,0,62,63,7,1,0,0,63,64,7,3,0,0,64,65,7,5,
  	0,0,65,16,1,0,0,0,66,67,5,100,0,0,67,68,5,97,0,0,68,69,5,116,0,0,69,70,
  	5,101,0,0,70,71,5,40,0,0,71,85,1,0,0,0,72,74,5,34,0,0,73,75,3,25,12,0,
  	74,73,1,0,0,0,75,76,1,0,0,0,76,74,1,0,0,0,76,77,1,0,0,0,77,78,1,0,0,0,
  	78,79,5,34,0,0,79,86,1,0,0,0,80,82,3,25,12,0,81,80,1,0,0,0,82,83,1,0,
  	0,0,83,81,1,0,0,0,83,84,1,0,0,0,84,86,1,0,0,0,85,72,1,0,0,0,85,81,1,0,
  	0,0,86,87,1,0,0,0,87,88,5,41,0,0,88,18,1,0,0,0,89,92,3,21,10,0,90,92,
  	3,23,11,0,91,89,1,0,0,0,91,90,1,0,0,0,92,20,1,0,0,0,93,97,5,34,0,0,94,
  	96,3,25,12,0,95,94,1,0,0,0,96,99,1,0,0,0,97,95,1,0,0,0,97,98,1,0,0,0,
  	98,100,1,0,0,0,99,97,1,0,0,0,100,101,5,34,0,0,101,22,1,0,0,0,102,104,
  	3,27,13,0,103,102,1,0,0,0,104,105,1,0,0,0,105,103,1,0,0,0,105,106,1,0,
  	0,0,106,24,1,0,0,0,107,112,3,39,19,0,108,109,5,92,0,0,109,112,5,34,0,
  	0,110,112,8,6,0,0,111,107,1,0,0,0,111,108,1,0,0,0,111,110,1,0,0,0,112,
  	26,1,0,0,0,113,119,3,39,19,0,114,119,3,37,18,0,115,119,3,31,15,0,116,
  	119,3,29,14,0,117,119,8,7,0,0,118,113,1,0,0,0,118,114,1,0,0,0,118,115,
  	1,0,0,0,118,116,1,0,0,0,118,117,1,0,0,0,119,28,1,0,0,0,120,121,5,42,0,
  	0,121,30,1,0,0,0,122,123,5,92,0,0,123,124,3,33,16,0,124,32,1,0,0,0,125,
  	129,3,11,5,0,126,129,3,13,6,0,127,129,3,15,7,0,128,125,1,0,0,0,128,126,
  	1,0,0,0,128,127,1,0,0,0,129,34,1,0,0,0,130,131,5,60,0,0,131,136,5,61,
  	0,0,132,133,5,62,0,0,133,136,5,61,0,0,134,136,7,8,0,0,135,130,1,0,0,0,
  	135,132,1,0,0,0,135,134,1,0,0,0,136,36,1,0,0,0,137,138,5,92,0,0,138,139,
  	3,41,20,0,139,38,1,0,0,0,140,141,5,92,0,0,141,147,5,116,0,0,142,143,5,
  	92,0,0,143,147,5,114,0,0,144,145,5,92,0,0,145,147,5,110,0,0,146,140,1,
  	0,0,0,146,142,1,0,0,0,146,144,1,0,0,0,147,40,1,0,0,0,148,149,7,9,0,0,
  	149,42,1,0,0,0,150,151,7,10,0,0,151,152,1,0,0,0,152,153,6,21,0,0,153,
  	44,1,0,0,0,12,0,76,83,85,91,97,105,111,118,128,135,146,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  kqllexerLexerStaticData = staticData.release();
}

}

KQLLexer::KQLLexer(CharStream *input) : Lexer(input) {
  KQLLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *kqllexerLexerStaticData->atn, kqllexerLexerStaticData->decisionToDFA, kqllexerLexerStaticData->sharedContextCache);
}

KQLLexer::~KQLLexer() {
  delete _interpreter;
}

std::string KQLLexer::getGrammarFileName() const {
  return "KQL.g4";
}

const std::vector<std::string>& KQLLexer::getRuleNames() const {
  return kqllexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& KQLLexer::getChannelNames() const {
  return kqllexerLexerStaticData->channelNames;
}

const std::vector<std::string>& KQLLexer::getModeNames() const {
  return kqllexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& KQLLexer::getVocabulary() const {
  return kqllexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView KQLLexer::getSerializedATN() const {
  return kqllexerLexerStaticData->serializedATN;
}

const atn::ATN& KQLLexer::getATN() const {
  return *kqllexerLexerStaticData->atn;
}




void KQLLexer::initialize() {
  ::antlr4::internal::call_once(kqllexerLexerOnceFlag, kqllexerLexerInitialize);
}
