#include <stdio.h>
void copy_arr(double *source, double *target, int size);
void copy_ptr(double *source, double *target, int size);

int main(void)
{	
	double source[5][6] = {
	{1.1, 2.2, 3.3, 4.4, 5.5, 6.6},
	{1.2, 1.3, 5.4, 4.3, 3.2, 2.1},
	{3.4, 6.5, 7.8, 1.4, 23.3, 67.1},
	{1.4, 1.3, 5.8, 4.9, 3.2, 2.9},
	{1.1, 1.6, 5.4, 4.3, 3.4, 2.1}
	};
	double target[5][6];	
	int index, i;
	
	for (index = 0; index < 5; index++) {
		copy_ptr(source[index], target[index], 6);
		for (i = 0; i < 6; i++) 
			printf("%.1f ", target[index][i]);//or *(target[index] + i)
		putchar('\n');
	}
	return 0;
} 

void copy_arr(double *source, double *target, int size)//用数字索引 
{
	int index;
	
	for (index = 0; index < size; index++)
		target[index] = source[index];
}

void copy_ptr(double *source, double *target, int size)//用指针 
{
	int index;
	
	for (index = 0; index < size; index++)
		*(target + index) = *(source + index);
}
