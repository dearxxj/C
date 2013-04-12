#include <stdio.h>
void to_base_n(unsigned long n, int m);
int main(void)
{	
	unsigned long n; 
	int m;
	printf("Enter an integer and an number(2~10) to change.(q to quit):");
	while (scanf("%lu%d", &n, &m) == 2) {
		if (m > 10 || m < 2) {
			printf("input error. second number must be between 2 and 10.\n");
			continue;
		}
		printf("%lu %d½øÖÆ is:", n, m);
		to_base_n(n, m);
		printf("\nEnter an integer and an number(2~10) to change.(q to quit):");
	}
	printf("Done !");
	return 0;
}

void to_base_n(unsigned long n, int m)
{
	if (n >= m) to_base_n(n/m, m);
	printf("%d", n%m);	
} 

