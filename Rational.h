/*
 * Rational.h
 *
 *  Created on: Oct 22, 2014
 *      Author: MOSTAFA
 */

#include <string>
#include <math.h>

using namespace std;

class Rational {
	public :
		Rational(long num, long den);
		Rational(long num);
		Rational();
		Rational operator+(Rational& that);
		Rational operator-(Rational& that);
		Rational operator*(Rational& that);
		Rational operator/(Rational& that);
		Rational pow(int p);
		void print();
		static Rational readRational(string prompt);
	private :
		long num;
		long den;
		long gcd(long x, long b);
		long abs(long a);
		long pow(long n, int p);
};

Rational::Rational() {
	num = 0;
	den = 1;
}

Rational::Rational(long num) {
	this->num = num;
	den = 1;
}

Rational::Rational(long num, long den) {
	long g = gcd(abs(num), abs(den));
	this->num = num / g;
	this->den = den / g;
	if (den < 0)
		this->num = -this->num;
}

Rational Rational::operator+(Rational& that) {
	return Rational(this->num * that.den + this->den * that.num, this->den * that.den);
}

Rational Rational::operator-(Rational& that) {
	return Rational(this->num * that.den - this->den * that.num, this->den * that.den);
}

Rational Rational::operator*(Rational& that) {
	return Rational(this->num * that.num, this->den * that.den);
}

Rational Rational::operator/(Rational& that) {
	return Rational(this->num * that.den, this->den * that.num);
}

//added method...

Rational Rational::pow(int p) {
	return Rational(pow(num, p), pow(den, p));
}

void Rational::print() {
	if (this->den == 1)
		cout << this->num;
	else
		cout << this->num << "/" << this->den;
}

Rational Rational::readRational(string prompt) {
	while (1) {
		long num;
		long den;
		char ch;
		cout << prompt;
		cin >> num;
		ch = getchar();
		if (ch == '\n')
			return Rational(num);
		else if (ch == '/') {
			cin >> den;
			return Rational(num, den);
		}
		cout << "Illegal rational number." << endl;
	}

}

long Rational::gcd(long x, long y) {
	return (y == 0) ? x : gcd(y, x % y);
}

long Rational::abs(long a) {
	return (a < 0) ? -a : a;
}

long Rational::pow(long n, int p) {
	return (p == 0) ? 1 : n * pow(n, p - 1);
}
