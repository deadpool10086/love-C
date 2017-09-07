#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Jiedian
{
	int data;
	Jiedian*next;
	Jiedian*right;
}Jiedian;

int hightt(Jiedian *p);
int max(int h1,int h2);
void stuff(Jiedian**p,int n);
void bianli(Jiedian*p);
	
	
int main()
{

	int n=5;
	srand(time(NULL));
	Jiedian *root=NULL;
	stuff(&root,n);
	printf("%d\n",root->next->next->next->next->data);
	printf("%d\n",hightt(root)); 
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
int hightt(Jiedian *p)
{
	int h1,h2,ht;
	if(p==NULL)
	 return 0;
	else
	{
		h1=hightt(p->right);
		h2=hightt(p->next);
		ht=max(h1,h2);
		ht++;
		return ht;
	}
}
int max(int h1,int h2)
{
	if(h2>h1)
	h1=h2;
	return h1;
}
