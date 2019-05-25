#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///features
// add_symbol 	ok
// return_val - give name and profondeur - get val -- removed
// delete_symbol - give name and profondeur - remove symbol   removed
// delete_symbol - remove last symbol
// find symbol - give name, and profondeur, get table index
// get_last_address

//get_curr_depth();
// depth_increment(); operation for depth
//depth_decrement();
// symbol_initialise - give address, mark var as initialised

int global_id = 0;
int global_prof=0;


int add_symbol(char* name, char* type,  int initialise, int profondeur) { 



  entry* tempTable = tab_symbols;


if(name!=NULL){   // if var is not temp
	while(tempTable != NULL) {
    		if(strcmp(tempTable->name,name) == 0 ){    //case var name already exists
      			if(tempTable->profondeur == profondeur){		
	    			printf("Error: Variable name : -> %s <- in same profondeur :->%d<- already exists\n",tempTable->name,tempTable->profondeur);
				return -1;
      			}else if(tempTable->profondeur < profondeur){
				break;
				}		
   		 }

   		tempTable = tempTable->next;
  	}

		
}


  	entry* new = malloc(sizeof(entry));
	while(new ==tab_symbols){
		printf("\nERRROR var  created at same pointer\n");
  		new = malloc(sizeof(entry));
		}
  new->name = malloc(sizeof(name));
  new->type = malloc(sizeof(type));
  new->name = name;
  new->type = type;
  new->id = global_id;
  global_id++;
  new->initialise = initialise;
  new->next = tab_symbols; 	
  new->profondeur = profondeur;
  tab_symbols = new;


  return 1;
}





void symbol_initialise(int index) {
entry* current = tab_symbols;


  while(current != NULL)
  {
		if(current->id == index)
		{
		current->initialise = 1;
		break;
		}
  current = current->next;
  }
}


char* get_variable_name(int tableIndex){
   	entry* current = tab_symbols;
	for(int i = 0; i<global_id-tableIndex-1; i++){
		current = current->next;
	}
	if(current->profondeur==NULL){
		return NULL;
	}
	return current->name;
}



int get_curr_prof(){
	return global_prof;}


void prof_increment(){global_prof++;}


void prof_decrement(){global_prof--;}


void update_last_entry(){

   entry* current = tab_symbols;
	

}


int delete_all_var(int prof){

   entry* current = tab_symbols;

 while(current != NULL){
		if((current->profondeur == prof)){
			entry* tmp = tab_symbols;
			current = current->next;	  // replace the current with tab_symbols because
			free(tmp);
			global_id--;
	 	}else{
			return 0;
			}
  }
  return 0;

}
 
 int find_func_symbol(char* nameArg, int profondeur){ 

   entry* current = tab_symbols;

 while(current != NULL){

    if((current->name != NULL) && (strcmp(current->name,nameArg) == 0))
	{
		if((current->profondeur == 0)) { 
			return current->id;	
	 	}
	} else
	{
	current = current->next;
	}
	
  }
printf("\n Error : Variable -> %s <- not declared on function level !\n",nameArg);
  return -1;

}



 int find_symbol(char* nameArg, int profondeur){

   entry* current = tab_symbols;

		 


 while(current != NULL){


    if((current->name != NULL) && (strcmp(current->name,nameArg) == 0)){
			return current->id;	
	 	
	}else{
	current = current->next;
		}
	
  }
printf("\n Error : Variable -> %s <- not declared !\n",nameArg);
  return -1;

}






void add_temporary_symbol() {

add_symbol(NULL, "int", 0, get_curr_prof());
}



int delete_symbol() {
	entry* tmp = tab_symbols;
	tab_symbols = tab_symbols->next;
	free(tmp);
	global_id--;
	return 1;
}



int get_last_index(){
if(global_id>0)
  return global_id-1;
else
   return global_id;
}


void print_table(){ //possibly add table as in param

  entry* temporaryTable = tab_symbols;
  printf("| ID name type init prof|\n");
  while(temporaryTable != NULL){
    printf("\n| %d   %s   %s  %d  %d |\n", temporaryTable->id, temporaryTable->name, temporaryTable->type, temporaryTable->initialise, temporaryTable->profondeur);
    temporaryTable = temporaryTable->next;
  } 

}

