#include <iostream>

using namespace std;

int isValue(int a)
{
	if (a == 0)
	 throw a;
} 

int main()
{
	cout << "Enter two integers: ";
	int number1, number2;
	cin >> number1 >> number2;
	
	try {
		cout << "what" <<isValue(number2) << endl;
		
		cout << number1 <<" / " << number2 <<
			" is " << (number1 / number2) << endl; 
	}
	catch (int e) {
		cout << "Exception: an integer " << e <<
			" cannot be divided by zero " << endl;
	}
	
	cout << "Execution continuse ..." << endl;
	
	
 } 
 

