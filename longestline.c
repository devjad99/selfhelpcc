#include<stdio.h>
// exercise 1-16 
// Print the length of arbitrarily long lines and a good deal of text


#define MAXLINE 2000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* We are going  to print the longest line */

int main(void) {

int lines = 0 ;
int len; // Curren t line
int max; //Longest line
char line[MAXLINE]; // Buffer for line 
char longest[MAXLINE]; // The longest line so far


max=0;
while( (len=get_line(line,MAXLINE)) > 0)
	if(len > max) {
		max = len;
		copy(longest,line);
	}
	printf("%d characters in Longest: \n %s  \n",max,longest);
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
	if(c == '\n')
		i++; /* A blank line is not zero length */
	return i;
}

/* copy: copy from into to assuming to is big enough */
void copy(char to[], char from[]) {

int i;

	i=0;
	while((to[i] = from[i]) != '\0')
		++i;
}
	
