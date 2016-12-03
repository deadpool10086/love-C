#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

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
	
	printf("������ѧ�ţ��������༶:");
	scanf("%d%s%s",&p->studentNum,p->studentName,p->className);
} 


int search(struct Student *p)
{
	char a[20];
	printf("�������ѯ��ѧ��������"); 
	scanf("%s",a);
	
	p=p->next;
	
	while(p != NULL)
	{
		if(strcmp(a,p->studentName) == 0)
			break;
		else
			p = p->next;
	}
	if (p == NULL)
	{
		printf("û�и�ѧ��");
	} 
	else
	{
		printf("ѧ��   ����   �༶  \n");
		printf("%-6d %-6s %-6s\n",p->studentNum,p->studentName,p->className);
	}
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
		printf("������ѧ�ţ��������༶:");
		scanf("%d%s%s",&temp->studentNum,temp->studentName,temp->className);
		temp -> next = head->next;
		head->next= temp;
	}
	
	addStudent(head); 
	search(head);
	
	printf("ѧ��   ����   �༶  \n");
	
	p = head->next;
	while(p!=NULL)
	{
		printf("%-6d %-6s %-6s\n",p->studentNum,p->studentName,p->className); 
		p = p->next;
	}
	
	return 0;
 } 
