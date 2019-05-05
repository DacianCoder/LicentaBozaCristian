#include "interpreteur.h"

Instruction instr[1024];
int indexInst = 0;
int currentInst=0;
int reg_start=4;
int registers[16];
int recursivity_register[8];
int recursivity_depth=0;
int memory[1024];


void queue_instruction(char* operation, int a, int b){
	Instruction new_inst;
	strcpy(new_inst.operation, operation);
	new_inst.a = a;
	new_inst.b = b;

	instr[indexInst] = new_inst;
	indexInst++;
	
}


void printHexInstr(){

FILE *f = fopen("HexInstr.txt", "w");
if (f == NULL)
{
    printf("Error opening file!\n");
    exit(1);
}




for(int i=0;i<=indexInst;i++){

	if(strcmp(instr[i].operation, "ADD") == 0){
		fprintf(f, "instr_mem(%d)<=x\"00%02x%04x\";\n",i,instr[i].a , instr[i].b);

	} else if(strcmp(instr[i].operation, "SUB") == 0){
		fprintf(f, "instr_mem(%d)<=x\"01%02x%04x\";\n",i,instr[i].a , instr[i].b);

	} else if(strcmp(instr[i].operation, "MUL") == 0){
		fprintf(f, "instr_mem(%d)<=x\"02%02x%04x\";\n",i,instr[i].a , instr[i].b);

	} else if(strcmp(instr[i].operation, "DIV") == 0){
		fprintf(f, "instr_mem(%d)<=x\"03%02x%04x\";\n",i,instr[i].a , instr[i].b);

	} else if(strcmp(instr[i].operation, "STORE") == 0){ 
		fprintf(f, "instr_mem(%d)<=x\"04%02x%04x\";\n",i,instr[i].a , instr[i].b);
		printf("instr_mem(%d)<=x\"04%02x  %04x\";\n",i,instr[i].a , instr[i].b);
	
	} else if(strcmp(instr[i].operation, "LOAD") == 0){
		fprintf(f, "instr_mem(%d)<=x\"05%02x%04x\";\n",i,instr[i].a , instr[i].b);


	} else if(strcmp(instr[i].operation, "AFC") == 0){
		fprintf(f, "instr_mem(%d)<=x\"06%02x%04x\";\n",i,instr[i].a , instr[i].b);


	} else if(strcmp(instr[i].operation, "EQU") == 0){
		fprintf(f, "instr_mem(%d)<=x\"07%02x%04x\";\n",i,instr[i].a , instr[i].b);


	} else if(strcmp(instr[i].operation, "INF") == 0){
		fprintf(f, "instr_mem(%d)<=x\"08%02x%04x\";\n",i,instr[i].a , instr[i].b);


	} else if(strcmp(instr[i].operation, "INFE") == 0){
		fprintf(f, "instr_mem(%d)<=x\"09%02x%04x\";\n",i,instr[i].a , instr[i].b);


	} else if(strcmp(instr[i].operation, "SUP") == 0){
		fprintf(f, "instr_mem(%d)<=x\"0a%02x%04x\";\n",i,instr[i].a , instr[i].b);


	} else if(strcmp(instr[i].operation, "SUPE") == 0){
		fprintf(f, "instr_mem(%d)<=x\"0b%02x%04x\";\n",i,instr[i].a , instr[i].b);

	} else if(strcmp(instr[i].operation, "JMP") == 0){
		fprintf(f, "instr_mem(%d)<=x\"0c%02x%04x\";\n",i,instr[i].a , instr[i].b);

	} else if(strcmp(instr[i].operation, "JMPC") == 0){
		fprintf(f, "instr_mem(%d)<=x\"0d%02x%04x\";\n",i,instr[i].a , instr[i].b);

	} else if(strcmp(instr[i].operation, "CALL") == 0){	
		fprintf(f, "instr_mem(%d)<=x\"0e%02x%04x\";\n",i,instr[i].a , instr[i].b);

	} else if(strcmp(instr[i].operation, "RET") == 0){	
		fprintf(f, "instr_mem(%d)<=x\"0f%02x%04x\";\n",i,instr[i].a , instr[i].b);
	
	} 

	}


fclose(f);


}





void printAllInst(){
	int i=0;
	while(i<indexInst){
		printf("%d  -> ",i);
		printInst(i);
		i++;
	}	

}

