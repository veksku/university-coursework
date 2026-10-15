/* ND -> ND D TZ
 * 		| D
 *		
 * D -> RAZLOMAK VAR
 * 		| RAZLOMAK VAR DODELA OZ NUM ZAREZ NUM ZZ
 * 		| STAMPAJ N
 * 
 * N -> N VAR TZ
 * 		|	VAR
 * 
 * naivno resenje, ne pisem ovo na ispitu
 */

/* ND -> D ND'		{ RAZLOMAK, STAMPAJ }
 * 
 * ND' -> D ND'	{ RAZLOMAK, STAMPAJ }
 * 		| eps		{ EOI }
 *		
 * D -> RAZLOMAK VAR DD	TZ	{ RAZLOMAK }
 * 		| STAMPAJ N	TZ	{ STAMPAJ }
 * 
 * DD -> DODELA OZ NUM ZAREZ NUM ZZ		{ DODELA }
 * 		| eps		{ TZ }
 * 
 * N -> VAR N'		{ VAR }
 * 
 * N' -> VAR N'		{ VAR }
 * 		| eps		{ TZ }
 * 
 * bez leve rekurzije, pisem na ispitu
 */


#include "tokeni.h"

#define DEBUG (1)

//extern?
int yylex();

int preduvid = 0;

void ND(void);
void NDP(void);
void D(void);
void DD(void);
void N(void);
void NP(void);

int main() {
	
	preduvid = yylex();
	ND(); //prvo se poziva pocetni simbol
	
	if (preduvid == EOI){
		printf("Sve ok!\n");
	}
	else {
		printf("Sintaksna greska. Visak tokena na ulazu.\n");
		printf("Poslednji uhvaceni token: %i\n", preduvid);
	}
	return 0;
}

void ND(void){
	if (preduvid == RAZLOMAK || preduvid == STAMPAJ) {
#ifdef DEBUG
	printf("ND -> D ND'\n");
#endif
		D();
		NDP();
	}
	else {
		printf("Dobio sam %i\n", preduvid);
		check_error("ND:Ocekivano RAZLOMAK ili STAMPAJ.\n");
	}
}

void NDP(void){
	if (preduvid == RAZLOMAK || preduvid == STAMPAJ) {
#ifdef DEBUG
	printf("ND' -> D ND'\n");
#endif
		D();
		NDP();
	}
	else if (preduvid == EOI) {
#ifdef DEBUG
	printf("ND' -> eps\n");
#endif
		return;
	}
	else {
		printf("Dobio sam %i\n", preduvid);
		check_error("NDP:Ocekivano RAZLOMAK, STAMPAJ ili EOI.\n");
	}
}

void D(void){
	if (preduvid == RAZLOMAK) {
#ifdef DEBUG
	printf("D -> RAZLOMAK VAR DD TZ\n");
#endif
		preduvid = yylex();
		preduvid = yylex();
		DD();
		if (preduvid != TZ){
			printf("Dobio sam %i\n", preduvid);
			check_error("D:Ocekivano TZ.\n");
		}
		preduvid = yylex();
	}
	else if (preduvid == STAMPAJ) {
#ifdef DEBUG
	printf("D -> STAMPAJ N TZ\n");
#endif
		preduvid = yylex();
		N();
		if (preduvid != TZ){
			printf("Dobio sam %i\n", preduvid);
			check_error("D:Ocekivano TZ.\n");
		}
		preduvid = yylex();
	}
	else {
		printf("Dobio sam %i\n", preduvid);
		check_error("D:Ocekivano RAZLOMAK ili STAMPAJ.\n");
	}
}

void DD(void){
	if (preduvid == DODELA) {
#ifdef DEBUG
	printf("DD -> DODELA OZ NUM ZAREZ NUM ZZ'\n");
#endif
		preduvid = yylex();
		preduvid = yylex();
		preduvid = yylex();
		preduvid = yylex();
		preduvid = yylex();
		preduvid = yylex();
	}
	else if (preduvid == TZ) {
#ifdef DEBUG
	printf("DD -> eps\n");
#endif
		return;
	}
	else {
		printf("Dobio sam %i\n", preduvid);
		check_error("DD:Ocekivano DODELA, RAZLOMAK, STAMPAJ ili TZ.\n");
	}
}

void N(void){
	if (preduvid == VAR) {
#ifdef DEBUG
	printf("N -> VAR N'\n");
#endif
		preduvid = yylex();
		NP();
	}
	else {
		printf("Dobio sam %i\n", preduvid);
		check_error("N:Ocekivan VAR.\n");
	}
}

void NP(void){
	if (preduvid == VAR) {
#ifdef DEBUG
	printf("N' -> VAR N'\n");
#endif
		preduvid = yylex();
		NP();
	}
	else if (preduvid == TZ) {
#ifdef DEBUG
	printf("N' -> eps\n");
#endif		
		return;
	}
	else {
		printf("Dobio sam %i\n", preduvid);
		check_error("NP:Ocekivano VAR, RAZLOMAK ili STAMPAJ.\n");
	}
}
