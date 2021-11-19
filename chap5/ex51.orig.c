/* Execise 51 getint function is a simple test program */
#include<stdio.h>
#include<ctype.h>

#define SZARRAY 20

int getch(void);
void ungetch(int);

int main(int argc,char *argv[])
{

/* fill an array with integers then ... */
	int i,array[SZARRAY],getint(int *);
	for(i=0;i<SZARRAY;i++)
		array[i]=0;
	
	for(i=0; i < SZARRAY && getint(&array[i]) != EOF;i++)
		;

/* ... spitthem all out again */

	printf("Array contents:\n");
	for(i=0; i < SZARRAY ; i++)
		printf("%d - %d\n",i,array[i]);
}


int getint(int *pn)
{
	int c, sign;

	while (isspace(c=getch())) /* usual skip white space */
		;

	if (!isdigit(c) && c !=EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c=='+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}


#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if(bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}

