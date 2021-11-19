// make a version of strcat using pointers based on chapter 2 on page 48
// strcat(s,t) appends t to s and assumes there is room ??  
// page 107

#include<stdio.h>
#include<string.h>

#define SZSTRING 120

int stringcat(char *,char *);

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
	stringcat(buf,argv[2]);
	sp = buf;
	printf("Result %s\n",sp);
}

int stringcat(char *s,char *t)
{
// Find the end of s
	int i;
	while (*s != '\0')
		s++; /* seperate increment to prevent zero sneaking into s */
// Copy t over the empty space
	while ((*s++ = *t++) !='\0')
		;
return 0;
}

