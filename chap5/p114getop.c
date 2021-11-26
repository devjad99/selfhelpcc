// Exercise 5-9 
// Re-write day_of_year and month_day to use pointers
// instead of indexes
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);
void useage(void);


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

	static char const options[] = "d:m:n:y:";
 	// d override default day (1) 
	// y overrride current year
	// m select month defauklts to day=1
	// n day of year default is current year unless y is set

// Variables to store day of month, month and year
int tmp_dom, tmp_month, tmp_year ;


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

	// Get the date today 
	time_t rawtime = time(NULL);	
	if (rawtime == -1){
		printf("Failed to obtain date value.\n");
		exit(1);
	}
	// Set date values in tm struct
	struct tm *ptm = localtime(&rawtime);
	if (ptm == NULL) {
		printf("Localtime conversion failed\n");
		exit(1);
	}
	// What happended
	// printf("Year is: %d\n",ptm->tm_year + 1900);
	// printf("Month is: %d\n",ptm->tm_mon + 1);
	// printf("Day is: %d\n",ptm->tm_mday);
	// printf("Day of year: %d\n",ptm->tm_yday + 1);
	tmp_dom = ptm->tm_mday;
	tmp_month = ptm->tm_mon + 1;
	tmp_year = ptm->tm_yday + 1;

	while (( c = getopt(argc,argv,options)) != -1)
		switch (c)
			{
				case 'd':
				  printf("d %d\n",atoi(optarg));
				  break;
				case 'm':
				  printf("m %d\n",atoi(optarg));
				  break;
				case 'n':
				  printf("n %d\n",atoi(optarg));
				  break;
				case 'y':
				  cvalue = optarg;
				  printf("y %d\n",atoi(optarg));
				  break;
				case '?':
				  useage();
				  exit(1); 
				default:
				  printf("fell through\n");
				  exit(1);

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

void useage(void) {
	char *usestring = "Useage: p114getop [-d day] [-m month] [-y year] [-n day number]\n"
		          "All values are integers.\nDefault is current day from system date. "
			  "All options override only their scope i.e. days, month or year.";
			   	
	printf("%s\n",usestring);
}
