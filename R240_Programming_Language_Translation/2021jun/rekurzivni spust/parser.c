/*
 * E -> PRINT_T E         PRINT_T OZ VAR_T STRING_T         ZZ
 *	| OZ E ZZ 		
 *	| T
 * 
 * T -> VAR_T DODELA T		VAR_T STRING_T
 * 	| VAR_T
 *	| STRING_T
 *
 */

/*
 * E -> PRINT_T T         PRINT_T VAR_T         ZZ
 *     	| VAR_T DODELA T
 * 
 * T -> ( T )
 * 	| VAR_T
 *	| STRING_T
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "tokeni.h"


extern int yylex();

int preduvid = 0;

void E(void);
void T(void);

int main(int argc, char** argv){
	
	preduvid = yylex();
	E();
	
	if (preduvid == EOI){
		printf("Sve ok!\n");
	}
	else
		printf("Sintaksna greska! Visak tokena na ulazu.\n");
		
	exit(EXIT_SUCCESS);
}

void E(void){ 
	if (preduvid == PRINT_T){
#ifdef DEBUG
		printf("E -> PRINT_T E\n");
#endif
		preduvid = yylex();
		E();
	}
	
	else if (preduvid == OZ){
#ifdef DEBUG
		printf("E -> OZ E ZZ\n");
#endif		
		preduvid = yylex();
		E();
		if (preduvid != ZZ)
			check_error("Ocekivao sam ZZ");
		preduvid = yylex();
	}
	
	else if (preduvid == VAR_T || preduvid == STRING_T){
#ifdef DEBUG
		printf("E -> T\n");
#endif
		T();
		if(preduvid != ZZ)
			preduvid = yylex();
	}
	else {
		check_error("Ocekivao sam PRINT_T, VAR_T ili STRING_T\n");
	}
}

void T(void){
	if (preduvid == VAR_T || preduvid == STRING_T){
#ifdef DEBUG
		printf("T -> VAR_T DODELA T\n");
#endif
		preduvid = yylex();
		if(preduvid == DODELA)
			preduvid = yylex();
	}
	else {
		check_error("Ocekivao sam VAR_T ili STRING_T\n");
	}
}
