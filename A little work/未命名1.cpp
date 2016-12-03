#include <iostream>
#include <stdlib.h>

using namespace std;
class B
{
	private:
		B* p1;	
		B* p2;
	public:
		B ()
		{
			p1 = p2 =0;	
		}
		~B()
		{
			cout << " B free" << endl;
		}
		int sda()
		{
			return 1;
		 } 
};

class A
{
	private:
		B* data;	
	public:
		A (B* p)
		{
			data = (B*)realloc(p,sizeof(B)*20); 	
		}
		~A()
		{
			free(data);
			cout << "A free " << endl;
		}
}; 



int main()
{
	B* data = (B*)malloc(sizeof(B)*10);
//	B* data = new B[10];
	for(int i=0 ;i <10; i++)
	{
		cout << data[i].sda() << endl;
	}
	A data2(data);
	return 0;
 } 
