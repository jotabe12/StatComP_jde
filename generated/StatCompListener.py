# Generated from StatComp.g4 by ANTLR 4.13.2
from antlr4 import *
if "." in __name__:
    from .StatCompParser import StatCompParser
else:
    from StatCompParser import StatCompParser

# This class defines a complete listener for a parse tree produced by StatCompParser.
class StatCompListener(ParseTreeListener):

    # Enter a parse tree produced by StatCompParser#prog.
    def enterProg(self, ctx:StatCompParser.ProgContext):
        pass

    # Exit a parse tree produced by StatCompParser#prog.
    def exitProg(self, ctx:StatCompParser.ProgContext):
        pass


    # Enter a parse tree produced by StatCompParser#printExpr.
    def enterPrintExpr(self, ctx:StatCompParser.PrintExprContext):
        pass

    # Exit a parse tree produced by StatCompParser#printExpr.
    def exitPrintExpr(self, ctx:StatCompParser.PrintExprContext):
        pass


    # Enter a parse tree produced by StatCompParser#updateSymbol.
    def enterUpdateSymbol(self, ctx:StatCompParser.UpdateSymbolContext):
        pass

    # Exit a parse tree produced by StatCompParser#updateSymbol.
    def exitUpdateSymbol(self, ctx:StatCompParser.UpdateSymbolContext):
        pass


    # Enter a parse tree produced by StatCompParser#arrayDecl.
    def enterArrayDecl(self, ctx:StatCompParser.ArrayDeclContext):
        pass

    # Exit a parse tree produced by StatCompParser#arrayDecl.
    def exitArrayDecl(self, ctx:StatCompParser.ArrayDeclContext):
        pass


    # Enter a parse tree produced by StatCompParser#exprNeg.
    def enterExprNeg(self, ctx:StatCompParser.ExprNegContext):
        pass

    # Exit a parse tree produced by StatCompParser#exprNeg.
    def exitExprNeg(self, ctx:StatCompParser.ExprNegContext):
        pass


    # Enter a parse tree produced by StatCompParser#exprPar.
    def enterExprPar(self, ctx:StatCompParser.ExprParContext):
        pass

    # Exit a parse tree produced by StatCompParser#exprPar.
    def exitExprPar(self, ctx:StatCompParser.ExprParContext):
        pass


    # Enter a parse tree produced by StatCompParser#exprAddSub.
    def enterExprAddSub(self, ctx:StatCompParser.ExprAddSubContext):
        pass

    # Exit a parse tree produced by StatCompParser#exprAddSub.
    def exitExprAddSub(self, ctx:StatCompParser.ExprAddSubContext):
        pass


    # Enter a parse tree produced by StatCompParser#exprVar.
    def enterExprVar(self, ctx:StatCompParser.ExprVarContext):
        pass

    # Exit a parse tree produced by StatCompParser#exprVar.
    def exitExprVar(self, ctx:StatCompParser.ExprVarContext):
        pass


    # Enter a parse tree produced by StatCompParser#exprPow.
    def enterExprPow(self, ctx:StatCompParser.ExprPowContext):
        pass

    # Exit a parse tree produced by StatCompParser#exprPow.
    def exitExprPow(self, ctx:StatCompParser.ExprPowContext):
        pass


    # Enter a parse tree produced by StatCompParser#exprLiteral.
    def enterExprLiteral(self, ctx:StatCompParser.ExprLiteralContext):
        pass

    # Exit a parse tree produced by StatCompParser#exprLiteral.
    def exitExprLiteral(self, ctx:StatCompParser.ExprLiteralContext):
        pass


    # Enter a parse tree produced by StatCompParser#exprArrayAccess.
    def enterExprArrayAccess(self, ctx:StatCompParser.ExprArrayAccessContext):
        pass

    # Exit a parse tree produced by StatCompParser#exprArrayAccess.
    def exitExprArrayAccess(self, ctx:StatCompParser.ExprArrayAccessContext):
        pass


    # Enter a parse tree produced by StatCompParser#exprMulDiv.
    def enterExprMulDiv(self, ctx:StatCompParser.ExprMulDivContext):
        pass

    # Exit a parse tree produced by StatCompParser#exprMulDiv.
    def exitExprMulDiv(self, ctx:StatCompParser.ExprMulDivContext):
        pass


    # Enter a parse tree produced by StatCompParser#arrayInit.
    def enterArrayInit(self, ctx:StatCompParser.ArrayInitContext):
        pass

    # Exit a parse tree produced by StatCompParser#arrayInit.
    def exitArrayInit(self, ctx:StatCompParser.ArrayInitContext):
        pass


    # Enter a parse tree produced by StatCompParser#num.
    def enterNum(self, ctx:StatCompParser.NumContext):
        pass

    # Exit a parse tree produced by StatCompParser#num.
    def exitNum(self, ctx:StatCompParser.NumContext):
        pass


    # Enter a parse tree produced by StatCompParser#decltype.
    def enterDecltype(self, ctx:StatCompParser.DecltypeContext):
        pass

    # Exit a parse tree produced by StatCompParser#decltype.
    def exitDecltype(self, ctx:StatCompParser.DecltypeContext):
        pass


    # Enter a parse tree produced by StatCompParser#pos.
    def enterPos(self, ctx:StatCompParser.PosContext):
        pass

    # Exit a parse tree produced by StatCompParser#pos.
    def exitPos(self, ctx:StatCompParser.PosContext):
        pass



del StatCompParser