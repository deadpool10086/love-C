#include "Date.h"

Date::Date(int newYear, int newMonth, int newDay)
{
	year = newYear;
	month = newMonth;
	day = newDay;
}

void Date::setYear(int newYear)
{
	year = newYear;
};

int Date::getYear()
{
	return year;
}
