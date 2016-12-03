#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Student
{
	int num;
	float score;
	struct Student *next;
};
int n;
int main(int argc, char *argv[])
 {
	struct Student *creat();
	struct Student *stu;
	stu=creat();
	printf("number score\n");
	while(stu!=NULL)
	{printf("%-6d %-4.2f\n",stu->num,stu->score);
	stu=stu->next;
	}
	return 0;
}
struct Student *creat()
{
	struct Student *head,*p1,*p2;
	n=0;
	p1=p2=(struct Student *)malloc(sizeof(struct Student));
	printf("please input \"number,score\"\n");
	scanf("%d,%f",&p1->num,&p1->score);
	head=NULL;
	while(p1->num!=0)
	{
		n++;
		if(n==1) head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct Student *)malloc(sizeof(struct Student));
		printf("please input \"number,score\"\n");
		scanf("%d,%f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return head;
}
