
// Generated from KQL.g4 by ANTLR 4.11.1


#include "KQLVisitor.h"

#include "KQLParser.h"


using namespace antlrcpp;
using namespace kql;

using namespace antlr4;

namespace {

struct KQLParserStaticData final {
  KQLParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  KQLParserStaticData(const KQLParserStaticData&) = delete;
  KQLParserStaticData(KQLParserStaticData&&) = delete;
  KQLParserStaticData& operator=(const KQLParserStaticData&) = delete;
  KQLParserStaticData& operator=(KQLParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag kqlParserOnceFlag;
KQLParserStaticData *kqlParserStaticData = nullptr;

void kqlParserInitialize() {
  assert(kqlParserStaticData == nullptr);
  auto staticData = std::make_unique<KQLParserStaticData>(
    std::vector<std::string>{
      "start", "query", "expression", "column_range_expression", "column_value_expression", 
      "column", "value_expression", "list_of_values"
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
  	4,1,14,78,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,3,1,34,8,1,1,1,1,1,1,1,5,1,39,8,1,10,1,12,1,42,9,1,1,2,1,2,1,2,3,2,
  	47,8,2,1,3,1,3,1,3,1,3,3,3,53,8,3,1,4,1,4,1,4,1,4,1,4,3,4,60,8,4,1,5,
  	1,5,1,6,1,6,1,7,1,7,3,7,68,8,7,1,7,5,7,71,8,7,10,7,12,7,74,9,7,1,7,1,
  	7,1,7,0,1,2,8,0,2,4,6,8,10,12,14,0,2,1,0,6,7,1,0,6,8,80,0,16,1,0,0,0,
  	2,33,1,0,0,0,4,46,1,0,0,0,6,48,1,0,0,0,8,54,1,0,0,0,10,61,1,0,0,0,12,
  	63,1,0,0,0,14,65,1,0,0,0,16,17,3,2,1,0,17,18,5,0,0,1,18,1,1,0,0,0,19,
  	20,6,1,-1,0,20,21,3,10,5,0,21,22,5,1,0,0,22,23,5,2,0,0,23,24,3,2,1,0,
  	24,25,5,3,0,0,25,34,1,0,0,0,26,27,5,4,0,0,27,28,3,2,1,0,28,29,5,5,0,0,
  	29,34,1,0,0,0,30,31,5,8,0,0,31,34,3,2,1,3,32,34,3,4,2,0,33,19,1,0,0,0,
  	33,26,1,0,0,0,33,30,1,0,0,0,33,32,1,0,0,0,34,40,1,0,0,0,35,36,10,2,0,
  	0,36,37,7,0,0,0,37,39,3,2,1,3,38,35,1,0,0,0,39,42,1,0,0,0,40,38,1,0,0,
  	0,40,41,1,0,0,0,41,3,1,0,0,0,42,40,1,0,0,0,43,47,3,6,3,0,44,47,3,8,4,
  	0,45,47,3,12,6,0,46,43,1,0,0,0,46,44,1,0,0,0,46,45,1,0,0,0,47,5,1,0,0,
  	0,48,49,3,10,5,0,49,52,5,13,0,0,50,53,5,9,0,0,51,53,5,10,0,0,52,50,1,
  	0,0,0,52,51,1,0,0,0,53,7,1,0,0,0,54,55,3,10,5,0,55,59,5,1,0,0,56,60,3,
  	14,7,0,57,60,5,9,0,0,58,60,5,10,0,0,59,56,1,0,0,0,59,57,1,0,0,0,59,58,
  	1,0,0,0,60,9,1,0,0,0,61,62,5,10,0,0,62,11,1,0,0,0,63,64,5,10,0,0,64,13,
  	1,0,0,0,65,67,5,4,0,0,66,68,7,1,0,0,67,66,1,0,0,0,67,68,1,0,0,0,68,72,
  	1,0,0,0,69,71,5,10,0,0,70,69,1,0,0,0,71,74,1,0,0,0,72,70,1,0,0,0,72,73,
  	1,0,0,0,73,75,1,0,0,0,74,72,1,0,0,0,75,76,5,5,0,0,76,15,1,0,0,0,7,33,
  	40,46,52,59,67,72
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  kqlParserStaticData = staticData.release();
}

}

KQLParser::KQLParser(TokenStream *input) : KQLParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

KQLParser::KQLParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  KQLParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *kqlParserStaticData->atn, kqlParserStaticData->decisionToDFA, kqlParserStaticData->sharedContextCache, options);
}

KQLParser::~KQLParser() {
  delete _interpreter;
}

const atn::ATN& KQLParser::getATN() const {
  return *kqlParserStaticData->atn;
}

std::string KQLParser::getGrammarFileName() const {
  return "KQL.g4";
}

const std::vector<std::string>& KQLParser::getRuleNames() const {
  return kqlParserStaticData->ruleNames;
}

const dfa::Vocabulary& KQLParser::getVocabulary() const {
  return kqlParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView KQLParser::getSerializedATN() const {
  return kqlParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

KQLParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KQLParser::QueryContext* KQLParser::StartContext::query() {
  return getRuleContext<KQLParser::QueryContext>(0);
}

tree::TerminalNode* KQLParser::StartContext::EOF() {
  return getToken(KQLParser::EOF, 0);
}


size_t KQLParser::StartContext::getRuleIndex() const {
  return KQLParser::RuleStart;
}


std::any KQLParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

KQLParser::StartContext* KQLParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, KQLParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    query(0);
    setState(17);
    match(KQLParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QueryContext ------------------------------------------------------------------

KQLParser::QueryContext::QueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t KQLParser::QueryContext::getRuleIndex() const {
  return KQLParser::RuleQuery;
}

void KQLParser::QueryContext::copyFrom(QueryContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprContext ------------------------------------------------------------------

KQLParser::ExpressionContext* KQLParser::ExprContext::expression() {
  return getRuleContext<KQLParser::ExpressionContext>(0);
}

KQLParser::ExprContext::ExprContext(QueryContext *ctx) { copyFrom(ctx); }


std::any KQLParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NestedQueryContext ------------------------------------------------------------------

KQLParser::ColumnContext* KQLParser::NestedQueryContext::column() {
  return getRuleContext<KQLParser::ColumnContext>(0);
}

KQLParser::QueryContext* KQLParser::NestedQueryContext::query() {
  return getRuleContext<KQLParser::QueryContext>(0);
}

KQLParser::NestedQueryContext::NestedQueryContext(QueryContext *ctx) { copyFrom(ctx); }


std::any KQLParser::NestedQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitNestedQuery(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotQueryContext ------------------------------------------------------------------

tree::TerminalNode* KQLParser::NotQueryContext::NOT() {
  return getToken(KQLParser::NOT, 0);
}

KQLParser::QueryContext* KQLParser::NotQueryContext::query() {
  return getRuleContext<KQLParser::QueryContext>(0);
}

KQLParser::NotQueryContext::NotQueryContext(QueryContext *ctx) { copyFrom(ctx); }


std::any KQLParser::NotQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitNotQuery(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubQueryContext ------------------------------------------------------------------

KQLParser::QueryContext* KQLParser::SubQueryContext::query() {
  return getRuleContext<KQLParser::QueryContext>(0);
}

KQLParser::SubQueryContext::SubQueryContext(QueryContext *ctx) { copyFrom(ctx); }


std::any KQLParser::SubQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitSubQuery(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrAndQueryContext ------------------------------------------------------------------

std::vector<KQLParser::QueryContext *> KQLParser::OrAndQueryContext::query() {
  return getRuleContexts<KQLParser::QueryContext>();
}

KQLParser::QueryContext* KQLParser::OrAndQueryContext::query(size_t i) {
  return getRuleContext<KQLParser::QueryContext>(i);
}

tree::TerminalNode* KQLParser::OrAndQueryContext::OR() {
  return getToken(KQLParser::OR, 0);
}

tree::TerminalNode* KQLParser::OrAndQueryContext::AND() {
  return getToken(KQLParser::AND, 0);
}

KQLParser::OrAndQueryContext::OrAndQueryContext(QueryContext *ctx) { copyFrom(ctx); }


std::any KQLParser::OrAndQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitOrAndQuery(this);
  else
    return visitor->visitChildren(this);
}

KQLParser::QueryContext* KQLParser::query() {
   return query(0);
}

KQLParser::QueryContext* KQLParser::query(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  KQLParser::QueryContext *_localctx = _tracker.createInstance<QueryContext>(_ctx, parentState);
  KQLParser::QueryContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, KQLParser::RuleQuery, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(33);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<NestedQueryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(20);
      antlrcpp::downCast<NestedQueryContext *>(_localctx)->col = column();
      setState(21);
      match(KQLParser::T__0);
      setState(22);
      match(KQLParser::T__1);
      setState(23);
      antlrcpp::downCast<NestedQueryContext *>(_localctx)->q = query(0);
      setState(24);
      match(KQLParser::T__2);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SubQueryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(26);
      match(KQLParser::T__3);
      setState(27);
      antlrcpp::downCast<SubQueryContext *>(_localctx)->q = query(0);
      setState(28);
      match(KQLParser::T__4);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NotQueryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(30);
      match(KQLParser::NOT);
      setState(31);
      antlrcpp::downCast<NotQueryContext *>(_localctx)->q = query(3);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(32);
      expression();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(40);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<OrAndQueryContext>(_tracker.createInstance<QueryContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->lhs = previousContext;
        pushNewRecursionContext(newContext, startState, RuleQuery);
        setState(35);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(36);
        antlrcpp::downCast<OrAndQueryContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == KQLParser::AND

        || _la == KQLParser::OR)) {
          antlrcpp::downCast<OrAndQueryContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(37);
        antlrcpp::downCast<OrAndQueryContext *>(_localctx)->rhs = query(3); 
      }
      setState(42);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

KQLParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KQLParser::Column_range_expressionContext* KQLParser::ExpressionContext::column_range_expression() {
  return getRuleContext<KQLParser::Column_range_expressionContext>(0);
}

KQLParser::Column_value_expressionContext* KQLParser::ExpressionContext::column_value_expression() {
  return getRuleContext<KQLParser::Column_value_expressionContext>(0);
}

KQLParser::Value_expressionContext* KQLParser::ExpressionContext::value_expression() {
  return getRuleContext<KQLParser::Value_expressionContext>(0);
}


size_t KQLParser::ExpressionContext::getRuleIndex() const {
  return KQLParser::RuleExpression;
}


std::any KQLParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

KQLParser::ExpressionContext* KQLParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 4, KQLParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(43);
      column_range_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(44);
      column_value_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(45);
      value_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_range_expressionContext ------------------------------------------------------------------

KQLParser::Column_range_expressionContext::Column_range_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KQLParser::Column_range_expressionContext::RANGE_OPERATOR() {
  return getToken(KQLParser::RANGE_OPERATOR, 0);
}

KQLParser::ColumnContext* KQLParser::Column_range_expressionContext::column() {
  return getRuleContext<KQLParser::ColumnContext>(0);
}

tree::TerminalNode* KQLParser::Column_range_expressionContext::DATE_LITERAL() {
  return getToken(KQLParser::DATE_LITERAL, 0);
}

tree::TerminalNode* KQLParser::Column_range_expressionContext::LITERAL() {
  return getToken(KQLParser::LITERAL, 0);
}


size_t KQLParser::Column_range_expressionContext::getRuleIndex() const {
  return KQLParser::RuleColumn_range_expression;
}


std::any KQLParser::Column_range_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitColumn_range_expression(this);
  else
    return visitor->visitChildren(this);
}

KQLParser::Column_range_expressionContext* KQLParser::column_range_expression() {
  Column_range_expressionContext *_localctx = _tracker.createInstance<Column_range_expressionContext>(_ctx, getState());
  enterRule(_localctx, 6, KQLParser::RuleColumn_range_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    antlrcpp::downCast<Column_range_expressionContext *>(_localctx)->col = column();
    setState(49);
    match(KQLParser::RANGE_OPERATOR);
    setState(52);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KQLParser::DATE_LITERAL: {
        setState(50);
        antlrcpp::downCast<Column_range_expressionContext *>(_localctx)->date_lit = match(KQLParser::DATE_LITERAL);
        break;
      }

      case KQLParser::LITERAL: {
        setState(51);
        antlrcpp::downCast<Column_range_expressionContext *>(_localctx)->lit = match(KQLParser::LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_value_expressionContext ------------------------------------------------------------------

KQLParser::Column_value_expressionContext::Column_value_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

KQLParser::ColumnContext* KQLParser::Column_value_expressionContext::column() {
  return getRuleContext<KQLParser::ColumnContext>(0);
}

KQLParser::List_of_valuesContext* KQLParser::Column_value_expressionContext::list_of_values() {
  return getRuleContext<KQLParser::List_of_valuesContext>(0);
}

tree::TerminalNode* KQLParser::Column_value_expressionContext::DATE_LITERAL() {
  return getToken(KQLParser::DATE_LITERAL, 0);
}

tree::TerminalNode* KQLParser::Column_value_expressionContext::LITERAL() {
  return getToken(KQLParser::LITERAL, 0);
}


size_t KQLParser::Column_value_expressionContext::getRuleIndex() const {
  return KQLParser::RuleColumn_value_expression;
}


std::any KQLParser::Column_value_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitColumn_value_expression(this);
  else
    return visitor->visitChildren(this);
}

KQLParser::Column_value_expressionContext* KQLParser::column_value_expression() {
  Column_value_expressionContext *_localctx = _tracker.createInstance<Column_value_expressionContext>(_ctx, getState());
  enterRule(_localctx, 8, KQLParser::RuleColumn_value_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    antlrcpp::downCast<Column_value_expressionContext *>(_localctx)->col = column();
    setState(55);
    match(KQLParser::T__0);
    setState(59);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case KQLParser::T__3: {
        setState(56);
        antlrcpp::downCast<Column_value_expressionContext *>(_localctx)->list = list_of_values();
        break;
      }

      case KQLParser::DATE_LITERAL: {
        setState(57);
        antlrcpp::downCast<Column_value_expressionContext *>(_localctx)->date_lit = match(KQLParser::DATE_LITERAL);
        break;
      }

      case KQLParser::LITERAL: {
        setState(58);
        antlrcpp::downCast<Column_value_expressionContext *>(_localctx)->lit = match(KQLParser::LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnContext ------------------------------------------------------------------

KQLParser::ColumnContext::ColumnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KQLParser::ColumnContext::LITERAL() {
  return getToken(KQLParser::LITERAL, 0);
}


size_t KQLParser::ColumnContext::getRuleIndex() const {
  return KQLParser::RuleColumn;
}


std::any KQLParser::ColumnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitColumn(this);
  else
    return visitor->visitChildren(this);
}

KQLParser::ColumnContext* KQLParser::column() {
  ColumnContext *_localctx = _tracker.createInstance<ColumnContext>(_ctx, getState());
  enterRule(_localctx, 10, KQLParser::RuleColumn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(KQLParser::LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_expressionContext ------------------------------------------------------------------

KQLParser::Value_expressionContext::Value_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* KQLParser::Value_expressionContext::LITERAL() {
  return getToken(KQLParser::LITERAL, 0);
}


size_t KQLParser::Value_expressionContext::getRuleIndex() const {
  return KQLParser::RuleValue_expression;
}


std::any KQLParser::Value_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitValue_expression(this);
  else
    return visitor->visitChildren(this);
}

KQLParser::Value_expressionContext* KQLParser::value_expression() {
  Value_expressionContext *_localctx = _tracker.createInstance<Value_expressionContext>(_ctx, getState());
  enterRule(_localctx, 12, KQLParser::RuleValue_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(KQLParser::LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- List_of_valuesContext ------------------------------------------------------------------

KQLParser::List_of_valuesContext::List_of_valuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> KQLParser::List_of_valuesContext::LITERAL() {
  return getTokens(KQLParser::LITERAL);
}

tree::TerminalNode* KQLParser::List_of_valuesContext::LITERAL(size_t i) {
  return getToken(KQLParser::LITERAL, i);
}

tree::TerminalNode* KQLParser::List_of_valuesContext::AND() {
  return getToken(KQLParser::AND, 0);
}

tree::TerminalNode* KQLParser::List_of_valuesContext::OR() {
  return getToken(KQLParser::OR, 0);
}

tree::TerminalNode* KQLParser::List_of_valuesContext::NOT() {
  return getToken(KQLParser::NOT, 0);
}


size_t KQLParser::List_of_valuesContext::getRuleIndex() const {
  return KQLParser::RuleList_of_values;
}


std::any KQLParser::List_of_valuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<KQLVisitor*>(visitor))
    return parserVisitor->visitList_of_values(this);
  else
    return visitor->visitChildren(this);
}

KQLParser::List_of_valuesContext* KQLParser::list_of_values() {
  List_of_valuesContext *_localctx = _tracker.createInstance<List_of_valuesContext>(_ctx, getState());
  enterRule(_localctx, 14, KQLParser::RuleList_of_values);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(KQLParser::T__3);
    setState(67);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 448) != 0) {
      setState(66);
      antlrcpp::downCast<List_of_valuesContext *>(_localctx)->condition = _input->LT(1);
      _la = _input->LA(1);
      if (!(((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 448) != 0)) {
        antlrcpp::downCast<List_of_valuesContext *>(_localctx)->condition = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(72);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == KQLParser::LITERAL) {
      setState(69);
      antlrcpp::downCast<List_of_valuesContext *>(_localctx)->literalToken = match(KQLParser::LITERAL);
      antlrcpp::downCast<List_of_valuesContext *>(_localctx)->literals.push_back(antlrcpp::downCast<List_of_valuesContext *>(_localctx)->literalToken);
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(75);
    match(KQLParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool KQLParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return querySempred(antlrcpp::downCast<QueryContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool KQLParser::querySempred(QueryContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void KQLParser::initialize() {
  ::antlr4::internal::call_once(kqlParserOnceFlag, kqlParserInitialize);
}
