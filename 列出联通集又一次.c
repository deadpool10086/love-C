#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 10
//#define FAR 1000000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct graph
{
	int vn;
	int en;
	int graph[MAXNUM][MAXNUM];
	int collected[MAXNUM];
}Graph;

int queue[MAXNUM] = {0};
int head = 0;
int last = 0;

void DFS(Graph * p, int n)
{
	int i;
	p->collected[n] = 1;
	printf("%d ",n);	
	for(i=0; i<p->vn; i++)
	{
		if(p->graph[n][i] && !p->collected[i])
		{
			DFS(p, i);
		}
	}	
	return;
}

int BFS(Graph *p,int n)
{
	int i;
	printf("{ ");
	queue[last] = n;
	p->collected[n] = 1;
	last++;
	while(head != last)
	{
		n= queue[head++];
		
		printf("%d ",n);
		for(i=0; i<p->vn; i++)
		{
			if(p->graph[n][i] && !p->collected[i])
			{
				queue[last++] = i;
				p->collected[i] = 1;
			}	
		}
	}
	printf("}\n");
}

int main(int argc, char *argv[]) {
	int i,j;
	Graph g;
	int v1;
	int v2;
	scanf("%d%d",&g.vn,&g.en);
	for(i=0; i<g.vn; i++)
	{
		for(j=0; j<g.vn; j++)
		{
			g.graph[i][j] = 0;
		}
	}
	for(i=0; i<g.vn; i++)
	{
		g.collected[i] = 0;
	}
	
	for(i=0; i<g.en; i++)
	{
		scanf("%d%d",&v1,&v2);
		g.graph[v1][v2] = 1;
		g.graph[v2][v1] = 1;
	}
	for(i=0; i<g.vn; i++)
	{
		if(!g.collected[i])
		{
			printf("{ ");
			DFS(&g, i);
			printf("}\n");
		}
	}
	for(i=0; i<g.vn; i++)
	{
		g.collected[i] = 0;
	}
	for(i=0; i<g.vn; i++)
	{
		if(!g.collected[i])
		{
			BFS(&g,i);
		}
	}
	return 0;
}
