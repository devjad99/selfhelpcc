/* a crack at an int swap function */
#include<stdio.h>

void swap(int *,int *);

int main(int argc, char *argv[]) 
{
int a=1,b=1307;

	printf("a=%d b=%d\n",a,b);
	swap(&a,&b);
	printf("swap ... \n");
	printf("a=%d b=%d\n",a,b);


}

void swap(int *x,int *y)
{
int tmp;

tmp = *x;
*x = *y;
*y = tmp;
}

