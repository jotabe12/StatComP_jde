grammar StatComp;
// Parser

prog: stmt* ;
stmt
    : expr ';'                              # printExpr
    | decltype ID '=' expr ';'           # updateSymbol
    | 'array' decltype ID '=' arrayInit ';'  # arrayDecl
    ;

expr
    : '-' expr                            # exprNeg
    | expr '^' expr                       # exprPow
    | expr ('*'|'/'|'//'|'%') expr        # exprMulDiv
    | expr ('+'|'-') expr                 # exprAddSub
    | '(' expr ')'                        # exprPar
    | num                                 # exprLiteral
    | ID                                  # exprVar
    | ID '[' pos ']'                     # exprArrayAccess
    ;

arrayInit
    : '{' (num (',' num)*)? '}'
    ;

num  : INT | FLOAT ;
decltype : TINT | TFLOAT ;
pos : INT ;
// Scanner
POW    : '^' ;
ADD    : '+' ;
SUB    : '-' ;
MUL    : '*' ;
DIV    : '/' ;
INTDIV : '//' ;
MOD    : '%' ;
ASSIGN : '=' ;
LPAR   : '(' ;
RPAR   : ')' ;
COLON  : ':' ;
LBRACE : '{' ;
RBRACE : '}' ;
LBRACK : '[' ;
RBRACK : ']' ;
COMMA  : ',' ;

TINT   : 'int' ;
TFLOAT : 'float' ;
ARRAY  : 'array' ;

ID    : [A-Za-z_][A-Za-z_0-9]* ;
INT   : [0-9]+ ;
FLOAT : [0-9]+'.'[0-9]+ ;

WS  : [ \t\n\r]+ -> skip ;

