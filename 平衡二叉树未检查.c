#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Shu
{
	int num;
	struct Shu *lef;
	struct Shu *rig;
}shu;

typedef struct Huan            //建立一个环 
{
	shu **data;
	struct Huan *next;
}huan;
huan *hp; 
shu *duilie[20];
int s=0,e=0;

void insert(shu **p,int n);
void build(shu **p,int n);
void llspin(shu **p);
void lrspin(shu **p);
void rrspin(shu **p);
void rlspin(shu **p);
void push(shu **p);
int hight(shu *p);
void bianli(shu *p);
void add(shu *p);
void del(shu **p);

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	int i,n;
	hp=(huan *)malloc(sizeof(huan));                    //环结构 
	hp->data=NULL;
	hp->next=(huan *)malloc(sizeof(huan));
	hp->next->data=NULL;
	hp->next->next=(huan *)malloc(sizeof(huan));
	hp->next->next->data=NULL;
	hp->next->next->next=hp;
	shu *root=NULL;
	for(i=0;i<20;i++)
	{
		n=rand();
		insert(&root,n);
	}
	printf("%d",hight(root));
	bianli(root);
	getchar();
	return 0;
}

void insert(shu **p,int n)
{
	int a,b;
	if(*p==NULL)
	{build(p,n); return;}
	while(1)					//实现数据的插入 
	{
		if(n<(*p)->num)
		{
			push(p);
			p=&(*p)->lef;
		}
		else if(n>(*p)->num)
		{
			push(p);
			p=&(*p)->rig;
		}
		if(*p==NULL)
		break;
	}
	build(p,n);
	p=hp->data;
	
	if(p==NULL)
	return;	
	shu *test;
	test=*p;
	test=test->lef;
	a=hight(test);
	b=hight((*p)->rig);				//  进行调整； 
	if(a-b==2)                   //进行判定旋转方式 
	{
		if(hight((*p)->lef->lef)>hight((*p)->lef->rig))
		llspin(p);
		else if(hight((*p)->lef->rig)>hight((*p)->lef->lef))
		lrspin(p);
	}
	else if(b-a==2)
	{
		if(hight((*p)->rig->rig)>hight((*p)->rig->lef))
		rrspin(p);
		else if(hight((*p)->rig->lef)>hight((*p)->rig->rig))
		rlspin(p);
	}
}
void build(shu **p,int n)
{
	*p=(shu *)malloc(sizeof(shu));
	(*p)->num=n;
	(*p)->rig=NULL;(*p)->lef=NULL;
}
void llspin(shu **p)
{
	shu *temp;
	temp=*p; 
	*p=(*p)->lef;
	temp->lef=(*p)->rig;
	(*p)->rig=temp;
}
void lrspin(shu **p)
{
	shu *t1,*t2;
	t1=*p;
	*p=(*p)->lef->rig;
	t2=(*p)->lef;
	(*p)->lef=t1->lef;
	t1->lef->rig=t2;
	t2=(*p)->rig;
	(*p)->rig=t1;
	t1->lef=t2;
}
void push(shu **p)
{
	hp->data=p;
	hp=hp->next;
}
void rrspin(shu **p)
{
	shu *temp;
	temp=*p;
	*p=(*p)->rig;
	temp->rig=(*p)->lef;
	(*p)->lef=temp;
}
void rlspin(shu **p)
{
	shu *t1,*t2;
	t1=*p;
	*p=(*p)->rig->lef;
	t2=(*p)->rig;
	(*p)->rig=t1->rig;
	t1->rig->lef=t2;
	t2=(*p)->lef;
	(*p)->lef=t1;
	t1->rig=t2;
}
int hight(shu *p)
{
	int n,m;
	if(p==NULL)
	return 0;
	n=hight(p->lef);
	m=hight(p->rig);
	if(m>n)
	n=m;
	return n+1;
}
void bianli(shu *p)
{
	if(p==NULL)
	{
		printf("empty");
		return;
	}
	add(p);
	int i=0,n=1;
	while(s!=e)
	{
		del(&p);
		printf("%8d",p->num);
		i++;
		if(i==n)
		{
			printf("\n");
			n=2*n+1;
		}
		if(p->lef!=NULL)  add(p->lef);
		if(p->rig!=NULL)  add(p->rig);
	}
}
void add(shu *p)
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
void del(shu**p)						//并没有关于队列空的处理，因为已经加到前面的while循环中； 
{
	if(s==19)
	{
		*p=duilie[s];
		s=0;
	}
	else
		*p=duilie[s++];
}

