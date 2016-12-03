#include "Rectangle2.h"

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
	height_ =  height;
}

double Rectangle::getWidth()
{
	return width_;
}

void Rectangle::setWidth(double width)
{
	width_ = width;
}

double Rectangle::getHeight()
{
	return height_;
}

void Rectangle::setHeight(double height)
{
	height_ = height;
}

double Rectangle::getArea()
{
	return height_ * width_;
}

double Rectangle::getPerimeter()
{
	return height_ + width_;
}
