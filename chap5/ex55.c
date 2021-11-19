// ex54 page 107
// ex55 page 107 - new versions of str - ncpy, ncomp, concat
// make a version of strcat using pointers based on chapter 2 on page 48
// strcat(s,t) appends t to s and assumes there is room ??  
// ex5-4 is a func strend returns 1 if t is at the end of s but zero otherwise

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SZSTRING 120

int stringcat(char *,char *);
int strend(char *,char *);

int strncopy(char *,char *,int n);
int strncomp(char *,char *,int n);
int strnconcat(char *,char *,char *,int n);

int main(int argc, char *argv[])
{
	if(argc != 5) {
		printf("Usage: %s [y,t,p] string1 string2 num\n",argv[0]);
		printf("where y = copy, t = cat and p = compare.\n");
		return -1;
	}
/* should do a proper check on the types of the parameters ... might later */
int i;
int j;
char buf[SZSTRING]; 

	for(i=0;i < SZSTRING;i++)
		buf[i]=0;

	i = atoi(argv[4]);
	j = *argv[1];


	printf("number:%d\n",i);
	
	switch (j) {
		case 'y':
			strncopy(buf,argv[3],i);
			break;
		case 't':
			strnconcat(buf,argv[2],argv[3],i);
			printf("%d\n",i);
			break;
		case 'p':
			printf("Found a p \n");
			strncomp(argv[2],argv[3],i);
			break;
		default:
			printf("Incorrect usage see manual page\n");
	}
	
			if ( strlen(buf) < 1){
				printf("Buffer empty\n");
			}
			else {
				printf("Result: %s\n",buf);
			}
		

	for (i=0; i<SZSTRING;i++)
		buf[i]='\0';
	exit(0);
}

int strncopy(char *s, char *t, int n)
{
int i;
	/* test */
	printf("strncopy\n");
 	for(i=0; i <=n ; i++)
		*s++ = *t++;
	for(i=n;i < SZSTRING;i++)
		*s++ = '\0'; 
	return 0;
}

int strnconcat(char *buffer, char *s, char *t, int i)
{
char *ip;
	/* test */
	ip = s;
	printf("strnconcat\n");
	while (*ip != '\0'){
		*(buffer++) = *(ip++); 
	}
	ip = t;
	while ((*ip != '\0') && (i-- > 0)){
		printf("%d\n",i);
		*(buffer++) = *(ip++); 
	}
	*buffer = '\0';
	
	printf("Length of buf string in strncat %ld\n",ip - s);
	return 0;
}


int strncomp(char *s, char *t, int i)
{
	
	while ( i-- > 0){
		if( *s++ != *t++){
			printf("Mismatch\n");
			return 1;
	}
	}
	printf("Mathes all the way.\n");
	return 0;
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
int i;

	while ( mt >= t ){
		putchar(*mt);
		putchar(*ms);
		if ( *mt != *ms )
			putchar('*');
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

