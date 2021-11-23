#include<stdio.h>
#include<stdlib.h>
int isLeap(int year);
int daysInMonth(int year, int month);
int isLegal(int date[]);
void dateInput(int date[]);
//int can_be_compared(int date1[],int date2[]);
int dateSince2010(int date[]);

int main()
{
	int date1[3], date2[3],days;
	printf("请输入今天的日期：年.月.日\n");
	dateInput(date1);
	printf("请输入下次生日的日期：年.月.日\n");
	dateInput(date2);
	days = dateSince2010(date2) - dateSince2010(date1);
	if (days > 0)
		printf("距离下一次生日还有%d天\n", days);
	else printf("输入有误！");
	system("pause");
	return 0;
}

int isLeap(int year)
{
	if (year%100==0)
	{
		if (year%400==0) return 1;
		else return 0;
	}
	if (year%4==0) return 1;
	return 0;
}

int daysInMonth(int year, int month)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if (isLeap(year)) return 29;
		else return 28;
	}
	else return 31;
}

int isLegal(int date[])
{
	if (date[1] > 0 && date[1] < 13 && date[2]>0 && date[2] <= daysInMonth(date[0], date[1]))
		return 1;
	return 0;
}

void dateInput(int date[])
{
	scanf("%d.%d.%d", &date[0], &date[1], &date[2]);
	while (!isLegal(date))
	{
		printf("请重新输入：\n");
		scanf("%d.%d.%d", &date[0], &date[1], &date[2]);
	}
}

int dateSince2010(int date[])
{
	int i,days=0;
	for (i = 2010; i < date[0]; i++)
		if (isLeap(i)) days += 1;
	for (i = 1; i < date[1]; i++)
		days += daysInMonth(date[0], i);
	days += 365 * (date[0] - 2010) + date[2] - 1;
	return days;
}