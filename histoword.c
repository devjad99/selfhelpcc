#include<stdio.h>

/* Exercise 1.13 page 24 K&R */

#define IN 1
#define OUT 0

void drawhisto(int max );
int maxtofive(void);
int length = 0; /* word length */
int histo[13]; /* an array for each word length plus one for words of over 12 characters */
int i, inword,wc,wl;
char c;

int main() {

inword = i = wc = wl =  0;
for (i=0 ; i < 12 ; ++i)
	histo[i] = 0;

while((c=getchar()) != EOF)
	if( c==' ' || c=='\n' || c=='\t') {
		inword = OUT;
		if (wl > 0 && wl < 13){ /* Words over 12 characters are discarded */
			++histo[wl -1];
			wl = 0;
		}
	}
	else if ( inword == OUT) {
		inword = IN;
		++wc;
		++wl;
	}
	else if ( inword == IN) 
		++wl;

	
printf("Word count %d\n",wc);	
for(i=0;i<12;++i)
	printf("Histo contents ascending: %d\n",histo[i]);
for(i=0;i<8;++i)
	printf("\n");
printf("Histogram:\n");
drawhisto(maxtofive());
}

int maxtofive(void) {

int max; /* Round max value to nearest 5 for a neat graph */

max=0;
	for(i=0;i<12;++i)
		if(histo[i] > max)
			max = histo[i];		
max = max + (max % 5);

return max;
}

void drawhisto(int max) {
	
printf("Got max of %d\n",max);

int i,curr;

	for(i = max ; i > 0 ; --i) {
		for(curr = 0 ; curr < 13 ; curr++) {
			if(histo[curr] >= i)
				printf("***** ");
			else 
				printf("      ");
		} /* inner for */
	printf("\n");
	}
		
/* Print legend on x axis */
printf("  1     2     3     4     5     6     7     8     9    10    11    12\n");
/*      ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
}




















