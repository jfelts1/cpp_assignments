
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <array>
#include <cmath>
//should make each node exactly one page in size on x64 
#define NODEDATASIZE 4086

template<class T>
class LinkedList
{

	friend std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList)
	{
		for (int i = 0;i < linkedList.size();i++)
		{
			out << linkedList[i]<<"\n";
		}
		return out;
	}
public:

	LinkedList()
	{
		_size = 0;
		_numNodes = 0;
	}

	virtual ~LinkedList()
	{
	}

	//deep copy constructor
	LinkedList(LinkedList& orig)
	{
		long long i = 0;
		while (i < orig._size)
		{
			add(orig[i]);
			i++;
		}
	}
	//assigns using deep copy
	LinkedList& operator=(LinkedList& orig)
	{
		if (&orig != this)
		{
			clear();
			long long i = 0;
			while (i < orig._size)
			{
				add(orig[i]);
				i++;
			}
		}
		return *this;
	}

	//adds the given value to the end of the list
	void add(T value)
	{
		if (_size == 0LL)
		{
			std::shared_ptr<Node> nn = makeNewNode(value);
			_head = _tail = nn;
		}
		else if (_size%_nodeSize == 0LL)
		{
			std::shared_ptr<Node> nn = makeNewNode(value);
			_tail->_next = nn;
			_tail = nn;
		}
		else
		{
			_tail->_digits[_tail->_usedDigits] = value;
			_tail->_usedDigits++;
		}
		_size++;
	}

	//returns the value at the given index
	T& operator[](long long index)
	{
		long long atNode = index / _nodeSize;
		long long indexInNode = index%_nodeSize;
		std::shared_ptr<Node> n = getNode(atNode);
		return n->_digits[indexInNode];
	}

	//returns the value at the given index
	const T& operator[](long long index)const
	{
		long long atNode = index / _nodeSize;
		long long indexInNode = index%_nodeSize;
		std::shared_ptr<Node> n = getNode(atNode);
		return n->_digits[indexInNode];
	}
	
	long long size()const {
		return _size;
	}

	void clear()
	{
		_head = nullptr;
		_tail = nullptr;
		_size = 0;
		_numNodes = 0;
		//smart pointers should clean up the nodes
	}

	const int _nodeSize = NODEDATASIZE / sizeof(T)<1 ? 1 : NODEDATASIZE / sizeof(T);

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
private:
	struct Node
	{
		std::shared_ptr<Node> _next;
		short _usedDigits;
		
		T _digits[NODEDATASIZE / sizeof(T)<1 ? 1 : NODEDATASIZE / sizeof(T)];
	};
	std::shared_ptr<Node> _head;
	std::shared_ptr<Node> _tail;
	long long _numNodes = 0;
	long long _size = 0;//can't ever reach this value but int isn't big enough

	std::shared_ptr<Node> makeNewNode(const T value)
	{
		std::shared_ptr<Node> nn = std::make_shared<Node>();
		nn->_next = nullptr;
		nn->_digits[0] = value;
		nn->_usedDigits = 0;
		nn->_usedDigits++;
		_numNodes++;
		return nn;
	}

	std::shared_ptr<Node> getNode(const long long index)const
	{
		long long count = 0;
		std::shared_ptr<Node> cur = _head;
		while (count < index)
		{
			cur = cur->_next;
			count++;
		}

		return cur;
	}
};
#endif
