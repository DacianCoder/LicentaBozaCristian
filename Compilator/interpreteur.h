#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Instruction{
	char operation[16];
	int a;
	int b;
} Instruction;


void queue_instruction(char* operation, int a, int b);

void instructionExecute(int instructionIndex);

int get_last_inst(void);

void printInst(int Index);
void printAllInst();

void execute_all_instructions();

int get_register_value(int tableIndex);

int get_memory_value(int tableIndex);

int get_reg_index_depth(int i);

void printHexInstr();

int get_reg_val(int i);

int get_latest_inst();

void edit_instruction(int pos, char* op , int a, int b);
