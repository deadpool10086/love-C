#include <iostream>

using namespace std;

struct Vertex
{
	int index; //编号 
	int degree;  //度 
	int color; //该节点颜色 
	Vertex()
	{
		index = 0;
		degree = 0;
		color = 0;
	}
};

struct Graph
{
	int vn;
	int en;
	int **graph;
	Vertex * vertexs;
	
	Graph()
	{
		vn = 0;
		en = 0;
		graph = 0;
		vertexs = 0;	
	}
	void build()
	{
		cin >> vn >> en;
		vertexs = new Vertex[vn];
		graph = new int[8][9];
		for(int i=0; i<vn; i++)
		{
			vertexs[i].index = i;
		}
		
		for(int i=0; i<vn; i++)
		{
			for(int j=0; j<vn; j++)
				graph[i][j] = 0;
		}
		for(int i=0; i<en; i++)
		{
			int v1, v2;
			cin >> v1 >>v2;
			graph[v1][v2] = 1;
			graph[v2][v1] = 1;
			vertexs[v1].degree++;
			vertexs[v2].degree++;
		}
	}
};

int main(int argc, char** argv) {
	Graph *graph;
	graph = new Graph();
	graph->build();
	
	return 0;
}
