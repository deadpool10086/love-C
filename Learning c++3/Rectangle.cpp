#include "Rectangle.h"

Rectangle::Rectangle()
{
	width_ = 1;
	height_ = 1; 
}

Rectangle::Rectangle(double width, double height)
{
	width_ = width;
	height_ = height;
}

Rectangle::Rectangle(double width, double height, string color, bool filled)
	:GeometricObject(color, filled)
{
	width_ = width;
	height_ = height;
}

double Rectangle::GetWidth()
{
	return width_;
} 

void Rectangle::setWidth(double width)
{
	width_ = (width >= 0) ? width : 0;
}

double Rectangle::getHeight()
{
	return height_;
} 

void Rectangle::setHeight(double height)
{
	height_ = (height >= 0) ? height : 0;
}

double Rectangle::gerArea()
{
	return height_ * width_;
}

double Rectangle::getPerimeter()
{
	return 2 * (height_ + width_);
}


