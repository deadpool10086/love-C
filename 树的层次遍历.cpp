#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Jiedian
{
	int data;
	Jiedian*next;
	Jiedian*right;
}Jiedian;

void stuff(Jiedian**p,int n);
void bianli(Jiedian*p);
void add(Jiedian*p);
void del(Jiedian**p);
//Jiedian *zhan[20];
//int zd=0;
Jiedian *duilie[20];
int s=0,e=0;
int main()
{
	void stuff(Jiedian**p,int n);
	void bianli(Jiedian*p);
	int n=5;
	srand(time(NULL));
	Jiedian *root=NULL;
	stuff(&root,n);
	printf("%d\n",root->next->next->next->next->data);
	bianli(root);
	getchar();
	return 0;
}
void stuff(Jiedian**p,int n)
{
	*p=(Jiedian*)malloc(sizeof(Jiedian));
	(*p)->data=rand();
	if(--n)
	{
		stuff(&((*p)->next),n);
		stuff(&((*p)->right),n);
	}
	else
	{
		(*p)->next=NULL;
		(*p)->right=NULL;
	}
}
void bianli(Jiedian*p)
{
	if(p==NULL)
	{
		printf("empty");
		return;
	}
	add(p);
	while(s!=e)
	{
		del(&p);
		printf("%d\n",p->data);
		if(p->next!=NULL)  add(p->next);
		if(p->right!=NULL)  add(p->right);
	}
}
void add(Jiedian *p)
{
	if(e-s==18||s-e==1)
		{
			printf("full");
			exit(0);
		}
	else
	{
		if(e==19)
		{
			duilie[e]=p;
			e=0;
		}
		else
		duilie[e++]=p;
	}
}
void del(Jiedian**p)						//并没有关于队列空的处理，因为已经加到前面的while循环中； 
{
	if(s==19)
	{
		*p=duilie[s];
		s=0;
	}
	else
		*p=duilie[s++];
}
/*
void bianli(Jiedian*p)
{
	int sum=0;
	while(zd!=0||p!=NULL)
	{
		while(p!=NULL)
		{
			zhan[zd++]=p;
			p=p->next;
		}
		if(zd)
		{
			p=zhan[--zd];
			printf("%d\n",p->data);
			sum++;
			p=p->right;
		}

	}
	printf("%d",sum);
}*/
