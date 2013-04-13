#include <stdio.h>
//一点感想：消除输入字符or数字后的'\n'很重要 
void plus(void);
void minus(void);
void mutiply(void);
void divide(void);
char get_first(void);
char get_choice(void);
float get_digit(void);

int main(void)
{	
	char ch;
	
	while ((ch = get_choice()) != 'q') {	
		switch (ch) {
			case 'a': plus(); break;
			case 's': minus();break;
			case 'm': mutiply();break;
			case 'd': divide();break;
		}
	}
	printf("Bye!");
	return 0;
}

char get_choice(void)
{
	char choice;
	
	printf("Enter the operation of your choice:\n");
	printf("a. add             s. subtract\n");
	printf("m. mutiply         d. divide\nq. quit\n");
	choice = get_first();
	while (choice != 'a' && choice != 's' && choice != 'm' && choice !='d' && choice != 'q')
	{
		printf("please respond with a, s, m, d, q.\n");
		choice = get_first();
	}	
	return choice;
}

char get_first(void)
{
	char ch;
	while ((ch = getchar()) == '\n' || ch == ' ' || ch == '\t')//取第一个非空白字符 
			continue;
	while (getchar() != '\n')//跳过余下输入字母 
		continue;
	return ch;	
}
	 
float get_digit(void)
{
	float x;
	char ch;
	
	while (scanf("%f", &x) != 1) {
		while ((ch = getchar()) != '\n') printf("%c", ch);
		printf(" is not a number.\n");
		printf("please enter a number, such as 2.5, -1.78e8, or 3:");
		
	}
	return x;
}

void plus(void) 
{
	float a, b;
	printf("Enter first number.");
	a = get_digit();
	printf("Enter second number.");
	b = get_digit();
	printf("%.2f + %.2f = %.2f\n\n", a, b, a+b);
}

void minus(void)
{
	float a, b;
	printf("Enter first number.");
	a = get_digit();
	printf("Enter second number.");
	b = get_digit();
	printf("%.2f - %.2f = %.2f\n\n", a, b, a-b);
}

void mutiply(void)
{
	float a, b;
	printf("Enter first number.");
	a = get_digit();
	printf("Enter second number.");
	b = get_digit();
	printf("%.2f × %.2f = %.2f\n\n", a, b, a*b);
}

void divide(void)
{
	float a, b;
	printf("Enter first number.");
	a = get_digit();
	printf("Enter second number.");
	while ((b = get_digit()) == 0) 
		printf("Invalid number as a divider.please enter again.");
	printf("%.2f ÷ %.2f = %.2f\n\n", a, b, a/b);
}
