#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include <iostream>
//should make each node exactly one page in size on x64 
#define NODEDATASIZE 4086

class BigIntegerLinkedList
{

	friend std::ostream& operator<<(std::ostream& out, const BigIntegerLinkedList& linkedList);
	public:
		BigIntegerLinkedList();
		virtual ~BigIntegerLinkedList();
		//addLast
		void add(const char value);
	private:
		struct Node
		{
			Node* _next;
			short _usedDigits;
			//char is used because it is a very small integer
			//still wastes quite a bit of memory due to only using 1 digit values
			char _digits[NODEDATASIZE];
		};
		Node* _head;
		Node* _tail;
		long long _numNodes;
		long long _size;//can't ever reach this value but int isn't big enough
		Node* makeNewNode(const char value);

};

#endif