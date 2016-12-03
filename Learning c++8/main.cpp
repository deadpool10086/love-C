#include <iostream>
#include "Trangle.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	try
	{
		Triangle triangle(2, 1, 1);
		cout << triangle.getPerimeter() << endl;
		cout << triangle.getArea() << endl;
	}
	catch (TriangleException &ex)
	{
		cout << ex.getSide2() << endl; 
		cout << ex.what() << endl; 
	}
	return 0;
}
