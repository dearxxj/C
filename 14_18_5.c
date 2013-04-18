#include <stdio.h>
#include <stdlib.h>
#define CSIZE 4
#define MAX 3

struct name {
	char fname[40];
	char lname[40];	
};
struct student {
	struct name stu;
	float grade[MAX];
	float avg;
};
float avg_one(const float grade[MAX]);
void avg_all(const struct student *mem);
void display(const struct student *mem);
int main(void)
{
	struct student mem[CSIZE];
	int i = 0;
	int j = 0;
	//set input
	puts("Enter student name(0 to quit input)");
	while (i < CSIZE && scanf("%s", mem[i].stu.fname) && mem[i].stu.fname[0] != '0')
	{
		scanf("%s", mem[i].stu.lname);
		while (getchar() != '\n')
			continue;
		puts("Enter scores");
		for (j = 0; j < MAX; j++)
		{
			while (scanf("%f", &mem[i].grade[j]) != 1)
			{
				puts("Invalid score please enter a float!");
				while (getchar() != '\n')
					continue;
			}	
		}
		mem[i].avg = avg_one(mem[i].grade);
		i++;
		if (i < CSIZE)
			puts("Enter next student name(blank line to quit)");
	}
	if (i == CSIZE)
	{
		display(mem);
		avg_all(mem);
	}
	else 
		exit(1);
	return 0;
}

float avg_one(const float grade[MAX])
{
	float sum = 0.0;
	int j;
	
	for (j = 0; j < MAX; j++)
		sum += grade[j];
	return sum/MAX;
}

void avg_all(const struct student *mem)
{
	int i, j;
	float sum[MAX] = {0.0};
	puts("each subject's average is");
	for (i = 0; i < MAX; i++) 
	{
		for (j = 0; j < CSIZE; j++)
			sum[i] += mem[j].grade[i];
		printf("%.2f ", sum[i]/CSIZE);
	}
}

void display(const struct student *mem)
{
	int i;
	for (i = 0; i < CSIZE; i++)
	{
		printf("%-10s %-10s ", mem[i].stu.fname, mem[i].stu.lname);
		printf("%-7.2f %-7.2f %-7.2f  avg: %-7.2f\n", mem[i].grade[0], mem[i].grade[1], mem[i].grade[2], mem[i].avg);
	}
}

