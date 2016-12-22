#include <stdio.h>
#include <stdlib.h>
#define MAXLOAD  20000;                               
#define MAXNUM 30
#define FAR 100000

typedef struct stack
{
	int * data;
	int *top;
}Stack;


typedef struct  Goods //货物的节点
{
	int goal;     //货物目的地 
	int weight;		//货物重量 
	struct Goods *next;
}Cargo;

typedef struct Truck
{
	int standardLoad;  //卡车的标准载重 
	int residualLoad; //卡车的剩余载重 
	int goods[MAXNUM];
	Stack path;
}Truck;

typedef struct Enode
{
	int v1,v2;
	int weight;
}Edge;

typedef struct Vertex
{
	char placeName[20];  //节点表示物流配送站站点 
	Cargo * cargo;	 //需要运往外地的货物链表 
}Vertex;

typedef struct Graph
{
	int en;   //总边数 
	int vn;		//	总节点个数 
	int graph[MAXNUM][MAXNUM]; 
	Vertex vertex[MAXNUM];	
}Graph;

int initialize(Graph * placeGraph,Truck *truck)  //初始化 
{
	int i = 0;
	int j = 0;
	placeGraph->en = 0;
	placeGraph->vn = 0;
	for(i=0; i<MAXNUM; i++)
	{
		for(j=0; j<MAXNUM; j++)
		{
			if(i == j)
			{
				placeGraph->graph[i][j] = 0; //初始化自己到自己为0 
			}
			else
			{
				placeGraph->graph[i][j] = FAR;  //所有边的初始距离为无穷大 	
			}			
		}
	}
	for(i=0; i<MAXNUM; i++)
	{
		placeGraph->vertex[i].cargo = NULL;
		placeGraph->vertex[i].placeName[0] = '\0'; //地点名字初始化为空 
	}
	truck->residualLoad = MAXLOAD;
	truck->standardLoad = MAXLOAD;
	for(i=0; i<MAXNUM; i++ )
	{
		truck->goods[i] = 0;
	}
	truck->path.data = (int *)malloc(MAXNUM*sizeof(int));
	truck->path.top = truck->path.data; 
	return 0;
}

int insert(Graph * placeGraph,Edge *d)  //在图中插入双向路径 
{
	placeGraph->graph[d->v1][d->v2] = d->weight;
	placeGraph->graph[d->v2][d->v1] = d->weight;
} 

int inputData(Graph * placeGraph)
{
	int i = 0;
	Edge d;
	printf("please input the number of vertexes and edges\n");
	scanf("%d%d",&placeGraph->vn,&placeGraph->en);
	for (i=0; i<placeGraph->en; i++)
	{
		printf("please input the v1 v2 and cost\n");
		scanf("%d%d%d",&d.v1,&d.v2,&d.weight);
		insert(placeGraph,&d);
	}
	return 0;
}
int checkView(int data[][MAXNUM],int n)  //查看二维数组内容 n作为数组大小 
{
	int i = 0;
	int j = 0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d\t",(data[i][j]==FAR)?-7:data[i][j]);
		printf("\n");
	}
	return 0;
}

int Floyd(Graph *p,int cost[MAXNUM][MAXNUM],int path[MAXNUM][MAXNUM])
{
	int i = 0;
	int j = 0;
	int k = 0;
	for(i=0; i<p->vn; i++)
		for(j=0; j<p->vn; j++)
			{
				cost[i][j] = p->graph[i][j];
				path[i][j] = -1;
			}
	for(i=0; i<p->vn; i++)    //把i节点插入每个路径当中看是否能使其距离缩短 
		for(j=0; j<p->vn; j++)
		{
			if (i == j)
				continue; 
			for(k=0; k<p->vn; k++)
			{
				if(cost[j][i] + cost[i][k] < cost[j][k])
				{
					cost[j][k] = cost[j][i] + cost[i][k];
					path[j][k] = i;
				}
			}
		}
}

int loadUp(Graph * placeGraph)
{
	int source = 0;  //源地址 
	Cargo * tempCargo = NULL;
	printf("please input cargo information \n");
	printf("input -1 -1 -1 to exit input");
	printf("v1 to v2 200kg goods format：v1 v2 200\n");
	tempCargo = (Cargo *)malloc(sizeof(Cargo));
	while(source != -1)                           //采用链表存储货物信息 
	{
		scanf("%d%d%d",&source,&tempCargo->goal,&tempCargo->weight);   //源地址  目的地址 货物重量  
		tempCargo->next = placeGraph->vertex[source].cargo;
		placeGraph->vertex[source].cargo = tempCargo;
		tempCargo = (Cargo *)malloc(sizeof(Cargo));
	}
	printf("All the goods have already been loaded!\n");
} 

int checkCargo(Graph * p)   //输出货物信息 
{
	int i;
	Cargo *temp = NULL;
	for(i=0; i<p->vn; i++)
	{
		temp = p->vertex[i].cargo;
		while(temp)
		{
			printf("%d -> %d : %d\n",i,temp->goal,temp->weight);
			temp = temp->next;
		}
	}
}

