#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int zbir_apsolutnih(int*, int);

int main ()
{
	int *niz, n,i=0;
	
	scanf("%d", &n);
	
	if(n<0)
		greska();
		
	if (n==0)
		printf("Prazan niz\n");
		return 0;
	
	niz=malloc(n*sizeof(int));
	if (niz==NULL)
		greska();
		
	printf("%d\n", zbir_apsolutnih(niz,n));
		
	return 0;
}