void edit_instruction(int pos, char* op , int a, int b) {   
	strcpy(instr[pos].operation, op);
	instr[pos].a = a;
	instr[pos].b = b;
}




int get_latest_inst(){
	if(indexInst>0)
	return(indexInst-1);
else 
	return indexInst;
}

int get_reg_index_depth(int i){
return reg_start +i;
}

int get_reg_val(int i){
return registers[i];
}


int get_memory_value(int tableIndex){
return memory[tableIndex];
}


void printInst(int Index){
	printf("Inst %s a %d b %d \n", instr[Index].operation, instr[Index].a, instr[Index].b); 
}

void execute_all_instructions(){

	for(currentInst; currentInst<indexInst; currentInst++){
		instructionExecute(currentInst);
	}

}

void instructionExecute(int i){

	if(strcmp(instr[i].operation, "ADD") == 0){
		registers[instr[i].a] += registers[instr[i].b] ;


	} else if(strcmp(instr[i].operation, "SUB") == 0){
		registers[instr[i].a] -= registers[instr[i].b] ;


	} else if(strcmp(instr[i].operation, "MUL") == 0){
		registers[instr[i].a] *= registers[instr[i].b] ;

	} else if(strcmp(instr[i].operation, "DIV") == 0){
		if( registers[instr[i].b] != 0 ){
			registers[instr[i].a] /= registers[instr[i].b] ;
		}else{
			registers[instr[i].a] = 0;
		}

	} else if(strcmp(instr[i].operation, "STORE") == 0){ 
		printf("%d   %d ::  %d  %d\n",instr[i].a,registers[instr[i].a],instr[i].b,registers[instr[i].b]);

		memory[registers[instr[i].a]] = registers[instr[i].b];

	} else if(strcmp(instr[i].operation, "LOAD") == 0){ 

		registers[instr[i].a] = memory[registers[instr[i].b]];


	} else if(strcmp(instr[i].operation, "AFC") == 0){
		registers[instr[i].a] = instr[i].b;


	} else if(strcmp(instr[i].operation, "EQU") == 0){
		if(registers[instr[i].a] == registers[instr[i].b]){
			registers[instr[i].a] = 1; // equality betw our values
		} else{
			registers[instr[i].a] = -1; // not equality
		}



	} else if(strcmp(instr[i].operation, "INF") == 0){
		if(registers[instr[i].a] < registers[instr[i].b]){
			registers[instr[i].a] = 1;
		} else{
			registers[instr[i].a] = -1;
		}


	} else if(strcmp(instr[i].operation, "INFE") == 0){
		if(registers[instr[i].a] <= registers[instr[i].b]){
			registers[instr[i].a] = 1;
		} else{
			registers[instr[i].a] = -1;
		}


	} else if(strcmp(instr[i].operation, "SUP") == 0){
		if(registers[instr[i].a] > registers[instr[i].b]){
			registers[instr[i].a] = 1;
		} else{
			registers[instr[i].a] = -1;
		}



	} else if(strcmp(instr[i].operation, "SUPE") == 0){
		if(registers[instr[i].a] >= registers[instr[i].b]){
			registers[instr[i].a] = 1;
		} else{
			registers[instr[i].a] = -1;
		}
	} else if(strcmp(instr[i].operation, "JMP") == 0){
		currentInst = instr[i].a;



	} else if(strcmp(instr[i].operation, "JMPC") == 0){
		if(registers[instr[i].b] == -1){ 			
			currentInst= instr[i].a;
		}


	} else if(strcmp(instr[i].operation, "CALL") == 0){	
		
			currentInst= memory[instr[i].a]; // jump at @ stored in variable with index A
		        recursivity_register[recursivity_depth]=instr[i].b; // storing the return address
			recursivity_depth++;
	} else if(strcmp(instr[i].operation, "RET") == 0){	
		
			recursivity_depth--;
			currentInst= recursivity_register[recursivity_depth]; // jump at designated address
			
	} 
	else if(strcmp(instr[i].operation, "PRT") == 0){	
		
	printf("\nValue of reg %d is %d  and memory %d is  %d \n\n", instr[i].a, registers[instr[i].a], instr[i].b, memory[instr[i].b]);
	} 

}


