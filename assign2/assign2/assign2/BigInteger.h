/*
 * James Felts
 * should be able to handle up to (2^64) digit numbers in theory
 * limited to about 16000 digits due to string length limitions
 *
 * no multiplication and substraction is buggy
 *
 * compilers used
 * Visual c++ 2013 targeting x64
 * g++ 4.9.2 doesn't compile
 */
#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#pragma once
#include "LinkedList.h"
#include <cctype>

class BigInteger
{
	friend std::istream& operator>>(std::istream& in, BigInteger& bigInt);
	friend std::ostream& operator<<(std::ostream& out, const BigInteger& bigInt);
	public:
		BigInteger();
		virtual ~BigInteger();
		BigInteger(BigInteger& orig);
		BigInteger& operator=(BigInteger& orig);

		bool fillList(std::istream& in);
		std::string toString()const;

		BigInteger operator+(const BigInteger& in)const;
		BigInteger operator-(const BigInteger& in)const;
		BigInteger operator*(const BigInteger& in)const;

		bool operator==(const BigInteger& in)const;
		bool operator!=(const BigInteger& in)const;
		bool operator>(const BigInteger& in)const;
		bool operator<(const BigInteger& in)const;
		bool operator>=(const BigInteger& in)const;
		bool operator<=(const BigInteger& in)const;

		long long numDigits()const;
		char operator[](long long index)const;
		bool isNegative()const;
		void addDigit(const char digit);
		void clear();
	private:
		bool _negative;
		BigIntegerLinkedList _list;
		
};

#endif