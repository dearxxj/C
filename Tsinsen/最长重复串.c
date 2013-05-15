#include <stdio.h>
#include <string.h>

char str[101];
int len;
int check(int);
int main(void)
{
	int i, j;
	int L;		
	int ans = 0;
	
	scanf("%s", str);
	len = strlen(str);
	for (L = 2; L < len/2; L++)
		if (check(L) && 2*L > ans)
			ans = 2*L;
	printf("%d\n", ans);
	return 0;
}

int check(int L)
{
	int k;
	for (k = 0; k + L < len; k++)
		if (str[k] != str[k+L])
			return 0;
	return 1;
}
