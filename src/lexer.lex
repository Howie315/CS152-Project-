%option noyywrap
%{

  #include "parser.tab.h"

  int lineCount = 1;
  int lineCharacterCount = 0;
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

COMMENT		(\$\$([^(\$\$)]*(\n?))*\$\$)|(\$[^(\$|\n)]*\$)

%%

{NUMBER}       		{ yylval.int_val=atoi(yytext); lineCharacterCount += yyleng; return INTEGER_TOKEN;}
{DOUBLE}    		{ yylval.int_val=atof(yytext); lineCharacterCount += yyleng; return DECIMAL_TOKEN; }

{ADD}			    {return PLUS; }
{SUB}			    {return MINUS; }
{MUL}				{return MULTI; }
{DIV}				{return DIVIDE; }
{BEGINPARAM}		{return OPENP; }
{ENDPARAM}			{return CLOSEP; }

{NEWLINE}       	{lineCount++; lineCharacterCount = 0; return EOL;}
{WHITESPACE}    	{lineCharacterCount += yyleng;}
%%
