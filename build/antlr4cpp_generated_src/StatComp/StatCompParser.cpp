
// Generated from /home/mayta/projects/CompilersTheory/StatComP/src/StatComp.g4 by ANTLR 4.13.2


#include "StatCompVisitor.h"

#include "StatCompParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct StatCompParserStaticData final {
  StatCompParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  StatCompParserStaticData(const StatCompParserStaticData&) = delete;
  StatCompParserStaticData(StatCompParserStaticData&&) = delete;
  StatCompParserStaticData& operator=(const StatCompParserStaticData&) = delete;
  StatCompParserStaticData& operator=(StatCompParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag statcompParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<StatCompParserStaticData> statcompParserStaticData = nullptr;

void statcompParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (statcompParserStaticData != nullptr) {
    return;
  }
#else
  assert(statcompParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<StatCompParserStaticData>(
    std::vector<std::string>{
      "prog", "stmt", "expr", "statFunc", "tableFunc", "arglist", "arrayInit", 
      "numlist", "num", "decltype"
    },
    std::vector<std::string>{
      "", "';'", "'Mean'", "'Median'", "'Mode'", "'Stdev'", "'Var'", "'Square_root'", 
      "'Range'", "'CoeffVar'", "'Quartile'", "'IQR'", "'Percentile'", "'Min'", 
      "'Max'", "'Sum'", "'Count'", "'Skewness'", "'Kurtosis'", "'Moment'", 
      "'Standardize'", "'ZProb'", "'InvZ'", "'NormalPDF'", "'NormalCDF'", 
      "'UniformPDF'", "'UniformCDF'", "'Print'", "'Freq'", "'AbsFreq'", 
      "'RelFreq'", "'AbsFreqCum'", "'RelFreqCum'", "'CrossTab'", "'^'", 
      "'+'", "'-'", "'*'", "'/'", "'//'", "'%'", "'='", "'('", "')'", "'{'", 
      "'}'", "'['", "']'", "','", "'int'", "'float'", "'string'", "'array'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "POW", "ADD", "SUB", "MUL", "DIV", "INTDIV", "MOD", "ASSIGN", "LPAR", 
      "RPAR", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COMMA", "TINT", "TFLOAT", 
      "TSTRING", "ARRAY", "ID", "INT", "FLOAT", "STRING", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,57,120,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,1,0,5,0,22,8,0,10,0,12,0,25,9,0,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,43,8,1,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,63,
  	8,2,1,2,1,2,1,2,1,2,1,2,3,2,70,8,2,1,2,1,2,3,2,74,8,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,5,2,85,8,2,10,2,12,2,88,9,2,1,3,1,3,1,4,1,4,1,5,1,
  	5,1,5,5,5,97,8,5,10,5,12,5,100,9,5,1,6,1,6,3,6,104,8,6,1,6,1,6,1,7,1,
  	7,1,7,5,7,111,8,7,10,7,12,7,114,9,7,1,8,1,8,1,9,1,9,1,9,0,1,4,10,0,2,
  	4,6,8,10,12,14,16,18,0,6,1,0,37,40,1,0,35,36,1,0,2,27,1,0,28,33,1,0,54,
  	55,1,0,49,51,127,0,23,1,0,0,0,2,42,1,0,0,0,4,73,1,0,0,0,6,89,1,0,0,0,
  	8,91,1,0,0,0,10,93,1,0,0,0,12,101,1,0,0,0,14,107,1,0,0,0,16,115,1,0,0,
  	0,18,117,1,0,0,0,20,22,3,2,1,0,21,20,1,0,0,0,22,25,1,0,0,0,23,21,1,0,
  	0,0,23,24,1,0,0,0,24,1,1,0,0,0,25,23,1,0,0,0,26,27,3,4,2,0,27,28,5,1,
  	0,0,28,43,1,0,0,0,29,30,3,18,9,0,30,31,5,53,0,0,31,32,5,41,0,0,32,33,
  	3,4,2,0,33,34,5,1,0,0,34,43,1,0,0,0,35,36,5,52,0,0,36,37,3,18,9,0,37,
  	38,5,53,0,0,38,39,5,41,0,0,39,40,3,12,6,0,40,41,5,1,0,0,41,43,1,0,0,0,
  	42,26,1,0,0,0,42,29,1,0,0,0,42,35,1,0,0,0,43,3,1,0,0,0,44,45,6,2,-1,0,
  	45,46,5,36,0,0,46,74,3,4,2,11,47,48,5,42,0,0,48,49,3,4,2,0,49,50,5,43,
  	0,0,50,74,1,0,0,0,51,74,3,16,8,0,52,74,5,56,0,0,53,74,5,53,0,0,54,55,
  	5,53,0,0,55,56,5,46,0,0,56,57,3,4,2,0,57,58,5,47,0,0,58,74,1,0,0,0,59,
  	60,3,6,3,0,60,62,5,42,0,0,61,63,3,10,5,0,62,61,1,0,0,0,62,63,1,0,0,0,
  	63,64,1,0,0,0,64,65,5,43,0,0,65,74,1,0,0,0,66,67,3,8,4,0,67,69,5,42,0,
  	0,68,70,3,10,5,0,69,68,1,0,0,0,69,70,1,0,0,0,70,71,1,0,0,0,71,72,5,43,
  	0,0,72,74,1,0,0,0,73,44,1,0,0,0,73,47,1,0,0,0,73,51,1,0,0,0,73,52,1,0,
  	0,0,73,53,1,0,0,0,73,54,1,0,0,0,73,59,1,0,0,0,73,66,1,0,0,0,74,86,1,0,
  	0,0,75,76,10,10,0,0,76,77,5,34,0,0,77,85,3,4,2,11,78,79,10,9,0,0,79,80,
  	7,0,0,0,80,85,3,4,2,10,81,82,10,8,0,0,82,83,7,1,0,0,83,85,3,4,2,9,84,
  	75,1,0,0,0,84,78,1,0,0,0,84,81,1,0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,86,
  	87,1,0,0,0,87,5,1,0,0,0,88,86,1,0,0,0,89,90,7,2,0,0,90,7,1,0,0,0,91,92,
  	7,3,0,0,92,9,1,0,0,0,93,98,3,4,2,0,94,95,5,48,0,0,95,97,3,4,2,0,96,94,
  	1,0,0,0,97,100,1,0,0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,11,1,0,0,0,100,
  	98,1,0,0,0,101,103,5,44,0,0,102,104,3,14,7,0,103,102,1,0,0,0,103,104,
  	1,0,0,0,104,105,1,0,0,0,105,106,5,45,0,0,106,13,1,0,0,0,107,112,3,16,
  	8,0,108,109,5,48,0,0,109,111,3,16,8,0,110,108,1,0,0,0,111,114,1,0,0,0,
  	112,110,1,0,0,0,112,113,1,0,0,0,113,15,1,0,0,0,114,112,1,0,0,0,115,116,
  	7,4,0,0,116,17,1,0,0,0,117,118,7,5,0,0,118,19,1,0,0,0,10,23,42,62,69,
  	73,84,86,98,103,112
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  statcompParserStaticData = std::move(staticData);
}

}

StatCompParser::StatCompParser(TokenStream *input) : StatCompParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

StatCompParser::StatCompParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  StatCompParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *statcompParserStaticData->atn, statcompParserStaticData->decisionToDFA, statcompParserStaticData->sharedContextCache, options);
}

