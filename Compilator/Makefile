flex compiler.l
bison -d -y --warnings=none rule.y
cc lex.yy.c y.tab.c -ll -ly -o RoC_Compiler
./RoC_Compiler < RoC
cp HexInstr.txt ../Procesor/instructions.txt
