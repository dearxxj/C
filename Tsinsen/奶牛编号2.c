#include <stdio.h>
#include <string.h>
int main(void)
{
	int n, i, j;
	char cow[1001];
	char tmp[1001];

	scanf("%d", &n);
	char name[n][1001];
	//set input
	scanf("%s", cow);
	for (i = 0; i < n; i++)
		scanf("%s", name[i]);
	//sort by abc
	for (i = 0; i < n-1; i++) 
		for (j = i+1; j < n; j++)
			if (strcmp(name[i], name[j]) > 0)
			{
				strcpy(tmp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], tmp);
			}
	//find 		 
	for (i = 0; i < n; i++)
		if (strcmp(cow, name[i]) == 0)
			break;
	if (i == n - 1)
		printf("The End");
	else
		printf("%s", name[i+1]);
	return 0;
}

