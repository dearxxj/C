#include <stdio.h>
#include <string.h>
char **string_in(const char *str1, const char *str2);
//��һ���ַ�����Ѱ����һ���ַ��� 
char *address[20];//���ָ������� 
int count = 0;
int main(void)
{	
	char string1[100];
	char string2[100];
	int i; 
	
	while (1) {
		printf("enter a string: "); scanf("%s", string1);
		printf("enter target string: "); scanf("%s", string2);	
		string_in(string1, string2);
		if (*address) 
			for (i = 0; i < count; i++)
				printf("target was found at : %p\n\n", address[i]);			
		else 
			printf("oooops! target not found ! :%p\n\n", NULL);
		//��ʼ������ 
		for (i = 0; i < 20; address[i] = NULL, i++);
		count = 0;
	}
	return 0;
} 

char **string_in(const char *str1, const char *str2)
{
	const char *start = str2;
	char **ptr = address;//ptr��ָ��ָ���ָ�� 	
	
	while (*str1) {
		if (!*str2) {
			count++;
			str2 = start;
			*ptr = str1 - strlen(str2);//*ptr��ֵ��һ��ָ��ĵ�ַ //�˴���һ��warning���Ұ�constָ�븳ֵ����constָ���� 
			ptr++;
		}		
		if (*str1 == *str2) {
			str1++;
			str2++;
		}
		else {
			str1 -= str2 - start - 1;//str1�˻صľ��� 
			str2 = start;//str2�˻���ʼ�� 
		}
	}
	if (!*str1 && !*str2) //str1ĩβΪstr2������������Ĵ��� 
	{
		count++;
		*ptr = str1 - strlen(str2);
	}
	if (count) 
		return address;
	else 
		return NULL;
}
