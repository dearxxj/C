#include <stdio.h>
#include <string.h>
void reverse(char *);
int main(void)
{	
	char string[100];
	int i;
	
	while (1) {
		printf("enter a sentence.\n");
		gets(string);
		reverse(string);
		puts(string);
		for (i = 0; i < 100; string[i] = '\0', i++);
	}
	return 0;
} 

void reverse(char *string)
{	
	char *start = string;
	char tmp;	
	
	while (*start) { 
		start++;
		continue;		
	}
	while (start-- > string) {//��β���� 
		tmp = *start;
		*start = *string;
		*string = tmp;
		string++;
	}
}

void rev_chsimp(char *string)//��ת���ĺ�Ӣ�Ļ�ϵľ���  unsolved
{
	char *start = string;
	char temp[100];
	char *tmp = temp;
	char *pr;//��ֵ�� 
	
	while (*start) { 
		start++;
		continue;		
	}
	
	while (start-- > string) {
		if (*(start - 1) < 0 || *(start - 1) > 0x80) {//�жϺ��� ˫�ֽڣ� 
			*(tmp + 1) = *start;
			*tmp = *--start;
			tmp += 2;
		}
		else {
			*tmp = *start;
			tmp++;
		}
	}
	*tmp = '\0';
	for (pr = temp; pr <= tmp; *string = *pr, pr++, string++);
}
