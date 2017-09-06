#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Graph tu;
typedef struct Edge bian;
typedef struct Enode zbian;
typedef struct Vertex dingdian;
typedef struct Queue duilie;

struct Enode
{
	int v1,v2;
	int weight;
};

struct Edge
{
	int vertex;
	int weight;
	struct Edge *next;
};

struct Vertex
{
	int du;
	int fastest;
	struct Edge *star;
};

struct Graph
{
	int Vn;
	int En;
	dingdian *graph;
};

struct Queue
{
	dingdian *d[300];
	int star,end;
};

void initialize(tu *p);
void insert(tu *p,zbian *tp);
int tuopusuanfa(tu *p);

int main(int argc, char *argv[]) {
	int i;
	tu *data=NULL;
	data=(tu *)malloc(sizeof(tu));
	scanf("%d %d",&data->Vn,&data->En);
	initialize(data);
	zbian *temp=NULL;
	temp=(zbian *)malloc(sizeof(zbian));
	for(i=0;i<data->En;i++)
	{
		scanf("%d %d %d",&temp->v1,&temp->v2,&temp->weight);
		insert(data,temp);
	}
	free(temp);
	tuopusuanfa(data);
	free(data);
	return 0;
}

void initialize(tu *p)
{
	int i;
	p->graph=(dingdian *)malloc(p->Vn*sizeof(dingdian));
	for(i=0;i<p->Vn;i++)
	{
		p->graph[i].fastest=0;
		p->graph[i].du=0;
		p->graph[i].star=NULL;
	}
}
void insert(tu *p,zbian *tp)
{
	bian *ne=NULL; 
	ne=(bian *)malloc(sizeof(bian));
	ne->vertex=tp->v2;
	ne->weight=tp->weight;
	ne->next=p->graph[tp->v1].star;
	p->graph[tp->v1].star=ne;
	p->graph[tp->v2].du++;
}
int tuopusuanfa(tu *p)
{
	int i;
	dingdian data; 
	duilie *dp=NULL;
	dp=(duilie *)malloc(sizeof(duilie));
	dp->end=dp->star=0;
	for(i=0;i<p->Vn;i++)
	{
		if(p->graph[i].du==0)
		dp->d[dp->end++]=p->graph+i;
	}
	while(dp->star!=dp->end)
	{
		data=*(dp->d[dp->star++]);
		while(data.star!=NULL)
		{
			if(data.star->weight+data.fastest>p->graph[data.star->vertex].fastest)
			p->graph[data.star->vertex].fastest=data.star->weight+data.fastest;
			if(--p->graph[data.star->vertex].du==0)
			dp->d[dp->end++]=p->graph+data.star->vertex;
			data.star=data.star->next;
		}
	}
	if(dp->end-1!=p->Vn)
	{
		printf("Impossable");
		exit(0);
	}
	printf("%d",dp->d[dp->end-1]->fastest);
	free(dp);
}
