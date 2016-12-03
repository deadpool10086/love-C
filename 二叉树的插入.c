#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Jiedian
{
	int data;
	struct Jiedian*next;
	struct Jiedian*right;
}Jiedian;

Jiedian *duilie[20];
int s=0,e=0;
Jiedian *zhan[20];
int zd=0;

void cengcibl(Jiedian*p);
void add(Jiedian*p);
void del(Jiedian**p);
void charu(Jiedian **p,int n);
void bianli(Jiedian *p);
void cengsgu(Jiedian *p);


int main(int argc, char *argv[]) {
	int i;
	srand(time(NULL));
	Jiedian *root=NULL;
	for(i=0;i<20;i++)
		charu(&root,rand());
    bianli(root);
    printf("\n");
	cengcibl(root);
	i=cengshu(root);
	printf("%d\n",i);
	return 0;
	
}
void charu(Jiedian **p,int n)               //插入做的太垃圾了记得改进 
{
	while(1)
	{
		if(*p==NULL)
		{
			*p=malloc(sizeof(Jiedian));
			(*p)->data=n;
			(*p)->next=(*p)->right=NULL;
			break;
		}
		else
		{
			if(n>(*p)->data)
				p=&((*p)->right);
			else
				p=&((*p)->next);
		}
	}

}
void cengcibl(Jiedian*p)
{
	add(p);
	int flag=1;
	while(s!=e)
	{
		while(s!=flag)
		{
			del(&p);
			printf("%8d",p->data);
			if(p->next!=NULL)  add(p->next);
			if(p->right!=NULL) add(p->right);	
		}
		flag=e;
		printf("\n");
	}
	
}
void add(Jiedian *p)
{
	if(s-e==1||e-s==19)
	{
		printf("full\n");
		exit(0);
	}
	else
	{
		if(e!=19)
		duilie[e++]=p;
		else
		{
			duilie[e]=p;
			e=0;
		}
	}
}
void del(Jiedian**p)
{
	if(s!=19)
	 *p=duilie[s++];
	else
	{
		*p=duilie[s];
		s=0;
	}
}
void bianli(Jiedian*p)
{
	int n=0;
	while(zd!=0||p!=NULL)
	{
		while(p!=NULL)
		{
			zhan[zd++]=p;
			p=p->next;
		}
		if(zd!=0)
		{
			p=zhan[--zd];
			printf("%8d",p->data);
			n++;
			if(n%5==0)
			printf("\n");
			p=p->right;
		}
	}
}
int cengshu(Jiedian *p)
{
	int h1,h2;
	if(p==NULL)
		return 0;
	else
		{
			h1=cengshu(p->next);
			h2=cengshu(p->right);
			if(h1>h2)
				return h1+1;
			else
				return h2+1;
		}
}
