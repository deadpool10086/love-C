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
	
	printf("请输入学号，姓名，班级:");
	scanf("%d%s%s",&p->studentNum,p->studentName,p->className);
} 


int search(struct Student *p)
{
	char a[20];
	printf("请输入查询的学生姓名："); 
	scanf("%s",a);
	
	p = p->next;
	
	while(p != NULL)
	{
		if(strcmp(a,p->studentName) == 0)
			break;
		else
			p = p->next;
	}
	if (p == NULL)
	{
		printf("没有该学生");
	} 
	else
	{
		printf("学号   姓名   班级  \n");
		printf("%-6d %-6s %-6s\n",p->studentNum,p->studentName,p->className);
	}
}

int delStudent(struct Student *p)
{
	int a; 
	struct Student* p1;
	p1 = p->next;
	
	printf("请输入要删除的学号:");
	scanf("%d",&a);
	while(p1 != NULL && p1->studentNum != a)
	{
		p = p->next;
		p1 = p1->next;
	}
	
	if(p1 != NULL)
	{
		p->next = p1->next;
		free(p1);
	}
	
}

int write(struct Student *p)
{
	FILE *fp;
	fp = fopen("data.txt","w");
	p = p->next;
	while (p != NULL)
	{
		fwrite(p,sizeof(struct Student),1,fp);
		p = p->next;
	} 
	fclose(fp);
}

int read(struct Student *p)
{
	FILE *fp;
	fp = fopen("data.txt","r");
	while(1)
	{
		p->next=(struct Student*)malloc(sizeof(struct Student));
		if(fread(p->next,sizeof(struct Student),1,fp) != 1)
			{break;}
		p = p->next;
	}
	p->next = NULL;
	fclose(fp);
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

	
	read(head);
	
	
	for (i=0; i<2; i++)
	{
		temp = (struct Student *)malloc(sizeof(struct Student)); 
		printf("请输入学号，姓名，班级:");
		scanf("%d%s%s",&temp->studentNum,temp->studentName,temp->className);
		temp -> next = head->next;
		head->next= temp;
	}
	
	addStudent(head); 
	search(head);
	delStudent(head);
	 
	printf("学号   姓名   班级  \n");
	
	p = head->next;
	while(p!=NULL)
	{
		printf("%-6d %-6s %-6s\n",p->studentNum,p->studentName,p->className); 
		p = p->next;
	}
	
	write(head); 
	
	return 0;
 } 