int onPath(Stack * s,int n) //检查是否顺道 
{
	int *p = NULL;
	int ret = 0;
	for(p=s->top; p!=s->data; p++)
	{
		if (*p == n)
		{
			ret = 1;
			break;
		}
	}
	return ret;
}

Cargo * onTruck(Truck * truck, Cargo *head, int collected[MAXNUM])   //把货物装上车 
{
	Cargo * ret = NULL;
	Cargo * temp = NULL;
	while(head)
	{
		temp = head;
		head = head->next;
		if ((collected[temp->goal] || onPath(&truck->path,temp->goal)) && temp->weight <= truck->residualLoad)   //如果还没有经过目的节点 而且火车还装的下 
		{
			truck->goods[temp->goal] +=  temp->weight;  //进行装载 
			truck->residualLoad -= temp->weight;
			free(temp);
		}
		else
		{
			temp->next = ret;    //否则的话把该货物信息保存用以返还； 
			ret = temp;
		}
		
	}
	return ret;
}

int pick(int n, int vn, int condition[MAXNUM], int cost[][MAXNUM])  //根据限制条件 选择最短路径 
{
	int ret = -1;  //初始化为 -1 
	int min = FAR;
	int i = 0;
	for (i=0; i<vn; i++)
	{
		if (condition[i] && cost[n][i] < min)
		{
			min = cost[n][i];
			ret = i;
		}
	}
	return ret;
}

int pickDestination(int n, Truck * truck, int vn, int cost[][MAXNUM], int collected[])  //挑选下个目的地  n表示出发点 
{
	int truckStatu = 0;
	int	vertexStatu = 0;
	int i = 0;
	int ret; 
	for(i=0; i<vn; i++)
	{
		truckStatu = truckStatu | (truck->goods[i]);
	}
	for(i=0; i<vn; i++)
	{
		vertexStatu = vertexStatu | (collected[i]);
	}
	
	
	if(truckStatu)   //如果还有货物 选一个要送的最近的 
	{
		ret = pick(n, vn, truck->goods, cost);
	}
	else if(vertexStatu)  // 如果还有没去的节点 选一个没去的最近的 
	{
	 	ret = pick(n, vn, collected, cost);
	}
	else              //如果都送完了也走完了以当前为源头再走一遍 
	{
		for(i = 0; i<vn; i++)
		{
			collected[i] = 1;
		}
		collected[n] = 0;
		ret = pick(n, vn, collected, cost); 
	}
}

int loadPath(int s, int t,Truck* truck, int path[][MAXNUM])  //s代表源目的地， t代表目的地址 
{
	while(path[s][t] != -1)
	{
		t = path[s][t];
		*truck->path.top++ = t;
	}
	return 0;
}

int onTheWay(Truck * truck)
{
	while(truck->path.top != truck->path.data)
	{
		truck->path.top--;
		printf("The truck passed by %d\n",*truck->path.top);
		printf("Unloading\n");
		truck->residualLoad += truck->goods[*truck->path.top];
		truck->goods[*truck->path.top] = 0;
		printf("Move on\n");
	}
}

int begantransport(Truck * truck, Graph * graph, int cost[][MAXNUM], int path[][MAXNUM])
{
	int i = 0;
	int n = 0;
	int source;
	int collected[MAXNUM];   //表示已经经过的定点 1 表示没走过  0表示走过了 
	for (i=0; i<graph->vn; i++)
	{
		collected[i] = 1;
	} 
	printf("Please enter the truck starting the place of departure \n");
	scanf("%d",&n);
	while(n >= 0)
	{
		printf("Starting from the %d \n",n);
		collected[n] = 0;	// 收集该定点 
		source = n;
		n = pickDestination(n, truck, graph->vn, cost, collected);  //挑选节点 
		if(n == -1)
		{
			printf("The picture is not a connected graph\n");
			return -1;
		} 
		printf("The next place %d\n",n);
		loadPath(source, n, truck, path);  //向卡车里加入路径 
		graph->vertex[n].cargo = onTruck(truck,graph->vertex[n].cargo,collected);  // 装货上车 
		onTheWay(truck);  //沿路经过 
		printf("Has reached the %d\n",n);
		printf("Unloading\n");
		truck->residualLoad += truck->goods[n];
		truck->goods[n] = 0;
		printf("keep go on？");
		getchar(); 
	}
	return 0;
}

int main()
{
	Truck *truck = NULL;
	truck = (Truck *)malloc(sizeof(Truck));
	Graph * placeGraph = NULL;
	placeGraph = (Graph *)malloc(sizeof(Graph));
	initialize(placeGraph,truck);
	inputData(placeGraph);		//输入节点和路径信息 
	loadUp(placeGraph); 		//输入货物信息 
	
	
	int cost[MAXNUM][MAXNUM],path[MAXNUM][MAXNUM];
	Floyd(placeGraph,cost,path);
	
//	checkView(cost,placeGraph->vn);   //查看数组中的内容;
//	checkCargo(placeGraph);				//查看货物的内容;  
	begantransport(truck, placeGraph, cost, path);    //启动汽车运输函数 
	
	
	free(truck);
	free(placeGraph);
	return 0;
}
