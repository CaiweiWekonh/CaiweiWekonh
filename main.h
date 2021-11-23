#ifndef _SCORE_H
#define _SCORE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


#define N				10
#define STUDENT_COUNT	50		//学生数
#define LESSON_COUNT	3		//课程数

#define SUM_SORT				0     	//按总分排序 
#define MATH_SORT				1		//按数学成绩排序 
#define ENGLISH_SORT			2		//按英语成绩总分排序 
#define COMPUTER_SORT			3		//按计算机成绩排序 
#define SUM_STATISTICS			4		// 统计总分 
#define MATH_STATISTICS			5		// 统计数学成绩
#define ENGLISH_STATISTICS		6		// 统计英语成绩
#define COMPUTER_STATISTICS		7		// 统计计算机成绩
#define SEARCH					8		// 查找

typedef struct _Student
{
	int 	id;						//学号
	char 	name[N];				//姓名
	int 	score[LESSON_COUNT];	//成绩
	int 	sum;					//总分
}Student;




//按课程成绩对学生进行排序
void Sort(Student *stu , int count , int lessonId);

//求所有课程的总分
int Sum(Student stu);

//按学号搜索某一名学生
int Search(Student stu[] , int count, int studentId, Student * student);

//统计某门课程的不及格人数
int Statistics(Student stu[] , int lessonId);

//显示信息
void ShowInfo(Student stu[] , int count);

//交换两个结构体变量
void swap(Student* s1, Student* s2);

//从文件读取数据 
void ReadData(Student stu[] , int count);

//显示菜单 
int Menu();
#endif
