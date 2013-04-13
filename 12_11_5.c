#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void sort(int *);
//随机显示100个1到10的数字，按降序排列，并且显示每个数字出现次数 
int main(void)
{	
	int list[MAX];
	int i, ctr;
	ctr = 0;//数字出现的次数 
	
	srand((unsigned int)time(0));//随机化种子 
	for (i = 0; i < MAX; i++)
		list[i] = rand() % 10 + 1;
	sort(list);
	for (i = 0; i < MAX; i++) {
		ctr++;
		printf("%d ", list[i]);
		if (i < (MAX - 1) && list[i] > list[i + 1]) {//控制换行并且计数 
			printf("-----------%d\n", ctr);
			ctr = 0;
		}
		if (i == MAX -1) {
			printf("-----------%d\n", ctr);
		}
	}
	return 0;
} 

void sort(int *array)//selection sort 
{
	int i, j, tmp;
	
	for (i = 0; i < MAX; i++) {
		for (j = i + 1; j < MAX; j++)
			if (array[i] < array[j]) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
	}
}
