#include <stdio.h>
#include <stdlib.h>

#define MAX 21

void greska()
{
	fprintf(stderr, "-1");
	exit(EXIT_FAILURE);
}

int izbaci_parne(int x)
{
	if(x==0)
		return 0;
		
	int levi= izbaci_parne(x/10);
	
	if((x%10)%2 == 0){
		return levi;
	}
	else 
		return levi*10 + x%10;
}

int main(int argc, char* argv[])
{
	int x;
	
	if(argc!=2)
		greska();
		
	x=atoi(argv[1]);
	
	printf("%d\n", izbaci_parne(x));
	
	return 0;
}
