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

while ((c=getchar()) != EOF) {
	switch (c) {
		case SQUOTE :
		printf("Single quote.\n");
		squote++;
		break;
		case DQUOTE : printf("Double quote.\n");
		dquote++;
		break;
		case OBRACE : printf("Opening brace.\n");
		obrace++;
		break;
		case CBRACE : printf("Closing brace.\n");
		cbrace++;
		break;	
		case OBRACT : printf("Opening bracket.\n");
		obract++;
		break;	
		case CBRACT : printf("Closing bracket.\n");
		cbract++;
		break;	
			default: 
			break;
	} 
			

} /* while */
printf("Single quotes: %d Double quotes:%d\n",squote,dquote);
printf("Opening braces: %d Closing braces:%d\n",obrace,cbrace);
printf("Opening bracket: %d Closing bracket:%d\n",obract,cbract);
return 0;

}

