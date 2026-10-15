#include <stdio.h>

unsigned prost(unsigned);

int main(){

	unsigned a;

	scanf("%u", &a);
	if(prost(a))
		printf("%u je prost broj\n", a);
	else
		printf("%u nije prost broj\n", a);

return 0;
}
