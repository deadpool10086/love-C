#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE  1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Shu tree;
struct Shu{
	int *data;
	int size;
	int max;
};
void insert(tree *p,int n);
int del(tree *p);
void build(tree *p);
void percdm(tree *p,int s);
void jianli(tree **p);

int main(int argc, char *argv[]) {
	int i=0,n=0;
	srand((unsigned)time(NULL));
	tree *max=NULL;
	jianli(&max);
	for(i=0;i<19;i++){
		n=rand();
		max->data[++max->size]=n;
	}
	build(max);
	insert(max,8888);
	for(i=0;i<20;i++)
		printf("%d  %d\n",del(max),i);
	return 0;
}
void insert(tree *p,int n)
{
	int i;
	if(p->size>=MAXSIZE-1)
	{
		printf("full");
		return;
	}
	i=++p->size;
	for(;n>p->data[i/2];i=i/2)
		p->data[i]=p->data[i/2];
	p->data[i]=n;
}
int del(tree *p)
{
	if(p->size==0)
	{
		printf("empty");
		return;
	}
	int n=p->data[1],m;
	m=p->data[p->size--];
	int i=1,j;
	for(i=1;i*2<p->size;i=j)
	{
		j=2*i;
		if(j+1<=p->size&&p->data[j]<p->data[j+1])
			j++;
		if(m>p->data[j]) break;
		p->data[i]=p->data[j];
	}
	p->data[i]=m;
	return n;
}
void build(tree *p)
{
	int i;
	for(i=p->size;i>0;i--)
		percdm(p,i);
}
void percdm(tree *p,int s)
{
	int j,n;
	n=p->data[s];
	for(;s*2<=p->size;s=j)
	{
		j=2*s;
		if(j+1<=p->size&&p->data[j]<p->data[j+1])
		j++;
		if(n>p->data[j]) break;
		p->data[s]=p->data[j];
	}
	p->data[s]=n;
}
void jianli(tree **p)
{
	if(*p)
	{
		printf("existing");
		return;
	}
	*p=(tree *)malloc(sizeof(tree));
	(*p)->data=(int *)malloc(sizeof(int)*MAXSIZE);
	(*p)->data[0]=99999;
	(*p)->size=0;
	(*p)->max=MAXSIZE;
}
