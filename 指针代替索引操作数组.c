#include <stdio.h>
int main(void)
{	
	int (*yr)[6], *mon;
	int tot, row, col, i;
	int rain[5][6] = {
	{1,2,3,4,5,6},
	{1,2,3,4,5,6},
	{1,2,3,4,5,6},
	{1,2,3,4,5,6},
	{1,2,3,4,5,6}
	};
	tot = row = col = 0;
	//�������ֻ��yr�� 
	for (yr = rain; yr < rain + 5; yr++) {
		printf("row:");
		for (mon = *yr; mon < *yr + 6; mon++) 
			row += *mon;			
		tot += row;	
		printf("%d\n", row);
		row = 0;	
	}
	printf("total: %d\n", tot);
	
	//�еĲ�����i����mon����Ϊ��ָ�벻����� ��*(*yr + mon); 
	tot = 0;
	for (i = 0; i < 6; i++) {
		printf("col:");
		for (yr = rain; yr < rain + 5; yr++) 
			col += *(*yr + i);
		tot += col;
		printf("%d\n", col);
		col = 0;			
	}
	printf("total: %d\n", tot);
	return 0; 
} 

