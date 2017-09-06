#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
#define FAR 3000000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Enode
{
	int v1,v2;
	int weight;
}bian;

typedef struct Graph
{
	int En;
	int Vn;
	int graphedge[MAXNUM][MAXNUM];
}tu;

void initilaze(tu *p);
void insert(tu *p,bian *dp);
void prim(tu *p);

int main(int argc, char *argv[]) {
	int i;
	tu *data=NULL;
	data=(tu *)malloc(sizeof(tu));
	scanf("%d %d",&data->Vn,&data->En);
	initilaze(data);
	bian *temp=NULL;
	temp=(bian *)malloc(sizeof(bian));
	for(i=0;i<data->En;i++)
	{
		scanf("%d %d %d",&temp->v1,&temp->v2,&temp->weight);
		insert(data,temp);
	}
	free(temp);
	prim(data); 
	return 0;
}

void initilaze(tu *p)
{
	int i,j;
	p->Vn++;
	for(i=0;i<p->Vn;i++)
		for(j=0;j<p->Vn;j++)
			p->graphedge[i][j]=FAR;
}
void insert(tu *p,bian *dp)
{
	p->graphedge[dp->v1][dp->v2]=dp->weight;
	p->graphedge[dp->v2][dp->v1]=dp->weight;
}
void prim(tu *p)
{
	int parent[MAXNUM],dist[MAXNUM];
	int i,v,min;
	for(i=0;i<p->Vn;i++)
	{
		parent[i]=-1;
		dist[i]=FAR;
	}
	dist[1]=0;
	while(1)
	{
		min=FAR;
		for(i=1;i<p->Vn;i++)
		if(min>dist[i])
		{
			v=i;
			min=dist[i];
		}
		if(min==FAR)
		break;
		dist[v]=FAR+1;
		for(i=0;i<p->Vn;i++)
		{
			if(dist[i]==FAR+1)
			continue;
			if(dist[i]>p->graphedge[v][i])
			{
				dist[i]=p->graphedge[v][i];
				parent[i]=v;
			}
		}
	}
	for(v=0,i=2;i<p->Vn;i++)
	{
		if(dist[i]==FAR)
		{
			printf("-1");
			return;
		}
		v+=p->graphedge[i][parent[i]];
	}
	printf("%d ",v);
}
