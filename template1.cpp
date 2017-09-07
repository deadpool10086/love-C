#include <iostream>

using namespace std;
template<typename T, typename S>
T maxValue(T x, S y)
{
	  T x1 = static_cast<T>(y);
	  if (x > x1)
	  	return x;
	  else
	    return x1;
 }
 
 int main()
 {
 	cout << "Maxinum between 1.0 and 3 is " <<
 		maxValue(1.0, 3) << endl;
 	cout << "Maxinum between 1 and 1.1 is " <<
 		maxValue(1, 1.1) << endl;
 	cout << "Maxinum between 'A' and 90 is " <<
 		maxValue('A', 90) << endl;
 //	cout << "Maxinum between 1.0 and \"ABD\" is " <<
 //		maxValue('A', "ABD") << endl;
 }
