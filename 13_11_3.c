#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int main(void)
{
	FILE *fp1, *fp2;
	char fn1[50], fn2[50];
	int ch;
	
	printf("enter source file's name: ");
	scanf("%s", fn1);
	printf("enter target file's name: ");
	scanf("%s", fn2);
	if ((fp1 = fopen(fn1, "r")) == NULL)
	{
		printf("Can't open %s\n", fp1);
		exit(1);
	} 
	if ((fp2 = fopen(fn2, "w+")) == NULL)//file fp2 can write and read
	{
		printf("Can't create %s\n", fp2);
		exit(2);
	} 
	while ((ch = getc(fp1)) != EOF)//copy file
		putc(toupper(ch), fp2);
	rewind(fp2);//back to start pointer of file
	while ((ch = getc(fp2)) != EOF)// display new file
		putc(ch, stdout);
	return 0;
}

