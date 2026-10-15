/*
 * E -> PRINT_T T         PRINT_T OZ VAR_T STRING_T         ZZ
 * 
 * T -> VAR_T DODELA T		VAR_T STRING_T
 *	| ( T )
 * 	| VAR_T
 *	| STRING_T
 *
 */


#include <stdio.h>
#include <stdlib.h>

#include "tokeni.h"

#define MAX_DEPTH (256)

extern int yylex();

int stek[MAX_DEPTH];
int sp = 0;

void push(int x);
int pop();
int peek();

int check(int x);
int empty();

int main(int argc, char** argv){
	
	int preduvid = yylex();
	push(E);
	
	while(!empty()){
		switch(peek()){
			case E:
				if (preduvid == PRINT_T){
					pop();
					push(T);
					push(PRINT_T);
				}
				else if (preduvid == VAR_T){
					pop();
					push(T);
					push(DODELA);
					push(VAR_T);
				}
				else if (preduvid == DODELA){
					pop();
					pop();
				}
				else
					check_error(0,"E");
				break;
			case T:
				if (preduvid == VAR_T){
					if(peek()==OZ){
						pop();
						pop();
						push(VAR_T);
						push(OZ);
					}
					else{
						pop();
						push(VAR_T);
					}
				}
				else if(preduvid == STRING_T){
					if(peek()==OZ){
						pop();
						pop();
						push(STRING_T);
						push(OZ);
					}
					else{
						pop();
						push(STRING_T);
					}
				}
				else if(preduvid == OZ){
					pop();
					push(ZZ);
					push(T);
					push(OZ);
				}
				else if(preduvid == ZZ || preduvid == EOI){
					while(!empty())
						pop();
				}
				else
					check_error(0,"T");
				break;
			default:
				if (check(preduvid)){
					pop();
					preduvid = yylex();
				}
				else
					check_error(0,"default");
				break;
		}
	}
	
	printf("Sve ok\n");
		
	exit(EXIT_SUCCESS);
}

void push(int x){
	check_error(sp < MAX_DEPTH, "Stek je pun\n");
	
	stek[sp++] = x;
}
int pop(){
	check_error(sp>0, "Stek je prazan\n");
	
	return stek[--sp];
}
int peek(){
	check_error(sp>0, "Stek je prazan\n");
	
	return stek[sp-1];
}

int check(int x){
	check_error(sp>0, "Stek je prazan\n");
	
	return stek[sp-1] == x;
}
int empty(){
	return sp == 0;
}
