#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "GeometricObject.h"

class Rectangle: public GeometricObject
{
	public:
		Rectangle();
		Rectangle(double width, double height);
		Rectangle(double width, double height, string color, bool filled);
		double GetWidth();
		void setWidth(double);
		double getHeight();
		void setHeight(double);
		double gerArea();
		double getPerimeter();
		
		
	private:
		double width_;
		double height_;
};

#endif 
