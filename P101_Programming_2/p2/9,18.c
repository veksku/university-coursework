#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

unsigned invertovanje(unsigned x, unsigned k, unsigned p)
{
// k = 20; p=20;

	unsigned mask =0;
	unsigned tmp=k, size= 8*sizeof(unsigned);
	if(k+p>=size){
		k = size-p;
		p = p- abs(k-tmp);
	}
	
	if(p>0){
	mask = mask << p-1;
	mask = ~mask;
	}
	
	mask = mask << (size-k-p);
	mask = ~mask;
	
	mask = mask << k;
	mask = ~mask;
	
	return x ^ mask;
}

int main ()
{
	unsigned x,k,p;
	
	scanf("%u %u %u", &x, &k, &p);
	
	printf("%u\n", invertovanje(x,k,p));
	
	return 0;
}

