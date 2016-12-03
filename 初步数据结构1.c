#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Polynomial*polp;
struct Polynomial
{
	float constant;
	float index;
	polp next;
};
int n=0;
polp scan()
{
	polp head,p1,p2;
	p1=p2=(polp)malloc(sizeof(struct Polynomial));
	printf("Please input your information as \"constant,index\"\n");
	scanf("%f,%f",&p1->constant,&p1->index);
	if(p1->constant==0)
	head=NULL;
	else
	head=p1;
	while(p1->constant!=0)
	{
		n++;
		p1=(polp)malloc(sizeof(struct Polynomial));
		p2->next=p1;
		scanf("%f,%f",&p1->constant,&p1->index);
	}
	p2=NULL;
	free(p1);
	return head;
}
int main(int argc, char *argv[]) {
	void print(polp p);
	void search(polp p);
	polp del(polp p);
	polp insert(polp p);
	polp p;
	p=scan();
	int m;
	printf("The polynomial has %d xiang",n);
	do
	{
		printf("what do you want <1>print <2>search <3>delete <4>insert <0>quit\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1:print(p);
			case 2:search(p);
			case 3:p=del(p);
			case 4:p=insert(p);
		}
	}while(m!=0);
 	return 0;
}
void print(polp p)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%-7.2f,%-5.0f",p->constant,p->index);
		p=p->next;
	}
}
int input()
{
	int i;
	printf("Please input whitch one do you want:");
	scanf("%d",&i);
	while(i>n)
	{
		printf("error\n");
		scanf("%d",&i);
	}
	return i;
}
void search(polp p)
{
	int i,j;
	i=input();
	for(j=1;j<i;j++)
	p=p->next;
	printf("%-7.2f,%-5.0f",p->constant,p->index);
}
polp del(polp p)
{
	int i,j;
	i=input();
	polp temp;
	if(i==1)
	{
		temp=p;
		p=p->next;
	}
	else if(i==n)
	{
		temp=p;
		for(j=1;j<i-1;j++)
		temp=temp->next;
	}
	else
	{
		temp=p;
		for(j=1;j<i-1;j++)
		temp=temp->next;
		polp temp1;
		temp1=temp->next;
		temp->next=temp1->next;
		temp=temp1;
	}
	free(temp);
	n=n-1;
	return p;
}
polp insert(polp p)
{
	printf("please input whitch one do you want insert in it\'s behind:");
	int i,j;
	scanf("%d",&i);
	while(i>=n)
	{
		printf("error\n");
		scanf("%d",&i);
	}
	polp zanshi,temp=p,temp1;
	zanshi=(polp)malloc(sizeof(struct Polynomial));
	printf("Please input your information as \"constant,index\"\n");
	scanf("%f,%f",&zanshi->constant,&zanshi->index);
	if(i==0)
	{
		zanshi->next=p;
		p=zanshi;
	}
	else if(i==n)
	{
		for(j=1;j<i;j++)
		temp=temp->next;
		temp->next=zanshi;
		zanshi->next=NULL;
	}
	else
	{
		for(j=1;j<i;j++)
		temp=temp->next;
		temp1=temp;
		temp->next=zanshi;
		zanshi->next=temp1;
	}
	n=n+1;
	return p;
}
