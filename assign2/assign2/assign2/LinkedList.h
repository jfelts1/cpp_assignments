#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include <iostream>
#include <memory>
#include <string>
//should make each node exactly one page in size on x64 
#define NODEDATASIZE 4086

class BigIntegerLinkedList
{

	friend std::ostream& operator<<(std::ostream& out, const BigIntegerLinkedList& linkedList);
	public:
		BigIntegerLinkedList();
		virtual ~BigIntegerLinkedList();
		//addLast
		BigIntegerLinkedList(BigIntegerLinkedList& orig);
		BigIntegerLinkedList& operator=(BigIntegerLinkedList& orig);
		void add(const char value);
		signed char& operator[](long long index);
		const signed char& operator[](long long index)const;
		std::string toString()const;
		long long size()const;
		void clear();
	private:
		struct Node
		{
			std::shared_ptr<Node> _next;
			short _usedDigits;
			//char is used because it is a very small integer
			//still wastes quite a bit of memory due to only using 1 digit values
			signed char _digits[NODEDATASIZE];
		};
		std::shared_ptr<Node> _head;
		std::shared_ptr<Node> _tail;
		long long _numNodes = 0;
		long long _size = 0;//can't ever reach this value but int isn't big enough
		std::shared_ptr<Node> makeNewNode(const char value);
		std::shared_ptr<Node> getNode(const long long index)const;
};

#endif