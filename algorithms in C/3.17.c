#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nmax 1000
#define Mmax 10000
char buf[Mmax]; int M = 0;
int compare(const void *a, const void *b)
{
	return **(char **)a - **(char **)b;// or strcmp(*(char **)a, *(char **)b)
}

int main(void)
{
	int i, N;
	char *a[Nmax];
	for (N = 0; N < Nmax; N++)
	{
		a[N] = &buf[M];
		if (scanf("%s", a[N]) == EOF) break;
		M += strlen(a[N]) + 1;
	}
	qsort(a, N, sizeof(char*), compare);
	for (i = 0; i < N; i++) printf("%s\n", a[i]);
	return 0;
}
