#ifndef TOKENI_H
#define TOKENI_H

#include <stdio.h>
#include <stdlib.h>

#define check_error(expr, userMsg)\
	do {\
		if (!(expr)) {\
			fprintf(stderr, "Sintaksna greska: %s\n", userMsg);\
			exit(EXIT_FAILURE);\
		}\
	}while(0) 

#define EOI (0)
#define BROJ (1)
#define STAMPAJ (2)
#define VAR (3)
#define NUM (4)
#define JEDNAKO (5)
#define TZ (6)

#define ND (100)
#define NDP (101)
#define D (102)
#define DD (103)
#define N (104)
#define NP (105)

#endif
