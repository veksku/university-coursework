#include <stdio.h>
#include <stdlib.h>

int i=0;

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int f16(int* a, int n)
{
	if(n==0)
		if(i!=0)
			return 1;
		else
			return -1;
	
	if(((abs(*a))%2)==1){
		i++;
		return (*a)*f16(a+1,n-1);
	}
	
	else
		return f16(a+1,n-1);
}

int main()
{
	int j=0,n,*x,rez;
	
	scanf("%d", &n);
	
	if(n<1)
		greska();
		
	for(j=0;j<n;j++){
		scanf("%d", x+j);
	}
	
	rez=f16(x,n);
	
	if(rez==-1 && i==0)
		printf("-\n");
	
	else
		printf("%d\n", rez);
	
	return 0;
}
