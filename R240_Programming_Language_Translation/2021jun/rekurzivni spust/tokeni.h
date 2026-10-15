#ifndef TOKENI
#define TOKENI

#include <stdio.h>
#include <stdlib.h>

#define check_error(userMsg)\
	do {\
		fprintf(stderr, "Sintaksna greska: %s\n", userMsg);\
		exit(EXIT_FAILURE);\
	} while(0)

#define EOI (0)
#define STRING_T (1)
#define PRINT_T (2)
#define DODELA (3)
#define OZ (4)
#define ZZ (5)
#define VAR_T (6)

#endif
