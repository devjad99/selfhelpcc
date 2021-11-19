#include<stdio.h>

/* fold long lines at a pre-determined point or multiple. break at a whitspace if possible */


#define LOWER 80
#define UPPER 100 /* insert a newline somewhere between LOWER and UPPER */

int main(void) {

char c;
int i=0;

while((c=getchar()) != EOF ) {
	if(i > LOWER){
		if(c == ' ' || c == '\t' || c == '\n' ) {
			c = '\n';
			i = 0;
			}
	}
	if(i >= UPPER) { 
		printf("\n");
		i = 0;
	}
i++;
putchar(c);
if(c == '\n')
	i = 0;
}
		
printf("\n");
return  1;

}
