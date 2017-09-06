#include <stdio.h>
#include <stdlib.h>
#define FAR 99999
struct Enode
{
	int v1,v2;
	int distance,expense;
};

struct Edge
{
	struct Edge *next;
	int vertex;
	int distance,expense;
}; 

struct Vnode
{
	int data;
	struct Edge *head;
};

struct  Graph
{
	int Vn,En;
	struct Vnode *graph; 
};

void initialize(struct  Graph* p);
void insert(struct  Graph* p,struct Enode *d);
void Dijkstra(struct  Graph* p,int s,int e);
int search(int **dist,int *collected,int Vn);

int main(int argc, char *argv[]) {
	int source,destination,i;
	struct  Graph *data;
	struct Enode *temp;
	temp=(struct Enode *)malloc(sizeof(struct Enode));
	data=(struct  Graph *)malloc(sizeof(struct  Graph));
	scanf("%d %d %d %d",&data->Vn,&data->En,&source,&destination);
	initialize(data);
	for(i=0;i<data->En;i++)
	{
		scanf("%d %d %d %d",&temp->v1,&temp->v2,&temp->distance,&temp->expense);
		insert(data,temp);
	}
	free(temp);
	Dijkstra(data,source,destination);
	return 0;
}
void initialize(struct  Graph* p)
{
	p->graph=(struct Vnode*)malloc(p->Vn*sizeof(struct Vnode));
	if(p->graph==NULL)
	{
		printf("\nerror\n");
		exit(0);
	}
	int i;
	for(i=0;i<p->Vn;i++)
	{
		p->graph[i].data=0;
		p->graph[i].head=NULL;
	}
}
void insert(struct  Graph* p,struct Enode *d)
{
	struct Edge *temp;
	temp=(struct Edge*)malloc(sizeof(struct Edge));
	temp->vertex=d->v2;
	temp->distance=d->distance;
	temp->expense=d->expense;
	temp->next=p->graph[d->v1].head;
	p->graph[d->v1].head=temp;
	temp=(struct Edge*)malloc(sizeof(struct Edge));
	temp->vertex=d->v1;
	temp->distance=d->distance;
	temp->expense=d->expense;
	temp->next=p->graph[d->v2].head;
	p->graph[d->v2].head=temp;	
}
void Dijkstra(struct  Graph* p,int s,int e)
{
	int **dist,*path,i,*collected,v;
	struct Edge *traverse;
	path=(int *)malloc(p->Vn*sizeof(int));
	dist=(int **)malloc(p->Vn*sizeof(int *));
	collected=(int *)malloc(p->Vn*sizeof(int));
	for(i=0;i<p->Vn;i++)
	{
		path[i]=-1;
		dist[i]=(int *)malloc(2*sizeof(int));
		dist[i][0]=FAR;
		dist[i][1]=FAR;
		collected[i]=0; 
	}
	dist[s][0]=0;
	dist[s][1]=0;
	v=search(dist,collected,p->Vn);
	while(v!=-1)
	{
		collected[v]=1;
		traverse=p->graph[v].head;
		while(traverse!=NULL)
		{
			if(traverse->distance + dist[v][0]<dist[traverse->vertex][0])
			{
				dist[traverse->vertex][0]=traverse->distance + dist[v][0];
				dist[traverse->vertex][1]=traverse->expense  + dist[v][1];
				path[traverse->vertex]=v;
			}
			else if(traverse->distance + dist[v][0]==dist[traverse->vertex][0])
			{
				if(traverse->expense  + dist[v][1]<dist[traverse->vertex][1])
				{
					path[traverse->vertex]=v;
					dist[traverse->vertex][1]=traverse->expense;
				}
			}
			traverse=traverse->next;
		}
		v=search(dist,collected,p->Vn);
	}
	printf("%d %d",dist[e][0],dist[e][1]);
}
int search(int **dist,int *collected, int Vn)
{
	int i,min,qian=FAR,juli=FAR;
	for(i=0,min=-1;i<Vn;i++)
	{
		if(dist[i][0]<juli&&collected[i]==0)
		{
			min=i;
			qian=dist[i][1];
			juli=dist[i][0];
		}
	}
	return min;
}
