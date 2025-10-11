# Generated from StatComp.g4 by ANTLR 4.13.2
# encoding: utf-8
from antlr4 import *
from io import StringIO
import sys
if sys.version_info[1] > 5:
	from typing import TextIO
else:
	from typing.io import TextIO

def serializedATN():
    return [
        4,1,24,88,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
        6,1,0,5,0,16,8,0,10,0,12,0,19,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,37,8,1,1,2,1,2,1,2,1,2,1,2,
        1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,53,8,2,1,2,1,2,1,2,1,2,1,
        2,1,2,1,2,1,2,1,2,5,2,64,8,2,10,2,12,2,67,9,2,1,3,1,3,1,3,1,3,5,
        3,73,8,3,10,3,12,3,76,9,3,3,3,78,8,3,1,3,1,3,1,4,1,4,1,5,1,5,1,6,
        1,6,1,6,0,1,4,7,0,2,4,6,8,10,12,0,4,1,0,5,8,1,0,3,4,1,0,22,23,1,
        0,18,19,92,0,17,1,0,0,0,2,36,1,0,0,0,4,52,1,0,0,0,6,68,1,0,0,0,8,
        81,1,0,0,0,10,83,1,0,0,0,12,85,1,0,0,0,14,16,3,2,1,0,15,14,1,0,0,
        0,16,19,1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,1,1,0,0,0,19,17,1,
        0,0,0,20,21,3,4,2,0,21,22,5,1,0,0,22,37,1,0,0,0,23,24,3,10,5,0,24,
        25,5,21,0,0,25,26,5,9,0,0,26,27,3,4,2,0,27,28,5,1,0,0,28,37,1,0,
        0,0,29,30,5,20,0,0,30,31,3,10,5,0,31,32,5,21,0,0,32,33,5,9,0,0,33,
        34,3,6,3,0,34,35,5,1,0,0,35,37,1,0,0,0,36,20,1,0,0,0,36,23,1,0,0,
        0,36,29,1,0,0,0,37,3,1,0,0,0,38,39,6,2,-1,0,39,40,5,4,0,0,40,53,
        3,4,2,8,41,42,5,10,0,0,42,43,3,4,2,0,43,44,5,11,0,0,44,53,1,0,0,
        0,45,53,3,8,4,0,46,53,5,21,0,0,47,48,5,21,0,0,48,49,5,15,0,0,49,
        50,3,12,6,0,50,51,5,16,0,0,51,53,1,0,0,0,52,38,1,0,0,0,52,41,1,0,
        0,0,52,45,1,0,0,0,52,46,1,0,0,0,52,47,1,0,0,0,53,65,1,0,0,0,54,55,
        10,7,0,0,55,56,5,2,0,0,56,64,3,4,2,8,57,58,10,6,0,0,58,59,7,0,0,
        0,59,64,3,4,2,7,60,61,10,5,0,0,61,62,7,1,0,0,62,64,3,4,2,6,63,54,
        1,0,0,0,63,57,1,0,0,0,63,60,1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,
        65,66,1,0,0,0,66,5,1,0,0,0,67,65,1,0,0,0,68,77,5,13,0,0,69,74,3,
        8,4,0,70,71,5,17,0,0,71,73,3,8,4,0,72,70,1,0,0,0,73,76,1,0,0,0,74,
        72,1,0,0,0,74,75,1,0,0,0,75,78,1,0,0,0,76,74,1,0,0,0,77,69,1,0,0,
        0,77,78,1,0,0,0,78,79,1,0,0,0,79,80,5,14,0,0,80,7,1,0,0,0,81,82,
        7,2,0,0,82,9,1,0,0,0,83,84,7,3,0,0,84,11,1,0,0,0,85,86,5,22,0,0,
        86,13,1,0,0,0,7,17,36,52,63,65,74,77
    ]

