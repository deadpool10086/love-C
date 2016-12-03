#include <iostream>
#include "Person.h"
using namespace std;


int main(int argc, char** argv) {
	Person person(123456789, 1970, 5, 3);
	cout << "Birth year before the change is:" <<
		person.getBirthDate() -> getYear() << endl;
	Date *pDate = person.getBirthDate();
	pDate -> setYear(2012);
	cout << "Birth year after the change is:" <<
		person.getBirthDate() -> getYear() << endl;
		
	return 0;
}
