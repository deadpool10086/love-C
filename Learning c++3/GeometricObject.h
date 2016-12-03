#ifndef GEOMETRICOBJECT
#define GEOMETRICOBJECT
#include <string>

using namespace std;

class GeometricObject
{
	public:
		GeometricObject();
		GeometricObject(string color, bool folled);
		string getColor();
		void setColor(string color);
		bool isFilled();
		void setFilled(bool filled);
		string toString();
	
	private:
		string color_;
		bool filled_;
};

#endif
