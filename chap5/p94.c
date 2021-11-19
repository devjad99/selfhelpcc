/* Page 94 */

#include <stdio.h>

int main(void)
{

unsigned long mynum;
int x=1, y=2, z[10]={2,4,6,8,10,12,14,16,18,20};
int *ip; /* my first pointer */

ip = &x; /* ip points to x */
mynum = (long) ip;
printf("x =:%d at address %lu\n",x,mynum); /* suspect this cast may be invalid */

int i;

	ip=&z[0];

	for(i=0;i<10;i++){
		printf("Number:%d ",(*ip)++);
		printf("number:%d\n",*ip++);
	}
}

