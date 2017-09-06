#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20

typedef struct ENode Enode;
struct ENode
{
	int v;
	int weight;
	Enode *next;
};

struct hello
{
	int v1,v2;
	int height;
};

struct Vnode
{
	Enode *head;
	char data;
};

struct GRaph
{
	int esum;
	int vsum;
	struct Vnode av[MAXNUM];
};

void initialize(struct GRaph *p); 
void insert(struct GRaph *p,struct hello *temp);
void bfs(struct GRaph *p,int dist[],int path[],int vertex);
int main()
{
	int i;
	printf("hello world");
	struct GRaph *data;
	data=(struct GRaph *)malloc(sizeof(struct GRaph));
	initialize(data);
	scanf("%d %d",&data->vsum,&data->esum);
	struct hello *temp;
	temp=(struct hello *)malloc(sizeof(struct hello));
	for(i=0;i<data->esum;i++)
		{
			scanf("%d %d %d",&temp->v1,&temp->v2,&temp->height);
			insert(data,temp);
		}
	int dist[MAXNUM],path[MAXNUM];
	for(i=0;i<MAXNUM;i++)
	dist[i]=path[i]=-1;
	bfs(data,dist,path,2);
	for(i=0;i<data->vsum;i++)
	printf("%d",dist[i]);
	return 0;
}
void initialize(struct GRaph *p)
{
	int i;
	p->esum=p->vsum=0;
	for(i=0;i<MAXNUM;i++)
	{
		p->av[i].head=NULL;
		p->av[i].data=0;
	}
}
void insert(struct GRaph *p,struct hello *temp)
{
	Enode *xinde;
	
	xinde=malloc(sizeof(Enode));
	xinde->v=temp->v2;
	xinde->weight=temp->height;
	xinde->next=p->av[temp->v1].head;
	p->av[temp->v1].head=xinde;
}
void bfs(struct GRaph *p,int dist[],int path[],int vertex)
{
	int duilie[100];
	int s=0,e=0;
	int v;
	Enode *temp;
	duilie[e++]=vertex;
	dist[vertex]=0;
	while(s!=e)
	{
		v=duilie[s++];
		for(temp=p->av[v].head;temp;temp=temp->next)
		if(dist[temp->v]==-1)
		{
			dist[temp->v]=dist[v]+1;
			duilie[e++]=temp->v;
			path[temp->v]=v;
		}
	}
}
