#include <stdio.h>
#include <stdlib.h>
int max(int a[], int l, int r)
{
	int u, v;
	int m = (l + r)/2;
	if (l == r) return a[l];
	u = max(a, l, m);
	v = max(a, m+1, r);
	if (u > v) return u; 
	else return v;
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

