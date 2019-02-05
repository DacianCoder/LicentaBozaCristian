%{
	#include <stdio.h>
	#include "table.c"
	#include "interpreteur.c"
	
	#define YYDEBUG 1
	#define YYLTYPE 1
	
	int yylex(void);
	void yyerror(char*);


char* type;
%}

%union {
	int nb;
	char* str;
}

%type <str> tVAR tINT
%type <nb> tINTNR

%token tINT
%token tACO
%token tACC
%token tCONST
%token tADD
%token tSUBTRACT
%token tDIVIDE
%token tMULTIPLY
%token tEQUAL
%token tPLUSPLUS  
%token tMINUSMINUS 
%token tIF
%token tELSE
%token tCHECKEQ
%token tPO
%token tPC
%token tTAB
%token tVIRGULE
%token tDOLLAR
%token tFINSTR
%token tINTNR
%token tWHILE
%token tPRINTF
%token tMAIN
%token tVAR
%token tFOR
%token tSTRING
%token tCHECKHIGHER
%token tLESS
%token tLESSEQUAL
%token tMOREEQUAL
%token tMINUSEQUAL
%token tPLUSEQUAL
%token tRETURN


%left tADD tSUBTRACT
%left tMULTIPLY tDIVIDE

%type <nb>  tIF tWHILE tFOR tPO tPC tFINSTR 

%%

Main: DeclFunction tMAIN {prof_increment();} tPO tPC Body {} ;

//adding other type to the function
DeclFunction :vartype tVAR { // hard coded 4 
			int b=4 + get_latest_inst(); // we don't execute everytime the first 4 instructions
			

			add_symbol($2, type, 0, get_curr_prof()); 
			int a= get_last_index(); 
			queue_instruction("AFC",1,b);

			queue_instruction("AFC",14,a);
			queue_instruction("ADD",14,15); 
			queue_instruction("STORE",14,1);// we store at @14 the val b 

			queue_instruction("TMPJMP",1,1); }

	   	tPO Params tPC FuncBody tFINSTR {
			edit_instruction(4,"JMP",get_latest_inst(),0);} //works good until now
		
	        | ; // no function


Params :Param NextParam 
	| { // if there is no parameter we need to add a temp variable in wich we store the result 
		add_temporary_symbol();}; // this will be our return value


NextParam : tVIRGULE Param  | ;

Param :	vartype tVAR { 
			add_symbol($2, type, 0, get_curr_prof()); }
	| tVAR  {	
			int a= find_symbol($1, get_curr_prof()); 
			add_symbol($1, type, 0, get_curr_prof());

			int b= get_last_index();

			queue_instruction("AFC",2,a);
	 		queue_instruction("LOAD", 1, 2);// we copy the value  in r1

			queue_instruction("AFC",14,b);

			queue_instruction("STORE", 14, 1); 
};



FuncBody : tACO FuncInstr  tACC;

 

FuncInstrs: Instructions |RetVal; 

FuncInstr : FuncInstrs FuncInstr
	    | FuncInstrs
	    | ;



RetVal : tRETURN tVAR tFINSTR { 
					int a=find_func_symbol($2, 0);// we know the delta now
				
					queue_instruction("AFC",14,a);//we add the delta
					queue_instruction("ADD",14,15); // we add the new ref

					queue_instruction("LOAD",1,14);//we load the data in the first register
					queue_instruction("AFC",14,1); //we set r14 to 1; so we have the first var from the function
					queue_instruction("ADD",14,15); // we add the new ref to where to store the result

					queue_instruction("STORE",14,1); // we store it at the correct @adr
					queue_instruction("RET",1,1);
};



Body: tACO Instruction tACC; // add here the get_curr_prof()

Instruction : Instructions Instruction 
	   | Instructions 
	   | ;

Instructions: 
	   Calcul 
	 | For 
     | While
     | Print
     | Declaration
     | If |RetVal;

Declaration: vartype Declarations tFINSTR ;


Declarations: Multideclaration Declarations
			| Lastdeclaration ;

Multideclaration : tVAR tVIRGULE {add_symbol($1, type, 0,get_curr_prof());}
		| tVAR tEQUAL tINTNR tVIRGULE {
			int b=get_curr_prof();
		    add_symbol($1, type, 0, b);
		// we could change add symbol to return the address
		    int a = find_symbol($1, get_curr_prof());
		    queue_instruction("AFC", 1, $3);

		    queue_instruction("AFC",14,a);
		    queue_instruction("ADD",14,15); 

		    queue_instruction("STORE", 14, 1);
};



Lastdeclaration: tVAR {add_symbol($1, type, 0, get_curr_prof());}
		| tVAR tEQUAL tINTNR {

				 add_symbol($1, type, 0, get_curr_prof()); 

				 int a = find_symbol($1, get_curr_prof());
				 queue_instruction("AFC", 1, $3);
		
				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15); 

				 queue_instruction("STORE", 14, 1);  
};


vartype : tINT { type = "int"; }
     | tCONST { type = "const"; };


