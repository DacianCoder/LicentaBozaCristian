all: compiler test_compiler

compiler.lex: compiler.l
	flex compiler.l

compiler.tab.c: compiler.y
	bison -d -v rule.y
	yacc -f rule.y

compiler: compiler.tab.c compiler.lex
	cc -std=c99 -o compiler lex.yy.c y.tab.c -ll -ly

test_compiler: compiler
	./compiler < fakeC

