#include <stdio.h>
void binary(unsigned long);
void binary1(unsigned long);
int main(void)
{	
	unsigned long n; 
	printf("Enter a integer to change it to binary(q to quit):");
	while (scanf("%lu", &n) == 1) {
		printf("%lu binary is:", n);
		binary1(n);
		//binary(n);
		printf("\nEnter a integer to change it to binary(q to quit):");
	}
	printf("Done !");
	return 0;
}

//recursion verson
void binary(unsigned long n)
{
	if (n >= 2) binary(n/2);
	printf("%d", n%2);
	
} 

//loop version
void binary1(unsigned long n)
{
	int bi[50];
	int index = 0;
	int i;
	
	while(n >= 2 && index <= 49) {
		bi[index] = n%2;
		index++;
		n = n/2;
	}
	
	if (index == 50) //
		printf("out of memory.");
	else {
		bi[index] = n;
		for(; index >= 0; printf("%d", bi[index]), index--);
	}
}
