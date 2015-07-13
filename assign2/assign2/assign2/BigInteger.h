/*
 * James Felts
 */
#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#pragma once
#include "LinkedList.h"

class BigInteger
{
	public:
		BigInteger();
		virtual ~BigInteger();
	private:
		bool _negative;
		BigIntegerLinkedList _list;
};

#endif