#ifndef RATIONAL_H 
#define RATIONAL_H
#include <string>

using namespace std;

class Rational
{
	public:
		Rational();
		Rational(long numberator, long denominator);
		long getNumerator();
		long getDenominator();
		Rational add(Rational &secondRational);
		Rational subtract(Rational &secondRational);
		Rational multiply(Rational &secondRational);
		Rational divide(Rational &secondRational);
		int compareTo(Rational &secondRational);
		bool equals(Rational &secondRational);
		int intValue();
		double doubleValue();
		string toString(); 
		bool operator<(Rational &secondRational);
		Rational operator+=(Rational &secondRational); 
		long& operator[](const int &index);  
		Rational operator-();
		Rational operator++();
		Rational operator++(int dummy);
		friend ostream &operator<<(ostream &stream, Rational &rational);
		friend istream &operator>>(istream &stream, Rational &rational);
		operator double();

	private:
		long numerator_;
		long denominator_;
		static long gcd(long b, long d);
};
#endif
