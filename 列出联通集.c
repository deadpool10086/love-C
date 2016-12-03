#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int node[8]={0};
int graph[8][8]={0};
int duilie[10];
int s=0,e=0;

void bfs(void);
int main(int argc, char *argv[]) {
	int i,j,m,n;
	for(i=0;i<6;i++)
	{
		scanf("%d %d",&m,&n);
		graph[m][n]=graph[n][m]=1; 
	}
	for(i=0;i<8;i++)
		{
			if (node[i]==0)
			{
				duilie[sum++]=i;
				bfs();
			}
		}
	return 0;
}
void bfs(void)
{
	int n,i;
	printf("{");
	while(sum!=0)
	{
		n=duilie[--sum];
		node[n]++;
		printf("%d",n);
		for(i=0;i<8;i++)
		{
			if(graph[n][i]==1&&node[i]==0)
			{
				duilie[sum++]=i;
			}
		}
	}
	printf("}");
}
