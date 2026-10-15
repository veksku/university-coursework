#include <stdio.h>
#include <stdlib.h>

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

unsigned sekv(unsigned x)
{
	unsigned i=0;
	int size=8*sizeof(unsigned);

	while(size>0){
		if((x & 1) == 0){
			x = x >> 1;
			size--;
			if((x & 1) == 1){
				x = x >> 1;
				size--;
				if(size<=0)
					break;
				if((x & 1) == 0)
					i++;
			}
		}
		else{
			x = x >> 1;
			size--;
		}
	}
	
	return i;
}

int main ()
{
		unsigned x;
		
		scanf("%u", &x);
		
		printf("%u\n", sekv(x));
	
	return 0;
}

