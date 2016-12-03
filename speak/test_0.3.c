#include <stdio.h>
#include <stdlib.h>

struct Student
{
	int studentNum;
	char studentName[20];
	char className[10];	
	struct Student *next; 
};

int addStudent(struct Student *p)
{
	while(p->next != NULL)
	{
		p = p->next; 
	}
	
	p->next = (struct Student *)malloc(sizeof(struct Student));
	p = p->next;
		p->next = NULL;
		
	printf("请输入学号，姓名，班级:");
	scanf("%d%s%s",&p->studentNum,p->studentName,p->className);
} 
	

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
		printf("请输入学号，姓名，班级:");
		scanf("%d%s%s",&temp->studentNum,temp->studentName,temp->className);
		temp -> next = head->next;
		head->next= temp;
	}
	
	addStudent(head); 
	
	p = head->next;
	while(p!=NULL)
	{
		printf("%-6d %-6s %-6s\n",p->studentNum,p->studentName,p->className); 
		p = p->next;
	}
	
	return 0;
 } 