Print: tPRINTF tPO tVAR tPC tFINSTR {
			printf("Print not supported\n"); 
 		/* queue_instruction("PRT",x,y); is printing value of r[x] and m[y]*/};




If : tIF{prof_increment();} tPO Condition tPC{
		int a = get_last_index(); //condition-index

		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 10, 14);

		queue_instruction("TMP", 1, 1);
		$1 = get_latest_inst();
		delete_symbol();
		
	} Body {
		queue_instruction("TMP", 1, 1);
		edit_instruction($1, "JMPC" , get_latest_inst(), 10);
		$1 = get_latest_inst();
		
	} Else {	
		edit_instruction($1, "JMP" , get_latest_inst(), 10);
		delete_all_var(get_curr_prof());
		prof_decrement();
				
}

	;

Else: tELSE Body
	//| tELSE If
 	| ;


Condition : 	

	  Expression tCHECKEQ Expression {

		int a = get_last_index();
		int b = a-1;
		
		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 2, 14);

		queue_instruction("EQU", 2, 1);
	
		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
	| Expression tLESS Expression {
		int a = get_last_index();
		int b = a-1;

		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 2, 14);
		queue_instruction("INF", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
	| Expression tCHECKHIGHER Expression {
		int a = get_last_index();
		int b = a-1;

		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15); 
		queue_instruction("LOAD", 2, 14);
		queue_instruction("SUP", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
	| Expression tLESSEQUAL Expression {
		int a = get_last_index();
		int b = a-1;
		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 2, 14);
		queue_instruction("INFE", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	}
	| Expression tMOREEQUAL Expression {
		int a = get_last_index(); // right arg
		int b = a-1;			// left arg
		queue_instruction("AFC",14,a);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 1, 14);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("LOAD", 2, 14);

		queue_instruction("SUPE", 2, 1);

		queue_instruction("AFC",14,b);
		queue_instruction("ADD",14,15);
		queue_instruction("STORE", 14, 2);
		delete_symbol();
	};




//while
While : tWHILE {
	prof_increment();
	$1 = get_latest_inst(); /* Hop to here to retry condition */
	} tPO Condition tPC {

	int a = get_last_index(); //condition-index after all conditions

	queue_instruction("AFC",14,a);
	queue_instruction("ADD",14,15);
	queue_instruction("LOAD", 10, 14); 

	queue_instruction("TMP", 1, 1); //we add the unedited JMPC
	$3 = get_latest_inst();         
	delete_symbol();

	} Body {
		queue_instruction("JMP", $1, 1);
		edit_instruction($3, "JMPC" , get_latest_inst(), 10);

		delete_all_var(get_curr_prof());
		prof_decrement();

	} 

; 

For :   tFOR tPO {
			prof_increment();}  //incrementing the depth
	DeclCalc {
		    	$1 = get_latest_inst();}  

	Condition tFINSTR{
	   		int a = get_last_index(); //condition-index after all conditions
			queue_instruction("AFC",14,a);
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 10, 14);} // add in place of 10 , 5+ prof

	tVAR tPLUSPLUS tPC  {
			$2= find_symbol($9, get_curr_prof());
			queue_instruction("TMP", 1, 1); //we add the unedited JMPC 
			$7 = get_latest_inst();         
			delete_symbol();}
	Body {	
			//we add here the code for incrementing but targeting the variable that has to be targeted
			queue_instruction("AFC",14,$2);
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 1, 14);

			queue_instruction("AFC", 2, 1);
			queue_instruction("ADD", 1, 2);
			queue_instruction("STORE", 14, 1); //$2
			//we updated the value of the value incremented and now we can jump to the condition
			queue_instruction("JMP", $1, 1);
			edit_instruction($7, "JMPC" , get_latest_inst(), 10);


			delete_all_var(get_curr_prof());
			prof_decrement();};


For: 	tFOR tPO {
			prof_increment();}  // incrementing the depth
	DeclCalc {
		        $1 = get_latest_inst();}
	Condition tFINSTR{
	   		int a = get_last_index(); //condition-index after all conditions

			queue_instruction("AFC",14,a);
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 10, 14);} // add in place of 10 , 5+ prof
	tVAR tMINUSMINUS tPC  {
			$2= find_symbol($9, get_curr_prof());
			queue_instruction("TMP", 1, 1); //we add the unedited JMPC 
			$7 = get_latest_inst();         
			delete_symbol();}
	Body {
	
			queue_instruction("AFC",14,$2); // we store in r14 value of $2
			queue_instruction("ADD",14,15);
			queue_instruction("LOAD", 1,14);

			queue_instruction("AFC", 2, 1);  // increment part
 			queue_instruction("SUB", 1, 2);

			queue_instruction("STORE", 14, 1); // $2

			queue_instruction("JMP", $1, 1);
			edit_instruction($7, "JMPC" , get_latest_inst(), 10);


			delete_all_var(get_curr_prof());
			prof_decrement(); };


