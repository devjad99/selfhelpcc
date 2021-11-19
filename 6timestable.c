#include <stdio.h>
#include <limits.h>

int counter = 0;
int bigone = 600;

int main(void) {
	for (counter =0;counter <= bigone ;counter = counter + 6) {
		printf("%d\n",counter);
	}
}
