#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"

int main()
{
	Student stu[STUDENT_COUNT];
	int menuitem;
	//int i ;
	system("cls");	 
	ReadData(stu, STUDENT_COUNT);
	for(int j=0;j<STUDENT_COUNT;j++)
	{
		stu[j].sum = Sum(stu[j]);
	}

	while(1)
	{
		menuitem = Menu();

		switch(menuitem)
		{
		case SUM_SORT:
		{
			Sort(stu, STUDENT_COUNT, 3);
			ShowInfo(stu, STUDENT_COUNT);
		}; break;

		case MATH_SORT:
		{
			Sort(stu, STUDENT_COUNT, 0);
			ShowInfo(stu, STUDENT_COUNT);
		}; break;

		case ENGLISH_SORT:
		{
			Sort(stu, STUDENT_COUNT, 1);
			ShowInfo(stu, STUDENT_COUNT);
		}; break;

		case COMPUTER_SORT:
		{
			Sort(stu, STUDENT_COUNT, 2);
			ShowInfo(stu, STUDENT_COUNT);
		}; break;

		case MATH_STATISTICS:
		{
			printf("数学不及格的人有%d个\n", Statistics(stu, 0));
			system("pause");
		}; break;

		case ENGLISH_STATISTICS:
		{
			printf("英语不及格的人有%d个\n", Statistics(stu, 1));
			system("pause");
		}; break;

		case COMPUTER_STATISTICS:
		{
			printf("计算机不及格的人有%d个\n", Statistics(stu, 2));
			system("pause");
		}; break;

		case SEARCH:

		{
			int studentId;
			printf("请输入学号：");
			scanf("%d", &studentId);
			Student* goal = stu;
			if (Search(stu, STUDENT_COUNT, studentId, goal))
			{
				printf("姓名:%s 学号:%d\t", goal->name, goal->id);
				printf("数学:%d 英语:%d 计算机:%d 总分%d\n", goal->score[0], goal->score[1], goal->score[2], goal->score[3]);
				system("pause");
			}
			else
			{
				printf("没有查到这个人...");
				system("pause");
			}
		}; break;

		}
	}
}


/************************************************************************************************/
//Sort function
//功能：排序
//参数：Student stu[]
//		int count：要排序的学生数目
//		int lessonId：要排序的课程编号
//				数学:MATH_SORT; 英语:ENGLISH_SORT;计算机:COMPUTER_SORT;总分:SUM_SORT
/************************************************************************************************/
void Sort(Student stu[] , int count , int lessonId)
{
	int i,j;
	if (lessonId == 3)
	{
		for (j = 1; j < count; j++)
		{
			for (i = 0;j<i&&i<count; i++)
			{
				if (stu[i-1].sum < stu[i].sum)
					swap(&stu[i], &stu[i + 1]);
			}
		}
	}
	else
	{
		for (j = 1; j < count; j++)
		{
			for (i = 0; i < count - j; i++)
			{
				if (stu[i].score[lessonId] < stu[i + 1].score[lessonId])
					swap(&stu[i], &stu[i + 1]);
			}
		}
	}
}

/************************************************************************************************/
//功能：按学号搜索学生
//参数：Student stu[]:学生 
//		int count：学生数目
//		int studentId：要搜索的学号
//		Student * student: 搜索到的学生
//返回值：如果搜索到的学生返回1，否则返回0
/************************************************************************************************/
int Search(Student stu[] , int count, int studentId, Student * student)
{
	int low = 0, high = STUDENT_COUNT,mid;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (stu[mid].id == studentId)
		{
			*student = stu[mid];
			return 1;
		}
		else if (stu[mid].id > studentId) high = mid - 1;
		else low = mid + 1;
	}
	if (low > high) return 0;
}

/************************************************************************************************/
//功能：计算所有课程的总分
//参数：Student stu[]
//		int count：学生数目
//返回值：总分
/************************************************************************************************/
int Sum(Student stu)
{
	int sum=0;
	sum = stu.score[0] + stu.score[1] + stu.score[2];
	return sum;
	
}