DeclCalc : Declaration |Calcul;












 Calcul:  // we always have the result in the last temp variable
	 	  tVAR tEQUAL Expression tFINSTR {
				 int a = find_symbol($1, get_curr_prof());
				 int b = get_last_index();

				 queue_instruction("AFC",14,b);
				 queue_instruction("ADD",14,15);

				 queue_instruction("LOAD", 1, 14);
				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);

				 queue_instruction("STORE", 14, 1);

				 delete_symbol();} 

		| tVAR tEQUAL tSUBTRACT Expression tFINSTR {
				 int a = find_symbol($1, get_curr_prof());
				 int b = get_last_index();

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);
				 queue_instruction("AFC", 2, -1);
				 queue_instruction("MUL", 1, 2);

			 	 queue_instruction("AFC",14,a);
			 	 queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();} 

		| tVAR tPLUSPLUS tFINSTR {
				 int a = find_symbol($1, get_curr_prof());

				 queue_instruction("AFC",14,a);
			 	 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC", 2, 1);
				 queue_instruction("ADD", 1, 2);

				 queue_instruction("STORE", 14, 1);}

		| tVAR tMINUSMINUS tFINSTR {
				 int a = find_symbol($1, get_curr_prof());
				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC", 2, 1);
				 queue_instruction("SUB", 1, 2);

				 queue_instruction("STORE", 14, 1);}

		| tVAR tMINUSEQUAL Expression tFINSTR {
				 int a = find_symbol($1, get_curr_prof());
				 int b = get_last_index();

				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				 queue_instruction("AFC",14,b);
				 queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

				 queue_instruction("SUB", 1, 2);

				 queue_instruction("AFC",14,a);
				 queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();}

		| tVAR tPLUSEQUAL Expression tFINSTR{
				 int a = find_symbol($1, get_curr_prof());
				 int b = get_last_index();

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

			   	 queue_instruction("ADD", 1, 2);

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol();}
;


Expression :
 	     Expression tADD Expression {
				 int a = get_last_index();
				 int b = a-1;

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

				 queue_instruction("ADD", 1, 2);
			     queue_instruction("STORE", 14, 1);
				 delete_symbol(); }	  

		| Expression tSUBTRACT Expression {
				 int a = get_last_index();
			 	 int b = a-1;

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
			 	 queue_instruction("LOAD", 2, 14);

				 queue_instruction("SUB", 1, 2);
				 queue_instruction("STORE", 14, 1);
			 	 delete_symbol(); }

 		| Expression tDIVIDE Expression {
				 int a = get_last_index();
				 int b = a-1;

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
			 	 queue_instruction("LOAD", 2, 14);

				 queue_instruction("DIV", 1, 2);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol(); }		

		| Expression tMULTIPLY Expression {
		 		 int a = get_last_index();
				 int b = a-1;
				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				 queue_instruction("LOAD", 2, 14);

				 queue_instruction("MUL", 1, 2);
				 queue_instruction("STORE", 14, 1);
				 delete_symbol(); }

 		| tVAR {
				add_temporary_symbol();
				int a=find_symbol($1, get_curr_prof());
				int b=get_last_index();
				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
	 			queue_instruction("LOAD", 1, 14);

				queue_instruction("AFC",14,b);
				queue_instruction("ADD",14,15);
				queue_instruction("STORE", 14, 1); }

		| tINTNR {
				add_temporary_symbol();
				int a=get_last_index();
				queue_instruction("AFC", 1, $1);

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				queue_instruction("STORE",14, 1); }
		|Function {
				
				queue_instruction("AFC",15,0);
				delete_symbol();
				prof_decrement();
			 }

		| tPO tSUBTRACT tINTNR tPC {
				add_temporary_symbol();
				int a= get_last_index();
				queue_instruction("AFC", 1, $3);
				queue_instruction("AFC", 2, -1);
				queue_instruction("MUL", 1, 2);

				queue_instruction("AFC",14,a);
				queue_instruction("ADD",14,15);
				queue_instruction("STORE", 14, 1); }

		| tPO Expression tPC


			;


Function : tVAR tPO{
				int z = get_last_index();
				queue_instruction("AFC",15,z);
			
		prof_increment();
		} 

	Params tPC {
		int a= get_latest_inst() +1;
		int b=find_symbol($1,0);// the var NameFUNC has stored the index needed for function CALL
		queue_instruction("CALL",b,a);};

%%


void yyerror(char *s) {
	//printf("da-te ba ca cade%d",yylloc.first_line);
	//printf("da-te ba ca cade%d",yylineno);
	fprintf(stderr, "error: %s\n", s);
	exit(1);
}

int main() {
	
	//#if YYDEBUG
	//	yydebug = 1;
	//#endif

	yyparse();

	printf("\n\n                 Setting up instructions          \n\n\n");
	//printAllInst();
	printf("\n\n                   Instructions ready          \n\n\n");
	printf("\n\n----------------------------------------------------------  \n\n");
	printf("\n\n                   Starting execution           \n\n\n");
	execute_all_instructions();
	printHexInstr();

	print_table();

	for(int i=0; i<=get_last_index(); i++){

		printf("var: %s, value: %d\n", get_variable_name(i), get_memory_value(i));
	}
	
}



