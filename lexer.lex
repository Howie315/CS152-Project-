%{
#include <stdio.h>

%}

DIGIT [0-9]
ALPHA [A-Za-z]
DOUBLE  dbl
FLOAT   flt
INTEGER int
BOOLEAN bln
CHAR    chr

%%
{DOUBLE}      {printf("DOUBLE\n"); }
{FLOAT}       {printf("FLOAT\n"); }
{INTEGER}     {printf("INTEGER\n"); }
{BOOLEAN}     {printf("BOOLEAN");}
{CHAR}		  {printf("CHAR");}
{DIGIT}+      {printf("NUMBER: %s\n", yytext); }
{ALPHA}+      {printf("TOKEN:  %s\n", yytext); }
.             {printf("!!Error!!"); }
%%

int main(void)
{
	printf("Ctrl + D to quit. \n");
	yylex();

}
