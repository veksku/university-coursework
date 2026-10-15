#ifndef TOKENI_H
#define TOKENI_H

#include <stdio.h>
#include <stdlib.h>

#define check_error(userMsg)\
	do {\
			fprintf(stderr, "Sintaksna greska: %s\n", userMsg);\
			exit(EXIT_FAILURE);\
	} while(0)

#define EOI (0)
#define RAZLOMAK (1)
#define STAMPAJ (2)
#define VAR (3)
#define OZ (4)
#define ZZ (5)
#define ZAREZ (6)
#define DODELA (7)
#define TZ (8)
#define NUM (9)

#endif
