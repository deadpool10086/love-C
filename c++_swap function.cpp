#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
	int p;
	p=a;
	a=b;
	b=p;
}
int main()
{
	int a,b;
	cin>>a>>b;
	swap(a,b);
	cout<<a<<' '<<b;
	return 0;
}

