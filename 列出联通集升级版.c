#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int node[20]={0};
int graph[20][20]={0};
int duilie[100]={0};
int star=0,end=0;

void bfs(int s);
void dfs(int n,int s);
int main(int argc, char *argv[]) {
	int s,b,i,m,n;
	scanf("%d %d",&s,&b);
	for(i=0;i<b;i++)
	{
		scanf("%d %d",&m,&n);
		graph[m][n]=graph[n][m]=1;
	}
	for(i=0;i<s;i++)
	{
		if(node[i]==0)
		{
		duilie[end++]=i;
		node[i]++;
		bfs(s);
		}
	}
	for(i=0;i<s;i++)
	{
		if(node[i]==1)
		{
			printf("{ ");
			dfs(i,s);
			printf("}\n");
		}
	}
	return 0;
}
void bfs(int s)
{
	int i,n;
	printf("{ ");
	while(star!=end)
	{
		n=duilie[star++];
		printf("%d ",n);
		for(i=0;i<s;i++)
		if(graph[n][i]==1&&node[i]==0)
		{
			duilie[end++]=i;
			node[i]++; 
		} 
	}
	printf("}\n");
}
void dfs(int n,int s)
{
	int i;
	printf("%d ",n);
	node[n]++;
	for(i=0;i<s;i++)
	if(graph[n][i]==1&&node[i]==1)
		dfs(i,s);
}
