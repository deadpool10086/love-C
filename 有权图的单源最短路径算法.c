#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
#define FAR 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct Enode
{
	int v1,v2;
	int weight;
}bian;

typedef struct Graph
{
	int nv;
	int ne;
	int graph[MAXNUM][MAXNUM];
	int vertdata[MAXNUM];
}tu;

void initialize(tu *p);
void insert(tu *p,bian *temp);
void Dijkstra(tu *p,int dist[],int path[],int star);
int findmindist(tu p,int dist[],int collected[]);

int main(int argc, char *argv[]) {
	int i,*dist,*path;
	tu *data;
	data=(tu *)malloc(sizeof(tu));
	scanf("%d %d",&data->nv,&data->ne);
	dist=(int *)malloc(sizeof(int)*data->nv);
	path=(int *)malloc(sizeof(int)*data->nv);
	initialize(data);
	bian *temp;
	temp=(bian*)malloc(sizeof(bian));
	for(i=0;i<data->ne;i++)
	{
		scanf("%d %d %d",&temp->v1,&temp->v2,&temp->weight);
		insert(data,temp);
	}
	free(temp);
	scanf("%d",&i);
	Dijkstra(data,dist,path,i);
	for(i=0;i<data->nv;i++)
	{
		printf("%d %d \n",i,dist[i]);
	}
	return 0;
}

void initialize(tu *p)
{
	int i,j;
	for(i=0;i<p->nv;i++)
	{
		p->vertdata[i]=0;
		for(j=0;j<p->nv;j++)
		p->graph[i][j]=FAR;
	}
}

void insert(tu *p,bian *temp)
{
	p->graph[temp->v1][temp->v2]=temp->weight;
}

void Dijkstra(tu *p,int dist[],int path[],int star)
{
	int collected[MAXNUM];
	int i,v;
	for(i=0;i<p->nv;i++)
	{
		collected[i]=0;
		dist[i]=p->graph[star][i];
		path[i]=-1;
	}
	dist[star]=0;
	while(1)
	{
		v=findminxdist(p,dist,collected);
		if(v==-1)
		break;
		collected[v]=1;
		for(i=0;i<p->nv;i++)
		{
			if(p->graph[v][i]<FAR&&collected[i]==0)
			{
				if(p->graph[v][i]<0)
				exit(0);
				if(dist[v]+p->graph[v][i]<dist[i])
				{
					dist[i]=dist[v]+p->graph[v][i];
					path[i]=v;
				}
			}
		}
	}
	return;
}

int findminxdist(tu *p,int dist[],int collected[])
{
	int min=FAR;
	int i,v;
	for(i=0;i<p->nv;i++)
	{
		if(collected[i]==0&&dist[i]<min)
		{
			v=i;
			min=dist[i];
		}
	}
	if(min<FAR)
	return v;
	else
	return -1;
}
