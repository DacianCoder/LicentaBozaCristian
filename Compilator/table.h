 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 20

typedef struct entry {
  int id;
  char* name;
  char* type;
  int initialise;
  int profondeur;
  struct entry* next;
} entry;

entry* tab_symbols= NULL;




///features
// add_symbol 	ok
// return_val - give name and profondeur - get val -- removed
// delete_symbol - give name and profondeur - remove symbol   removed
// delete_symbol - remove last symbol
// delete_all_var  delete all variable at givven depth
// find symbol - give name, and profondeur, get table index
// get_last_address
// symbol_initialise - give address, mark var as initialised


int add_symbol(char* name, char* type,  int initialise, int profondeur);

void symbol_initialise(int index);

int find_symbol(char* nameArg, int profondeur); // prof isnt taken into consideration

void add_temporary_symbol();

int delete_symbol();
 int find_func_symbol(char* nameArg, int profondeur);

int delete_all_var(int prof);

int get_last_index();

void update_last_entry();

int get_curr_prof();
void prof_increment();
void prof_decrement();

void print_table();

char* get_variable_name(int tableIndex);



