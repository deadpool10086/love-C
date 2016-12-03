#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Student Stu;
struct Student
{
	int num;
	char name[20];
	int math;
	int english;
	int sport;
}students[5]={{1,"Tom",80,87,60},{2,"Mike",70,65,80},{3,"Angle",85,80,70},{4,"Bobo",60,85,90},{5,"Cook",90,60,60}};

void average(Stu*p); 
void search(int n);
void sort(Stu *p);
void highest(Stu *p);
int main(int argc, char *argv[]) {
	int i=0,n=-1;
	for(i=0;i<5;i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\n",students[i].num,students[i].name,students[i].math,students[i].english,students[i].sport);
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%d.\t",i+1);
		average(students+i); 
	}
	printf("\n请入一个查找的学号：");
	scanf("%d",&n);
	search(n);
	sort(students);
	printf("\n");
	highest(students);
	return 0;
}

void search(int n)
{
	int i=0;
	for(i=0;i<5;i++)
	{
		if(students[i].num==n)
		{
			printf("%d\t%s\t%d\t%d\t%d\n\n",students[i].num,students[i].name,students[i].math,students[i].english,students[i].sport);
			return;
		}
	}
	printf("没有该学生\n");
	return;
}
void average(Stu *p)
{
	int sum=0;
	sum+=p->math;
	sum+=p->sport;
	sum+=p->english;
	printf("%f\t",(double)sum/3);
}
void sort(Stu *p)
{
	int i=0,j=0;
	Stu temp;
	for(i=1;i<5;i++)
	{
		temp=p[i];
		for(j=i;j>0;j--)
		{
			if(strcmp(temp.name,p[j-1].name)>0)
			break;
			p[j]=p[j-1];
		}
		p[j]=temp;
	}
	for(i=0;i<5;i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\n",students[i].num,students[i].name,students[i].math,students[i].english,students[i].sport);
	}
}
void highest(Stu *p)
{
	int i,heng=0,hmat=0,hspo=0;
	for(i=0;i<5;i++)
	{
		if(p[i].english>heng)
		heng=p[i].english;
		if(p[i].math>hmat)
		hmat=p[i].math;
		if(p[i].sport>hspo)
		hspo=p[i].sport;
	}
	printf("highest:math:%d  english:%d  sport:%d\n",hmat,heng,hspo);
}
