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
	printf("������ѧ�ţ��������༶:");
	scanf("%d%s%s",&student1.studentNum,student1.studentName,student1.className);
	printf("ѧ�ţ�%d,������%s,�༶��%s\n",student1.studentNum,student1.studentName,student1.className); 
	return 0;
 } 
