#include <stdio.h>
#include <stdlib.h>

struct Student
{
	int studentNum;
	char studentName[20];
	char className[10];	
	struct Student *next; 
};

		

int main()
{
	int i;
	struct Student *head = NULL;
	struct Student *temp = NULL;
	struct Student *p = NULL;
	
	head = (struct Student *)malloc(sizeof(struct Student));
	head->studentNum=0;
	head->next=NULL; 

	
	for (i=0; i<10; i++)
	{
		temp = (struct Student *)malloc(sizeof(struct Student)); 
		printf("������ѧ�ţ��������༶:");
		scanf("%d%s%s",&temp->studentNum,temp->studentName,temp->className);
		temp -> next = head->next;
		head->next= temp;
	}
	
	p = head->next;
	for (i=0; i<10; i++)
	{
		printf("ѧ�ţ�%d,������%s,�༶��%s\n",p->studentNum,p->studentName,p->className); 
		p = p->next;
	}
	
	return 0;
 } 
