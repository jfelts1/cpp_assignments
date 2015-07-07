/*
 * James Felts
 */

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>
using namespace std;

class Complex
{
	friend ostream& operator<<(ostream& out, const Complex& complex);
	friend istream& operator>>(istream& in, Complex& complex);
	public:
		Complex(double realPart = 0, double imaginaryPart = 0);
		~Complex();
		double getRealPart() const{ return _realPart; };
		double getImaginaryPart() const{ return _imaginaryPart; };
		Complex operator+(const Complex& in)const;
		Complex operator-(const Complex& in)const;
		Complex operator*(const Complex& in)const;

	private:
		double _realPart;
		double _imaginaryPart;
		void displayRealPart()const;
		void displayImaginaryPart()const;
		double findImaginaryPart(const string& in, const int& delimIndex, const string::size_type& iPos);
		double findRealPart(const string& in, const int& delimIndex);
		int findDelimIndex(const string& in, const string::size_type& pos);
};

#endif