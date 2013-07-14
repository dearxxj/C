#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[100];
	int len, i = 0, j;
	char ch;
	
	printf("enter a sentense. I'll judge its palindrome!\n");
	while ((ch = getchar()) != '\n')
		str[i++] = ch;
	str[i] = '\0';//this cannot be ignored !!!!
	len = strlen(str);
	i = 0; j = len - 1; 
	while (i < j)
	{
		while (str[i] == ' ') i++;
		while (str[j] == ' ') j--;
		if (str[i] != str[j]) 
			break;
		else 
			i++; j--;	
	}
	if (i < j) printf("NO!");
	else printf("YES!");
	return 0;
}

