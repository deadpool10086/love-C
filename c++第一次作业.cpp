#include <iostream>
using std::cin; 
using std::cout;
using std::endl; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int swap(int *x,int *y,int *z)
{
	swap(y,z);
	swap(x,y);
}
int swap(int &x,int &y,int &z)
{
	swap(y,z);
	swap(x,y);
}
int main(int argc, char** argv) {
	int a=0,b=0,c=0,max=-1;
	cin >> a >> b >> c;
	swap(&a,&b,&c);
	swap(a,b,c);
	max=a;
	if(b>max)
	max=b;
	if(c>max)
	max=c;
	cout << max << ' ' << a << ' ' << b << ' ' << c <<endl; 
	return 0;
}
