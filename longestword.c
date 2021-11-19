#include<stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* We are going  to print the longest line */

int main(void) {

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
if(max > 0) // There was a line
	printf("Longest:\n%s",longest);
return 0;
}

/* Getline read a line into a buffer */
int get_line(char s[], int lim) {

int c,i;

	for(i=0;i<lim - 1 && (c=getchar()) != EOF && c!='\n' ; ++i)
		s[i]=c;

	if(c == '\n') {
		s[i] = c;
		++i;
		}

	s[i] = '\0';
	return i;
}

/* copy: copy from into to assuming to is big enough */
void copy(char to[], char from[]) {

int i;

	i=0;
	while((to[i] = from[i]) != '\0')
		++i;
}
	
