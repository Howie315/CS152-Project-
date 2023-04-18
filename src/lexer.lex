%{
#include <stdio.h>
int lineCount = 0, lineCharacterCount = 0;

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
COMMA		\,

OUTPUT		defecate
INPUT		intake

NUMBER		[0-9]+
DECIMAL 	[0-9]+"."[0-9]*

NEWLINE		\n
WHITESPACE	\t|" "

IDENTIFIER	[a-zA-Z_][a-zA-Z_0-9]*
BAD_IDENTIFIER	[0-9]+([_a-zA-Z]+[_a-zA-Z0-9]*)

COMMENT		(\$\$([^(\$\$)]*(\n?))*\$\$)|(\$[^(\$|\n)]*\$)

%%

{INTEGER}       	{ return INTEGER }
{DOUBLE}    		{ return DOUBLE }
{BOOLEAN}       	{ fprintf(yyout, "BOOLEAN\n"); lineCharacterCount += yyleng; return BOOLEAN; }
{CHAR}        		{ fprintf(yyout, "CHAR\n"); lineCharacterCount += yyleng; return CHAR; }

{ASSIGN}      		{ fprintf(yyout, "ASSIGN\n"); lineCharacterCount += yyleng; return ASSIGN; }
{ADD}			{ fprintf(yyout, "ADD\n"); lineCharacterCount += yyleng; return ADD; }
{SUB}			{ fprintf(yyout, "SUB\n"); lineCharacterCount += yyleng; return SUB; }
{DIV}			{ fprintf(yyout, "DIV\n"); lineCharacterCount += yyleng; return DIV; }
{MUL}			{ fprintf(yyout, "MUL\n"); lineCharacterCount += yyleng; return MUL; }
{MOD}			{ fprintf(yyout, "MOD\n"); lineCharacterCount += yyleng; return MOD; }
{EQ}			{ fprintf(yyout, "EQ\n"); lineCharacterCount += yyleng; retrun EQ; }
{LT}          		{ fprintf(yyout, "LT\n"); lineCharacterCount += yyleng; retrun LT; }
{LTE}         		{ fprintf(yyout, "LTE\n"); lineCharacterCount += yyleng; return LTE; }
{GT}          		{ fprintf(yyout, "GT\n"); lineCharacterCount += yyleng; return GT; }
{GTE}     		{ fprintf(yyout, "GTE\n"); lineCharacterCount += yyleng; return GTE; }
{NE}          		{ fprintf(yyout, "NE\n"); lineCharacterCount += yyleng; return NE; }

{FUNCTION}		{ fprintf(yyout, "FUNCTION\n"); lineCharacterCount += yyleng; return FUNCTION; }
{BEGINSCOPE}		{ fprintf(yyout, "BEGINSCOPE\n"); lineCharacterCount += yyleng; return BEGINSCOPE; }
{ENDSCOPE}		{ fprintf(yyout, "ENDSCOPE\n"); lineCharacterCount += yyleng; return ENDSCOPE; }
{BEGINPARAM}		{ fprintf(yyout, "BEGINPARAM\n"); lineCharacterCount += yyleng; return BEGINPARAM; }
{ENDPARAM}		{ fprintf(yyout, "ENDPARAM\n"); lineCharacterCount += yyleng; return ENDPARAM; }
{BEGINBRACKET}		{ fprintf(yyout, "BEGINBRACKET\n"); lineCharacterCount += yyleng; return BEGINBRACKET; }
{ENDBRACKET}		{ fprintf(yyout, "ENDBRACKET\n"); lineCharacterCount += yyleng; return ENDBRACKET; }
{IF}          		{ fprintf(yyout, "IF\n"); lineCharacterCount += yyleng; return IF;}
{ELSE}        		{ fprintf(yyout, "ELSE\n"); lineCharacterCount += yyleng; return ELSE; }
{FOR}         		{ fprintf(yyout, "FOR\n"); lineCharacterCount += yyleng; return FOR; }
{WHILE}       		{ fprintf(yyout, "WHILE\n"); lineCharacterCount += yyleng; return WHILE; }
{CONTINUE}    		{ fprintf(yyout, "CONTINUE\n"); lineCharacterCount += yyleng; return CONTINUE;}
{BREAK}       		{ fprintf(yyout, "BREAK\n"); lineCharacterCount += yyleng; return BREAK;}
{TRUE}			{ fprintf(yyout, "TRUE\n"); lineCharacterCount += yyleng; return TRUE; }
{FALSE}			{ fprintf(yyout, "FALSE\n"); lineCharacterCount += yyleng; return FALSE; }
{RETURN}		{ fprintf(yyout, "RETURN\n"); lineCharacterCount += yyleng; return RETURN; }
{VOID}			{ fprintf(yyout, "VOID\n"); lineCharacterCount += yyleng; return VOID; }
{NOT}			{ fprintf(yyout, "NOT\n"); lineCharacterCount += yyleng; return NOT; }
{AND}			{ fprintf(yyout, "AND\n"); lineCharacterCount += yyleng; return AND; }
{OR}			{ fprintf(yyout, "OR\n"); lineCharacterCount += yyleng; return OR; }
{SEMICOLON}		{ fprintf(yyout, "SEMICOLON\n"); lineCharacterCount += yyleng; return SEMICOLON; }
{COMMA}			{ fprintf(yyout, "COMMA\n"); lineCharacterCount += yyleng; return COMMA; }

{OUTPUT}		{ fprintf(yyout, "OUTPUT\n"); lineCharacterCount += yyleng; return OUTPUT; }
{INPUT}			{ fprintf(yyout, "INPUT\n"); lineCharacterCount += yyleng; return INPUT; }

{IDENTIFIER}   		{ fprintf(yyout, "IDENTIFIER: %s\n", yytext); lineCharacterCount += yyleng; return IDENTIFIER; }
{BAD_IDENTIFIER}	{ printf("Error: Invalid identifier %s on line %d, col %d\n", yytext, lineCount + 1, lineCharacterCount + 1); lineCharacterCount += yyleng; return BAD_IDENTIFIER; }
 
{COMMENT}		{ lineCharacterCount += yyleng; return COMMENT; }

{NUMBER}      		{ fprintf(yyout, "NUMBER: %s\n", yytext); lineCharacterCount += yyleng; return NUMBER; }
{DECIMAL}    		{ fprintf(yyout, "DECIMAL: %s\n", yytext); lineCharacterCount += yyleng; return DECIMAL; }

{NEWLINE}       	{ lineCount++; lineCharacterCount = 0; return NEWLINE; }
{WHITESPACE}    	{ lineCharacterCount += yyleng; return WHITESPACE; }
.       		{ printf("Error: Unrecognized symbol \"%s\" on line %d, col %d\n", yytext, lineCount + 1, lineCharacterCount + 1); lineCharacterCount += yyleng; return .;}
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
