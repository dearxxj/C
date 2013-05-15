#include <stdio.h>
//º”ºı‘ÀÀ„~ 
int main(void)
{
	int num[100];
	char sym[50];
	int i = 0, j;
	int ans;
	
	scanf("%d", &num[0]);
	while ((sym[i++] = getchar()) != '=')
		scanf("%d", &num[i]);
	ans = num[0];
	for (j = 1; j < i; j++)
	{
		if (sym[j - 1] == '+')
			ans += num[j];
		else
			ans -= num[j];
	}
	printf("%d", ans);
	return 0;
}

