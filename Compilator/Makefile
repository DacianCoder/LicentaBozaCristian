flex compiler.l
bison -d -y rule.y
cc lex.yy.c y.tab.c -ll -ly -o RoC_Compiler
./RoC_Compiler < RoC-while
cp HexInstr.txt ../Procesor/instructions.txt
