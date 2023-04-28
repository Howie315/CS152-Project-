all:
		flex lexer.lex
		bison -d -t parser.y
		gcc lex.yy.c parser.tab.c
		

