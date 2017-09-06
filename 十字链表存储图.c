#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX_VERTEX_NUM 20

typedef struct InfoType
{
//	int data;
}InfoType;
typedef struct ArcBox
{
	int tailvex,headvex;
	struct ArcBox *hlink, *tlink;
	InfoType *info;
}ArcBox;

typedef struct VexNode 
{
	int data;
	ArcBox *firstin, *firstout;
}VexNode;

typedef struct
{
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum,arcnum;
}OLGraph;

int Input(InfoType *info)
{
	return 0;
}

int LocateVex(OLGraph *G,int index)
{
	return index;
}

int CreateDG(OLGraph *G)
{
	int IncInfo;
	ArcBox *p;
	int i,k,j;
	int v1,v2;
	printf("顶点数 边数 是否有信息\n");
	scanf("%d%d%d",&G->vexnum,&G->arcnum,&IncInfo);
	for(i=0; i<G->vexnum; i++)
	{
		printf("定点内容\n"); 
		scanf("%d",&G->xlist[i].data);
		G->xlist[i].firstin = G->xlist[i].firstout = NULL;
	}
	for(k=0; k<G->arcnum; k++)
	{
		printf("边的定点\n");
		scanf("%d%d",&v1,&v2);
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		p = (ArcBox *)malloc(sizeof(ArcBox));
		p->headvex=i;
		p->tailvex=j;
		p->hlink = G->xlist[j].firstin;
		p->tlink = G->xlist[i].firstout;
		G->xlist[j].firstin = G->xlist[i].firstout = p;
		if(IncInfo)
			Input(p->info);
	}
}
int outPut(OLGraph *G)
{
	int i;
	for(i=0; i<G->vexnum; i++)
	{
		struct ArcBox *p;	
		p = G->xlist[i].firstout;
		while(p)
		{
			printf("%d->%d\n",p->headvex,p->tailvex);
			p = p->tlink;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	OLGraph G;
	CreateDG(&G);
	outPut(&G);
	return 0;
}
