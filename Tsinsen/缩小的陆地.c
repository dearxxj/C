#include <stdio.h>
#define pi 3.14159
int main(void)
{
	int n, i;
	float s;
	
	scanf("%d", &n);
	float a[n][2];
	
	for (i = 0; i < n; i++)
		scanf("%f%f", &a[i][0], &a[i][1]);
	for (i = 0; i < n; i++)
	{
		s = (a[i][0]*a[i][0] + a[i][1]*a[i][1]) * pi * 0.5;
		printf("%d\n", (int)(s/50.0) + 1);			
	}
	return 0;
}

