#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

unsigned invertujSvakiTreci(unsigned x)
{
	unsigned mask = 1;
	int i=8*sizeof(unsigned)-1;
	while(i>0){
		mask = mask << 3;
		mask = mask | 1;
		i=i-3;
	}
	
	return x^mask;
	
}

int main ()
{
	unsigned x;
	
	scanf("%u", &x);
	
	printf("%u\n", invertujSvakiTreci(x));
	
	return 0;
}

