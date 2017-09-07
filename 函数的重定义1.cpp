#include <iostream>
#include <typeinfo>
using namespace std;

class A
{
	public:
	A()
	{
		a='A';
	}
	void wc()
	{
		cout << a << endl;
	 } 
	
	private:
		char a;
};

class B : public A
{
	public:
	B()
	{
		b='B';
	}
	void wc()
	{
		cout << b << endl;
	 } 
	
	private:
		char b;
};

class C : public B
{
	public:
	C()
	{
		c='C';
	}
	void wc()
	{
		cout << c << endl;
	 } 
	
	private:
		char c;
};

int display(A v)
{
	cout << boolalpha <<  (typeid(v)==typeid(A)) <<endl ;
	cout << boolalpha <<  (typeid(v)==typeid(B)) <<endl ;
	cout << boolalpha <<  (typeid(v)==typeid(C)) <<endl ;
	cout <<"***********************************"<<endl;
}

int main()
{
	cout << 's'<<endl;
	A a;
	B b;
	C c;
	display(a);
	display(b);
	display(c);
	return 0;
} 
