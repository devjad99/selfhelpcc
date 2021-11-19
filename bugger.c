#include<stdio.h>

// Check balanced old style comments
/* Check for balanced single and doubel quotes including escaped quotes 
*/

#define COMPLEX "The cat sat on the mat \" was that a single double quote" 
#define NOPUNCS 6

char line[] = COMPLEX;
enum punc { SQUOTE = '\'', DQUOTE = '\"', OBRACE = '{' , CBRACE = '}', OBRACT = '(', CBRACT = ')'};


int main(void) {

char c;
// We are going to count all of out puct marks seperately
int i,squote,dquote,obrace,cbrace,obract,cbract;
squote = dquote = obrace = cbrace = obract = cbract =0;

while((c=getchar()) != EOF) {
	printf("about ...\n");
	putchar(c);
	} 

printf("\nSingle quotes: %d Double quotes:%d\n",squote,dquote);
printf("Opening braces: %d Closing braces:%d\n",obrace,cbrace);
printf("Opening bracket: %d Closing bracket:%d\n",squote,dquote);
return 0;

}

