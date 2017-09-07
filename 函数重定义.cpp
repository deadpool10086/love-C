#include <iostream>
using namespace std;

class A
{
	public:
		virtual void pt()
		{
			cout << "i'm class A" << endl;
		}
};

class B : public A
{
	public:
	void pt()
	{
		cout << "i'm class B" << endl;
	}
};

class C : public B
{
	public:
	void pt()
	{
		cout << "i'm class C" << endl;
	}
};

void wc(A *v)
{
	v->pt();
 } 

int main()
{
	A a;
	B b;
	C c;
	wc(&a);
	wc(&b);
	wc(&c);
	return 0;
} 
