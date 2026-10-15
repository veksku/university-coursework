#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int savrsen_stepen(unsigned n, unsigned* m, unsigned* k);

int main ()
{
	unsigned n,*m,*k;
		
	scanf("%d", &n);
	
	if(savrsen_stepen(n,m,k)==1)
		printf("Ima savrseni stepen.\n");
	else
		printf("Nema savrseni stepen.\n");
	
	return 0;
}

