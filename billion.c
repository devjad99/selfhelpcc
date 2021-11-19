#include <stdio.h>
#include <limits.h>

int counter =0;
int bigone = 2000000;

int main(void) {
	for (counter =0;counter < bigone ;counter = counter + 6) {
		while(counter < bigone ) {
			counter++;
		}
	printf("%d\n",counter);
	}
}
