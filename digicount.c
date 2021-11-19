#include<stdio.h>
/* See page 22 K&R */

int main(void) {

int c, i, nwhite, nother;
int ndigit[10];

nwhite = nother = 0;
for(i=0;i<10;++i)
	ndigit[i]=0;

	while((c = getchar()) != EOF)
		if ( c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\t' || c == '\n')
			++nwhite;
		else
			++nother;
			
	printf("Digits count 9 to 0:");
	for(i = 9 ; i > -1 ; --i)
		printf(" %d",ndigit[i]);
	printf("\nWhite space: %d, Other characters: %d\n",nwhite,nother);
}
