#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>

int main(void)
{
	unsigned long i;
	unsigned char c;
	double f;
	double delta;

	i = 20;
	c = 250;
	delta = 1.1;

	printf("Bits in a char: %d\n",CHAR_BIT);
	printf("Max in an int:%lu size:%lu\n",ULONG_MAX,sizeof(i));
	i=1;
	f = 0.999;
	delta=1.007;
	printf("Size of float:%lu\n",sizeof(f));
	printf("Max for float:%f\n",DBL_MAX);
	for(i=1; i < ( ULONG_MAX  - 1); i++) {
		f = f * delta;
		printf("%f\n",f);
	}
}
