// How does qsort work if not actualluy written


void qsort(char *lineptr[], int left, int right);

int main(void)
{

char line[] = "The cat sat on teh mat";
char otherline[] = "the cat did not sit on the mat";
char *linesptr[2];

	linesptr[0] = line;
	linesptr[1] = otherline;
	qsort (linesptr,0,1);
}


