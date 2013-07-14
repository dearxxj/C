#include <stdio.h>

int main(void)
{
	int n;
	
	scanf("%d", &n);
	printf("%d:%d:%d", n/3600, (n/60)%60, n%60);
	return 0;
}

