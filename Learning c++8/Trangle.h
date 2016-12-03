#include <cmath>

#include "AbstractGeometricObject.h"
#include "TriangleException.h"

class Triangle: public GeometricObject
{
	private:
		double side1_;
		double side2_;
		double side3_;
		
		bool isValid(double side1, double side2 , double side3)
		{
			return (side1 < side2 + side3) &&  (side2 < side1 + side3)  &&
				(side3 < side2 + side1);
		}
	
	public:
		Triangle (double side1, double side2, double side3)
		{
			if (!isValid(side1, side2, side3))
				throw TriangleException(side1, side2, side3);
				
			side1_ = side1;
			side2_ = side2;
			side3_ = side3;
		}
		
		double getSide1()
		{
			return side1_;
		}
		double getSide2()
		{
			return side2_;
		}
		double getSide3()
		{
			return side3_;
		}
		
		double setSide1(double side1)
		{
			if (!isValid(side1, side2_, side3_))
				throw TriangleException(side1, side2_, side3_);
			
			side1_ = side1;
		}
		
		double setSide2(double side2)
		{
			if (!isValid(side1_, side2, side3_))
				throw TriangleException(side1_, side2, side3_);
			
			side2_ = side2;
		}
		double setSide3(double side3)
		{
			if (!isValid(side1_, side2_, side3))
				throw TriangleException(side1_, side2_, side3);
			
			side3_ = side3;
		}
		
		double getPerimeter()
		{
			return side1_ + side2_ + side3_;
		}
		
		double getArea()
		{
			double s = getPerimeter() / 2;
			return sqrt(s * (s - side1_) * (s - side2_) * (s - side3_));
		}
		

};
