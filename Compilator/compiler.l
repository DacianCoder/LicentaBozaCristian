%{
#include "rule.tab.h"
#include "y.tab.h"
%}

%option yylineno

%%

int		return tINT;
string		return tSTRING;
"{"		return tACO;
"}"		return tACC;
const		return tCONST;
"+"		return tADD;
"-"		return tSUBTRACT;
"/"		return tDIVIDE;
"*"		return tMULTIPLY;
"="		return tEQUAL;
">"    		return tCHECKHIGHER;
"=="		return tCHECKEQ;
"("		return tPO;
")"		return tPC;
[ \t\n] ;
","		return tVIRGULE;
"$"		return tDOLLAR;
";"		return tFINSTR;
"daca"		return tIF;
"altfel"	return tELSE;
"catTimp"	return tWHILE;
"pentru"	return tFOR;
"++"		return tPLUSPLUS;
"--"		return tMINUSMINUS;

"<" 		return tLESS;
"<=" 		return tLESSEQUAL;
">="		return tMOREEQUAL;


"-="		return tMINUSEQUAL;
"+="		return tPLUSEQUAL;
"intoarce"	return tRETURN;

[0-9]+  {
						yylval.nb = atoi(yytext);
						return tINTNR;	};

printf return tPRINTF;

main return tMAIN;

[a-zA-Z][_a-zA-Z0-9]* {				yylval.str = strdup(yytext);
						return tVAR; };


%%

void yyerror(const char *str){
    printf("Error | Line: %d\n%s\n",yylineno,str);
	exit(-1);
}








