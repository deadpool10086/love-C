#include <iostream>
#include "DerivedCircle.h"
#include "Rectangle.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	GeometricObject shape;
	shape.setColor("red");
	shape.setFilled(true);
	
	cout << shape.toString() << endl << endl;
	
	Circle circle(5);
	circle.setColor("black");
	circle.setFilled(false);
	cout << circle.toString() << endl;
	cout << " Circle radius: " << circle.getRadius() <<
		" area: " << circle.getArea() <<
		" peroment: " << circle.getPerimeter() <<
		'\n' << endl;
		
	Rectangle rectangle(2, 3, "orange", true);
	cout << rectangle.toString() << endl;
	cout << " Rectangle width: " << rectangle.GetWidth() <<
		" height: " << rectangle.getHeight() <<
		" are: " << rectangle.gerArea() <<
		" perimeter: " << rectangle.getPerimeter() <<
		'\n' << endl;
	return 0;
}
