#include <stdio.h>
#include <stdlib.h>
#define FAR 2000000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Enode zbian;
typedef struct Vnode dingdian;
typedef struct Edge bian;
typedef struct Graph tu;


struct Enode
{
	int v1,v2;
	int distance,expense;
};

struct Vnode
{
	int data;
	struct Edge *head;
};

struct Edge
{
	struct Edge *next;
	int vertex;
	int distance,expense;
};

struct Graph
{
	int Vn;
	int En;
	struct Vnode *garph;	
};

void initialize(tu *p);
void insert(tu *p,zbian *dp);
void Dijkstra(tu *p,int s,int e);
int search(int **dist,int collected[],int Vn);

int main(int argc, char *argv[]) {
	int i,starcity,endcity;
	tu *data=NULL;
	data=(tu *)malloc(sizeof(tu));
	scanf("%d %d %d %d",&data->Vn,&data->En,&starcity,&endcity);
	initialize(data);
	zbian *temp=NULL;
	temp=(zbian *)malloc(sizeof(zbian));
	for(i=0;i<data->En;i++)
	{
		scanf("%d %d %d %d",&temp->v1,&temp->v2,&temp->distance,&temp->expense);
		insert(data,temp);
	}
	free(temp);

	Dijkstra(data,starcity,endcity);

	bian *shifang;
	for(i=0;i<data->Vn;i++)
	{
		while(data->garph[i].head!=NULL)
		{
			shifang=data->garph[i].head;
			data->garph[i].head=data->garph[i].head->next;
			free(shifang);
		}
	}
	free(data->garph);
	free(data);
	return 0;
}

void initialize(tu *p)
{
	p->garph=(dingdian *)malloc(p->Vn*sizeof(dingdian));
	int i;
	for(i=0;i<p->Vn;i++)
	{
		p->garph[i].data=0;
		p->garph[i].head=NULL;
	}
}
void insert(tu *p,zbian *dp)
{
	bian *cao=NULL;
	cao=(bian *)malloc(sizeof(bian));
	cao->vertex=dp->v2;
	cao->distance=dp->distance;
	cao->expense=dp->expense;
	cao->next=p->garph[dp->v1].head;
	p->garph[dp->v1].head=cao;
	cao=(bian *)malloc(sizeof(bian));
	cao->vertex=dp->v1;
	cao->distance=dp->distance;
	cao->expense=dp->expense;
	cao->next=p->garph[dp->v2].head;
	p->garph[dp->v2].head=cao;
	
}
void Dijkstra(tu *p,int s,int e)
{
	int v,i,**dist,*path=NULL,*collected;
	bian *sb=NULL;
	dist=(int **)malloc(p->Vn*sizeof(int*));
	path=(int*)malloc(sizeof(int)*p->Vn);
	collected=(int *)malloc(sizeof(int)*p->Vn);
	for(i=0;i<p->Vn;i++)
	{
		dist[i]=(int *)malloc(sizeof(int)*2);
		dist[i][0]=FAR;
		dist[i][1]=FAR;
		path[i]=-1;
		collected[i]=0;
	}
	dist[s][0]=0;
	dist[s][1]=0;
	v=search(dist,collected,p->Vn);
	while(v!=-1)
	{
		collected[v]=1;
		sb=p->garph[v].head;
		while(sb!=NULL)
		{
			if(sb->distance+dist[v][0]<dist[sb->vertex][0])
			{
				dist[sb->vertex][0]=sb->distance+dist[v][0];
				path[sb->vertex]=v;
				dist[sb->vertex][1]=sb->expense+dist[v][1];
			}
			else if(sb->distance+dist[v][0]==dist[sb->vertex][0])
			{
				if(sb->expense+dist[v][1]<dist[sb->vertex][1])
				{
					path[sb->vertex]=v;
					dist[sb->vertex][1]=sb->expense+dist[v][1];
				}
			}
			sb=sb->next;
		}
		v=search(dist,collected,p->Vn);
	}
	printf("%d %d",dist[e][0],dist[e][1]);
	free(path);
	free(dist);
}
int search(int **dist,int collected[],int Vn)   //查找一个费用最小的节点 
{
	int qian=FAR,juli=FAR,i,v=-1;
	for(i=0;i<Vn;i++)
	{
		if(collected[i]==0&&dist[i][0]<juli)
		{
			v=i;
			juli=dist[v][0];
			qian=dist[v][1];
		}
		else if(collected[i]==0&&dist[i][0]==juli)
		{
			if(dist[i][1]<qian)
			{
				v=i;
				juli=dist[v][0];
				qian=dist[v][1];
			}
		}
	}
	return v;
}
