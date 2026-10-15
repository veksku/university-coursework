#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 63

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int izmeni(int n)
{
	if(n==0)
		return 0;
	
	int cifra;
	
	if(n>10){
		cifra=n%10;
	}
	else
		cifra=n;
	
	int levideo = n/10;
	
	if(cifra%2==1)
		return izmeni(levideo)*10 + cifra;
	else
		return izmeni(levideo)*10 + cifra/2;
	
}

int main(int argc, char* argv[])
{
	int n,znak=1;
	
	if(argc!=2)
		greska();
		
	n=atoi(argv[1]);
	
	if(n<0){
		n=-n;
		znak=-1;
	}
	
	printf("%d\n", izmeni(n)*znak);
			
	return 0;
}
