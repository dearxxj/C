#include <stdio.h>
float max_min(float *num);//原题是double类型 但输出会有问题怎么破？ 
int main(void)
{	
	float num[10];
	char ch;
	int cho, index;
	
	printf("enter 1 to start, others to quit :");
	while (scanf("%d", &cho) == 1 && cho == 1) {
		printf("Enter 10 numbers(q to quit):\n");
		for (index = 0; index < 10; index++)
		{ 	
			while(scanf("%f", &num[index]) != 1) {
				while ((ch = getchar()) != '\n')
					putchar(ch);
				printf("is not a float. enter again!\n");
			}
		}
		for (index = 0; index < 10; index++)
			printf("%f ", num[index]);
		printf("\nmax - min = %f", max_min(num));
		printf("\nenter 1 to continue, others to quit :");
	}
	printf("\nDone !");
	return 0;
} 

float max_min(float *num)
{
	float max, min;
	int index;
	
	max = min = num[0];
	for(index = 0; index < 10; index++) {
		if (num[index] < min) 
			min = num[index];
		if (num[index] > max)
			max = num[index];
	}
		
	return max - min;	
}
