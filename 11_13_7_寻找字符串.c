#include <stdio.h>
#include <string.h>
char **string_in(const char *str1, const char *str2);
//在一个字符串中寻找另一个字符串 
char *address[20];//存放指针的数组 
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
		//初始化数组 
		for (i = 0; i < 20; address[i] = NULL, i++);
		count = 0;
	}
	return 0;
} 

char **string_in(const char *str1, const char *str2)
{
	const char *start = str2;
	char **ptr = address;//ptr是指向指针的指针 	
	
	while (*str1) {
		if (!*str2) {
			count++;
			str2 = start;
			*ptr = str1 - strlen(str2);//*ptr的值是一个指针的地址 //此处有一个warning‘我把const指针赋值给非const指针了 
			ptr++;
		}		
		if (*str1 == *str2) {
			str1++;
			str2++;
		}
		else {
			str1 -= str2 - start - 1;//str1退回的距离 
			str2 = start;//str2退回起始处 
		}
	}
	if (!*str1 && !*str2) //str1末尾为str2这种特殊情况的处理 
	{
		count++;
		*ptr = str1 - strlen(str2);
	}
	if (count) 
		return address;
	else 
		return NULL;
}
