#include <stdio.h>
#include <ctype.h>
char *find(char *, char);
int main(void)
{	
	char string[100];
	char target;
	int i;
	
	while (1) {
		printf("enter a sentence.\n");
		gets(string);
		printf("enter a character: ");
		target = getchar();
		if (find(string, target))
			printf("target found :%p\n", find(string, target));
		else 
			printf("target not found.%p\n", NULL);
		while(getchar() != '\n')//�����س���ʣ���ַ� 
			continue;
		for (i = 0; i < 100; string[i] = '\0', i++);
	}
	return 0;
} 

char *find(char *string, char targ)//Ѱ���ַ����е�Ŀ����ĸ 
{	
	while (*string) {
		if (*string = targ)
			break;
		string++;
	}
	return (*string)? string: NULL;
}
