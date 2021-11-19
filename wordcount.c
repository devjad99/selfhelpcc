#include<stdio.h>

#define IN 1
#define OUT 0 /* In and out of a word */

int whitespace( char c);

int main(void) {

int c, nl, nw, nc, state;

state = OUT;
nl = nw = nc = 0 ; 

  while(( c=getchar()) != EOF) {
	++nc;
	if ( c == '\n')
		++nl;
	if ( whitespace(c) )
		state = OUT;
	else if (state == OUT) {
		state = IN;
		++nw;
	} /* else if  */
  }
  printf("Lines: %d Words: %d Total characters: %d\n",nl,nw,nc);
  return 0;
} /* main */

int whitespace(char c) {
	if (c == ' ' || c == '\t' || c == '\n')
		return 1;
  return 0;
}
