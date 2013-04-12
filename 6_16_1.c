#include <stdio.h>
int main(void)
{	
	char ch[26], letter;
	int index;
	
	for(index = 0, letter = 'a'; index < 26; ++index, letter += 1) {
		ch[index] = letter;
		printf("%d %c\n", index, ch[index]);
	}	
	return 0;
	
}

/*int main(void)
{	
	int i,j;
	char ch = 'F';
	
	for (i = 0; i < 6; i++) {
		for (j = 0; j <= i; j++, ch--)
			printf("%c", ch);
		ch = 'F';
		putchar('\n');
	}
		
	return 0;
}
