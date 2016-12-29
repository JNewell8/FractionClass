/*
 * fraction.cpp
 *
 *  Created on: Oct 10, 2016
 *      Author: James Newell
 */

#include "fraction.h"

using namespace std;

FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() { return message; }

Fraction::Fraction(){
	nmtr = 0;
	dmtr = 1;
}

Fraction::Fraction(const int num){
	nmtr = num;
	dmtr = 1;
}

Fraction::Fraction(const int num, const int den){
	if(den == 0)
		throw FractionException("Cannot have a zero valued denominator!");
	nmtr = num;
	dmtr = den;
	reduce();
}

void Fraction::reduce() {
	int div = GCD(abs(nmtr),abs(dmtr));
	if((nmtr < 0 && dmtr < 0) || (nmtr > 0 && dmtr > 0)) {
		nmtr = abs(nmtr)/div;
		dmtr = abs(dmtr)/div;
	}
	else {
		nmtr = -abs(nmtr)/div;
		dmtr = abs(dmtr)/div;
	}
}

int Fraction::GCD(const int n, const int m) const{
	if((m <= n && n % m == 0) || n == 0)
		return m;
	else if(n < m)
		return GCD(m, n);

	else
		return GCD(m, n % m);
}

int Fraction::numerator() const{
	return nmtr;
}

int Fraction::denominator() const{
	return dmtr;
}

Fraction Fraction::clone() const {
	return Fraction(nmtr, dmtr);
}

Fraction& Fraction::operator+= (const Fraction& a){
	nmtr = nmtr * a.denominator() + dmtr * a.numerator();
	dmtr = dmtr * a.denominator();
	reduce();
	return *this;
}

Fraction& Fraction::operator+= (const int a){
	nmtr = nmtr + a*dmtr;
	reduce();
	return *this;
}

Fraction& Fraction::operator--(){
	nmtr = nmtr - dmtr;
	reduce();
	return *this;
}

Fraction Fraction::operator--(int a){
	Fraction cloneF = clone();
	nmtr = nmtr - dmtr;
	return cloneF;
}

Fraction& Fraction::operator++(){
	nmtr = nmtr + dmtr;
	reduce();
	return *this;
}

Fraction Fraction::operator++(int a) {
	Fraction cloneF = clone();
	nmtr = nmtr + dmtr;
	return cloneF;
}

Fraction operator-(const Fraction& a) {
	return Fraction(-a.numerator(), a.denominator());
}

Fraction operator+ (const Fraction& a, const Fraction& b) {
	return Fraction(a.numerator() * b.denominator() + b.numerator() * a.denominator(), a.denominator() * b.denominator());
}

Fraction operator+ (const int a, const Fraction& b) {
	return Fraction(b.numerator() + a * (b.denominator()), b.denominator());
}

Fraction operator+ (const Fraction& a, const int b) {
	return Fraction(a.numerator() + b * (a.denominator()), a.denominator());
}

Fraction operator- (const Fraction& a, const Fraction& b) {
	return Fraction(a.numerator() * b.denominator() - b.numerator() * a.denominator(), a.denominator() * b.denominator());
}

Fraction operator- (const int a, const Fraction& b) {
	return Fraction(a * (b.denominator()) - b.numerator(), b.denominator());
}

Fraction operator- (const Fraction& a, const int b) {
	return Fraction(a.numerator() - b * (a.denominator()), a.denominator());
}

Fraction operator* (const Fraction& a, const Fraction& b) {
	return Fraction(a.numerator() * b.numerator(), a.denominator() * b.denominator());
}

Fraction operator* (const int a, const Fraction& b) {
	return Fraction(a * b.numerator(), b.denominator());
}

Fraction operator* (const Fraction& a, const int b) {
	return Fraction(b * (a.numerator()), a.denominator());
}

Fraction operator/ (const Fraction& a, const Fraction& b) {
	return Fraction(a.numerator() * b.denominator(), a.denominator() * b.numerator());
}

Fraction operator/ (const int a, const Fraction& b) {
	return a * Fraction(b.denominator(), b.numerator());
}

Fraction operator/ (const Fraction& a, const int b) {
	return Fraction(a.numerator(), b * a.denominator());
}

bool operator< (const Fraction& a, const Fraction& b) {
	return a.numerator() * b.denominator() < b.numerator() * a.denominator();
}

bool operator< (const int a, const Fraction& b) {
	return a * b.denominator() < b.numerator();
}

bool operator< (const Fraction& a, const int b) {
	return a.numerator() < a.denominator() * b;
}

bool operator<= (const Fraction& a, const Fraction& b) {
	return a.numerator() * b.denominator() <= b.numerator() * a.denominator();
}

bool operator<= (const int a, const Fraction& b) {
	return a * b.denominator() <= b.numerator();
}

bool operator<= (const Fraction& a, const int b) {
	return a.numerator() <= a.denominator() * b;
}

bool operator== (const Fraction& a, const Fraction& b) {
	return a.numerator() * b.denominator() == b.numerator() * a.denominator();
}

bool operator== (const int a, const Fraction& b) {
	return a * b.denominator() == b.numerator();
}

bool operator== (const Fraction& a, const int b) {
	return a.numerator() == a.denominator() * b;
}

bool operator>= (const Fraction& a, const Fraction& b) {
	return a.numerator() * b.denominator() >= b.numerator() * a.denominator();
}

bool operator>= (const int a, const Fraction& b) {
	return a * b.denominator() >= b.numerator();
}

bool operator>= (const Fraction& a, const int b) {
	return a.numerator() >= a.denominator() * b;
}

bool operator> (const Fraction& a, const Fraction& b) {
	return a.numerator() * b.denominator() > b.numerator() * a.denominator();
}

bool operator> (const int a, const Fraction& b) {
	return a * b.denominator() > b.numerator();
}

bool operator> (const Fraction& a, const int b) {
	return a.numerator() > a.denominator() * b;
}

bool operator!= (const Fraction& a, const Fraction& b) {
	return a.numerator() * b.denominator() != b.numerator() * a.denominator();
}

bool operator!= (const int a, const Fraction& b) {
	return a * b.denominator() != b.numerator();
}

bool operator!= (const Fraction& a, const int b) {
	return a.numerator() != a.denominator() * b;
}

ostream& operator<<(ostream& out, const Fraction& a) {
	out << a.numerator() << "/" << a.denominator();
	return out;
}

istream& operator>>(istream& in, Fraction& a) {
	std::string iNmtr ="";
	std::string iDmtr ="";
	char next;
	char* p;
	do
	{
		in >> next;
		iNmtr += next;
	} while(in.peek() != 10 && in.peek() != '/');

	int iNmtrInt = strtol(iNmtr.c_str(), &p, 10);
	if(*p){
		throw FractionException("Fraction must have numeric inputs!");
	}
	if (in.peek() == 10){
		a = Fraction(iNmtrInt);
	}
	else {
		in >> next;
		while(in.peek() != 10){
			in >> next;
			iDmtr += next;
		}
		int iDmtrInt = strtol(iDmtr.c_str(), &p, 10);
		if(*p){
			throw FractionException("Fraction must have numeric inputs!");
		}
		a = Fraction(iNmtrInt, iDmtrInt);
	}
	return in;
}

