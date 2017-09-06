#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct HarryGraph graph;
struct HarryGraph
{
	int snode;
	int sedge;
	int graph[MAXNUM][MAXNUM];
};


int main(int argc, char *argv[]) {
	int i,n,m,weight;
	graph harry;
	scnaf("%d %d",&harry.snode,&harry.sedge);
	for(i=0;i<harry.sedge;i++)
	{
		scanf("%d %d %d",&n,&m,&weight);
		harry.graph[m][n]=harry.graph[n][m]=weight;
	}
	
	return 0;
}
