all: compiler test_compiler

compiler.lex: compiler.l
	flex compiler.l

compiler.tab.c: compiler.y
	bison -d rule.y

compiler: compiler.tab.c compiler.lex
	cc lex.yy.c y.tab.c -ll -ly

test_compiler: compiler
	./a.out < fakeC

