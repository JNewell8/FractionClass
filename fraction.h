/*
 * fraction.h
 *
 *  Created on: Oct 10, 2016
 *      Author: James Newell
 */
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>


using namespace std;

class FractionException {
public:
	// FractionException Constructor (message: error message)
	FractionException(const string& message);
	// Outputs the error message as a string
	string& what();
private:
	// The error message
	string message;
};

class Fraction{
public:
	Fraction();									//No input constructor
	Fraction(int single);						//Single input constructor
	Fraction(int num, int den);					//Two input constructor

	int numerator() const;						//Returns the numerator
	int denominator() const;					//Returns the denominator
	void reduce();								//Reduces the fraction
	Fraction& operator+= (const Fraction& a);	//Addition and assignment
	Fraction& operator+= (const int a);

	Fraction& operator-- (); 					//Pre decrement
	Fraction operator-- (int a);				//Post decrement

	Fraction& operator++ (); 					//Pre increment
	Fraction operator++ (int a); 				//Post increment

	Fraction clone() const;						//Creates a clone of the Fraction (same nmtr and dmtr)
private:
	int GCD (const int n,const int m) const;	//Returns the greatest common divisor of two numbers
	int nmtr;									//Numerator
	int dmtr;									//Denominator

// Outputs the fraction with a '/' in between the numbers
friend ostream& operator<<(ostream& outStream, const Fraction& fract);
// Takes a fraction as an input. Returns an error message if the fraction is not in the proper format
friend istream& operator>>(istream& inStream, Fraction& fract);
};

Fraction operator- (const Fraction& a);		// Negation

/* All operators were created for three cases:
 * A fraction on either side
 * A fraction on LHS and an int on RHS
 * A fraction on RHS and an int on LHS
 */

// Addition
Fraction operator+ (const Fraction& a, const Fraction& b);
Fraction operator+ (const int a, const Fraction& b);
Fraction operator+ (const Fraction& a, const int b);

// Subtraction
Fraction operator- (const Fraction& a, const Fraction& b);
Fraction operator- (const int a, const Fraction& b);
Fraction operator- (const Fraction& a, const int b);

// Multiplication
Fraction operator* (const Fraction& a, const Fraction& b);
Fraction operator* (const int a, const Fraction& b);
Fraction operator* (const Fraction& a, const int b);

// Division
Fraction operator/ (const Fraction& a, const Fraction& b);
Fraction operator/ (const int a, const Fraction& b);
Fraction operator/ (const Fraction& a, const int b);

// Same thing for all comparators

bool operator< (const Fraction& a, const Fraction& b);
bool operator< (const int a, const Fraction& b);
bool operator< (const Fraction& a, const int b);

bool operator<= (const Fraction& a, const Fraction& b);
bool operator<= (const int a, const Fraction& b);
bool operator<= (const Fraction& a, const int b);

bool operator== (const Fraction& a, const Fraction& b);
bool operator== (const int a, const Fraction& b);
bool operator== (const Fraction& a, const int b);

bool operator>= (const Fraction& a, const Fraction& b);
bool operator>= (const int a, const Fraction& b);
bool operator>= (const Fraction& a, const int b);

bool operator> (const Fraction& a, const Fraction& b);
bool operator> (const int a, const Fraction& b);
bool operator> (const Fraction& a, const int b);

bool operator!= (const Fraction& a, const Fraction& b);
bool operator!= (const int a, const Fraction& b);
bool operator!= (const Fraction& a, const int b);
