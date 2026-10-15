#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int vrednost(int);

void smesti(int*, int, int*, int*);

int main ()
{
	int *x, n, *y, k,i;
	
	scanf("%d", &n);
	
	if(n<0)
		greska();
		
	x=malloc(n*sizeof(int));
	if(x==NULL)
		greska();
	
	y=malloc(n*sizeof(int));
	if(y==NULL)
		greska();
	
	for(i=0;i<n;i++)
		scanf("%d", &x[i]);
		
	smesti(x,n,y,&k);	
		
	for(i=0;i<k;i++)
		printf("%d ", y[i]);
	printf("\n");
	
	free(x);
	free(y);
	return 0;
}

