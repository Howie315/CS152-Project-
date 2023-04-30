%{
#include <stdio.h>
int yylex();
int yyerror(char *s);
%}

%token INTEGER DOUBLE BOOLEAN CHAR
%token ASSIGN ADD SUB DIV MUL MOD EQ LT LTE GT GTE NE
%token FUNCTION BEGINSCOPE ENDSCOPE BEGINPARAM ENDPARAM BEGINBRACKET ENDBRACKET IF ELSE FOR WHILE CONTINUE BREAK TRUE FALSE RETURN VOID NOT AND OR SEMICOLON COMMA
%token OUTPUT INPUT
%token IDENTIFIER NUMBER DECIMAL


%start prog_start



%error-verbose


%%
prog_start:
      functions { printf("prog_start -> functions\n"); }
|     %empty    { printf("prog_start -> epsilon\n"); }
;

functions: 
      function            { printf("functions -> function\n"); }
|     function functions  { printf("functions -> function functions\n"); }
;

function:
      type FUNCTION IDENTIFIER BEGINPARAM arguements ENDPARAM BEGINSCOPE statements ENDSCOPE      { printf("function -> type FUNC IDENTIFIER BEGINPARAM arguements ENDPARAM BEGINBRACKET statements ENDBRACKET\n"); }
|     type FUNCTION IDENTIFIER BEGINPARAM arguements ENDPARAM SEMICOLON                           { printf("function -> type FUNC IDENTIFIER BEGINPARAM arguements ENDPARAM SEMICOLON\n"); } 
;

io:
      INPUT BEGINPARAM ref ENDPARAM{ printf("io -> INPUT BEGINPARAM ref ENDPARAM\n"); }
|     OUTPUT BEGINPARAM ref ENDPARAM{ printf("io -> INPUT BEGINPARAM ref ENDPARAM\n"); }
;

ref:
      IDENTIFIER        { printf("ref -> IDENTIFIER"); }
|     IDENTIFIER BEGINBRACKET NUMBER ENDBRACKET { printf("ref -> IDENTIFIER BEGINBRACKET NUMBER ENDBRACKET\n"); }
;

arguements:
      arguement repeat_arguements { printf("arguements -> arguement repeat_arguements\n"); }
|     %empty                      { printf("arguements -> epsilon\n"); }
;

repeat_arguements:
      COMMA arguement repeat_arguements { printf("repeat_arguements -> COMMA arguement repeat_arguements\n"); }
|     %empty                            { printf("repeat_arguements -> epsilon\n"); }
;

arguement: 
      type IDENTIFIER { printf("arguement -> type IDENTIFIER\n"); }
|     type array { printf("arguement -> array\n");}
;

type:
      VOID      { printf("type -> VOID\n\n"); }
|     INTEGER   { printf("type -> INTEGER\n\n"); }
|     BOOLEAN   { printf("type -> BOOLEAN\n\n"); }
|     DOUBLE    { printf("type -> DOUBLE\n\n"); }
|     CHAR      { printf("type -> CHAR\n\n"); }
;

statements:
      statement SEMICOLON statements  { printf("statements -> statement SEMICOLON statements\n"); }
|     %empty                          { printf("statements -> epsilon\n"); }
;

statement: 
      returnstmt    { printf("statement -> returnstmt\n"); }
|     ifstmt        { printf("statement -> ifstmt\n"); }
|     assignment    { printf("statement -> assignment\n"); }
|     functioncall  { printf("statement -> functioncall\n"); }
|     declaration   { printf("statement -> declaration\n"); }
|     whilestmt     { printf("statement -> whilestmt\n"); }
|     io            { printf("statement -> io\n"); }
|     continuestmt        { printf("statement -> continuestmt\n"); }
|     breakstmt           { printf("statement -> breakstmt\n"); }
;

whilestmt:
     WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE { printf("whilestmt -> WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE\n"); }
|    WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements continuestmt ENDSCOPE { printf("whilestmt -> WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements continuestmt ENDSCOPE\n"); }
|    WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements breakstmt ENDSCOPE  { printf("whilestmt -> WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements breakstmt ENDSCOPE\n"); }
|    WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE whilestmts ENDSCOPE { printf("whilestmt -> WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE whilestmts ENDSCOPE\n"); }
;

whilestmts:
      whilestmt
|     whilestmts whilestmt
;


continuestmt:
   CONTINUE { printf("continuestmt -> CONTINUE\n"); }
;

breakstmt:
   BREAK { printf("breakstmt -> BREAK\n"); }
;

