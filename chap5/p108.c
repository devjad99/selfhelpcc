// Page 108 a quick sort example 
// to sort a number of lines of text
// uses get_line from section 1.9 page 29 and
// alloc from section 5.4 on page 101
#include<stdio.h>
#include<string.h>

#define  MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */

int main(void)
{
	int nlines; /* number of lines read */
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr,0,nlines -1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}

}

/* quick sort */

#define MAXLEN 1000 /* max line length */
int get_line(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[],int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line,MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len) ) == NULL)
			return -1;
		else {
			line[len -1] ='\0'; /* delete newline */
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	return nlines;
}


/* wrirelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;
	
	for (i=0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

int get_line(char *s,int lim)
{
	int c,i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

#define ALLOCSIZE 10000 /* some space */

static char allocbuf[ALLOCSIZE]; /* assign storage for alloc */
static char *allocp = allocbuf;   /* next free memory position */

char *alloc(int n) /* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n; /* old p */
	} else /* not enough room */
		return 0;
}
	

/* here is the missing qsort */
void qsort(char *v[],int left , int right)
{
   	printf("left:%d right:%d %s  ---   %s\n",left,right,v[left],v[right]);
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right) { /* nothing to do if array < 2 */
		// printf("sorted\n");
		return;
	}
	swap(v,left, (left + right)/2);
	last = left;
	printf("-- last --%d\n",last);
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v,left,last);
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
