#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

unsigned mirrorf(unsigned int x)
{
	unsigned y = 0;
	
	// ona krece od bita najmanje tezine u x
	unsigned int mask1 = 1; 
	//ova maska krece od bita najvece tezine broja y
	unsigned int mask2 = 1 << (sizeof(int)*8 - 1);
	
	while(mask2)
	{
		if ((mask1 & x) != 0)
			y = mask2 | y;
			
		mask1 <<= 1;
		mask2 >>= 1;
	}
	
	return y;
}

unsigned invertujK(unsigned x, unsigned k)
{
	unsigned mask=0,mirrorm=0;
	unsigned i=0;
	unsigned tmp=x, size= 8*(sizeof(unsigned));
	
	do{
		if(tmp & 1 == 1){
			i++;
			if(i==k){
				i=0;
				mask = mask | 1;
			}
		}
		size--;
		if(size!=0)
			mask = mask << 1;
		tmp = tmp >> 1;
	}while (size>0);
	
	mirrorm = mirrorf(mask);
	return x ^ mirrorm;
}

int main ()
{
	unsigned x,k;
	scanf("%u %u", &x, &k);
	
	printf("%u\n", invertujK(x,k));	
	
	return 0;
}

