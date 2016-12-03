#include <stdio.h>

struct Student
{
	int studentNum;
	char studentName[20];
	char className[10];	
};



int main()
{
	struct Student student1;
	printf("请输入学号，姓名，班级:");
	scanf("%d%s%s",&student1.studentNum,student1.studentName,student1.className);
	printf("学号：%d,姓名：%s,班级：%s\n",student1.studentNum,student1.studentName,student1.className); 
	return 0;
 } 
