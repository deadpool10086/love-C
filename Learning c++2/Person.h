#include "Date.h"

class Person
{
	public:
		Person(int id, int year, int month, int day);
		Person(Person &);
		int getId();
		Date* getBirthDate();
		
	private:
		int id;
		Date* birthDate;
};
