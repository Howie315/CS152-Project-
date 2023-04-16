%{
#include <stdio.h>
int lineCount = 0, programCharacterCount = 0, lineCharacterCount = 0;

%}

DOUBLE  dbl
FLOAT   flt
INTEGER int
BOOLEAN bln
CHAR    chr
WHILE   while
IF      if 
ELSE    else 
FOR     for
CONTINUE continue 
BREAK    break 



ASSIGN   =
EQ       :=
LT		 <
LTE		 <=
GT		 >
GTE		 >=
NE		 ~= 


DIGIT [0-9]
ALPHA [A-Za-z]
DECIMAL [0-9]+"."[0-9]*
BOOL	 (true|false|0|1)
WS       [ \t\n]+
IDENTIFIER [a-z]([A-Za-z]|[0-9])*


%%
{INTEGER}        { printf("INTEGER\n"); programCharacterCount += 3; lineCharacterCount += 3; }
{DOUBLE}    { printf("DOUBLE\n"); programCharacterCount += 3; lineCharacterCount += 3; }
{FLOAT}        { printf("FLOAT\n"); programCharacterCount += 3; lineCharacterCount += 3;}
{BOOLEAN}        { printf("BOOLEAN\n"); programCharacterCount += 3; lineCharacterCount += 3; }
{CHAR}        { printf("CHAR\n"); programCharacterCount += 3; lineCharacterCount += 3; }

{WHILE}       { printf("WHILE\n"); programCharacterCount += 5; lineCharacterCount += 5; }
{IF}          { printf("IF\n"); programCharacterCount += 2; lineCharacterCount += 2; }
{ELSE}        { printf("ELSE\n"); programCharacterCount += 4; lineCharacterCount += 4; }
{FOR}         { printf("FOR\n"); programCharacterCount += 3; lineCharacterCount += 3; }
{CONTINUE}    { printf("CONTINUE\n"); programCharacterCount += 8; lineCharacterCount += 8; }
{BREAK}       { printf("BREAK\n"); programCharacterCount += 5; lineCharacterCount += 5; } 

{ASSIGN}      { printf("ASSIGN\n"); programCharacterCount += 1; lineCharacterCount += 1; }
{EQ}		  { printf("EQ\n"); programCharacterCount += 2; lineCharacterCount += 2; }
{LT}          { printf("LT\n"); programCharacterCount += 2; lineCharacterCount += 2; }
{LTE}         { printf("LTE\n"); programCharacterCount += 3; lineCharacterCount += 3; }
{GT}          { printf("GT\n"); programCharacterCount += 2; lineCharacterCount += 2; }
{GTE}     	  { printf("GTE\n"); programCharacterCount += 3; lineCharacterCount += 3; }
{NE}          { printf("NE\n"); programCharacterCount += 2; lineCharacterCount += 2; }

\$\$[^\$]*\$+(?:[^\$\$][^\$]*)\$\$  { printf("COMMENT(MULTI): %s\n", yytext); }  
\$[^\$]*\$       { printf("COMMENT: %s\n", yytext); }

{DIGIT}+      {printf("NUMBER: %s\n", yytext); }
{ALPHA}+      {printf("TOKEN:  %s\n", yytext); }
{DECIMAL}     { printf("DECIMAL: %s\n", yytext); } 
{IDENTIFIER}   {printf("IDENTIFIER: %s\n", yytext); }
 
{INTEGER}{WS}{IDENTIFIER}{WS}{ASSIGN}{WS}{DIGIT}+ {printf("INT_ASSIGN: %s\n", yytext); }
({FLOAT}|{DOUBLE}){WS}{IDENTIFIER}{WS}{ASSIGN}{WS}{DECIMAL} {printf("DECIMAL_ASSIGN: %s\n", yytext); } 
{BOOLEAN}{WS}{IDENTIFIER}{WS}{ASSIGN}{WS}{BOOL} {printf("BOOLEAN_ASSIGN: %s\n", yytext); }
{CHAR}{WS}{IDENTIFIER}{WS}{ASSIGN}{WS}'{ALPHA}' {printf("CHAR_ASSIGN: %s\n", yytext); }

{INTEGER}{WS}{IDENTIFIER}\[{DIGIT}+\] {printf("1D_INT_ARRAY: %s\n", yytext); }


\n        { lineCount++; programCharacterCount++; lineCharacterCount = 0; }
" "        { programCharacterCount++; lineCharacterCount++;}
.        { printf("Not Valid"); programCharacterCount++; lineCharacterCount++; }
%%

int main(void)
{
	printf("Ctrl + D to quit. \n");
	yylex();

}
