#include <iostream>
using namespace std;

class A
{
	public:
		void pt()
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

int main()
{
	A a;
	B b;
	C c;
	a.pt();
	b.pt();
	c.pt();
	c.A::pt();
	return 0;
} 
