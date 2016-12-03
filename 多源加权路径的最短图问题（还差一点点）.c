#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
#define FAR 1000000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Enode
{
	int v1,v2;
	int weight;
}edge;

typedef struct Graph
{
	int en;
	int vn;
	int graph[MAXNUM][MAXNUM];
	int vertex[MAXNUM];
}tu;

int intialize(tu *p);
int insert(tu *p,edge *temp);
int Floyd(tu *p,int d[MAXNUM][MAXNUM],int path[][MAXNUM]);
int judg(int d[MAXNUM][MAXNUM],int max);

int main(int argc, char *argv[]) {
	int i,j;
	tu *data=NULL;
	data=(tu *)malloc(sizeof(tu));
	scanf("%d %d",&data->vn,&data->en);
	intialize(data);
	edge *temp=NULL;
	temp=(edge *)malloc(sizeof(edge));
	for(i=0;i<data->en;i++)
	{
		scanf("%d %d %d",&temp->v1,&temp->v2,&temp->weight);
		insert(data,temp);
	}
	free(temp);
	int d[MAXNUM][MAXNUM],path[MAXNUM][MAXNUM];
	Floyd(data,d,path);
	judg(d,data->vn); 
	return 0;
}
int intialize(tu *p)
{
	if (p==NULL)
	return 1;
	int j,i;
	p->vn++;
	for(i=0;i<p->vn;i++)
	{
		p->vertex[i]=-1;
		for(j=0;j<p->vn;j++)
		{
			p->graph[i][j]=FAR;
		}
	}
	return 0;
}

int insert(tu *p,edge *temp)
{
	if(temp->v1>=p->vn||temp->v1<0)
	return 1;
	if(temp->v2>=p->vn||temp->v2<0)
	return 1;
	p->graph[temp->v1][temp->v2]=temp->weight;
	p->graph[temp->v2][temp->v1]=temp->weight;
	return 0;	
}

int Floyd(tu *p,int d[MAXNUM][MAXNUM],int path[][MAXNUM])
{
	int i,j,v;
	for(i=0;i<p->vn;i++)
	{
		for(j=0;j<p->vn;j++)
			{
				d[i][j]=p->graph[i][j];
				path[i][j]=-1;
			}
	}
		
	for(i=0;i<p->vn;i++)
	for(j=0;j<p->vn;j++)
	for(v=0;v<p->vn;v++)
	{
		if(d[j][i]+d[i][v]<d[j][v])
		{	
			d[j][v]=d[j][i]+d[i][v];
			if(i==j&&d[i][j]<0)
			return 1;
			path[j][v]=i;
		}
	}
	return 0;
}
int judg(int d[MAXNUM][MAXNUM],int max)
{
	int i,j,min=100000,v=1,temp=0;
	for(i=1;i<max;i++)
	{
		for(j=1;j<max;j++)
		{
			if(d[i][j]==FAR)
			{
				printf("0");
				return 0;
			}
			if(i==j) continue;
			if(d[i][j]>temp)
			temp=d[i][j];
		}
		if(temp<min)
		{
			min = temp;
			v=i;
		}
		temp=0;
	}
	printf("%d   %d",v,min);
}
