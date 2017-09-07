#include <iostream>

using namespace std;

template <typename T>
T maxValue(T x, T y)
{
	if (x > y)
		return x;
	else
		return y;
 } 
 
int main()
{
	cout << "Maxinum between 1 and 3 is " <<
		maxValue(1, 3) << endl;
	cout << "Maxinum between 1.5 and 0.3 is " <<
		maxValue(1.5, 0.3) << endl;
	cout << "Maxinum between 'A' and 'N' is " <<
		maxValue('A', 'N') << endl;
	cout << "Maxinum between \"ABC\" and \"ABD\" is " <<
		maxValue("ABC", "ABD") << endl;		
}
