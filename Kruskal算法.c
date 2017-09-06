#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 40
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Edge bian;

struct Enode
{
	int v1,v2;
	int weight;
};

struct Edge
{
	bian *next;
	int weight;
	int zhixian;
};

struct vertex
{
	int data;
	bian *head;
};

typedef struct Graph
{
	int En;
	int Vn;
	struct vertex graph[MAXNUM];
}tu;

void initialize(tu *p);
void insert(tu *p,struct Enode *dp);
void paixu(struct Enode *p,int s);
void kruskal(tu *p,struct Enode *dui,int s);
struct Enode out(struct Enode *p,int *s);
int judgement(int *data,int v1,int v2);

int main(int argc, char *argv[]) {
	int i;
	tu *data=NULL;
	data=(tu *)malloc(sizeof(tu));
	scanf("%d %d",&data->Vn,&data->En);
	initialize(data);
	struct Enode *dui=NULL;
	dui=(struct Enode *)malloc((data->En+1)*sizeof(struct Enode));
	for(i=1;i<=data->En;i++)
	{
		scanf("%d %d %d",&dui[i].v1,&dui[i].v2,&dui[i].weight);
		insert(data,dui+i);
	}
	paixu(dui,data->En);
	kruskal(data,dui,data->Vn);
	free(dui);
	free(data);
	return 0;
}

void initialize(tu *p)
{
	int i;
	for(i=0;i<p->Vn;i++)
	{
		p->graph[i].data=0;
		p->graph[i].head=NULL;
	}
}
void insert(tu *p,struct Enode *dp)
{
	bian *b;
	b=(bian *)malloc(sizeof(bian));
	b->zhixian=dp->v2;
	b->weight=dp->weight;
	b->next=p->graph[dp->v1].head;
	p->graph[dp->v1].head=b;
	b=(bian *)malloc(sizeof(bian));
	b->weight=dp->weight;
	b->zhixian=dp->v1;
	b->next=p->graph[dp->v2].head;
	p->graph[dp->v2].head=NULL;
}
void paixu(struct Enode *p,int s)
{
	int i,parent,child;
	struct Enode temp;
	for(i=s/2;i>0;i--)
	{
		temp=p[i];
		for(parent=i;parent*2<=s;parent=child)
		{
			child=parent*2;
			if(child+1<=s&&p[child].weight>p[child+1].weight)
			child++;
			if(temp.weight>p[child].weight)
			p[parent]=p[child];
			else
			break;
		}
		p[parent]=temp;
	}
}
void kruskal(tu *p,struct Enode *dui,int s)
{
	int weight=0;
	int i,flag,edgesum=0;
	int assemble[MAXNUM];
	for(i=0;i<p->Vn;i++)
	assemble[i]=-1;
	struct Enode min;
	s=p->En;
	while(edgesum<p->Vn-1)
	{
		min=out(dui,&s);
		if(judgement(assemble,min.v1,min.v2))
		continue;
		else
		{
			edgesum++;
			weight+=min.weight;
		}
	}
	printf("%d\n",weight);
}
struct Enode out(struct Enode *p,int *s)
{
	if(s==0)
	{
		printf("error\n");
		exit(0);
	}
	struct Enode data,temp;
	int parent,child;
	data=p[1];
	temp=p[*s];
	(*s)--;
	for(parent=1;parent*2<=*s;parent=child)
	{
		child=parent*2;
		if(child+1<=*s&&p[child].weight>p[child+1].weight)
		child++;
		if(temp.weight>p[child].weight)
		p[parent]=p[child];
		else
		break;
	}
	p[parent]=temp;
	return data;
}
int judgement(int *data,int v1,int v2)
{
	int root1=v1,root2=v2;
	while(data[root1]!=-1)
	{
		root1=data[root1];
	}
	while(data[root2]!=-1)
	{
		root2=data[root2];
	}
	if(root1!=root2)
	{
		data[root2]=root1;
		return 0;
	}
	else
	return 1;
}
