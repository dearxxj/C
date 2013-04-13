#include <stdio.h>
#include <ctype.h>
void input(char *, int);
int main(void)
{	
	char string[40];
	int i;
	
	while (1) {
		printf("enter a sentence.\n");
		input(string, 10);
		puts(string);
		for (i = 0; i < 40; string[i] = '0', i++);
	}
	return 0;
} 

void input(char *array, int n)
{
	int i = 0;
	char ch;
	
	while (!isblank(ch = getchar()) && i < n) {
		array[i] = ch;
		i++;
	}
	array[i] = '\0';//add a '\0' to form a string.
	while (getchar() != '\n')//skip the rest of the sentence.
		continue; 
}