returnstmt: 
      RETURN expression { printf("returnstmt -> expression\n"); }
;



ifstmt:
      IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE\n"); }
|     IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE ELSE BEGINSCOPE statements ENDSCOPE { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE ELSE BEGINSCOPE statements ENDSCOPE\n"); }
|     IF BEGINPARAM expression ENDPARAM BEGINSCOPE ifstmts ENDSCOPE { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE ifstmt ENDSCOPE\n"); }
|     IF BEGINPARAM expression ENDPARAM BEGINSCOPE ifstmts ENDSCOPE ELSE BEGINSCOPE ifstmt ENDSCOPE { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE ifstmt ENDSCOPE ELSE BEGINSCOPE ifstmt ENDSCOPE\n"); }
;

ifstmts:
      ifstmt
|     ifstmts ifstmt
;


assignment: 
      IDENTIFIER ASSIGN expression    { printf("assignment -> IDENTIFIER ASSIGN expression\n"); }
|     array ASSIGN expression         { printf("assignment -> array ASSIGN expression\n"); }
|     IDENTIFIER ASSIGN functioncall  { printf("assignment -> IDENTIFIER ASSIGN functioncall\n"); }
;

functioncall:
      IDENTIFIER BEGINPARAM passingargs ENDPARAM { printf("functioncall -> IDENTIFIER BEGINBRACKET passingargs ENDPARAM\n"); }
;

passingargs:
      expression repeat_passingargs   { printf("passingargs -> IDENTIFIER repeat_passingargs\n"); }
|     %empty                          {printf("passingargs -> epsilon\n\n"); }

repeat_passingargs:
      COMMA expression repeat_arguements    { printf("repeat_passingargs -> COMMA IDENTIFIER repeat_passingargs\n"); }
|     %empty                                { printf("repeat_passingargs -> epsilon\n"); }

declaration:
      type IDENTIFIER { printf("declaration -> type IDENTIFIER\n"); }
|     type assignment  { printf("declaration -> type assignment\n"); }
|     type array      { printf("declaration -> type array\n"); }
;


array:
      IDENTIFIER BEGINBRACKET NUMBER ENDBRACKET { printf("array -> IDENTIFIER BEGINBRACKET NUMBER ENDBRACKET\n"); }

expression:
      assignexp { printf("expression -> assignexp\n"); }
;

assignexp:
      logicexp logicop assignexp  { printf("assignexp -> logicexp logicop assignexp\n"); }
|     logicexp                    { printf("assignexp -> logicexp\n"); }
;

logicop:
      AND { printf("logicop -> AND\n\n"); }
|     OR  { printf("logicop -> OR\n\n"); }
;

logicexp:
      equalityexp eqop logicexp   { printf("logicexp -> equalityexp eqop logicexp\n"); }
|     equalityexp                 { printf("logicexp -> equalityexp\n"); }
;

eqop:
      EQ  { printf("eqop -> EQ\n\n"); }
|     NE  { printf("eqop -> NE\n\n"); }
;

equalityexp:
      relationexp relop equalityexp { printf("equalityexp -> relationexp relop equalityexp\n"); }
|     relationexp                   { printf("equalityexp -> relationexp\n"); }
;

relop:
      LT {printf("relop -> LT\n\n");}
|     LTE {printf("relop -> LTE\n\n");}
|     GT {printf("relop -> GT\n\n");}
|     GTE{printf("relop -> GTE\n\n");}
;

relationexp:
      addexp addop relationexp {printf("relationexp -> addexp addop relationexp\n");}
|     addexp {printf("relationexp -> addexp\n");}
;

addop:
      ADD {printf("addop -> ADD\n\n");}
|     SUB {printf("addop -> SUB\n\n");}
;

addexp:
      multexp multop addexp {printf("addexp -> multexp multop addexp\n");}
|     multexp {printf("addexp -> multexp\n");}
;

multop:
      MUL   {printf("multop -> MUL\n\n");}
|     DIV   {printf("multop -> DIV\n\n");}
|     MOD   {printf("multop -> MOD\n\n");}
;
multexp: 
      NOT term {printf("multexp -> NOT term\n");}
|     term  {printf("multexp -> term\n");}
;

term:
      BEGINPARAM expression ENDPARAM {printf("term -> BEGINPARAM expression ENDPARAM\n\n");}
|     NUMBER      {printf("term -> NUMBER\n\n");}
|     ref  {printf("term -> ref\n");}
; 
%%

int main()
{
  yyparse();
  return 0;
}

yyerror(char* s)
{
  printf("ERROR: %s\n", s);
  return 0;
}