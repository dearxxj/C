#include <stdio.h>
#include <stdlib.h>
#include "POLY.h"
int main(void)
{
	int N, M;
	int *n, *m;
	Poly t, x;
	int i, j;
	
	printf("Enter exp of each polynomials(two): ");
	scanf("%d %d", &N, &M);
	n = malloc((N + 1) * sizeof(int));
	m = malloc((M + 1) * sizeof(int));
	printf("Now enter coefficients of each polynomials:\n");
	for (i = N; i >= 0; i--)
		scanf("%d", &n[i]);
	for (i = M; i >= 0; i--)
		scanf("%d", &m[i]);
	
	for (i = N - 1, t = POLYterm(n[N], 0); i >= 0; i--)
		t = POLYadd(POLYmult(t, POLYterm(1, 1)), POLYterm(n[i], 0));
	for (i = M - 1, x = POLYterm(m[N], 0); i >= 0; i--)
		x = POLYadd(POLYmult(x, POLYterm(1, 1)), POLYterm(m[i], 0));
	POLYshow(t);
	POLYshow(x);
	POLYshow(POLYmult(t, x));

	return 0;
}

