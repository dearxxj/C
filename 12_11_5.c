#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void sort(int *);
//�����ʾ100��1��10�����֣����������У�������ʾÿ�����ֳ��ִ��� 
int main(void)
{	
	int list[MAX];
	int i, ctr;
	ctr = 0;//���ֳ��ֵĴ��� 
	
	srand((unsigned int)time(0));//��������� 
	for (i = 0; i < MAX; i++)
		list[i] = rand() % 10 + 1;
	sort(list);
	for (i = 0; i < MAX; i++) {
		ctr++;
		printf("%d ", list[i]);
		if (i < (MAX - 1) && list[i] > list[i + 1]) {//���ƻ��в��Ҽ��� 
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
