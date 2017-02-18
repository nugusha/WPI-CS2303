/*
 * Rational.h
 *
 *  Created on: Feb 17, 2017
 *      Author: Nugzar Chkhaidze & Daniel Sullivan
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <iostream>

using namespace std;

class Rational {
public:

	int top, bot;

	~Rational();
	Rational();
	Rational(const int num, const int denom);
	Rational(const int wholeNumber);
	Rational(const Rational &a) ;
	friend ostream& operator<<(ostream& out, const Rational& rat);
	friend istream& operator>>(istream& in,const Rational& rat);
	Rational operator+(const Rational &rat);
	Rational operator-(const Rational &rat);
	Rational operator*(const Rational &rat);
	Rational operator/(const Rational &rat);
	int operator==(const Rational &rat);
	int operator!=(const Rational &rat);
	int operator>(const Rational &rat);
	int operator<(const Rational &rat);
	int operator>=(const Rational &rat);
	int operator<=(const Rational &rat);
	double toDouble(const Rational &rat);
};

#endif /* RATIONAL_H_ */
