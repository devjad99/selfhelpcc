#include<stdio.h>
// exercise 1-18 
// Remove trailing blanks and blank lines


#define MAXLINE 2000

int get_line(char line[], int maxline);
int strip(char buf[],int len);
void clearbuf(char buf[]);

/* We are going  to print the longest line */

int main(void) {

int lines = 0 ;
int len; 
char line[MAXLINE]; // Buffer for line 


while( (len=get_line(line,MAXLINE)) > 0) { 
		if((strip(line,len)>1))
			printf("%s",line);
		clearbuf(line);
		}
return 0;
}

int get_line(char s[], int lim) {

int c,i;

	for(i=0; (c=getchar()) != EOF && c!='\n' ; ++i) {
		if(i < lim - 1) {
			s[i] = c;
			s[i+1]='\0'; /* Terminate the string just in case we hit end of for and never come back */
		}
	}
	if(c == '\n') {
		s[i]='\n';
		i++; /* A blank line is not zero length */
	}
	printf("Length is:%d\n",i);
	return i;
}

/* copy: copy from into to assuming to is big enough */
int strip(char buf[],int len) {

int i;
i = len;

while(i > 0) {
	if(buf[i] == '\t' || buf[i] == ' ' || buf[i] == '\n') // Skip white space 
		i--;
	else
		break;
	}
buf[i]='\0'; // Truncate
return i;
}
	
void clearbuf(char buf[]) {

int i;

for(i=0 ; i < MAXLINE - 1 ; i++)
	buf[i] = '\0';
}  

