%{
#include <stdio.h>
int lineCount = 0, programCharacterCount = 0, lineCharacterCount = 0;

%}

INTEGER 	int
DOUBLE  	dbl
FLOAT   	flt
BOOLEAN 	bln
CHAR    	chr

ASSIGN   	=
ADD		\+
SUB		-
DIV		\/
MUL		\*
MOD		mod|%
EQ       	:=
LT		<
LTE		<=
GT		>
GTE		>=
NE		~= 

FUNCTION	func
BEGINSCOPE 	\{
ENDSCOPE 	\}
BEGINPARAM 	\(
ENDPARAM 	\)
BEGINBRACKET	\[
ENDBRACKET	\]
IF      	if
ELSE    	else 
FOR     	for
WHILE		while
CONTINUE 	continue
BREAK 		break
TRUE		true
FALSE		false
RETURN		return
VOID		void
NOT		~
AND		and
OR		or
SEMICOLON	;

DIGIT 		[0-9]
ALPHA 		[A-Za-z]
DECIMAL 	[0-9]+"."[0-9]*

IDENTIFIER 	[a-z]([A-Za-z]|[0-9])*

%%

{INTEGER}       { fprintf(yyout, "INTEGER\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{DOUBLE}    	{ fprintf(yyout, "DOUBLE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{FLOAT}        	{ fprintf(yyout, "FLOAT\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{BOOLEAN}       { fprintf(yyout, "BOOLEAN\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{CHAR}        	{ fprintf(yyout, "CHAR\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }

{ASSIGN}      	{ fprintf(yyout, "ASSIGN\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{ADD}		{ fprintf(yyout, "ADD\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{SUB}		{ fprintf(yyout, "SUB\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{DIV}		{ fprintf(yyout, "DIV\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{MUL}		{ fprintf(yyout, "MUL\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{MOD}		{ fprintf(yyout, "MOD\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{EQ}		{ fprintf(yyout, "EQ\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{LT}          	{ fprintf(yyout, "LT\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{LTE}         	{ fprintf(yyout, "LTE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{GT}          	{ fprintf(yyout, "GT\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{GTE}     	{ fprintf(yyout, "GTE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{NE}          	{ fprintf(yyout, "NE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }

{FUNCTION}	{ fprintf(yyout, "FUNCTION\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{BEGINSCOPE}	{ fprintf(yyout, "BEGINSCOPE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{ENDSCOPE}	{ fprintf(yyout, "ENDSCOPE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{BEGINPARAM}	{ fprintf(yyout, "BEGINPARAM\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{ENDPARAM}	{ fprintf(yyout, "ENDPARAM\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{BEGINBRACKET}	{ fprintf(yyout, "BEGINBRACKET\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{ENDBRACKET}	{ fprintf(yyout, "ENDBRACKET\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{IF}          	{ fprintf(yyout, "IF\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{ELSE}        	{ fprintf(yyout, "ELSE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{FOR}         	{ fprintf(yyout, "FOR\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{WHILE}       	{ fprintf(yyout, "WHILE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{CONTINUE}    	{ fprintf(yyout, "CONTINUE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{BREAK}       	{ fprintf(yyout, "BREAK\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{TRUE}		{ fprintf(yyout, "TRUE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{FALSE}		{ fprintf(yyout, "FALSE\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{RETURN}	{ fprintf(yyout, "RETURN\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{VOID}		{ fprintf(yyout, "VOID\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{NOT}		{ fprintf(yyout, "NOT\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{AND}		{ fprintf(yyout, "AND\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{OR}		{ fprintf(yyout, "OR\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng;}
{SEMICOLON}	{ fprintf(yyout, "SEMICOLON\n"); programCharacterCount += yyleng; lineCharacterCount += yyleng; }

{DIGIT}+      	{ fprintf(yyout, "NUMBER: %s\n", yytext); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
{DECIMAL}    	{ fprintf(yyout, "DECIMAL: %s\n", yytext); programCharacterCount += yyleng; lineCharacterCount += yyleng; }

{IDENTIFIER}   	{ fprintf(yyout, "IDENTIFIER: %s\n", yytext); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
 
(\$\$([^(\$\$)]*(\n?))*\$\$)|(\$[^(\$|\n)]*\$)       { fprintf(yyout, "COMMENT\n", yytext); programCharacterCount += yyleng; lineCharacterCount += yyleng; }


\n        	{ lineCount++; programCharacterCount++; lineCharacterCount = 0; }
" "        	{ programCharacterCount++; lineCharacterCount++;}
.        	{ printf("Invalide identifier: \"%s\" on line %d, col %d\n", yytext, lineCount + 1, lineCharacterCount + 1); programCharacterCount += yyleng; lineCharacterCount += yyleng; }
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
