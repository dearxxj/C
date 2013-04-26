#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//count days until input date. and calculate which day of a week for input date is
int days_crtyr(int yr, int mo, int da);
int days_befyr(int yr);
void black_Fri(int yr);
struct month {
		char name[20];
		char srt[4];//not str[3]!!!!!!!!!cause '\0' needs one char!!
		int num;
		int day;
	};
struct month mon[12] = {
	{"January", "Jan", 1, 31},
	{"February", "Feb", 2, 28},
	{"March", "Mar", 3, 31},
	{"April", "Apr", 4, 30},
	{"May", "May", 5, 31},
	{"June", "Jun", 6, 30},
	{"July", "Jul", 7, 31},
	{"August", "Aug", 8, 31},
	{"September", "Sep", 9, 30},
	{"October", "Oct", 10, 31},
	{"November", "Nov", 11, 30},
	{"December", "Dec", 12, 31}
	};
	
int main(void)
{
	int days = 0;
	int da;
	int mo = 0;
	char mostr[20];// when (month input) were string
	char week[10];
	int yr;
	int i;
	// set input 
	printf("Enter year: ");
	while (scanf("%d", &yr) != 1)
	{
		printf("Invalid input! Enter year again: ");
		while(getchar() != '\n')
			continue;
		scanf("%d", &yr);
	}			
	printf("Enter month(name or number): ");
	while (scanf("%s", mostr) == 1)
	{
		for (i = 0; i < 12; i++)//set month
		{//use 'strcmp' and 'atoi' to compare strings and number
			if (!strcmp(mon[i].name, mostr) || !strcmp(mon[i].srt, mostr) || mon[i].num == atoi(mostr))
			{
				mo = mon[i].num;
				break;
			}
		}
		if (mo == 0)
		{
			printf("Invalid input! Enter month again: ");
			while(getchar() != '\n')
				continue;
			continue;
		}
		break;		
	}	
	
	printf("Enter day: ");
	while (scanf("%d", &da) != 1)
	{
		printf("Invalid input! Enter day again: ");
		while(getchar() != '\n')
			continue;
		scanf("%d", &da);
	}
	//count days
	days = days_crtyr(yr, mo, da) + days_befyr(yr);
	printf("%d days until %d.%d.%d\n", days, yr, mo, da);
	
	switch (days % 7)
	{
		case 1: strcpy(week, "Monday");break;
		case 2: strcpy(week, "Tuesday");break;
		case 3: strcpy(week, "Wednesday");break;
		case 4: strcpy(week, "Tuesday");break;
		case 5: strcpy(week, "Friday");break;
		case 6: strcpy(week, "Saturday");break;
		case 0: strcpy(week, "Sunday");break;
	}
	
	printf("%d.%d.%d is %s", yr, mo, da, week);
	black_Fri(yr);
	for (i = 1500; i < 1800; i++)
		black_Fri(i);
	return 0;
}

int days_crtyr(int yr, int mo, int da)// days of current year
{
	int days = 0;
	int i;
	
	if (yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0))//闰年的情况 
		mon[1].day = 29;
	else 
		mon[1].day = 28;//这句话少了算很多年的时候会有一个很隐蔽的bug--改变了全局变量却没有改回来	
	for (i = 0; i < mo - 1; i++)
		days += mon[i].day;
	
	days += da;	
	return days;	
}

int days_befyr(int yr)//days before current year
{
	int days = 0;
	int i;
	int days_oneyr(yr)
	{
		if (yr % 400 == 0 || (yr % 4 == 0 && yr % 100 != 0))//闰年的情况
			return 366;
		else 
			return 365; 
	}
	for (i = 1; i < yr; i++)
		days += days_oneyr(i);
		
	return days;
}

void black_Fri(int yr)
{
	int days = 0;
	int i;
	int count = 0;
	int ctr = 0;
	
	for (i = 0; i < 12; i++)
	{
		days = days_crtyr(yr, mon[i].num, 13) + days_befyr(yr);
		if (ctr == 0)
			printf("\nthese are black Fridays in %d: ", yr);
		if (days % 7 == 5)
		{
			count++;
			printf("%d.13  ", mon[i].num);
		}
		ctr++;
	}
}
