#include <iostream>
#include "Rational.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Rational r1(4, 2);
	Rational r2(2, 3);
	
	cout << r1.toString() + " + " + r2.toString() + " = " + 
		r1.add(r2).toString() << endl;
	cout << r1.toString() + " - " + r2.toString() + " = " + 
		r1.subtract(r2).toString() << endl;
	cout << r1.toString() + " * " + r2.toString() + " = " + 
		r1.multiply(r2).toString() << endl;
	cout << r1.toString() + " / " + r2.toString() + " = " + 
		r1.divide(r2).toString() << endl;
	
	cout << "r2.intValue()" << " is " << r2.intValue() << endl;
	cout << "r2.doubleValude()" << " is " << (double)r2 << endl;
	
	cout << "r1.compareTo(r2) is " << r1.compareTo(r2) << endl;
	cout << "r2.compareTo(r1) is " << r2.compareTo(r1) << endl;
	cout << "r1.compareTo(r1) is " << r1.compareTo(r1) << endl;
	cout << "r1.equals(r1) is " << r1.equals(r1) << endl; 
	cout << "r1.equals(r2) is " << r1.equals(r2) << endl; 
	cout << boolalpha <<"r1 < r2 is " << r1.equals(r2) << endl; 
	r1+=r2;
	cout << r1.toString() << endl;
	
	cout << r1[1] << endl;
	r1[1]=100;
	cout << "The denominator of r1 has changed to " << r1[1] << endl;
	
	return 0;
}
