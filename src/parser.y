%{
#include <stdio.h>
int yylex();
int yyerror(const char *s);
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

arguements:
      arguement repeat_arguements         { printf("arguements -> arguement repeat_arguements\n"); }
|     %empty                              { printf("arguements -> epsilon\n"); }
;

repeat_arguements:
      COMMA arguement repeat_arguements   { printf("repeat_arguements -> COMMA arguement repeat_arguements\n"); }
|     %empty                              { printf("repeat_arguements -> epsilon\n"); }
;

arguement: 
      type IDENTIFIER                     { printf("arguement -> type IDENTIFIER\n"); }
|     type array                          { printf("arguement -> array\n");}
;

type:
      VOID      { printf("type -> VOID\n"); }
|     INTEGER   { printf("type -> INTEGER\n"); }
|     BOOLEAN   { printf("type -> BOOLEAN\n"); }
|     DOUBLE    { printf("type -> DOUBLE\n"); }
|     CHAR      { printf("type -> CHAR\n"); }
;

statements:
      statement SEMICOLON statements  { printf("statements -> statement SEMICOLON statements\n"); }
|      controlstmt statements          { printf("statements -> controlstmt statements\n"); }
|     %empty                          { printf("statements -> epsilon\n"); }
;

controlstmt:
      whilestmt     { printf("controlstmt -> whilestmt\n"); }
|     ifstmt        { printf("controlstmt -> ifstmt\n"); }
;

statement: 
      returnstmt    { printf("statement -> returnstmt\n"); }
|     assignment    { printf("statement -> assignment\n"); }
|     functioncall  { printf("statement -> functioncall\n"); }
|     declaration   { printf("statement -> declaration\n"); }
|     io            { printf("statement -> io\n"); }
|     continuestmt  { printf("statement -> continuestmt\n"); }
|     breakstmt     { printf("statement -> breakstmt\n"); }
|     expression    { printf("statement -> expression\n"); }
;

whilestmt:
     WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE      { printf("whilestmt -> WHILE BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE\n"); }
;

continuestmt:
   CONTINUE                         { printf("continuestmt -> CONTINUE\n"); }
;

breakstmt:
   BREAK                            { printf("breakstmt -> BREAK\n"); }
;

returnstmt: 
      RETURN expression             { printf("returnstmt -> expression\n"); }
;

ifstmt:
      IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE                                      { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE\n"); }
|     IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE ELSE BEGINSCOPE statements ENDSCOPE  { printf("ifstmt -> IF BEGINPARAM expression ENDPARAM BEGINSCOPE statements ENDSCOPE ELSE BEGINSCOPE statements ENDSCOPE\n"); }
;

assignment: 
      IDENTIFIER ASSIGN expression                    { printf("assignment -> IDENTIFIER ASSIGN expression\n"); }
|     array ASSIGN expression                         { printf("assignment -> array ASSIGN expression\n"); }
|     IDENTIFIER ASSIGN functioncall                  { printf("assignment -> IDENTIFIER ASSIGN functioncall\n"); }
|     IDENTIFIER ASSIGN io                            { printf("assignment -> IDENTIFIER ASSIGn io\n"); }
;

functioncall:
      IDENTIFIER BEGINPARAM passingargs ENDPARAM      { printf("functioncall -> IDENTIFIER BEGINBRACKET passingargs ENDPARAM\n"); }
;

passingargs:
      expression repeat_passingargs             { printf("passingargs -> IDENTIFIER repeat_passingargs\n"); }
|     %empty                                    {printf("passingargs -> epsilon\n"); }

repeat_passingargs:
      COMMA expression repeat_arguements        { printf("repeat_passingargs -> COMMA IDENTIFIER repeat_passingargs\n"); }
|     %empty                                    { printf("repeat_passingargs -> epsilon\n"); }

declaration:
      type IDENTIFIER                           { printf("declaration -> type IDENTIFIER\n"); }
|     type assignment                           { printf("declaration -> type assignment\n"); }
|     type array                                { printf("declaration -> type array\n"); }
;

io:
      INPUT BEGINPARAM ENDPARAM                 { printf("io -> INPUT BEGINPARAM ref ENDPARAM\n"); }
|     OUTPUT BEGINPARAM ref ENDPARAM            { printf("io -> OUTPUT BEGINPARAM ref ENDPARAM\n"); }
;

ref:
      IDENTIFIER                                { printf("ref -> IDENTIFIER"); }
|     array                                     { printf("ref -> array\n"); }
;

array:
      IDENTIFIER BEGINBRACKET expression ENDBRACKET { printf("array -> IDENTIFIER BEGINBRACKET NUMBER ENDBRACKET\n"); }
;

expression:
      assignexp                           { printf("expression -> assignexp\n"); }
;

assignexp:
      logicexp logicop assignexp          { printf("assignexp -> logicexp logicop assignexp\n"); }
|     logicexp                            { printf("assignexp -> logicexp\n"); }
;

logicop:
      AND                                 { printf("logicop -> AND\n"); }
|     OR                                  { printf("logicop -> OR\n"); }
;

logicexp:
      equalityexp eqop logicexp           { printf("logicexp -> equalityexp eqop logicexp\n"); }
|     equalityexp                         { printf("logicexp -> equalityexp\n"); }
;

eqop:
      EQ                                  { printf("eqop -> EQ\n"); }
|     NE                                  { printf("eqop -> NE\n"); }
;

equalityexp:
      relationexp relop equalityexp       { printf("equalityexp -> relationexp relop equalityexp\n"); }
|     relationexp                         { printf("equalityexp -> relationexp\n"); }
;

relop:
      LT                                  {printf("relop -> LT\n");}
|     LTE                                 {printf("relop -> LTE\n");}
|     GT                                  {printf("relop -> GT\n");}
|     GTE                                 {printf("relop -> GTE\n");}
;

relationexp:
      addexp addop relationexp            {printf("relationexp -> addexp addop relationexp\n");}
|     addexp                              {printf("relationexp -> addexp\n");}
;

addop:
      ADD                                 {printf("addop -> ADD\n");}
|     SUB                                 {printf("addop -> SUB\n");}
;

addexp:
      multexp multop addexp               {printf("addexp -> multexp multop addexp\n");}
|     multexp                             {printf("addexp -> multexp\n");}
;

multop:
      MUL                                 {printf("multop -> MUL\n");}
|     DIV                                 {printf("multop -> DIV\n");}
|     MOD                                 {printf("multop -> MOD\n");}
;
multexp: 
      NOT term                            {printf("multexp -> NOT term\n");}
|     term                                {printf("multexp -> term\n");}
;

term:
      BEGINPARAM expression ENDPARAM      {printf("term -> BEGINPARAM expression ENDPARAM\n");}
|     NUMBER                              {printf("term -> NUMBER\n");}
|     ref                                 {printf("term -> ref\n");}
; 
%%

int main()
{
  yyparse();
  return 0;
}

yyerror(const char* s)
{
  printf("ERROR: %s\n", s);
  return 0;
}