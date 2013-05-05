#include <stdio.h>
#include <stdlib.h>
void intersect(int n, int m, int A[n], int B[m]);
void unite(int n, int m, int A[n], int B[m]);
void complement(int n, int m, int A[n], int B[m]);
int cmp(const void *, const void *);
int main(void)
{
	int n, m;
	int i;
	
	scanf("%d", &n);
	while (n > 1000 || n < 1)
		scanf("%d", &n);
	int A[n];
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	scanf("%d", &m);
	while (m > 1000 || m < 1)
		scanf("%d", &m);
	int B[m];
	for (i = 0; i < m; i++)
		scanf("%d", &B[i]);
	qsort(A, n, sizeof(int), cmp);//sort before calculation
	qsort(B, m, sizeof(int), cmp);
	intersect(n, m, A, B);
	unite(n, m, A, B);
	complement(n, m, A, B);
	return 0;
}
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void intersect(int n, int m, int A[n], int B[m])
{
	int i = 0, j = 0;
	
	while (i < n && j < m)
	{
		if (A[i] < B[j])
			i++;
		else if (A[i] > B[j])
			j++;
		else 
		{
			printf("%d ", A[i]);
			i++;
			j++;
		}	
	}
	putchar('\n');	
}
void unite(int n, int m, int A[n], int B[m])
{
	int i = 0, j = 0;
	
	while (i < n && j < m)
	{
		if (A[i] < B[j])
		{
			printf("%d ", A[i]);
			i++;
		}
		else if (A[i] > B[j])
		{
			printf("%d ", B[j]);
			j++;
		}
		else 
		{
			printf("%d ", A[i]);
			i++;
			j++;
		}	
	}
	while (i < n)
	{
		printf("%d ", A[i]);
		i++;
	}
	while (j < m)
	{
		printf("%d ", B[j]);
		j++;
	}
	putchar('\n');
}
void complement(int n, int m, int A[n], int B[m])
{
	int i = 0, j = 0;
	
	while (i < n && j < m)
	{
		if (A[i] < B[j])
		{
			printf("%d ", A[i]);
			i++;
		}
		else if (A[i] > B[j])
			j++;
		else 
		{
			i++;
			j++;
		}	
	}
	putchar('\n');
}
