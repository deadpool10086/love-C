#pragma once

class Date
{
	public:
		Date(int newYear, int newMonth, int newDay);
		int getYear();
		void setYear(int newYearr);
		
	private:
		int year;
		int month;
		int day; 
};

