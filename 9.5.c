#include <stdio.h>
#include <stdlib.h>
#define N 2

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Student
{
	int num;
	char name[20];
	float score[3];
}student[N];
int main(int argc, char *argv[]) {
	void print();
	int i;
	for(i=0;i<N;i++)
	{
		printf("please input NO:");
		scanf("%d",&student[i].num);
		printf("please input name:");
		scanf("%s",student[i].name);
		printf("please input math score:");
		scanf("%f",student[i].score);
		printf("please input english score:");
		scanf("%f",student[i].score+1);
		printf("please input chinese score:");
		scanf("%f",student[i].score+2);
	}
	print();
	return 0;
}                     
void print()
{
	int i,k,j;
	float ave=0,max=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<3;j++)
		{
			ave=ave+*(student[i].score+j);
			if(*(student[i].score+j)>max)
			k=i,max=*(student[i].score+j);
		}
	}
	ave=ave/N/3;
	printf("the average is %f\n",ave);
	printf("the highest score is the student\nNum:%d\nName:%s\nMath score:%f\nEnglishi score:%f\nChinese score:%f\n",
	student[k].num,student[k].name,*(student[k].score),*(student[k].score+1),*(student[k].score+2));
}
