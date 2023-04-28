%{

#include <stdio.h>

int yylex();
int yyerror(char *s);

%}

%union{
  int		int_val;
  float dec_val;
  char  sym;
}

%token EOL
%token<int_val> INTEGER_TOKEN
%token<dec_val> DECIMAL_TOKEN
%token<sym>     PLUS
%token<sym>     MINUS
%token<sym>     MULTI
%token<sym>     DIVIDE
%left     OPENP CLOSEP
   

%type<int_val> exp
%type<int_val> term
%type<int_val> factor


%start input



%%

input:
|   line input
;

line:
  exp EOL { printf("%d\n", $1); }
| EOL
;

exp: 
    term           { $$ = $1; }
|   term PLUS exp { $$ = $1 + $3; }
|   term MINUS exp { $$ = $1 - $3; }
;

term: 
    factor          { $$ = $1; }
|   factor MULTI term { $$ = $1 * $3; }
|   factor DIVIDE term { $$ = $1 / $3; }
;

factor:
    OPENP exp CLOSEP
|   INTEGER_TOKEN
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