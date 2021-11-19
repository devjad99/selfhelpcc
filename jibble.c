#include<stdio.h>

#define MAXLINE 64 
int chelsea=1 ;
int *pc ;
char alpha[] = "A";
char sometext[MAXLINE];
char sensible_default[]="______________________________";
char non_blank[]="=========================================================================================";
int get_line(char s[],int limit);
void copy_text(char to[],char from[]);
void dump_text(char dump[]);

struct jamble {
	int num;
	char fragment[MAXLINE];
	struct jamble* next;
	} ;

struct jamble j_struct;

int main(void) {
int len;
unsigned long pete = 100;
	copy_text(sometext,sensible_default);
	pc=&chelsea;
	printf("The address is %p\n",&chelsea);
	printf("The value is %d\n",*pc);
	printf("The address from ponter is %p\n",pc);
	printf("%s\n",sometext);
	printf("Sometext dumped\n");
	dump_text(sometext);
	printf("\n");
	printf("Length of text %d,%s\n",(get_line(sometext, MAXLINE)-1),sometext);	
	printf("Dump follows\n");
	dump_text(sometext);
	printf("\n");
	printf("Size of variables Alpha: %lu jamble: %lu non_blank: %lu\n",
		sizeof(alpha), sizeof(j_struct), sizeof(non_blank));
	printf("Pete is %lu\n",sizeof(pete));
}

int get_line(char s[],int limit)
{
	int c,i;
	
	for(i=0; i<limit-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
		s[i]=c;

	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i]='\0';
	printf("Got here\n");
	dump_text(s);
	printf("\n");
	return i;
}

void copy_text(char to[],char from[])
{
int n=0;
	while((to[n] = from[n]) != '\0')
		++n;
}

void dump_text(char dump[])
{
int i;
	for(i=0 ; i < MAXLINE ; i++)
		printf("%x",dump[i]);
}
