#include <stdio.h>

int main(void)
{
	int a, b, m;
	int x, y;
	
	scanf("%d,%d,%d", &a, &b, &m);
	for (x = 1; x < m/a; x++)
		for (y = x; y < m/b; y++)
			if (a*x + b*y <= m)
				printf("%d,%d\n", x, y);
	return 0;
}

