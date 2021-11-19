/* on page 99 it says pa = a is a pointer assignment */
/* contains deliberate overrun of array bounds */
#include <stdio.h>


int main(int argc,char *argv[])
{

int array[]={99,51,25,13,7,3,2,1,1,1};
int *pa,i;
int s;

s=sizeof(array)/sizeof(int);
pa=array;

for(i=0;i<s;i++)
	printf("Array contents via pa:%d i:%d\n",*pa++,i);	

}
