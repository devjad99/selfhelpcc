#include <stdio.h>

int main(void)
{

int i,j;

	for (i = 0; i <= 50 ; i++) {
		for (j = 1; j <= 10 ; j++) 
			printf("%d/%d=%d\t",i,j,(i/j));
		printf("\n");
	}
	
}
