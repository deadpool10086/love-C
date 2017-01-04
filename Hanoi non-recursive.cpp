#include <iostream>

using namespace std;

struct Tower
{
	char name;
	int layer[10];
	int n;
	
};

int main(int argc,char* argv[])
{
	int n;
	int x;
	int k;
	scanf("%d",&n);
	Tower t[3];
	Tower *p[3];
	t[0].name = 'A';
	for(int i=1; i<=n; i++)
	{
		t[0].layer[i] = i;
	}
	t[0].n = n;
	if(n%2)
	{
		t[1].name = 'C';
		t[2].name = 'B';
		x = 1;
	}
	else
	{
		t[1].name = 'B';
		t[2].name = 'C';
		x =2;
	}
	t[2].n = t[1].n = 0;
	k = 0;
	while(t[x].n != n)
	{
		p[0] = t + k % 3;
		p[1] = t + (k + 1) % 3;
		p[2] = t + (k + 2) % 3;
		p[1]->layer[++p[1]->n] = p[0]->layer[p[0]->n--];
		cout << p[0]->name << "->" << p[1]->name<<endl;
		if(t[x].n == n)
		{
			break;
		}
		if(p[2]->n == 0 || p[2]->layer[p[2]->n] < p[0]->layer[p[0]->n])
		{
			p[2]->layer[++p[2]->n] = p[0]->layer[p[0]->n--];
			cout << p[0]->name << "->" << p[2]->name<<endl;
		}
		else
		{
			p[0]->layer[++p[0]->n] = p[2]->layer[p[2]->n--];
			cout << p[2]->name << "->" << p[0]->name<<endl;
		}
		k++;
	}
	return 0;
}
