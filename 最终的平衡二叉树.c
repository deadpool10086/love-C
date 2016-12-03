#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Jiedian *jpoi;
struct Jiedian
{
	int data;
	jpoi lef;
	jpoi rig;
	int height;
}; 
jpoi duilie[20];
int s=0,e=0;

jpoi insert(jpoi p,int a);
int max(int a,int b);
jpoi llspin(jpoi a);
jpoi lrspin(jpoi a);
jpoi rrspin(jpoi a);
jpoi rlspin(jpoi a);
void bianli(jpoi p);
void add(jpoi p);
void del(jpoi *p);

int main(int argc, char *argv[]) {
	int n,i;
	jpoi root=NULL;
	srand((unsigned)time(NULL));
	for(i=0;i<20;i++)
	{
		n=rand();
		root=insert(root,n);
	}
	bianli(root);
	return 0;
}
int max(int a,int b)
{
	if(a<b)
	a=b;
	return a;
}
jpoi insert(jpoi p,int a)
{
	if(!p)
	{
		p=(jpoi)malloc(sizeof(struct Jiedian));
		p->data=a;
		p->lef=p->rig=NULL;
		p->height=0;
	}
	else if(a<p->data)
	{
		p->lef=insert(p->lef,a);
		if(height(p->lef)-height(p->rig)==2)
			if(a<p->lef->data)
				p=llspin(p);
			else
				p=lrspin(p);
	}
	else if(a>p->data)
	{
		p->rig=insert(p->rig,a);
		if(height(p->rig)-height(p->lef)==2)
			if(a>p->rig->data)
				p=rrspin(p);
			else
				p=rlspin(p);
		
	}
	p->height=max(height(p->lef),height(p->rig))+1;
	return p;
}
jpoi llspin(jpoi a)
{
	jpoi b;
	b=a->lef;
	a->lef=b->rig;
	b->rig=a;
	a->height=max(height(a->lef),height(a->rig))+1;
	b->height=max(height(b->lef),height(a))+1;
	return b;
}
jpoi lrspin(jpoi a)
{
	a->lef=rrspin(a->lef);
	a=llspin(a);
	return a;
}
jpoi rrspin(jpoi a)
{
	jpoi b;
	b=a->rig;
	a->rig=b->lef;
	b->lef=a;
	a->height=max(height(a->rig),height(a->lef))+1;
	b->height=max(height(b->rig),height(a))+1;
	return b;
}
jpoi rlspin(jpoi a)
{
	a->rig=llspin(a->rig);
	a=rrspin(a);
	return a;
}
int height(jpoi p)
{
	if(!p)
	return 0;
	else 
	return p->height;
}
void bianli(jpoi p)
{
	int i=1,n=0;
	if(p==NULL)
	{
		printf("empty");
		return;
	}
	add(p);
	while(s!=e)
	{
		del(&p);
		printf("%8d",p->data);
		n++;
		if(n==i)
		{
			printf("\n");
			i=2*i+1;
		}
		if(p->lef!=NULL)  add(p->lef);
		if(p->rig!=NULL)  add(p->rig);
	}
}
void add(jpoi p)
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
void del(jpoi *p)						//并没有关于队列空的处理，因为已经加到前面的while循环中； 
{
	if(s==19)
	{
		*p=duilie[s];
		s=0;
	}
	else
		*p=duilie[s++];
}
