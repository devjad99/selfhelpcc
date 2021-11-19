/* A simple memory allocator  with a test wrapper */

#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 100 /* total available space - very small so it will fail */


static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* pointer assignment as per page 99 */

char *alloc(int n) /* return pointer to n chars */
{
	if (allocbuf + ALLOCSIZE - allocp >=n) { /* fits */
		allocp += n;
		return allocp -n; /* old p */
	} else /* not enough room */
		return 0;
}


void afree(char *p) /* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;

}

void printmem(void)
{
int i;
	for(i=0;i<ALLOCSIZE;i++)
		printf("%d ",allocbuf[i]);
	printf("\n");
}

int main(void)
{
int i=0;
char array[]="James the friendly dragon";
char *pa;
pa = alloc(sizeof(array) / sizeof(char));
strcpy(pa,array);
printmem();
printf("\n%s\n",array);
}
