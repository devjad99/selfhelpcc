// ex54 page 107
// make a version of strcat using pointers based on chapter 2 on page 48
// strcat(s,t) appends t to s and assumes there is room ??  
// ex5-4 is a func strend returns 1 if t is at the end of s but zero otherwise

#include<stdio.h>
#include<string.h>

#define SZSTRING 120

int stringcat(char *,char *);
int strend(char *,char *);

int main(int argc, char *argv[])
{
	if(argc < 3) {
		printf("Concatenate strings usage: %s string1 string2 ",argv[0]);
		return -1;
	}
	
	int i;
	char buf[SZSTRING];
	char *sp;

	for (i=0; i<SZSTRING;i++)
		buf[i]='\0';

	strcpy(buf,argv[1]);
	/* stringcat(buf,argv[2]); */
	if (strend(buf,argv[2]))
		printf("%s does not end in %s\n",buf,argv[2]);
	else
		printf("%s ends in %s\n",buf,argv[2]);

	sp = buf;
	printf("\nResult %s\n",sp);
}

int strend(char *s, char *t)
{

char *ms;
char *mt;

/* set ms to s and mt to t to find the end of each string without changing */
/* s and t */

ms = s;
mt = t;

// Find the end of s and t using mt and ms

	while (*mt != '\0')
		mt++;
	
	while (*ms != '\0')
		ms++;

	while ( mt >= t ){
		putchar(*mt);
		putchar(*ms);
		if ( *mt != *ms )
			return 1;	
		mt--;
		ms--;	
	}
	return 0;
}

int stringcat(char *s,char *t)
{
// Find the end of s
	while (*s != '\0')
		s++; /* seperate increment to prevent zero sneaking into s */
// Copy t over the empty space
	while ((*s++ = *t++) !='\0')
		;
return 0;
}

