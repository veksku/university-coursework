#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

void izbaci_neparne(long* niz, unsigned* duzina);

int main ()
{
	long *niz;
	unsigned *n;
	
	n=malloc(sizeof(unsigned));
	if(n==NULL)
		greska();
		
	scanf("%u", &n[0]);
		
	niz=malloc((*n)*sizeof(long));
	if(niz==NULL)
		greska();
	
	for(unsigned i=0; i<*n;i++)
		scanf("%ld", &niz[i]);
	
	izbaci_neparne(niz,n);
	
	if(*n==0){
		printf("Nema parnih clanova niza.\n");
		return 0;
	}
	
	for(unsigned i=0; i<*n;i++)
		printf("%ld ", niz[i]);
	printf("\n");
	
	return 0;
}