/************************************************************************************************/
//功能：统计不及格人数
//参数：int score[]:学生所有的课程成绩
//		int n: 学生人数 
//返回值：不及格人数
/************************************************************************************************/
int Statistics(Student stu[],int lessonId )
{
	int count = 0;
	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		if (stu[i].score[lessonId] < 60)
			count += 1;
	}
	return count;
}

/************************************************************************************************/
//功能：显示学生信息
//参数：Student stu[]
//		int count：学生数目
//返回值：无
/************************************************************************************************/
void ShowInfo(Student stu[] , int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("姓名;%s\t",stu[i].name);
		printf("学号:%d\t", stu[i].id);
		printf("数学:%d 英语:%d 计算机:%d 总分:%d\n", stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].sum);
	}
	system("pause");
}

void swap(Student* s1, Student* s2)
{
	Student s=*s1;
	*s1 = *s2;
	*s2 = s;
}
//#include "ReadData.C"
void ReadData(Student stu[], int count)
{
	FILE* fp;
	int i;
	char ch[10];
	if ((fp = fopen("Score.dat", "r")) == NULL)
	{
		printf("\tCan't open the file: Score.dat.\n\tPress AnyKey to Exit... ");
		getch();
		exit(0);
	}

	fscanf(fp, "%s%s%s%s%s", ch, ch, ch, ch, ch);

	for (i = 0; i < count; i++)
		fscanf(fp, "%d%s%d%d%d", &stu[i].id, stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
}

//#include "Menu.C" 
int Menu()
{
	int menuitem;
	int item;
	while (1)
	{
		menuitem = -1;
		item = -1;
		while (menuitem != 1 && menuitem != 2 && menuitem != 3)
		{
			system("cls");	//清屏 
			printf("\n\t\t   主功能菜单\n");
			printf("\t\t***********************\n");
			printf("\n\t\t1. 成绩排序\n");
			printf("\t\t2. 不及格成绩统计\n");
			printf("\t\t3. 查找\n");
			printf("\t\t0. 退出\n\n");
			printf("\t\t***********************\n");
			printf("\t\t请选择(0-3):");
			scanf("%d", &menuitem);
			if (menuitem == 0)
			{
				printf("按回车键继续...");
				getchar();
				getchar();
				exit(0);
			}
		}
		switch (menuitem)
		{
		case 1:
		{
			while (item != 1 && item != 2 && item != 3 && item != 4)
			{
				system("cls");	//清屏 
				printf("\n\t\t  请选择排序方式\n");
				printf("\t\t***********************\n");
				printf("\n\t\t1. 按数学成绩排序\n");
				printf("\t\t2. 按英语成绩排序\n");
				printf("\t\t3. 按计算机成绩排序\n");
				printf("\t\t4. 按总分排序\n");
				printf("\t\t0. 返回\n");
				printf("\t\t***********************\n");
				printf("\t\t请选择(0-4):");
				scanf("%d", &item);
				if (item == 0) break;
			}

			switch (item)
			{
			case 1:
				return MATH_SORT; break;
			case 2:
				return ENGLISH_SORT; break;
			case 3:
				return COMPUTER_SORT; break;
			case 4:
				return SUM_SORT; break;
			};
			break;
		}
		case 2:
		{
			while (item != 1 && item != 2 && item != 3 && item != 4)
			{
				system("cls");	//清屏 
				printf("\n\t\t  统计功能选择\n");
				printf("\t\t***********************\n");
				printf("\n\t\t1. 统计数学成绩\n");
				printf("\t\t2. 统计英语成绩\n");
				printf("\t\t3. 统计计算机成绩\n");
				printf("\t\t0. 返回\n\n");
				printf("\t\t***********************\n");
				printf("\t\t请选择(0-4):");
				scanf("%d", &item);
				if (item == 0) break;
			}

			switch (item)
			{
			case 1:
				return MATH_STATISTICS; break;
			case 2:
				return ENGLISH_STATISTICS; break;
			case 3:
				return COMPUTER_STATISTICS; break;
			case 4:
				return SUM_STATISTICS; break;
			};
			break;
		}
		case 3:
		{
			return SEARCH;
		}; break;
		}
	}
}

