#include <stdio.h>
int main(void)
{	
	char start, end;
	int line, space, i;
	
	printf("输入大写字母："); 
	while ((end = getchar())< 'A' || end > 'Z') {
		if ('\n' == end) 
			printf("请重新输入大写字母：");//直接按空格的响应 
			continue;
		printf("请重新输入大写字母：");	  
		while (getchar() != '\n')//跳过输入行的其余部分 
			continue;
	}	
	line = end - 'A';	
	for (i = 0 ; i <= line; i++){
		for (space = 1; space <= line - i; space++)
			putchar(' ');//打印空格 
		for (start = 'A'; start <= 'A' + i; start++)
			putchar(start);//升序打印 
		for (start = 'A' + i - 1; start >= 'A'; start--)
			putchar(start);//倒序打印		
		putchar('\n');
	}	
		
	return 0;
}
