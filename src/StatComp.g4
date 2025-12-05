grammar StatComp;

prog: stmt* ;

stmt
    : expr ';'                                  # printExpr
    | decltype ID '=' expr ';'                  # updateSymbol
    | 'array' decltype ID '=' arrayInit ';'     # arrayDecl
    ;

expr
    : '-' expr                                  # exprNeg
    | expr '^' expr                             # exprPow
    | expr ('*'|'/'|'//'|'%') expr              # exprMulDiv
    | expr ('+'|'-') expr                       # exprAddSub
    | '(' expr ')'                              # exprPar
    | num                                       # exprLiteral
    | STRING                                    # exprString
    | ID                                        # exprVar
    | ID '[' expr ']'                           # exprArrayAccess
    | statFunc LPAR arglist? RPAR               # exprStatFunc
    | tableFunc LPAR arglist? RPAR              # exprTableFunc
    ;

statFunc
    : 'Mean'
    | 'Median'
    | 'Mode'
    | 'Stdev'
    | 'Var'
    | 'Square_root'
    | 'Range'
    | 'CoeffVar'
    | 'Quartile'
    | 'IQR'
    | 'Percentile'
    | 'Min'
    | 'Max'
    | 'Sum'
    | 'Count'
    | 'Skewness'
    | 'Kurtosis'
    | 'Moment'
    | 'Standardize'
    | 'ZProb'
    | 'InvZ'
    | 'NormalPDF'
    | 'NormalCDF'
    | 'UniformPDF'
    | 'UniformCDF'
    | 'Print'
    ;

tableFunc
    : 'Freq'
    | 'AbsFreq'
    | 'RelFreq'
    | 'AbsFreqCum'
    | 'RelFreqCum'
    | 'CrossTab'
    ;

arglist
    : expr (COMMA expr)*
    ;

arrayInit
    : LBRACE numlist? RBRACE
    ;

numlist
    : num (COMMA num)*
    ;

num      : INT | FLOAT ;
decltype : TINT | TFLOAT | TSTRING ;

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
LBRACE : '{' ;
RBRACE : '}' ;
LBRACK : '[' ;
RBRACK : ']' ;
COMMA  : ',' ;

TINT    : 'int' ;
TFLOAT  : 'float' ;
TSTRING : 'string' ;
ARRAY   : 'array' ;

ID     : [A-Za-z_][A-Za-z_0-9]* ;
INT    : [0-9]+ ;
FLOAT  : [0-9]+ '.' [0-9]+ ;
STRING : '"' (~["\\] | '\\' .)* '"' ;

WS     : [ \t\n\r]+ -> skip ;

