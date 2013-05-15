#include <stdio.h>
#include <string.h>
void integ(char s[]);
int main(void)
{
	int n, i = 0, j;
	int len;
	
	scanf("%d", &n);
	char s[n][100];
	char col[n];
	while (i < n)
		scanf("%s", s[i++]);
	len = strlen(s[0]);
	
	for (j = 0; j < len; j++)
	{
		for (i = 0; i < n; i++)
			col[i] = s[i][j];
		integ(col);
	}
	
	return 0;
}

void integ(char s[])
{
	int i, len, max;
	struct base {
		char name;
		int num;
	};
	struct base tmp[4] = {{'A', 0}, {'G', 0}, {'C', 0}, {'T', 0}};

	len = strlen(s);
	for (i = 0; i < len; i++)
		switch (s[i])
		{
			case 'A': tmp[0].num++;break;
			case 'G': tmp[1].num++;break;
			case 'C': tmp[2].num++;break;
			case 'T': tmp[3].num++;break;
		}
	max = 0;
	for (i = 0; i < 4; i++)
		if (tmp[i].num > tmp[max].num)
			max = i;
	printf("%c", tmp[max].name);
}
