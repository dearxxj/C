#include <stdio.h>
#define CAT1 17850.0
#define CAT2 23900.0
#define CAT3 29750.0
#define CAT4 14875.0
int main(void)
{	
	const float R1 = 0.15;
	const float R2 = 0.28;
	float inco, tax;
	int i, cho;
	inco=tax=0;
	
	while (1) {
		for (i = 0; i < 40; putchar('*'), i++ );
		putchar('\n');
		printf("enter a number corresponding to you tax:\n");
		printf("1) 单身               2) 户主\n3) 已婚，共有         4) 已婚，离异\n5) quit\n");
		for (i = 0; i < 40; putchar('*'), i++ );
		putchar('\n');
		scanf("%d", &cho);
		if (cho == 5) break;		
		printf("you income:");
		scanf("%f", &inco);		
		switch (cho) {
			case 1: tax = (inco <= CAT1) ? inco * R1: CAT1 * R1 + (inco - CAT1) * R2;break;
			case 2: tax = (inco <= CAT2) ? inco * R1: CAT2 * R1 + (inco - CAT2) * R2;break;
			case 3: tax = (inco <= CAT3) ? inco * R1: CAT3 * R1 + (inco - CAT3) * R2;break;
			case 4: tax = (inco <= CAT4) ? inco * R1: CAT4 * R1 + (inco - CAT4) * R2;break;
		} 
		printf("you tax is:%.3f\n", tax);
	}
	
	return 0;
}
