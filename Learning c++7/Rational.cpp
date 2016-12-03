#include <iostream>
#include <sstream>
#include <cmath>
#include "Rational.h"

using namespace std;

Rational::Rational()
{
	numerator_ = 0;
	denominator_ = 1;
}
Rational::Rational(long numerator, long denominator)
{
	if (denominator == 0)
	{
		cout << "Êý¾Ý´íÎó" << endl;
		exit(0);
	}
	else
	{
		long factor = gcd(numerator, denominator);
		numerator_ = ((denominator > 0) ? 1 : -1) * numerator / factor;
		denominator_ = abs(denominator) / factor;
	}
}

long Rational::getNumerator()
{
	return numerator_;
}

long Rational::getDenominator()
{
	return denominator_;
}

long Rational::gcd(long n, long d)
{
	long n1 = abs(n);
	long n2 = abs(d);
	int gcd = n2;
	while(n1 % n2 != 0)
	{
		long temp = n2 ;
		n2 = n1 % n2;
		n1 = temp;
		gcd = n2 ;
	}
	return gcd;
	
}

Rational Rational::add(Rational &secondRational)
{
	long n = numerator_ * secondRational.getDenominator() +
	 	denominator_ * secondRational.getNumerator();
	long d = denominator_ * secondRational.getDenominator();
	return Rational(n, d);
}

Rational Rational::subtract(Rational &secondRational)
{
	long n = numerator_ * secondRational.getDenominator() -
	 	denominator_ * secondRational.getNumerator();
	long d = denominator_ * secondRational.getDenominator();
	return Rational(n, d);
}

Rational Rational::multiply(Rational &secondRational)
{
	long n = numerator_ * secondRational.getNumerator();
	long d = denominator_ * secondRational.getDenominator();
	return Rational(n, d);
} 

Rational Rational::divide(Rational &secondRational)
{
	if (secondRational.getNumerator() != 0)
	{
		long n = numerator_ * secondRational.getDenominator();
		long d = denominator_ * secondRational.getNumerator();
		return Rational(n, d);
	}
	else
	{
		cout << "error" << endl;
		exit(0);
	}
	
}

int Rational::compareTo(Rational &secondRational)
{
	Rational temp = this->subtract(secondRational);
	if (temp.getNumerator() < 0)
	  return -1;
	else if (temp.getNumerator() == 0)
	  return 0;
	else 
	  return 1;
}

bool Rational::equals(Rational &secondRational)
{
	if (this->compareTo(secondRational) == 0)
	  return true;
	else
	  return false;
}

int Rational::intValue()
{
	return numerator_/denominator_;
}

double Rational::doubleValue()
{
	return static_cast<double>(numerator_)/denominator_; 
}

string Rational::toString()
{
	stringstream temp("", ios::out);
	temp << numerator_ << '/' << denominator_ ;
	return temp.str();
}

/*
string Rational::toString()
{
	char s1[20], s2[20];
	// itoa() is define in <stdlib.h> not in <cstdlib>
	itoa(numberator_, s1 ,10);
	itoa(denominator_, s2, 10);
	if (denominator_ == 1)
		return string(s1);
	else
		return string(strcat(strcat(s1, "/"), s2));
}

*/ 

bool Rational::operator<(Rational &secondRational)
{
	return this->compareTo(secondRational) < 0;
}

Rational Rational::operator+=(Rational &secondRational)
{
	*this = this->add(secondRational);
	return (*this);
}

long& Rational::operator[](const int &index)
{
	if(index == 0)
		return numerator_;
	else if(index == 1)
		return denominator_;
	else
		exit(0);
}

Rational Rational::operator-()
{
	return Rational(-numerator_,denominator_);
}

Rational Rational::operator++()
{
	numerator_ += denominator_;
	return *this;
}

Rational Rational::operator++(int dummy)
{
	Rational temp(numerator_, denominator_);
	numerator_ += denominator_;
	return temp ;
}

ostream &operator<<(ostream &str, Rational &rational)
{
	str << rational.numerator_ << "/" <<rational.denominator_;
	return str;
}
istream &operator>>(istream &str, Rational &rational)
{
	cout << "Enter numerator: ";
	str >> rational.numerator_;
	cout << "Enter numerator: ";
	str >> rational.denominator_;
	return str;
}

Rational::operator double()
{
	return doubleValue();
}

