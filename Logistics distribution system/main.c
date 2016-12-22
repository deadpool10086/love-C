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


typedef struct  Goods //����Ľڵ�
{
	int goal;     //����Ŀ�ĵ� 
	int weight;		//�������� 
	struct Goods *next;
}Cargo;

typedef struct Truck
{
	int standardLoad;  //�����ı�׼���� 
	int residualLoad; //������ʣ������ 
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
	char placeName[20];  //�ڵ��ʾ��������վվ�� 
	Cargo * cargo;	 //��Ҫ������صĻ������� 
}Vertex;

typedef struct Graph
{
	int en;   //�ܱ��� 
	int vn;		//	�ܽڵ���� 
	int graph[MAXNUM][MAXNUM]; 
	Vertex vertex[MAXNUM];	
}Graph;

int initialize(Graph * placeGraph,Truck *truck)  //��ʼ�� 
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
				placeGraph->graph[i][j] = 0; //��ʼ���Լ����Լ�Ϊ0 
			}
			else
			{
				placeGraph->graph[i][j] = FAR;  //���бߵĳ�ʼ����Ϊ����� 	
			}			
		}
	}
	for(i=0; i<MAXNUM; i++)
	{
		placeGraph->vertex[i].cargo = NULL;
		placeGraph->vertex[i].placeName[0] = '\0'; //�ص����ֳ�ʼ��Ϊ�� 
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

int insert(Graph * placeGraph,Edge *d)  //��ͼ�в���˫��·�� 
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
int checkView(int data[][MAXNUM],int n)  //�鿴��ά�������� n��Ϊ�����С 
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
	for(i=0; i<p->vn; i++)    //��i�ڵ����ÿ��·�����п��Ƿ���ʹ��������� 
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
	int source = 0;  //Դ��ַ 
	Cargo * tempCargo = NULL;
	printf("please input cargo information \n");
	printf("input -1 -1 -1 to exit input");
	printf("v1 to v2 200kg goods format��v1 v2 200\n");
	tempCargo = (Cargo *)malloc(sizeof(Cargo));
	while(source != -1)                           //��������洢������Ϣ 
	{
		scanf("%d%d%d",&source,&tempCargo->goal,&tempCargo->weight);   //Դ��ַ  Ŀ�ĵ�ַ ��������  
		tempCargo->next = placeGraph->vertex[source].cargo;
		placeGraph->vertex[source].cargo = tempCargo;
		tempCargo = (Cargo *)malloc(sizeof(Cargo));
	}
	printf("All the goods have already been loaded!\n");
} 

int checkCargo(Graph * p)   //���������Ϣ 
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

int onPath(Stack * s,int n) //����Ƿ�˳�� 
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

Cargo * onTruck(Truck * truck, Cargo *head, int collected[MAXNUM])   //�ѻ���װ�ϳ� 
{
	Cargo * ret = NULL;
	Cargo * temp = NULL;
	while(head)
	{
		temp = head;
		head = head->next;
		if ((collected[temp->goal] || onPath(&truck->path,temp->goal)) && temp->weight <= truck->residualLoad)   //�����û�о���Ŀ�Ľڵ� ���һ𳵻�װ���� 
		{
			truck->goods[temp->goal] +=  temp->weight;  //����װ�� 
			truck->residualLoad -= temp->weight;
			free(temp);
		}
		else
		{
			temp->next = ret;    //����Ļ��Ѹû�����Ϣ�������Է����� 
			ret = temp;
		}
		
	}
	return ret;
}

int pick(int n, int vn, int condition[MAXNUM], int cost[][MAXNUM])  //������������ ѡ�����·�� 
{
	int ret = -1;  //��ʼ��Ϊ -1 
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

int pickDestination(int n, Truck * truck, int vn, int cost[][MAXNUM], int collected[])  //��ѡ�¸�Ŀ�ĵ�  n��ʾ������ 
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
	
	
	if(truckStatu)   //������л��� ѡһ��Ҫ�͵������ 
	{
		ret = pick(n, vn, truck->goods, cost);
	}
	else if(vertexStatu)  // �������ûȥ�Ľڵ� ѡһ��ûȥ������� 
	{
	 	ret = pick(n, vn, collected, cost);
	}
	else              //�����������Ҳ�������Ե�ǰΪԴͷ����һ�� 
	{
		for(i = 0; i<vn; i++)
		{
			collected[i] = 1;
		}
		collected[n] = 0;
		ret = pick(n, vn, collected, cost); 
	}
}

int loadPath(int s, int t,Truck* truck, int path[][MAXNUM])  //s����ԴĿ�ĵأ� t����Ŀ�ĵ�ַ 
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
	int collected[MAXNUM];   //��ʾ�Ѿ������Ķ��� 1 ��ʾû�߹�  0��ʾ�߹��� 
	for (i=0; i<graph->vn; i++)
	{
		collected[i] = 1;
	} 
	printf("Please enter the truck starting the place of departure \n");
	scanf("%d",&n);
	while(n >= 0)
	{
		printf("Starting from the %d \n",n);
		collected[n] = 0;	// �ռ��ö��� 
		source = n;
		n = pickDestination(n, truck, graph->vn, cost, collected);  //��ѡ�ڵ� 
		if(n == -1)
		{
			printf("The picture is not a connected graph\n");
			return -1;
		} 
		printf("The next place %d\n",n);
		loadPath(source, n, truck, path);  //�򿨳������·�� 
		graph->vertex[n].cargo = onTruck(truck,graph->vertex[n].cargo,collected);  // װ���ϳ� 
		onTheWay(truck);  //��·���� 
		printf("Has reached the %d\n",n);
		printf("Unloading\n");
		truck->residualLoad += truck->goods[n];
		truck->goods[n] = 0;
		printf("keep go on��");
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
	inputData(placeGraph);		//����ڵ��·����Ϣ 
	loadUp(placeGraph); 		//���������Ϣ 
	
	
	int cost[MAXNUM][MAXNUM],path[MAXNUM][MAXNUM];
	Floyd(placeGraph,cost,path);
	
//	checkView(cost,placeGraph->vn);   //�鿴�����е�����;
//	checkCargo(placeGraph);				//�鿴���������;  
	begantransport(truck, placeGraph, cost, path);    //�����������亯�� 
	
	
	free(truck);
	free(placeGraph);
	return 0;
}
