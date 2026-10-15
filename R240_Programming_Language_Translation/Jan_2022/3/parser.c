/* ND -> D ND'		{ BROJ, STAMPAJ }
 * 
 * ND' -> D ND'		{ BROJ, STAMPAJ }
 *		| eps		{ EOI }
 * 
 * D -> BROJ VAR DD TZ		{ BROJ }
 *    	| STAMPAJ N TZ		{ STAMPAJ }
 * 
 * DD -> JEDNAKO NUM		{ JEDNAKO }
 * 		| eps		{ TZ }
 * 
 * N -> VAR N'		{ VAR }
 * 
 * N' -> VAR N'		{ VAR }
 * 		| eps		{ TZ }
 */

#include "tokeni.h"

#define DEBUG (1)
#define MAX_DEPTH (256)

extern int yylex();

int stek[MAX_DEPTH];
int sp = 0;

int pop();
void push(int x);
int peek(void);

int check(int x);
int empty();

int main() {
	
	int preduvid = yylex();
	push(ND);
	
	while(!empty()) {
		switch (peek()){
			case ND:
				if (preduvid == BROJ || preduvid == STAMPAJ){
					pop();
					push(NDP);
					push(D);
				}
				else 
					check_error(0, "Greska, dobio sam -- umesto BROJ ili STAMPAJ\n");
				break;
			case NDP:
				if (preduvid == BROJ || preduvid == STAMPAJ){
					pop();
					push(NDP);
					push(D);
				}
				else if (preduvid == EOI)
					pop();
				else
					check_error(0, "Greska, dobio sam -- umesto BROJ, STAMPAJ ili EOI\n");
				break;
			case D:
				if (preduvid == BROJ){
					pop();
					push(TZ);
					push(DD);
					push(VAR);
					push(BROJ);
				}
				else if (preduvid == STAMPAJ){
					pop();
					push(TZ);
					push(N);
					push(STAMPAJ);
				}
				else
					check_error(0, "Greska, dobio sam -- umesto BROJ ili STAMPAJ\n");
				break;
			case DD:
				if (preduvid == JEDNAKO){
					pop();
					push(NUM);
					push(JEDNAKO);
				}
				else if (preduvid == TZ){
					pop();
				}
				else
					check_error(0, "Greska, dobio sam -- umesto JEDNAKO ili TZ\n");
				break;
			case N:
				if (preduvid == VAR){
					pop();
					push(NP);
					push(VAR);
				}
				else 
					check_error(0, "Greska, dobio sam -- umesto VAR\n");
				break;
			case NP:
				if (preduvid == VAR){
					pop();
					push(NP);
					push(VAR);
				}
				else if (preduvid == TZ){
					pop();
				}
				else
					check_error(0, "Greska, dobio sam -- umesto VAR ili TZ\n");
				break;
			default: // ispitivanje tokena
				if (check(preduvid)){
					pop();
					preduvid = yylex();
				}
				else {
					check_error(0, "Leksicka greska, preduvid je -- a ocekivao sam --\n");
				}
				break;
		}
	}
	
	return 0;
}

int pop(){
	check_error(sp > 0, "Prazan stek\n");
	
	return stek [--sp];
}
void push(int x){
	check_error(sp < MAX_DEPTH, "Pun stek\n");
	
	stek[sp++] = x;
}
int peek(void){
	check_error(sp > 0, "Prazan stek\n");
	
	return stek [sp-1];
}
int check(int x){
	check_error(sp > 0, "Prazan stek\n");
	
	return stek [sp-1] == x;
}
int empty(){
	return sp == 0;
}
