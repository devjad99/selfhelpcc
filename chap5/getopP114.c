// Exercise 5-9 
// Re-write day_of_year and month_day to use pointers
// instead of indexes
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

	static char daytab[2][13] = {
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
	};

	static char *name[] = {
		"Illegal   ",
		"January   ","February  ","March     ",
		"April     ","May       ","June      ","July      ",
		"August    ","September ","October   ",
		"November  ","December  "
	};

	static char const options[] = "dmny:";
 	// d override default day (1) 
	// y overrride current year
	// m select month defauklts to day=1
	// n day of year default is current year unless y is set

int main(int argc, char **argv)
{
// A test rig for day_of_year and month_day
	int i;
	char c;
	char *cvalue = NULL;
	char **curname;
	curname = name;
	for (i=0 ; i<=12 ; i++) {
		printf("%s\t%d\n",*curname++,daytab[0][i]);			
	}

	while (( c = getopt(argc,argv,options)) != -1)
		switch (c)
			{
				case 'd':
				  printf("d\n");
				  break;
				case 'm':
				  printf("m\n");
				  break;
				case 'n':
				  printf("n\n");
				  break;
				case 'y':
				  cvalue = optarg;
				  printf("y\n");
				  break;
				default:
				  printf("fell through\n");

			}
	printf("Was there a cvalue %s\n",cvalue);
}
 
	int day_of_year(int year, int month, int day)
	{
		int i, leap;
		
		leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
		for (i = 1; i < month; i++)
			day += daytab[leap][i];
		return day;
	}

	void month_day(int year, int yearday, int *pmonth, int *pday)
	{
		int i, leap;	
		leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
		for (i = 1; yearday > daytab[leap][i]; i++)
			yearday -= daytab[leap][i];
		*pmonth = i;
		*pday = yearday;
	}

