#include <iostream>

using namespace std;

int main()
{
	string a = "hello";
	string b = a;
	cout << a << "|||||" << b << endl;
	printf("%d|||%d\n", reinterpret_cast<int>(&a), reinterpret_cast<int>(&b));
	a += b;
	cout << a << a.length() << endl;
	cout << reinterpret_cast<int> (&a)<<endl; 
	
	return 0;
} 
