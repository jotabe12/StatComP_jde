// Generated from StatComp.g4 by ANTLR 4.13.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link StatCompParser}.
 */
public interface StatCompListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link StatCompParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(StatCompParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link StatCompParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(StatCompParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by the {@code printExpr}
	 * labeled alternative in {@link StatCompParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterPrintExpr(StatCompParser.PrintExprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code printExpr}
	 * labeled alternative in {@link StatCompParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitPrintExpr(StatCompParser.PrintExprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code updateSymbol}
	 * labeled alternative in {@link StatCompParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterUpdateSymbol(StatCompParser.UpdateSymbolContext ctx);
	/**
	 * Exit a parse tree produced by the {@code updateSymbol}
	 * labeled alternative in {@link StatCompParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitUpdateSymbol(StatCompParser.UpdateSymbolContext ctx);
	/**
	 * Enter a parse tree produced by the {@code arrayDecl}
	 * labeled alternative in {@link StatCompParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterArrayDecl(StatCompParser.ArrayDeclContext ctx);
	/**
	 * Exit a parse tree produced by the {@code arrayDecl}
	 * labeled alternative in {@link StatCompParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitArrayDecl(StatCompParser.ArrayDeclContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprNeg}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprNeg(StatCompParser.ExprNegContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprNeg}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprNeg(StatCompParser.ExprNegContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprPar}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprPar(StatCompParser.ExprParContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprPar}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprPar(StatCompParser.ExprParContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprAddSub}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprAddSub(StatCompParser.ExprAddSubContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprAddSub}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprAddSub(StatCompParser.ExprAddSubContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprVar}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprVar(StatCompParser.ExprVarContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprVar}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprVar(StatCompParser.ExprVarContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprPow}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprPow(StatCompParser.ExprPowContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprPow}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprPow(StatCompParser.ExprPowContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprLiteral}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprLiteral(StatCompParser.ExprLiteralContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprLiteral}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprLiteral(StatCompParser.ExprLiteralContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprArrayAccess}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprArrayAccess(StatCompParser.ExprArrayAccessContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprArrayAccess}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprArrayAccess(StatCompParser.ExprArrayAccessContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprMulDiv}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprMulDiv(StatCompParser.ExprMulDivContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprMulDiv}
	 * labeled alternative in {@link StatCompParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprMulDiv(StatCompParser.ExprMulDivContext ctx);
	/**
	 * Enter a parse tree produced by {@link StatCompParser#arrayInit}.
	 * @param ctx the parse tree
	 */
	void enterArrayInit(StatCompParser.ArrayInitContext ctx);
	/**
	 * Exit a parse tree produced by {@link StatCompParser#arrayInit}.
	 * @param ctx the parse tree
	 */
	void exitArrayInit(StatCompParser.ArrayInitContext ctx);
	/**
	 * Enter a parse tree produced by {@link StatCompParser#num}.
	 * @param ctx the parse tree
	 */
	void enterNum(StatCompParser.NumContext ctx);
	/**
	 * Exit a parse tree produced by {@link StatCompParser#num}.
	 * @param ctx the parse tree
	 */
	void exitNum(StatCompParser.NumContext ctx);
	/**
	 * Enter a parse tree produced by {@link StatCompParser#decltype}.
	 * @param ctx the parse tree
	 */
	void enterDecltype(StatCompParser.DecltypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link StatCompParser#decltype}.
	 * @param ctx the parse tree
	 */
	void exitDecltype(StatCompParser.DecltypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link StatCompParser#pos}.
	 * @param ctx the parse tree
	 */
	void enterPos(StatCompParser.PosContext ctx);
	/**
	 * Exit a parse tree produced by {@link StatCompParser#pos}.
	 * @param ctx the parse tree
	 */
	void exitPos(StatCompParser.PosContext ctx);
}