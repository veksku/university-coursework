#include <stdio.h>

void bitovska_aritmetika(unsigned, unsigned, unsigned*, unsigned*, unsigned*, unsigned*);

int main(int argc, char *argv[])
{	
	unsigned a,b;
	unsigned and,or,xor,not;
	
	scanf("%u%u", &a,&b);
	
	bitovska_aritmetika(a,b,&and,&or,&xor,&not);
	
	printf("%u %u %u %u\n", and,or,xor,not);
	
	return 0;
}