StatCompParser::~StatCompParser() {
  delete _interpreter;
}

const atn::ATN& StatCompParser::getATN() const {
  return *statcompParserStaticData->atn;
}

std::string StatCompParser::getGrammarFileName() const {
  return "StatComp.g4";
}

const std::vector<std::string>& StatCompParser::getRuleNames() const {
  return statcompParserStaticData->ruleNames;
}

const dfa::Vocabulary& StatCompParser::getVocabulary() const {
  return statcompParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView StatCompParser::getSerializedATN() const {
  return statcompParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

StatCompParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StatCompParser::StmtContext *> StatCompParser::ProgContext::stmt() {
  return getRuleContexts<StatCompParser::StmtContext>();
}

StatCompParser::StmtContext* StatCompParser::ProgContext::stmt(size_t i) {
  return getRuleContext<StatCompParser::StmtContext>(i);
}


size_t StatCompParser::ProgContext::getRuleIndex() const {
  return StatCompParser::RuleProg;
}


std::any StatCompParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::ProgContext* StatCompParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, StatCompParser::RuleProg);
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
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 143556722068291580) != 0)) {
      setState(20);
      stmt();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

StatCompParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t StatCompParser::StmtContext::getRuleIndex() const {
  return StatCompParser::RuleStmt;
}

void StatCompParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UpdateSymbolContext ------------------------------------------------------------------

StatCompParser::DecltypeContext* StatCompParser::UpdateSymbolContext::decltype_() {
  return getRuleContext<StatCompParser::DecltypeContext>(0);
}

tree::TerminalNode* StatCompParser::UpdateSymbolContext::ID() {
  return getToken(StatCompParser::ID, 0);
}

tree::TerminalNode* StatCompParser::UpdateSymbolContext::ASSIGN() {
  return getToken(StatCompParser::ASSIGN, 0);
}

StatCompParser::ExprContext* StatCompParser::UpdateSymbolContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

StatCompParser::UpdateSymbolContext::UpdateSymbolContext(StmtContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::UpdateSymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitUpdateSymbol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayDeclContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ArrayDeclContext::ARRAY() {
  return getToken(StatCompParser::ARRAY, 0);
}

StatCompParser::DecltypeContext* StatCompParser::ArrayDeclContext::decltype_() {
  return getRuleContext<StatCompParser::DecltypeContext>(0);
}

tree::TerminalNode* StatCompParser::ArrayDeclContext::ID() {
  return getToken(StatCompParser::ID, 0);
}

tree::TerminalNode* StatCompParser::ArrayDeclContext::ASSIGN() {
  return getToken(StatCompParser::ASSIGN, 0);
}

StatCompParser::ArrayInitContext* StatCompParser::ArrayDeclContext::arrayInit() {
  return getRuleContext<StatCompParser::ArrayInitContext>(0);
}

StatCompParser::ArrayDeclContext::ArrayDeclContext(StmtContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ArrayDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitArrayDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

StatCompParser::ExprContext* StatCompParser::PrintExprContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

StatCompParser::PrintExprContext::PrintExprContext(StmtContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
StatCompParser::StmtContext* StatCompParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 2, StatCompParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(42);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case StatCompParser::T__1:
      case StatCompParser::T__2:
      case StatCompParser::T__3:
      case StatCompParser::T__4:
      case StatCompParser::T__5:
      case StatCompParser::T__6:
      case StatCompParser::T__7:
      case StatCompParser::T__8:
      case StatCompParser::T__9:
      case StatCompParser::T__10:
      case StatCompParser::T__11:
      case StatCompParser::T__12:
      case StatCompParser::T__13:
      case StatCompParser::T__14:
      case StatCompParser::T__15:
      case StatCompParser::T__16:
      case StatCompParser::T__17:
      case StatCompParser::T__18:
      case StatCompParser::T__19:
      case StatCompParser::T__20:
      case StatCompParser::T__21:
      case StatCompParser::T__22:
      case StatCompParser::T__23:
      case StatCompParser::T__24:
      case StatCompParser::T__25:
      case StatCompParser::T__26:
      case StatCompParser::T__27:
      case StatCompParser::T__28:
      case StatCompParser::T__29:
      case StatCompParser::T__30:
      case StatCompParser::T__31:
      case StatCompParser::T__32:
      case StatCompParser::SUB:
      case StatCompParser::LPAR:
      case StatCompParser::ID:
      case StatCompParser::INT:
      case StatCompParser::FLOAT:
      case StatCompParser::STRING: {
        _localctx = _tracker.createInstance<StatCompParser::PrintExprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(26);
        expr(0);
        setState(27);
        match(StatCompParser::T__0);
        break;
      }

      case StatCompParser::TINT:
      case StatCompParser::TFLOAT:
      case StatCompParser::TSTRING: {
        _localctx = _tracker.createInstance<StatCompParser::UpdateSymbolContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(29);
        decltype_();
        setState(30);
        match(StatCompParser::ID);
        setState(31);
        match(StatCompParser::ASSIGN);
        setState(32);
        expr(0);
        setState(33);
        match(StatCompParser::T__0);
        break;
      }

      case StatCompParser::ARRAY: {
        _localctx = _tracker.createInstance<StatCompParser::ArrayDeclContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(35);
        match(StatCompParser::ARRAY);
        setState(36);
        decltype_();
        setState(37);
        match(StatCompParser::ID);
        setState(38);
        match(StatCompParser::ASSIGN);
        setState(39);
        arrayInit();
        setState(40);
        match(StatCompParser::T__0);
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

//----------------- ExprContext ------------------------------------------------------------------

StatCompParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t StatCompParser::ExprContext::getRuleIndex() const {
  return StatCompParser::RuleExpr;
}

void StatCompParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprNegContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ExprNegContext::SUB() {
  return getToken(StatCompParser::SUB, 0);
}

StatCompParser::ExprContext* StatCompParser::ExprNegContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

StatCompParser::ExprNegContext::ExprNegContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprNegContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprNeg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprTableFuncContext ------------------------------------------------------------------

StatCompParser::TableFuncContext* StatCompParser::ExprTableFuncContext::tableFunc() {
  return getRuleContext<StatCompParser::TableFuncContext>(0);
}

tree::TerminalNode* StatCompParser::ExprTableFuncContext::LPAR() {
  return getToken(StatCompParser::LPAR, 0);
}

tree::TerminalNode* StatCompParser::ExprTableFuncContext::RPAR() {
  return getToken(StatCompParser::RPAR, 0);
}

StatCompParser::ArglistContext* StatCompParser::ExprTableFuncContext::arglist() {
  return getRuleContext<StatCompParser::ArglistContext>(0);
}

StatCompParser::ExprTableFuncContext::ExprTableFuncContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprTableFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprTableFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ExprParContext::LPAR() {
  return getToken(StatCompParser::LPAR, 0);
}

StatCompParser::ExprContext* StatCompParser::ExprParContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

tree::TerminalNode* StatCompParser::ExprParContext::RPAR() {
  return getToken(StatCompParser::RPAR, 0);
}

StatCompParser::ExprParContext::ExprParContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprPar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAddSubContext ------------------------------------------------------------------

std::vector<StatCompParser::ExprContext *> StatCompParser::ExprAddSubContext::expr() {
  return getRuleContexts<StatCompParser::ExprContext>();
}

StatCompParser::ExprContext* StatCompParser::ExprAddSubContext::expr(size_t i) {
  return getRuleContext<StatCompParser::ExprContext>(i);
}

tree::TerminalNode* StatCompParser::ExprAddSubContext::ADD() {
  return getToken(StatCompParser::ADD, 0);
}

tree::TerminalNode* StatCompParser::ExprAddSubContext::SUB() {
  return getToken(StatCompParser::SUB, 0);
}

StatCompParser::ExprAddSubContext::ExprAddSubContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprAddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStringContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ExprStringContext::STRING() {
  return getToken(StatCompParser::STRING, 0);
}

StatCompParser::ExprStringContext::ExprStringContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprVarContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ExprVarContext::ID() {
  return getToken(StatCompParser::ID, 0);
}

StatCompParser::ExprVarContext::ExprVarContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprPowContext ------------------------------------------------------------------

std::vector<StatCompParser::ExprContext *> StatCompParser::ExprPowContext::expr() {
  return getRuleContexts<StatCompParser::ExprContext>();
}

StatCompParser::ExprContext* StatCompParser::ExprPowContext::expr(size_t i) {
  return getRuleContext<StatCompParser::ExprContext>(i);
}

tree::TerminalNode* StatCompParser::ExprPowContext::POW() {
  return getToken(StatCompParser::POW, 0);
}

StatCompParser::ExprPowContext::ExprPowContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprPowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprPow(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprLiteralContext ------------------------------------------------------------------

StatCompParser::NumContext* StatCompParser::ExprLiteralContext::num() {
  return getRuleContext<StatCompParser::NumContext>(0);
}

StatCompParser::ExprLiteralContext::ExprLiteralContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprArrayAccessContext ------------------------------------------------------------------

tree::TerminalNode* StatCompParser::ExprArrayAccessContext::ID() {
  return getToken(StatCompParser::ID, 0);
}

tree::TerminalNode* StatCompParser::ExprArrayAccessContext::LBRACK() {
  return getToken(StatCompParser::LBRACK, 0);
}

StatCompParser::ExprContext* StatCompParser::ExprArrayAccessContext::expr() {
  return getRuleContext<StatCompParser::ExprContext>(0);
}

tree::TerminalNode* StatCompParser::ExprArrayAccessContext::RBRACK() {
  return getToken(StatCompParser::RBRACK, 0);
}

StatCompParser::ExprArrayAccessContext::ExprArrayAccessContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprArrayAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprArrayAccess(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMulDivContext ------------------------------------------------------------------

std::vector<StatCompParser::ExprContext *> StatCompParser::ExprMulDivContext::expr() {
  return getRuleContexts<StatCompParser::ExprContext>();
}

StatCompParser::ExprContext* StatCompParser::ExprMulDivContext::expr(size_t i) {
  return getRuleContext<StatCompParser::ExprContext>(i);
}

tree::TerminalNode* StatCompParser::ExprMulDivContext::MUL() {
  return getToken(StatCompParser::MUL, 0);
}

tree::TerminalNode* StatCompParser::ExprMulDivContext::DIV() {
  return getToken(StatCompParser::DIV, 0);
}

tree::TerminalNode* StatCompParser::ExprMulDivContext::INTDIV() {
  return getToken(StatCompParser::INTDIV, 0);
}

tree::TerminalNode* StatCompParser::ExprMulDivContext::MOD() {
  return getToken(StatCompParser::MOD, 0);
}

StatCompParser::ExprMulDivContext::ExprMulDivContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprMulDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprMulDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStatFuncContext ------------------------------------------------------------------

StatCompParser::StatFuncContext* StatCompParser::ExprStatFuncContext::statFunc() {
  return getRuleContext<StatCompParser::StatFuncContext>(0);
}

tree::TerminalNode* StatCompParser::ExprStatFuncContext::LPAR() {
  return getToken(StatCompParser::LPAR, 0);
}

tree::TerminalNode* StatCompParser::ExprStatFuncContext::RPAR() {
  return getToken(StatCompParser::RPAR, 0);
}

StatCompParser::ArglistContext* StatCompParser::ExprStatFuncContext::arglist() {
  return getRuleContext<StatCompParser::ArglistContext>(0);
}

StatCompParser::ExprStatFuncContext::ExprStatFuncContext(ExprContext *ctx) { copyFrom(ctx); }


std::any StatCompParser::ExprStatFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitExprStatFunc(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::ExprContext* StatCompParser::expr() {
   return expr(0);
}

StatCompParser::ExprContext* StatCompParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  StatCompParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  StatCompParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, StatCompParser::RuleExpr, precedence);

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
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprNegContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(45);
      match(StatCompParser::SUB);
      setState(46);
      expr(11);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprParContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(47);
      match(StatCompParser::LPAR);
      setState(48);
      expr(0);
      setState(49);
      match(StatCompParser::RPAR);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(51);
      num();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprStringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(52);
      match(StatCompParser::STRING);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprVarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(53);
      match(StatCompParser::ID);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprArrayAccessContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(54);
      match(StatCompParser::ID);
      setState(55);
      match(StatCompParser::LBRACK);
      setState(56);
      expr(0);
      setState(57);
      match(StatCompParser::RBRACK);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprStatFuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(59);
      statFunc();
      setState(60);
      match(StatCompParser::LPAR);
      setState(62);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 135112472766971900) != 0)) {
        setState(61);
        arglist();
      }
      setState(64);
      match(StatCompParser::RPAR);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ExprTableFuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(66);
      tableFunc();
      setState(67);
      match(StatCompParser::LPAR);
      setState(69);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 135112472766971900) != 0)) {
        setState(68);
        arglist();
      }
      setState(71);
      match(StatCompParser::RPAR);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(86);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(84);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprPowContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(75);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(76);
          match(StatCompParser::POW);
          setState(77);
          expr(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprMulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(78);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(79);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 2061584302080) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(80);
          expr(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(81);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(82);
          _la = _input->LA(1);
          if (!(_la == StatCompParser::ADD

          || _la == StatCompParser::SUB)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(83);
          expr(9);
          break;
        }

        default:
          break;
        } 
      }
      setState(88);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatFuncContext ------------------------------------------------------------------

