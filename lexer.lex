%{
#include <stdio.h>
int lineCount = 0, lineCharacterCount = 0;

%}

INTEGER         int
DOUBLE          dbl
FLOAT           flt
BOOLEAN         bln
CHAR            chr

ASSIGN          =
ADD             \+
SUB             -
DIV             \/
MUL             \*
MOD             mod|%
EQ              :=
LT              <
LTE             <=
GT              >
GTE             >=
NE              ~=

FUNCTION        func
BEGINSCOPE      \{
ENDSCOPE        \}
BEGINPARAM      \(
ENDPARAM        \)
BEGINBRACKET    \[
ENDBRACKET      \]
IF              if
ELSE            else
FOR             for
WHILE           while
CONTINUE        continue
BREAK           break
TRUE            true
FALSE           false
RETURN          return
VOID            void
NOT             ~
AND             and
OR              or
SEMICOLON       ;
COMMA           \,

OUTPUT          defecate
INPUT           intake

NUMBER          [0-9]+
DECIMAL         [0-9]+"."[0-9]*

NEWLINE         \n
WHITESPACE      \t|" "

IDENTIFIER      [_a-zA-Z][_a-zA-Z0-9]*
BAD_IDENTIFIER  [0-9]+([a-zA-Z]+[a-zA-Z0-9]*)

COMMENT         (\$\$([^(\$\$)]*(\n?))*\$\$)|(\$[^(\$|\n)]*\$)

%%

{INTEGER}               { fprintf(yyout, "INTEGER\n"); lineCharacterCount += yyleng; }
{DOUBLE}                { fprintf(yyout, "DOUBLE\n"); lineCharacterCount += yyleng; }
{FLOAT}                 { fprintf(yyout, "FLOAT\n"); lineCharacterCount += yyleng;}
{BOOLEAN}               { fprintf(yyout, "BOOLEAN\n"); lineCharacterCount += yyleng; }
{CHAR}                  { fprintf(yyout, "CHAR\n"); lineCharacterCount += yyleng; }

{ASSIGN}                { fprintf(yyout, "ASSIGN\n"); lineCharacterCount += yyleng; }
{ADD}                   { fprintf(yyout, "ADD\n"); lineCharacterCount += yyleng; }
{SUB}                   { fprintf(yyout, "SUB\n"); lineCharacterCount += yyleng; }
{DIV}                   { fprintf(yyout, "DIV\n"); lineCharacterCount += yyleng;}
{MUL}                   { fprintf(yyout, "MUL\n"); lineCharacterCount += yyleng;}
{MOD}                   { fprintf(yyout, "MOD\n"); lineCharacterCount += yyleng;}
{EQ}                    { fprintf(yyout, "EQ\n"); lineCharacterCount += yyleng; }
{LT}                    { fprintf(yyout, "LT\n"); lineCharacterCount += yyleng; }
{LTE}                   { fprintf(yyout, "LTE\n"); lineCharacterCount += yyleng; }
{GT}                    { fprintf(yyout, "GT\n"); lineCharacterCount += yyleng; }
{GTE}                   { fprintf(yyout, "GTE\n"); lineCharacterCount += yyleng; }
{NE}                    { fprintf(yyout, "NE\n"); lineCharacterCount += yyleng; }

{FUNCTION}              { fprintf(yyout, "FUNCTION\n"); lineCharacterCount += yyleng;}
{BEGINSCOPE}            { fprintf(yyout, "BEGINSCOPE\n"); lineCharacterCount += yyleng;}
{ENDSCOPE}              { fprintf(yyout, "ENDSCOPE\n"); lineCharacterCount += yyleng;}
{BEGINPARAM}            { fprintf(yyout, "BEGINPARAM\n"); lineCharacterCount += yyleng;}
{ENDPARAM}              { fprintf(yyout, "ENDPARAM\n"); lineCharacterCount += yyleng;}
{BEGINBRACKET}          { fprintf(yyout, "BEGINBRACKET\n"); lineCharacterCount += yyleng;}
{ENDBRACKET}            { fprintf(yyout, "ENDBRACKET\n"); lineCharacterCount += yyleng;}
{IF}                    { fprintf(yyout, "IF\n"); lineCharacterCount += yyleng; }
{ELSE}                  { fprintf(yyout, "ELSE\n"); lineCharacterCount += yyleng; }
{FOR}                   { fprintf(yyout, "FOR\n"); lineCharacterCount += yyleng; }
{WHILE}                 { fprintf(yyout, "WHILE\n"); lineCharacterCount += yyleng; }
{CONTINUE}              { fprintf(yyout, "CONTINUE\n"); lineCharacterCount += yyleng; }
{BREAK}                 { fprintf(yyout, "BREAK\n"); lineCharacterCount += yyleng; }
{TRUE}                  { fprintf(yyout, "TRUE\n"); lineCharacterCount += yyleng;}
{FALSE}                 { fprintf(yyout, "FALSE\n"); lineCharacterCount += yyleng;}
{RETURN}                { fprintf(yyout, "RETURN\n"); lineCharacterCount += yyleng;}
{VOID}                  { fprintf(yyout, "VOID\n"); lineCharacterCount += yyleng;}
{NOT}                   { fprintf(yyout, "NOT\n"); lineCharacterCount += yyleng;}
{AND}                   { fprintf(yyout, "AND\n"); lineCharacterCount += yyleng;}
{OR}                    { fprintf(yyout, "OR\n"); lineCharacterCount += yyleng;}
{SEMICOLON}             { fprintf(yyout, "SEMICOLON\n"); lineCharacterCount += yyleng; }
{COMMA}                 { fprintf(yyout, "COMMA\n"); lineCharacterCount += yyleng;}

{OUTPUT}                { fprintf(yyout, "OUTPUT\n"); lineCharacterCount += yyleng;}
{INPUT}                 { fprintf(yyout, "INPUT\n"); lineCharacterCount += yyleng;}

{IDENTIFIER}            { fprintf(yyout, "IDENTIFIER: %s\n", yytext); lineCharacterCount += yyleng; }
{BAD_IDENTIFIER}        { printf("Error: Invalid identifier %s on line %d, col %d\n", yytext, lineCount + 1, lineCharacterCount + 1); lineCharacterCount += yyleng;}

{COMMENT}               { lineCharacterCount += yyleng; }

{NUMBER}                { fprintf(yyout, "NUMBER: %s\n", yytext); lineCharacterCount += yyleng; }
{DECIMAL}               { fprintf(yyout, "DECIMAL: %s\n", yytext); lineCharacterCount += yyleng; }


{NEWLINE}               { lineCount++; lineCharacterCount = 0; }
{WHITESPACE}            { lineCharacterCount += yyleng; }
.                       { printf("Error: Unrecognized symbol \"%s\" on line %d, col %d\n", yytext, lineCount + 1, lineCharacterCount + 1); lineCharacterCount += yyleng; }
%%

int main(int argc, char* argv[]) {

        //printf("Arguement Count: %d\n", argc);

        if (argc == 1) {
                printf("Use Ctrl + D to quit: \n");
                yylex();
        } else if (argc == 2) {
                FILE* input_file = fopen(argv[1], "r");
                yyin = input_file;
                yylex();
        } else if (argc == 3) {
                FILE* input_file = fopen(argv[1], "r");
                FILE* output_file = fopen(argv[2], "w");
                yyin = input_file;
                yyout = output_file;
                yylex();
        }

        return 0;
}