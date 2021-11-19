/* Exercise 1-15 functions */
#include<stdio.h>

#define UPPER 100
#define LOWER -20
#define STEP 2

int c2f(int cel);

int main() {

int celsius;

celsius = UPPER;

while(celsius >= LOWER) {
	printf("%d\t%d\n",celsius,c2f(celsius));
	celsius = celsius - STEP;
	}
} /* main */

int c2f(int cel) {
	return ( 32 + (9 / 5 * cel));
}
