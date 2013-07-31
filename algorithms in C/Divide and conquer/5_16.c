#include <stdio.h>
#include <stdlib.h>
int max(int a[], int l, int r)
{
	int u;
	if (l == r) return a[r];
	u = max(a, l+1, r);
	return a[l] > u ? a[l]: u;
}

int main(void)
{
	int n, i = 0;
	scanf("%d", &n);
	int *a = malloc(n * sizeof(int));
	while ((i != n ) && (scanf("%d", &a[i++])));
	printf("%d", max(a, 0, n-1));
	return 0;
}


