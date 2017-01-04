#include <iostream>
#include <windows.h>
#define MAXNUM 4

using namespace std;

enum {SHUT = 2,GREEN = 1,RED = -1,YELLOW = 0};

struct Vertex
{
	int index; //��� 
	int degree;  //�� 
	int color; //�ýڵ���ɫ 
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
		bool com0(int a, int b)  //���նȴӸߵ������� 
		{
			return a>b;
		}
		bool com1(int a, int b)  // ���նȴӵ͵������� 
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
	void build()  // �������ݵ����� 
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
			graph[i][i] = 1;  // �Լ����Լ�����ͨ״̬ 
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

	
	void sort(int flag) //����1����Ӹߵ��� 2 ����ӵ͵��� 
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
				break; //���нڵ��Ϳɫ 
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
		cout << "����Ҫ" << k-1 << "����ɫ" << endl;
		for (int i = 0; i < vn; i++)
        	cout<< "�ڵ㣺"<<vertexs[i].index <<":��ɫ" << vertexs[i].color <<endl;
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
				str = "����";
				break;
			case 1: 
				str = "�̵�";
				break;
			case -1: 
				str = "���";
				break;
			case 0: 
				str = "�Ƶ�";
				break;
			default:
				str = "����";
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
			ret += "����";
			ret += i+'0';
			ret += "��·�ڵ��ǣ�" + lights[i].toString() +"\n";
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
	void star(int a,int b)  //a b �Ǹտ�ʼ������·���Ǻ�� 
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