class StatCompParser ( Parser ):

    grammarFileName = "StatComp.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "';'", "'^'", "'+'", "'-'", "'*'", "'/'", 
                     "'//'", "'%'", "'='", "'('", "')'", "':'", "'{'", "'}'", 
                     "'['", "']'", "','", "'int'", "'float'", "'array'" ]

    symbolicNames = [ "<INVALID>", "<INVALID>", "POW", "ADD", "SUB", "MUL", 
                      "DIV", "INTDIV", "MOD", "ASSIGN", "LPAR", "RPAR", 
                      "COLON", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "COMMA", 
                      "TINT", "TFLOAT", "ARRAY", "ID", "INT", "FLOAT", "WS" ]

    RULE_prog = 0
    RULE_stmt = 1
    RULE_expr = 2
    RULE_arrayInit = 3
    RULE_num = 4
    RULE_decltype = 5
    RULE_pos = 6

    ruleNames =  [ "prog", "stmt", "expr", "arrayInit", "num", "decltype", 
                   "pos" ]

    EOF = Token.EOF
    T__0=1
    POW=2
    ADD=3
    SUB=4
    MUL=5
    DIV=6
    INTDIV=7
    MOD=8
    ASSIGN=9
    LPAR=10
    RPAR=11
    COLON=12
    LBRACE=13
    RBRACE=14
    LBRACK=15
    RBRACK=16
    COMMA=17
    TINT=18
    TFLOAT=19
    ARRAY=20
    ID=21
    INT=22
    FLOAT=23
    WS=24

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.13.2")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None




    class ProgContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def stmt(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(StatCompParser.StmtContext)
            else:
                return self.getTypedRuleContext(StatCompParser.StmtContext,i)


        def getRuleIndex(self):
            return StatCompParser.RULE_prog

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterProg" ):
                listener.enterProg(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitProg" ):
                listener.exitProg(self)




    def prog(self):

        localctx = StatCompParser.ProgContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_prog)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 17
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while (((_la) & ~0x3f) == 0 and ((1 << _la) & 16516112) != 0):
                self.state = 14
                self.stmt()
                self.state = 19
                self._errHandler.sync(self)
                _la = self._input.LA(1)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class StmtContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return StatCompParser.RULE_stmt

     
        def copyFrom(self, ctx:ParserRuleContext):
            super().copyFrom(ctx)



    class UpdateSymbolContext(StmtContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.StmtContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def decltype(self):
            return self.getTypedRuleContext(StatCompParser.DecltypeContext,0)

        def ID(self):
            return self.getToken(StatCompParser.ID, 0)
        def ASSIGN(self):
            return self.getToken(StatCompParser.ASSIGN, 0)
        def expr(self):
            return self.getTypedRuleContext(StatCompParser.ExprContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterUpdateSymbol" ):
                listener.enterUpdateSymbol(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitUpdateSymbol" ):
                listener.exitUpdateSymbol(self)


    class ArrayDeclContext(StmtContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.StmtContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def ARRAY(self):
            return self.getToken(StatCompParser.ARRAY, 0)
        def decltype(self):
            return self.getTypedRuleContext(StatCompParser.DecltypeContext,0)

        def ID(self):
            return self.getToken(StatCompParser.ID, 0)
        def ASSIGN(self):
            return self.getToken(StatCompParser.ASSIGN, 0)
        def arrayInit(self):
            return self.getTypedRuleContext(StatCompParser.ArrayInitContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterArrayDecl" ):
                listener.enterArrayDecl(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitArrayDecl" ):
                listener.exitArrayDecl(self)


    class PrintExprContext(StmtContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.StmtContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self):
            return self.getTypedRuleContext(StatCompParser.ExprContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterPrintExpr" ):
                listener.enterPrintExpr(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitPrintExpr" ):
                listener.exitPrintExpr(self)



    def stmt(self):

        localctx = StatCompParser.StmtContext(self, self._ctx, self.state)
        self.enterRule(localctx, 2, self.RULE_stmt)
        try:
            self.state = 36
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [4, 10, 21, 22, 23]:
                localctx = StatCompParser.PrintExprContext(self, localctx)
                self.enterOuterAlt(localctx, 1)
                self.state = 20
                self.expr(0)
                self.state = 21
                self.match(StatCompParser.T__0)
                pass
            elif token in [18, 19]:
                localctx = StatCompParser.UpdateSymbolContext(self, localctx)
                self.enterOuterAlt(localctx, 2)
                self.state = 23
                self.decltype()
                self.state = 24
                self.match(StatCompParser.ID)
                self.state = 25
                self.match(StatCompParser.ASSIGN)
                self.state = 26
                self.expr(0)
                self.state = 27
                self.match(StatCompParser.T__0)
                pass
            elif token in [20]:
                localctx = StatCompParser.ArrayDeclContext(self, localctx)
                self.enterOuterAlt(localctx, 3)
                self.state = 29
                self.match(StatCompParser.ARRAY)
                self.state = 30
                self.decltype()
                self.state = 31
                self.match(StatCompParser.ID)
                self.state = 32
                self.match(StatCompParser.ASSIGN)
                self.state = 33
                self.arrayInit()
                self.state = 34
                self.match(StatCompParser.T__0)
                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class ExprContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return StatCompParser.RULE_expr

     
        def copyFrom(self, ctx:ParserRuleContext):
            super().copyFrom(ctx)


    class ExprNegContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def SUB(self):
            return self.getToken(StatCompParser.SUB, 0)
        def expr(self):
            return self.getTypedRuleContext(StatCompParser.ExprContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExprNeg" ):
                listener.enterExprNeg(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExprNeg" ):
                listener.exitExprNeg(self)


    class ExprParContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def LPAR(self):
            return self.getToken(StatCompParser.LPAR, 0)
        def expr(self):
            return self.getTypedRuleContext(StatCompParser.ExprContext,0)

        def RPAR(self):
            return self.getToken(StatCompParser.RPAR, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExprPar" ):
                listener.enterExprPar(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExprPar" ):
                listener.exitExprPar(self)


    class ExprAddSubContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(StatCompParser.ExprContext)
            else:
                return self.getTypedRuleContext(StatCompParser.ExprContext,i)

        def ADD(self):
            return self.getToken(StatCompParser.ADD, 0)
        def SUB(self):
            return self.getToken(StatCompParser.SUB, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExprAddSub" ):
                listener.enterExprAddSub(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExprAddSub" ):
                listener.exitExprAddSub(self)


    class ExprVarContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def ID(self):
            return self.getToken(StatCompParser.ID, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExprVar" ):
                listener.enterExprVar(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExprVar" ):
                listener.exitExprVar(self)


    class ExprPowContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(StatCompParser.ExprContext)
            else:
                return self.getTypedRuleContext(StatCompParser.ExprContext,i)

        def POW(self):
            return self.getToken(StatCompParser.POW, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExprPow" ):
                listener.enterExprPow(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExprPow" ):
                listener.exitExprPow(self)


    class ExprLiteralContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def num(self):
            return self.getTypedRuleContext(StatCompParser.NumContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExprLiteral" ):
                listener.enterExprLiteral(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExprLiteral" ):
                listener.exitExprLiteral(self)


    class ExprArrayAccessContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def ID(self):
            return self.getToken(StatCompParser.ID, 0)
        def LBRACK(self):
            return self.getToken(StatCompParser.LBRACK, 0)
        def pos(self):
            return self.getTypedRuleContext(StatCompParser.PosContext,0)

        def RBRACK(self):
            return self.getToken(StatCompParser.RBRACK, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExprArrayAccess" ):
                listener.enterExprArrayAccess(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExprArrayAccess" ):
                listener.exitExprArrayAccess(self)


    class ExprMulDivContext(ExprContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a StatCompParser.ExprContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def expr(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(StatCompParser.ExprContext)
            else:
                return self.getTypedRuleContext(StatCompParser.ExprContext,i)

        def MUL(self):
            return self.getToken(StatCompParser.MUL, 0)
        def DIV(self):
            return self.getToken(StatCompParser.DIV, 0)
        def INTDIV(self):
            return self.getToken(StatCompParser.INTDIV, 0)
        def MOD(self):
            return self.getToken(StatCompParser.MOD, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterExprMulDiv" ):
                listener.enterExprMulDiv(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitExprMulDiv" ):
                listener.exitExprMulDiv(self)



    def expr(self, _p:int=0):
        _parentctx = self._ctx
        _parentState = self.state
        localctx = StatCompParser.ExprContext(self, self._ctx, _parentState)
        _prevctx = localctx
        _startState = 4
        self.enterRecursionRule(localctx, 4, self.RULE_expr, _p)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 52
            self._errHandler.sync(self)
            la_ = self._interp.adaptivePredict(self._input,2,self._ctx)
            if la_ == 1:
                localctx = StatCompParser.ExprNegContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx

                self.state = 39
                self.match(StatCompParser.SUB)
                self.state = 40
                self.expr(8)
                pass

            elif la_ == 2:
                localctx = StatCompParser.ExprParContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx
                self.state = 41
                self.match(StatCompParser.LPAR)
                self.state = 42
                self.expr(0)
                self.state = 43
                self.match(StatCompParser.RPAR)
                pass

            elif la_ == 3:
                localctx = StatCompParser.ExprLiteralContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx
                self.state = 45
                self.num()
                pass

            elif la_ == 4:
                localctx = StatCompParser.ExprVarContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx
                self.state = 46
                self.match(StatCompParser.ID)
                pass

            elif la_ == 5:
                localctx = StatCompParser.ExprArrayAccessContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx
                self.state = 47
                self.match(StatCompParser.ID)
                self.state = 48
                self.match(StatCompParser.LBRACK)
                self.state = 49
                self.pos()
                self.state = 50
                self.match(StatCompParser.RBRACK)
                pass


            self._ctx.stop = self._input.LT(-1)
            self.state = 65
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,4,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    if self._parseListeners is not None:
                        self.triggerExitRuleEvent()
                    _prevctx = localctx
                    self.state = 63
                    self._errHandler.sync(self)
                    la_ = self._interp.adaptivePredict(self._input,3,self._ctx)
                    if la_ == 1:
                        localctx = StatCompParser.ExprPowContext(self, StatCompParser.ExprContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 54
                        if not self.precpred(self._ctx, 7):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 7)")
                        self.state = 55
                        self.match(StatCompParser.POW)
                        self.state = 56
                        self.expr(8)
                        pass

                    elif la_ == 2:
                        localctx = StatCompParser.ExprMulDivContext(self, StatCompParser.ExprContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 57
                        if not self.precpred(self._ctx, 6):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 6)")
                        self.state = 58
                        _la = self._input.LA(1)
                        if not((((_la) & ~0x3f) == 0 and ((1 << _la) & 480) != 0)):
                            self._errHandler.recoverInline(self)
                        else:
                            self._errHandler.reportMatch(self)
                            self.consume()
                        self.state = 59
                        self.expr(7)
                        pass

                    elif la_ == 3:
                        localctx = StatCompParser.ExprAddSubContext(self, StatCompParser.ExprContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_expr)
                        self.state = 60
                        if not self.precpred(self._ctx, 5):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 5)")
                        self.state = 61
                        _la = self._input.LA(1)
                        if not(_la==3 or _la==4):
                            self._errHandler.recoverInline(self)
                        else:
                            self._errHandler.reportMatch(self)
                            self.consume()
                        self.state = 62
                        self.expr(6)
                        pass

             
                self.state = 67
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,4,self._ctx)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.unrollRecursionContexts(_parentctx)
        return localctx


    class ArrayInitContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def LBRACE(self):
            return self.getToken(StatCompParser.LBRACE, 0)

        def RBRACE(self):
            return self.getToken(StatCompParser.RBRACE, 0)

        def num(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(StatCompParser.NumContext)
            else:
                return self.getTypedRuleContext(StatCompParser.NumContext,i)


        def COMMA(self, i:int=None):
            if i is None:
                return self.getTokens(StatCompParser.COMMA)
            else:
                return self.getToken(StatCompParser.COMMA, i)

        def getRuleIndex(self):
            return StatCompParser.RULE_arrayInit

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterArrayInit" ):
                listener.enterArrayInit(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitArrayInit" ):
                listener.exitArrayInit(self)




    def arrayInit(self):

        localctx = StatCompParser.ArrayInitContext(self, self._ctx, self.state)
        self.enterRule(localctx, 6, self.RULE_arrayInit)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 68
            self.match(StatCompParser.LBRACE)
            self.state = 77
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            if _la==22 or _la==23:
                self.state = 69
                self.num()
                self.state = 74
                self._errHandler.sync(self)
                _la = self._input.LA(1)
                while _la==17:
                    self.state = 70
                    self.match(StatCompParser.COMMA)
                    self.state = 71
                    self.num()
                    self.state = 76
                    self._errHandler.sync(self)
                    _la = self._input.LA(1)



            self.state = 79
            self.match(StatCompParser.RBRACE)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class NumContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def INT(self):
            return self.getToken(StatCompParser.INT, 0)

        def FLOAT(self):
            return self.getToken(StatCompParser.FLOAT, 0)

        def getRuleIndex(self):
            return StatCompParser.RULE_num

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterNum" ):
                listener.enterNum(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitNum" ):
                listener.exitNum(self)




    def num(self):

        localctx = StatCompParser.NumContext(self, self._ctx, self.state)
        self.enterRule(localctx, 8, self.RULE_num)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 81
            _la = self._input.LA(1)
            if not(_la==22 or _la==23):
                self._errHandler.recoverInline(self)
            else:
                self._errHandler.reportMatch(self)
                self.consume()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class DecltypeContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def TINT(self):
            return self.getToken(StatCompParser.TINT, 0)

        def TFLOAT(self):
            return self.getToken(StatCompParser.TFLOAT, 0)

        def getRuleIndex(self):
            return StatCompParser.RULE_decltype

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterDecltype" ):
                listener.enterDecltype(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitDecltype" ):
                listener.exitDecltype(self)




    def decltype(self):

        localctx = StatCompParser.DecltypeContext(self, self._ctx, self.state)
        self.enterRule(localctx, 10, self.RULE_decltype)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 83
            _la = self._input.LA(1)
            if not(_la==18 or _la==19):
                self._errHandler.recoverInline(self)
            else:
                self._errHandler.reportMatch(self)
                self.consume()
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class PosContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def INT(self):
            return self.getToken(StatCompParser.INT, 0)

        def getRuleIndex(self):
            return StatCompParser.RULE_pos

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterPos" ):
                listener.enterPos(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitPos" ):
                listener.exitPos(self)




    def pos(self):

        localctx = StatCompParser.PosContext(self, self._ctx, self.state)
        self.enterRule(localctx, 12, self.RULE_pos)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 85
            self.match(StatCompParser.INT)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx



    def sempred(self, localctx:RuleContext, ruleIndex:int, predIndex:int):
        if self._predicates == None:
            self._predicates = dict()
        self._predicates[2] = self.expr_sempred
        pred = self._predicates.get(ruleIndex, None)
        if pred is None:
            raise Exception("No predicate with index:" + str(ruleIndex))
        else:
            return pred(localctx, predIndex)

    def expr_sempred(self, localctx:ExprContext, predIndex:int):
            if predIndex == 0:
                return self.precpred(self._ctx, 7)
         

            if predIndex == 1:
                return self.precpred(self._ctx, 6)
         

            if predIndex == 2:
                return self.precpred(self._ctx, 5)
         




