all:
		flex lexer.lex
		bison -d -t -v parser.y
		g++ -o compiler lex.yy.c parser.tab.c -lfl
		

