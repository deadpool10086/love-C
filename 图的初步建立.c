#include <stdio.h>
#include <stdlib.h>
#define MVERTEXN 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Gnode Gno;
typedef struct Gedge Ged;

struct Gnode    //node： 节点 
{
	int nv;
	int ne;
	int graph[MVERTEXN][MVERTEXN];             //建立空图顶点 。 
};

struct Gedge
{
	int v1,v2,weight;						//用以储存边，便于输入进图中。 
};

void ginsert(Gno *p,Ged *e);
void initialize(Gno *p);

int main(int argc, char *argv[]) {
	Ged *tempe;
	Gno *graph;
	graph=(Gno *)malloc(sizeof(Gno));
	initialize(graph);
	printf("请输入图的链接情况，按照格式如A->B（节点A 节点B 权重）如想退出输入（0 0 0）:"); 
	tempe=(Ged *)malloc(sizeof(Ged));
	while(1)
	{
		scanf("%d %d %d",&tempe->v1,&tempe->v2,&tempe->weight);
		if(tempe->v1==0&&tempe->v2==0&&tempe->weight==0)
			break;
		ginsert(graph,tempe); 
	}
	return 0;
}
void ginsert(Gno *p,Ged *e)
{
	p->graph[e->v1][e->v2]=e->weight;
	p->ne++;
}
void initialize(Gno *p)
{
	int i,j;
	for(i=0;i<MVERTEXN;i++)
		for(j=0;j<MVERTEXN;j++)
		p->graph[i][j]=0;
	p->nv=MVERTEXN;
	p->ne=0;
}
