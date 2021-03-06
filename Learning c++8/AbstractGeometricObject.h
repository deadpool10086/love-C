#ifndef ABSTRACTGEOMETRICOBJECT_H
#define ABSTRACTGEOMETRICOBJECT_H
#include <string>

using namespace std;

class GeometricObject
{
	protected:
//  public:
		GeometricObject();
		GeometricObject(string color, bool filled);
	

	public:
		string getColor();
		void setColor(string color);
		bool isFilled();
		void setFilled(bool filled);
		string toString();
		virtual double getArea() = 0;
		virtual double getPerimeter() = 0;
// 		virtual double getArea() {};
//		virtual double getPerimeter() {};
		
	private:
		string color_;
		bool filled_;
};
#endif
