#include <iostream>
#include <windows.h>
#define MAXNUM 4

enum {SHUT = 2,GREEN = 1,RED = -1,YELLOW = 0};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


struct Vertex
{
	int statue;
	int before;
	Vertex()
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

struct Graph
{
	int vn;
	int en;
	int** graph;
	Vertex* vertexs;
	string toString()
	{
		string ret;
		for(int i=0; i<vn; i++)
		{
			ret += "����";
			ret += i+'0';
			ret += "��·�ڵ��ǣ�" + vertexs[i].toString() +"\n";
		}
		return ret;
	}
	void yellow()
	{
		for(int i=0; i<vn; i++)
		{
			vertexs[i].statue = YELLOW; 	
		}	
	}
	void star(int a,int b)  //a b �Ǹտ�ʼ������·���Ǻ�� 
	{
		int s = RED;
		int n = GREEN;
		for(int i=0; i<vn; i++)
		{
			if(i == a || i == b)
			{
				vertexs[i].before = s;	
				vertexs[i].statue = n;
			}
			else
			{
				vertexs[i].before = n;	
				vertexs[i].statue = s;	
			}
			
		}
	}
	void convent()
	{
		for(int i=0; i<vn; i++)
		{
			vertexs[i].statue += vertexs[i].before;
			vertexs[i].before = -vertexs[i].statue;
		}
	} 
	Graph(int num = MAXNUM,int en = 0)
	{
		vn = num;
		this->en = en; 
		graph = new int*[num];
		for(int i=0; i<num; i++)
		{
			graph[i] = new int[num];
		}
		vertexs = new Vertex[num];
	}
	~Graph()
	{
		for(int i=0; i<vn; i++)
		{
			delete[] graph[i];
		}
		delete[] graph;
		delete[] vertexs;
	}

	
};

struct Parameter
{
	Graph * gp;
	int * np;
};

//void CALLBACK TimeProc(HWND hwnd, UINT message, UINT idTimer, DWORD dwTime)  
//{  
//	printf("thread count = %d\n", 3);  
//} 
//DWORD CALLBACK ThreadProc(PVOID pvoid)  
//{  
//    MSG msg;  
//    SetTimer(NULL, 10, 100, TimeProc);  
//    while(GetMessage(&msg, NULL, 0, 0))  
//    {
//        if(msg.message == WM_TIMER)  
//        {  
//        	TranslateMessage(&msg);    // ������Ϣ  
//            DispatchMessage(&msg);     // �ַ���Ϣ  
//        }  
//    } 
//	KillTimer(NULL, 10);  
//    return 0;  
//}


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
	Graph* graph = new Graph();
	graph->star(1, 3);
	int i = 0;
	DWORD dwThreadId;
	//HANDLE hThread = CreateThread(NULL, 0, control, 0, 0, &dwThreadId);
	
	Parameter * para = (Parameter *)malloc(sizeof(Parameter));
	para->gp = graph;
	para->np = &i;
	CreateThread(NULL, 0, control, para,0,&dwThreadId);
	
	cout << graph->toString();
	while(1)
	{
		Sleep(1000);
		i++;
		//cout << i <<endl;
		if(i == 5)
		{
			i = 0;
			graph->yellow();
			system("cls"); 
			cout << graph->toString();
			Sleep(3000);
			graph->convent();
			system("cls");
			cout << graph->toString();
			
		}
	}
	cin.get(); 
	return 0;
}


 
