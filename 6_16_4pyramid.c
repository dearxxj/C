#include <stdio.h>
int main(void)
{	
	char start, end;
	int line, space, i;
	
	printf("�����д��ĸ��"); 
	while ((end = getchar())< 'A' || end > 'Z') {
		if ('\n' == end) 
			printf("�����������д��ĸ��");//ֱ�Ӱ��ո����Ӧ 
			continue;
		printf("�����������д��ĸ��");	  
		while (getchar() != '\n')//���������е����ಿ�� 
			continue;
	}	
	line = end - 'A';	
	for (i = 0 ; i <= line; i++){
		for (space = 1; space <= line - i; space++)
			putchar(' ');//��ӡ�ո� 
		for (start = 'A'; start <= 'A' + i; start++)
			putchar(start);//�����ӡ 
		for (start = 'A' + i - 1; start >= 'A'; start--)
			putchar(start);//�����ӡ		
		putchar('\n');
	}	
		
	return 0;
}
