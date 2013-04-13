#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])// command line program
{
	FILE *fp1, *fp2;
	int ch;
	
	if (argc != 3)
	{
		printf("inproper number of arguments.");
		exit(3);
	}
	if ((fp1 = fopen(argv[1], "rb")) == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(1);
	} 
	if ((fp2 = fopen(argv[2], "wb+")) == NULL)//file fp2 can write and read
	{
		printf("Can't create %s\n", argv[1]);
		exit(2);
	} 
	while ((ch = getc(fp1)) != EOF)//copy file
		putc(ch, fp2);
	rewind(fp2);//back to start pointer of file
	while ((ch = getc(fp2)) != EOF)// display new file
		putc(ch, stdout);
	return 0;
}

