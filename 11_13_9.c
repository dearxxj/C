#include <stdio.h>
#include <string.h>
void delspace(char *);
int main(void)
{	
	char string[100];
	int i;
	printf("enter a sentence.\n");
	gets(string);
	while (string[0] != '\0') {	//������н��� 
		delspace(string);
		puts(string);
		for (i = 0; i < 100; string[i] = '\0', i++);
		printf("\nenter a sentence.\n");
		gets(string);
	}
	return 0;
} 

void delspace(char *string)//ɾ���ո�ĳ��� 
{	
	char *start = string;
	char temp[100];	
	char *tmp = temp;
	char *pr; //��ֵ�� 
	
	while (*start != '\0') {
		if (*start != ' ' ) {
			*tmp = *start;
			tmp++;
		}
		start++;
	}
	*tmp = '\0';
	for (pr = temp; pr <= tmp; *string = *pr, pr++, string++);
}
