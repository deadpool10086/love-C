#include <iostream>
#include <typeinfo>
#include "AbstractGeometricObject.h"
#include "DerivedCircle2.h"
#include "Rectangle2.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

bool equalArea(GeometricObject &object1, GeometricObject &object2)
{
	return object1.getArea() == object2.getArea();
}

void displayGeometricObject(GeometricObject &object)
{
	cout << "the area is " << object.getArea() << endl;
	cout << "the perimeter is " << object.getPerimeter() << endl;
	
	GeometricObject *p = &object;
	Circle *p1 = dynamic_cast<Circle*> (p);
//	Circle *p1 = (Circle*)(p);
	if( p1 != 0)
	{
		cout << "The Radius is " << p1->getRadius() << endl;
		cout << "The diameter is " << p1->getDiameter() << endl;
	 } 
}


int main(int argc, char** argv) {
	Circle circle(5);
	Rectangle rectangle(5, 3);
//	GeometricObject  geometriObject;
	
	cout << "Circle info: " << endl;
	displayGeometricObject(circle);
	
	cout << "\nRectangle info: " << endl;
	displayGeometricObject(rectangle);
	
	cout << "\nThe two object have the same area? " <<
		(equalArea(circle, rectangle) ? "Yes" : "No") << endl; 
	cout << typeid(rectangle).name() << endl;
	return 0;
}
