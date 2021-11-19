#include<stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = {10,12,13,14,20};
	char name[] = "James";
	char fullname[] = {'J','a','m','e','s',' ','D','a','l','e','y','\0'};
	char *ip;
	
	printf("Sizeof int:%ld\n",sizeof(int));
	printf("Sizeof areas:%ld\n",sizeof(areas));
	printf("Sizeof name:%ld\n",sizeof(name));
	printf("Lengthof name:%ld\n",sizeof(name) / sizeof(char));
	printf("Sizeof full name:%ld\n",sizeof(fullname));
	printf("Sizeof pointer to int:%ld\n",sizeof(ip));
	
	return 0;

}

