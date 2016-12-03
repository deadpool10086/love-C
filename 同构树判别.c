#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Tree
{
	char c,l,r,b;
}data1[10],data2[10];

int sum1,sum2;

int compare(int a,int b);
int search(struct Tree *p,int n);             //用来查找树的root节点。 

int main()
{
	int i,a,b;
	scanf("%d",&sum1);
	fflush(stdin);
	for(i=0;i<sum1;i++)
	{
		scanf("%c %c %c",&data1[i].c,&data1[i].r,&data1[i].l);
		data1[i].b=0;
		fflush(stdin);
	}
	printf("asdasd");
	scanf("%d",&sum2);
	fflush(stdin);
	for(i=0;i<sum2;i++)
	{
		scanf("%c %c %c",&data2[i].c,&data2[i].r,&data2[i].l);
		data2[i].b=0;
		fflush(stdin);
	}
	a=search(data1,sum1);
	b=search(data2,sum2);
	if(compare(a,b))
	printf("\nyes");
	else
	printf("\nno");
	return 0;
}
int search(struct Tree *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(p[i].l!='-')
		p[(int)p[i].l-48].b=1;
		if(p[i].r!='-')
		p[(int)p[i].r-48].b=1;
	}
	for(i=0;i<n;i++)
	{
		if(p[i].b==0)
		return i;
	}
}
int compare(int a,int b)
{
	if(data1[a].c==data2[b].c)
	{
		if(data1[a].l=='-'&&data1[a].r=='-')
		{
			if(data2[b].l=='-'&&data2[b].r=='-')
			return 1;
			else return 0;
		}
		else if(data1[a].l=='-')
		{
			if(data2[b].l=='-'&&data2[b].r=='-'||data2[b].l!='-'&&data2[b].r!='-')
			return 0;
			else if(data2[b].l=='-')
			return compare((int)data1[a].r-48,(int)data2[b].r-48);
			else 
			return compare((int)data1[a].r-48,(int)data2[b].l-48);
		}
		else if(data1[a].r=='-')
		{
			if(data2[b].l=='-'&&data2[b].r=='-'||data2[b].l!='-'&&data2[b].r!='-')
			return 0;
			else if(data2[b].l=='-')
			return compare((int)data1[a].l-48,(int)data2[b].r-48);
			else 
			return compare((int)data1[a].l-48,(int)data2[b].l-48);
		}
		else
		{
			if(data2[b].l=='-'||data2[b].r=='-')
			return 0;
			return compare((int)data1[a].l-48,(int)data2[b].l-48)&&compare((int)data1[a].r-48,(int)data2[b].r-48)||compare((int)data1[a].l-48,(int)data2[b].r-48)&&compare((int)data1[a].r-48,(int)data2[b].l-48);
		}
	}
	else
	return 0;
}
