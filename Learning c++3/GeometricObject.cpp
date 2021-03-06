#include "GeometricObject.h"

GeometricObject::GeometricObject()
{
	color_ = "tranceparency";
	filled_ = false;
}

GeometricObject::GeometricObject(string color, bool filled)
{
	color_ = color;
	filled_ = filled;
}

string GeometricObject::getColor()
{
	return color_;
}

void GeometricObject::setColor(string color)
{
	color_ = color;
}

bool GeometricObject::isFilled()
{
	return filled_; 
}

void GeometricObject::setFilled(bool filled)
{
	filled_ = filled;
}

string GeometricObject::toString()
{
	return "Geometric object | color: " +color_ + 
		" | filled: " + ((filled_) ? "ture" : "false");
}
