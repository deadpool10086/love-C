#include <iostream>
#include <windows.h>
#define MAXNUM 4

using namespace std;

enum {SHUT = 2,GREEN = 1,RED = -1,YELLOW = 0};

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
	private:
		bool com0(int a, int b)  //按照度从高到低排列 
		{
			return a>b;
		}
		bool com1(int a, int b)  // 按照度从低到高排列 
		{
			return a<b;
		}
	
public: 
	int vn;
	int en;
	int **graph;
	Vertex * vertexs;
	int sumColor;
	
	Graph()
	{
		vn = 0;
		en = 0;
		graph = 0;
		vertexs = 0;	
	}
	~Graph()
	{
		delete[] vertexs;
		for(int i=0; i<vn; i++)
		{
			delete[] graph[i];
		}
		delete[] graph;
	}
	void build()  // 进行数据的输入 
	{
		cin >> vn >> en;
		vertexs = new Vertex[vn];
		graph = new int*[vn];
		for(int i=0; i<vn; i++)
		{
			graph[i] = new int[vn];
			vertexs[i].index = i;
		}
		
		for(int i=0; i<vn; i++)
		{
			for(int j=0; j<vn; j++)
				graph[i][j] = 0;
			graph[i][i] = 1;  // 自己跟自己是联通状态 
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

	
	void sort(int flag) //排序1代表从高到低 2 代表从低到高 
	{
		bool (Graph::*p)(int, int);
		if(1 == flag )
		{
			p = com0;
		}
		else if(2 == flag)
		{
			p = com1;
		}
		else
		{
			exit(0);
		}
		for(int i=1; i<vn; i++)
		{
			int j;
			Vertex 	temp = vertexs[i];
			for(j=i; j>0 && (this->*p)(temp.degree,vertexs[j-1].degree); j--)
			{
				vertexs[j] = vertexs[j-1];
			}
			vertexs[j] = temp;
		}
	}
	
	void welchPowell()
	{
		sort(1);
		int k = 0;
		while(1)
		{
			k++;
			int i;
			for(i=0; i<vn; i++)
			{
				if( 0 == vertexs[i].color)
				{
					vertexs[i].color = k;
					break;
				}
			}
			if (i == vn)
			{
				break; //所有节点均涂色 
			}
			for(int j=0; j<vn; j++)
			{
				if(!vertexs[j].color && !graph[vertexs[i].index][vertexs[j].index])
				{
					vertexs[j].color = k;
					for(int k=0; k<vn; k++)
					{
						if(graph[vertexs[j].index][k])
						{
							graph[vertexs[i].index][k] = 1;
						}
					} 
				} 
			}
		}
		sumColor = k-1;
		cout << "共需要" << k-1 << "种颜色" << endl;
		for (int i = 0; i < vn; i++)
        	cout<< "节点："<<vertexs[i].index <<":着色" << vertexs[i].color <<endl;
      	return;
	}
	
};


class Light
{
	public:
	int statue;
	int before;
	Light()
	{
		before = SHUT;
		statue = SHUT;	
	}	
	string toString()
	{
		string str;
		switch(statue)
		{
			case 2: 
				str = "灭了";
				break;
			case 1: 
				str = "绿灯";
				break;
			case -1: 
				str = "红灯";
				break;
			case 0: 
				str = "黄灯";
				break;
			default:
				str = "出错";
				break;
		}
		return str;
	}
};

class Lntersection
{
	public:
	Light* lights;
	string toString()
	{
		string ret;
		for(int i=0; i<MAXNUM; i++)
		{
			ret += "现在";
			ret += i+'0';
			ret += "号路口灯是：" + lights[i].toString() +"\n";
		}
		return ret;
	}
	void yellow()
	{
		for(int i=0; i<MAXNUM; i++)
		{
			lights[i].statue = YELLOW; 	
		}	
	}
	void star(int a,int b)  //a b 是刚开始哪两个路口是红灯 
	{
		int s = RED;
		int n = GREEN;
		for(int i=0; i<MAXNUM; i++)
		{
			if(i == a || i == b)
			{
				lights[i].before = s;	
				lights[i].statue = n;
			}
			else
			{
				lights[i].before = n;	
				lights[i].statue = s;	
			}
			
		}
	}
	void convent()
	{
		for(int i=0; i<MAXNUM; i++)
		{
			lights[i].statue += lights[i].before;
			lights[i].before = -lights[i].statue;
		}
	} 
	Lntersection(int num = MAXNUM,int en = 0)
	{
		lights = new Light[num];
	}
	~Lntersection()
	{
		delete[] lights;
	}
};

struct Parameter
{
	Lntersection * gp;
	int * np;
};

DWORD WINAPI control(LPVOID lpPatam)
{
	int n;
	char d;
	Parameter * p = (Parameter*)lpPatam;
	while(d != 'q')
	{
		cin>>d;
		if(d == 's')
		{
			p->gp->yellow();
			p->gp->convent();
			system("cls");
			cout << p->gp->toString();
		}
		if(d == 'w')
		{
			cin >> n;
			*p->np -= n;
		}
	}
}


int main(int argc, char** argv) {
	Graph *graph;
	graph = new Graph();
	graph->build();
	graph->welchPowell();

	Lntersection* lnt= new Lntersection();
	int i = 0;
	lnt->star(1, 3);
	DWORD dwThreadId;
	Parameter * para = (Parameter *)malloc(sizeof(Parameter));
	para->gp = lnt;
	para->np = &i;
	CreateThread(NULL, 0, control, para,0,&dwThreadId);

	cout << lnt->toString();
	while(1)
	{
		Sleep(1000);
		i++;
		if(i == 5)
		{
			i = 0;
			lnt->yellow();
			system("cls"); 
			cout << lnt->toString();
			Sleep(3000);
			lnt->convent();
			system("cls");
			cout << lnt->toString();
			
		}
	}
	cin.get(); 
	return 0;
}
