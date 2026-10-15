#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1");
	exit(EXIT_FAILURE);
}

int maksimum_niza(int* a, int n)
{
	if(n==1)
		return *a;
	int max = maksimum_niza(a+1,n-1);
	
	if(*a<max){
		/*printf("a: %d\n", *a);
		printf("max: %d\n", max); */
		return max;
	}
	else
		return *a;
}

int main ()
{
	int n,i=0,*x;
	
	scanf("%d", &n);
	
	if(n<0)
		greska();
	
	if(n==0)
		return 0;
	
	x=malloc(n*sizeof(int));
	if(x==NULL)
		greska();
	
	for(i=0;i<n;i++){
		scanf("%d", x+i);
	}
	
	printf("%d\n", maksimum_niza(x,n));
	
	return 0;
}
