#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stdout, "-1\n");
	exit(EXIT_FAILURE);
}

int deljiv (int, int);

void izdvoji_deljive(int*, int, int*, int*);

int main()
{
	int *niz1,n,*niz2,i,*krajniza;
	
	scanf("%d", &n);
	
	if(n<0)
		greska();
		
	niz1=malloc(n*sizeof(int));
	if(niz1==NULL)
		greska();
		
	niz2=malloc(n*sizeof(int));
	if(niz2==NULL)
		greska();
		
	for(i=0;i<n;i++){
		scanf("%d", &niz1[i]);
	}
		
	izdvoji_deljive(niz1, n, niz2,krajniza);
	
	for(i=0;&niz2[i]<krajniza;i++){
		
	}
	
	return 0;
}
