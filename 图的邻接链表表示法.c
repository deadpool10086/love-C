#include <stdio.h>
#include <stdlib.h>
#define MVERTICESN 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Gedge
{
	int v1,v2,height;
};
typedef struct Edgenode Edg;
struct Edgenode
{
	int zx,height;
	struct Edgenode *next;
};
struct Vnode
{
	Edg *head;
	//datatyap data
};
struct Graph
{
	int nv;
	int ne;
	struct Vnode *adjlist;
};
void initialize(struct Graph *p,int n);
void insert(struct Graph *p,struct Gedge *edge);

int main(int argc, char *argv[]) {
	int i;
	struct Gedge *edge;
	struct Graph *graph;
	graph=(struct Graph *)malloc(sizeof(struct Graph));
	initialize(graph,MVERTICESN);
	edge=(struct Gedge*)malloc(sizeof(struct Gedge));
	for(i=0;i<MVERTICESN;i++)
	{
		scanf("%d %d %d",&edge->v1,&edge->v2,&edge->height);
		insert(graph,edge);
	}
	return 0;
}
void initialize(struct Graph *p,int n)
{
	p->nv=n;
	p->ne=0;
	p->adjlist=(struct Vnode*)malloc(sizeof(struct Vnode)*n);
	for(;n>0;n--)
		p->adjlist[n].head=NULL;
}
void insert(struct Graph *p,struct Gedge *edge)
{
	Edg **abc=&(p->adjlist[edge->v1].head); 
	while(*abc!=NULL)
		abc=&((*abc)->next);
	*abc=(Edg *)malloc(sizeof(Edg));
	(*abc)->next=NULL;
	(*abc)->zx=edge->v2;
	(*abc)->height=edge->height;
		
}
