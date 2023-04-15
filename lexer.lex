%{
#include <stdio.h>
int lineCount = 0, programCharacterCount = 0, lineCharacterCount = 0;

%}

DIGIT [0-9]
ALPHA [A-Za-z]
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
COMMENT (\$\$([^(\$\$)]*(\n?))*\$\$)|(\$[^(\$|\n)]*\$)
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
{COMMENT}       { printf("COMMENT\n"); programCharacterCount += 2; lineCharacterCount += 2; }
{DIGIT}+      {printf("NUMBER: %s\n", yytext); }
{ALPHA}+      {printf("TOKEN:  %s\n", yytext); }
\n        { lineCount++; programCharacterCount++; lineCharacterCount = 0; }
" "        { programCharacterCount++; lineCharacterCount++;}
.        { printf("Not Valid"); programCharacterCount++; lineCharacterCount++; }
%%

int main(void)
{
	printf("Ctrl + D to quit. \n");
	yylex();

}
