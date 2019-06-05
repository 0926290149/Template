#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Rational
{
public:
	Rational();
	Rational(int, int);
	int getNumerator() const;
	int getDenominator() const;
	Rational add(const Rational &) const;
	Rational subtract(const Rational &) const;
	Rational multiply(const Rational &) const;
	Rational divide(const Rational &) const;
	int compareTo(const Rational &) const;
	bool equals(const Rational &) const;
	int intValue() const;
	double doubleValue() const;
	string toString() const;
	bool operator<(const Rational &);
	bool operator<=(const Rational &);
	bool operator>(const Rational &);
	bool operator>=(const Rational &);
	bool operator==(const Rational &);
	bool operator!=(const Rational &);
	Rational operator+(const Rational &);
	Rational operator-(const Rational &);
	Rational operator*(const Rational &);
	Rational operator/(const Rational &);
	friend ostream &operator<<(ostream &, Rational &);
	friend istream &operator>>(istream &, Rational &);
	int &operator[](int);
	Rational &operator+=(const Rational &);
	Rational &operator-=(const Rational &);
	Rational &operator*=(const Rational &);
	Rational &operator/=(const Rational &);
	Rational &operator++();
	Rational &operator--();
	Rational operator++(int);
	Rational operator--(int);
	Rational operator+();
	Rational operator-();
private:
	int numerator;
	int denominator;
	static int gcd(int, int);
};
#endif

