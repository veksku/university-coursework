#include <stdio.h>
#include <stdlib.h>

void kolicnik(unsigned, unsigned, unsigned*, unsigned*);

void greska()
{
	fprintf(stderr, "-1\n");
	exit(EXIT_FAILURE);
}

int main ()
{
	unsigned a,b;
	unsigned kol, ostatak;
	
	scanf("%u %u", &a, &b);
	
	kolicnik(a,b,&kol,&ostatak);
	
	printf("Kolicnik je %u, a ostatak je %u.\n", kol, ostatak);
	
	return 0;
}


