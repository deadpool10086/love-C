#include "DerivedCircle.h"

Circle::Circle()
{
	radius_ = 1;
} 

Circle::Circle(double radius)
{
	radius_ = radius;
}
Circle::Circle(double radius, string color, bool filled)
	:GeometricObject(color, filled)
{
	radius_ = radius;
} 

double Circle::getRadius()
{
	return radius_;
}

void Circle::setRadius(double radius)
{
	radius_ = (radius >= 0) ? radius : 0;
}

double Circle::getArea()
{
	return radius_*radius_*3.1415926;
}

double Circle::getPerimeter()
{
	return radius_*2*3.1415926;
}

double Circle::getDiameter()
{
	return radius_*2;
} 
