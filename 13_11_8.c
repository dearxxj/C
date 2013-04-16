#include <stdio.h>
#include <stdlib.h>
#define FILENUM 20
//检查多个文件中字符的个数并输出 通过stdin和commandline打开文件
//嚓 到目前为止写的最麻烦的一个 调试了好久 
int count(char ch, FILE *fp);
int main(int argc, char *argv[])
{
	FILE *fp[FILENUM];
	char fn[FILENUM][40];//store filename
	char *fpn[FILENUM];//passing filename in command line
	int i = 0;//i means file index
	int j, k;
	//set input
	if (argc == 2)//stdin mode
	{
		puts("enter filenames :");
		while (scanf("%s", fn[i]) == 1)
		{
			if((fp[i] = fopen(fn[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open %s\n", fn[i]);
				if (getchar() == '\n') 
				{
					i--;//如果最后一个文件不能打开 则需减1 
					break;
				}
				else 
					continue;
			} 
			fpn[i] = fn[i];
			if (getchar() == '\n')
				break;
			i++;
		}
	}
	else if (argc < 2)
	{
		puts("ERROR! too little arguments!");
		exit(1);
	}
	else                        //commandline mode
	{
		for (j = 0; j < argc - 2; j++)
		{
			fpn[i] = argv[j + 2];
			if((fp[i] = fopen(fpn[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open %s\n", fpn[i]);
				continue;
			}
			i++;//此处多加了1 在下面减去 
		}
	}
	if (argc > 2)
		i--;
	//count char and display
	for (k = 0; k <= i; k++)
		printf("there are %d %s in file %s\n", count(*argv[1], fp[k]), argv[1], fpn[k]);
			
	return 0;
}

int count(char ch, FILE *fp)
{
	int count = 0;
	char cht;
	while ((cht = getc(fp)) != EOF)
		if (cht == ch)
			count++;
	return count;
}
