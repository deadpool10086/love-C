#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Jiedian
{
	int data;
	Jiedian*next;
	Jiedian*right;
}Jiedian;

Jiedian *zhan[20];
int zd=0;

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
}

