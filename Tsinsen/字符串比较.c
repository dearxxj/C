#include <stdio.h>
#include <string.h>
#include <ctype.h>
void upper(char *);
int cmp(char *, char *);
int main(void)
{
	char a[11], b[11];
	int ans = 0;
	
	scanf("%s%s", a, b);
	ans = cmp(a, b);
	printf("%d", ans);
	return 0;
}
int cmp(char *a, char *b)
{
	if (strlen(a) != strlen(b))
		return 1;
	if (strcmp(a, b) == 0)
		return 2;
	upper(a);
	upper(b);
	if (strcmp(a, b) == 0)
		return 3;
	else
		return 4;
}
void upper(char *ar)
{
	while ('\0' != *ar)
	{
		*ar = toupper(*ar);
		ar++;
	}
}
