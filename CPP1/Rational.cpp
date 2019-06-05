#include "Rational.h"

Rational::Rational()
{
	numerator=0;
	denominator=1;
}

Rational::Rational(int numerator, int denominator)
{
	int factor = gcd(numerator, denominator);
	this->numerator = ((denominator>0)?1:-1)*numerator/ factor;
	this->denominator = abs(denominator)/ factor;
}

int Rational::getNumerator() const
{
	return numerator;
}

int Rational::getDenominator() const
{
	return denominator;
}

Rational Rational::add(const Rational & r2) const
{
	int n = numerator * r2.getDenominator() +
		    denominator * r2.getNumerator();
	int d = denominator * r2.getDenominator();
	return Rational(n,d);
}

Rational Rational::subtract(const Rational &r2) const
{
	int n = numerator * r2.getDenominator() -
		denominator * r2.getNumerator();
	int d = denominator * r2.getDenominator();
	return Rational(n, d);
}

Rational Rational::multiply(const Rational &r2) const
{
	int n = numerator * r2.getNumerator();
	int d = denominator * r2.getDenominator();
	return Rational(n, d);
}

Rational Rational::divide(const Rational &r2) const
{
	int n = numerator * r2.getDenominator();
	int d = denominator * r2.getNumerator();
	return Rational(n, d);
}

int Rational::compareTo(const Rational &r2) const
{
	Rational temp = subtract(r2);
	if (temp.getNumerator() < 0)
		return -1;
	else if (temp.getNumerator() == 0)
		return 0;
	else
		return 1;
}

bool Rational::equals(const Rational &r2) const
{
	if (compareTo(r2) == 0)
		return true;
	else
		return false;
}

int Rational::intValue() const
{
	return getNumerator()/getDenominator();
}

double Rational::doubleValue() const
{
	return 1.0*getNumerator() / getDenominator();;
}

string Rational::toString() const
{
	stringstream ss1, ss2;
	ss1 << numerator;
	ss2 << denominator;
	if (denominator == 1)
		return ss1.str() + "";
	else
		return ss1.str() + "/" + ss2.str();
}

bool Rational::operator<(const Rational &r2)
{
	//return (compareTo(r2)<0);
	double f, s;
	f = numerator * 1.0 / denominator * 1.0;
	s = r2.numerator * 1.0 / r2.denominator * 1.0;
	if (f < s)
		return true;
	else
		return false;
}

bool Rational::operator<=(const Rational &r2)
{
	return (compareTo(r2) <= 0);
}

bool Rational::operator>(const Rational &r2)
{
	return (compareTo(r2) > 0);
}

bool Rational::operator>=(const Rational &r2)
{
	return (compareTo(r2) >= 0);
}

bool Rational::operator==(const Rational &r2)
{
	return (compareTo(r2) == 0);
}

bool Rational::operator!=(const Rational &r2)
{
	return (compareTo(r2) != 0);
}

Rational  Rational::operator+(const Rational &r2)
{
	return add(r2);
}

Rational Rational::operator-(const Rational &r2)
{
	return subtract(r2);
}

Rational Rational::operator*(const Rational &r2)
{
	return multiply(r2);
}

Rational Rational::operator/(const Rational &r2)
{
	return divide(r2);
}

int & Rational::operator[](int index)
{
	if (index == 0)
		return numerator;
	if (index == 1)
		return denominator;
}

Rational & Rational::operator+=(const Rational &r2)
{
	*this = add(r2);
	return *this;
}

Rational & Rational::operator-=(const Rational &r2)
{
	*this = subtract(r2);
	return *this;
}

Rational & Rational::operator*=(const Rational &r2)
{
	*this = multiply(r2);
	return *this;
}

Rational & Rational::operator/=(const Rational &r2)
{
	*this = divide(r2);
	return *this;
}
Rational & Rational::operator++()
{
	numerator += denominator;
	return *this;
}
Rational & Rational::operator--()
{
	numerator -= denominator;
	return *this;
}
Rational Rational::operator++(int dummy)
{
	Rational temp(numerator, denominator);
	numerator += denominator;
	return temp;
}
Rational Rational::operator--(int dummy)
{
	Rational temp(numerator, denominator);
	numerator -= denominator;
	return temp;
}
Rational Rational::operator+()
{
	return *this;
}
Rational Rational::operator-()
{
	return Rational(-numerator, denominator);
}
int Rational::gcd(int n, int d)
{
	int n1 = abs(n);
	int n2 = abs(d);
	int gcd = 1;
	for (int i = 1; i <= n1 && i <= n2; i++)
	{
		if (n1%i == 0 && n2%i == 0)
			gcd = i;
	}
	return gcd;
}

ostream & operator<<(ostream & out, Rational & rational)
{
	if (rational.denominator == 1)
		out << rational.numerator;
	else
		out << rational.numerator<<"/"<< rational.denominator;
	return out;
}

istream & operator>>(istream & in, Rational &rational)
{
	in >> rational.numerator;
	in >> rational.denominator;
	return in;
}

