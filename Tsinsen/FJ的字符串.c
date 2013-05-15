#include <stdio.h>
void AN(int n); 
int main(void)
{
	int n;
	scanf("%d", &n);
	
	AN(n);
	printf("\n");
	return 0;
}

void AN(int n)
{
	if (1 == n)
		printf("A");
	else
	{
		AN(n - 1);
		printf("%c", 'A'+n-1);
		AN(n - 1);
	}
}
