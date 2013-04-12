#include <stdio.h>
#define ROW 3
#define COL 5
void input(int row, int col, double array[][COL]);
double avgall(int row, int col, double array[row][col]);
double avg(double array[], int col);
double maxall(int row, int col, double array[row][col]);
void display(int n, int m, double (*array)[m]);

int main(void)
{	
	double array[ROW][COL];
	int row;
	
	input(ROW, COL, array);
	printf("**************************************\n");
	display(ROW, COL, array);
	printf("**************************************\n");
	for (row = 0; row < ROW; row++) 
		printf("row %d average is :%.2f\n", row, avg(array[row], COL));
	printf("all numbers average is :%.2f\n", avgall(ROW, COL, array));
	printf("the maxium number is :%.2f\n", maxall(ROW, COL, array));
	
	return 0;
} 

void input(int row, int col, double array[row][col])//输入二维数组 
{
	int i, j;
	for (i = 0; i < row; i++) {
		printf("Enter %d doubles.\n", COL);
		for (j = 0; j < col; j++)
			scanf("%lf", &array[i][j]);
	}
}

double avgall(int row, int col, double array[row][col])
{
	double tot = 0;
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			tot += array[i][j]; 
	}
	
	return tot/(row*col);
	
}

double avg(double array[], int col)//每行的平均值 
{
	int index;
	double sum = 0;
	
	for (index = 0; index < col; index++)
		sum += array[index];
	return sum/col;
}

double maxall(int row, int col, double array[row][col])
{
	double max = 0.0;
	int i, j;	
	
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			if (max < array[i][j])
				max = array[i][j]; 
	}
	return max;
}

void display(int n, int m, double (*array)[m])//显示二维数组 
{
	int i, j;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) 
			printf("%.1f ", array[i][j]);
		putchar('\n');
	}		
}
