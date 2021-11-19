#include<stdio.h>

/* Remove all comments from a C source file old-style star slash comments */

#define IN 1
#define OUT 0
#define SLASH '/'
#define  STAR '*'

int main(void) {

int status = OUT;
char c;
char last;

last='\0';
	

// Read a character and save the last character read 
// Then when yo get a slash or a star check last character to see 
// if it is a comment

	while((c=getchar()) !=EOF) {
		if(c == STAR  && status == OUT && last == SLASH )
				status = IN;

		if(c == SLASH && status == IN && last == STAR){
				status = OUT;
		}		
		last = c; /* save current character */
		if(status == OUT)
			putchar(c);	
	}

}
