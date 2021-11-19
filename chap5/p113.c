// We have skipped the exercise 5-8 as the two dimensional 
// array didn't sem that interesting
// Page 113 has a static array of month names and we are going to 
// print s month name by number on the command line

#include <stdio.h>
#include <stdlib.h>

char *month_name(int);

int main(int argc, char *argv[])
{

	if(argc != 2) {
		printf("Usage: p113 month_number\n");
		exit(1);
	}
	int i;
	i = atoi(argv[1]);
	if ( i < 1 || i > 12 ) {
		printf("Month selector out of range. 1 - 12 only.\n"); 
		exit(1);
	}

	printf("%s\n",month_name(i));
		
exit(0);
}

char *month_name(int n)
{

	static char *name[] = {
		"Illegal Month",
		"January","February","March",
		"April","May","June","July",
		"August","September","October",
		"November","December"
	};

	return (n < 1 || n > 12) ? name[0] : name[n];
}
