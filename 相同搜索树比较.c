#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Node node;

struct Node
{
	int d;
	node *left,*right;
	int flag;
};

void insert(node **p,int n)
{
	if(*p==NULL)
	{
		(*p)=(node *)malloc(sizeof(node));
		(*p)->d=n;
		(*p)->left=(*p)->right=NULL;
		(*p)->flag=0;
		return; 
	}
	else if(n>(*p)->d)
		insert(&(*p)->right,n);
	else 
		insert(&(*p)->left,n);
}	

int  compare(node *root,int n)
{
	node *p=root;
	int i,data;
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		while(p->d!=data)
		{
			if(p->flag==0)
			return 0;
			else if(data>p->d)
			p=p->right;
			else
			p=p->left;
		}
		p->flag=1;
		p=root;
	}
	return 1;
}

void freeflag(node *p)
{
	
	if(p==NULL)
	return;
	p->flag=0;
	freeflag(p->right);
	freeflag(p->left);
}

int main(int argc, char *argv[]) {
	int i,n,m,data;
	node *root=NULL,*root1=NULL;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		insert(&root,data);
	}
	for(i=0;i<m;i++)
	{
		if(compare(root,4))
			printf("yes");
		else
			printf("no");
		freeflag(root);
	}
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		insert(&root1,data);
	}
		for(i=0;i<m;i++)
	{
		if(compare(root1,4))
			printf("yes");
		else
			printf("no");
		freeflag(root1);
	}
	return 0;
}
