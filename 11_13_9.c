#include <stdio.h>
#include <string.h>
void delspace(char *);
int main(void)
{	
	char string[100];
	int i;
	printf("enter a sentence.\n");
	gets(string);
	while (string[0] != '\0') {	//输入空行结束 
		delspace(string);
		puts(string);
		for (i = 0; i < 100; string[i] = '\0', i++);
		printf("\nenter a sentence.\n");
		gets(string);
	}
	return 0;
} 

void delspace(char *string)//删除空格的程序 
{	
	char *start = string;
	char temp[100];	
	char *tmp = temp;
	char *pr; //赋值用 
	
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