StatCompParser::StatFuncContext::StatFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t StatCompParser::StatFuncContext::getRuleIndex() const {
  return StatCompParser::RuleStatFunc;
}


std::any StatCompParser::StatFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitStatFunc(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::StatFuncContext* StatCompParser::statFunc() {
  StatFuncContext *_localctx = _tracker.createInstance<StatFuncContext>(_ctx, getState());
  enterRule(_localctx, 6, StatCompParser::RuleStatFunc);
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
    setState(89);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 268435452) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableFuncContext ------------------------------------------------------------------

StatCompParser::TableFuncContext::TableFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t StatCompParser::TableFuncContext::getRuleIndex() const {
  return StatCompParser::RuleTableFunc;
}


std::any StatCompParser::TableFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitTableFunc(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::TableFuncContext* StatCompParser::tableFunc() {
  TableFuncContext *_localctx = _tracker.createInstance<TableFuncContext>(_ctx, getState());
  enterRule(_localctx, 8, StatCompParser::RuleTableFunc);
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
    setState(91);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16911433728) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArglistContext ------------------------------------------------------------------

StatCompParser::ArglistContext::ArglistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StatCompParser::ExprContext *> StatCompParser::ArglistContext::expr() {
  return getRuleContexts<StatCompParser::ExprContext>();
}

StatCompParser::ExprContext* StatCompParser::ArglistContext::expr(size_t i) {
  return getRuleContext<StatCompParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> StatCompParser::ArglistContext::COMMA() {
  return getTokens(StatCompParser::COMMA);
}

tree::TerminalNode* StatCompParser::ArglistContext::COMMA(size_t i) {
  return getToken(StatCompParser::COMMA, i);
}


size_t StatCompParser::ArglistContext::getRuleIndex() const {
  return StatCompParser::RuleArglist;
}


std::any StatCompParser::ArglistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitArglist(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::ArglistContext* StatCompParser::arglist() {
  ArglistContext *_localctx = _tracker.createInstance<ArglistContext>(_ctx, getState());
  enterRule(_localctx, 10, StatCompParser::RuleArglist);
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
    setState(93);
    expr(0);
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StatCompParser::COMMA) {
      setState(94);
      match(StatCompParser::COMMA);
      setState(95);
      expr(0);
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayInitContext ------------------------------------------------------------------

StatCompParser::ArrayInitContext::ArrayInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StatCompParser::ArrayInitContext::LBRACE() {
  return getToken(StatCompParser::LBRACE, 0);
}

tree::TerminalNode* StatCompParser::ArrayInitContext::RBRACE() {
  return getToken(StatCompParser::RBRACE, 0);
}

StatCompParser::NumlistContext* StatCompParser::ArrayInitContext::numlist() {
  return getRuleContext<StatCompParser::NumlistContext>(0);
}


size_t StatCompParser::ArrayInitContext::getRuleIndex() const {
  return StatCompParser::RuleArrayInit;
}


std::any StatCompParser::ArrayInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitArrayInit(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::ArrayInitContext* StatCompParser::arrayInit() {
  ArrayInitContext *_localctx = _tracker.createInstance<ArrayInitContext>(_ctx, getState());
  enterRule(_localctx, 12, StatCompParser::RuleArrayInit);
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
    setState(101);
    match(StatCompParser::LBRACE);
    setState(103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == StatCompParser::INT

    || _la == StatCompParser::FLOAT) {
      setState(102);
      numlist();
    }
    setState(105);
    match(StatCompParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumlistContext ------------------------------------------------------------------

StatCompParser::NumlistContext::NumlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<StatCompParser::NumContext *> StatCompParser::NumlistContext::num() {
  return getRuleContexts<StatCompParser::NumContext>();
}

StatCompParser::NumContext* StatCompParser::NumlistContext::num(size_t i) {
  return getRuleContext<StatCompParser::NumContext>(i);
}

std::vector<tree::TerminalNode *> StatCompParser::NumlistContext::COMMA() {
  return getTokens(StatCompParser::COMMA);
}

tree::TerminalNode* StatCompParser::NumlistContext::COMMA(size_t i) {
  return getToken(StatCompParser::COMMA, i);
}


size_t StatCompParser::NumlistContext::getRuleIndex() const {
  return StatCompParser::RuleNumlist;
}


std::any StatCompParser::NumlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitNumlist(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::NumlistContext* StatCompParser::numlist() {
  NumlistContext *_localctx = _tracker.createInstance<NumlistContext>(_ctx, getState());
  enterRule(_localctx, 14, StatCompParser::RuleNumlist);
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
    setState(107);
    num();
    setState(112);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == StatCompParser::COMMA) {
      setState(108);
      match(StatCompParser::COMMA);
      setState(109);
      num();
      setState(114);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumContext ------------------------------------------------------------------

StatCompParser::NumContext::NumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StatCompParser::NumContext::INT() {
  return getToken(StatCompParser::INT, 0);
}

tree::TerminalNode* StatCompParser::NumContext::FLOAT() {
  return getToken(StatCompParser::FLOAT, 0);
}


size_t StatCompParser::NumContext::getRuleIndex() const {
  return StatCompParser::RuleNum;
}


std::any StatCompParser::NumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitNum(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::NumContext* StatCompParser::num() {
  NumContext *_localctx = _tracker.createInstance<NumContext>(_ctx, getState());
  enterRule(_localctx, 16, StatCompParser::RuleNum);
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
    setState(115);
    _la = _input->LA(1);
    if (!(_la == StatCompParser::INT

    || _la == StatCompParser::FLOAT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecltypeContext ------------------------------------------------------------------

StatCompParser::DecltypeContext::DecltypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StatCompParser::DecltypeContext::TINT() {
  return getToken(StatCompParser::TINT, 0);
}

tree::TerminalNode* StatCompParser::DecltypeContext::TFLOAT() {
  return getToken(StatCompParser::TFLOAT, 0);
}

tree::TerminalNode* StatCompParser::DecltypeContext::TSTRING() {
  return getToken(StatCompParser::TSTRING, 0);
}


size_t StatCompParser::DecltypeContext::getRuleIndex() const {
  return StatCompParser::RuleDecltype;
}


std::any StatCompParser::DecltypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StatCompVisitor*>(visitor))
    return parserVisitor->visitDecltype(this);
  else
    return visitor->visitChildren(this);
}

StatCompParser::DecltypeContext* StatCompParser::decltype_() {
  DecltypeContext *_localctx = _tracker.createInstance<DecltypeContext>(_ctx, getState());
  enterRule(_localctx, 18, StatCompParser::RuleDecltype);
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
    setState(117);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3940649673949184) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool StatCompParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool StatCompParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

void StatCompParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  statcompParserInitialize();
#else
  ::antlr4::internal::call_once(statcompParserOnceFlag, statcompParserInitialize);
#endif
}
