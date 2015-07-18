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
#include "LinkedList.h"

using namespace std;

BigIntegerLinkedList::BigIntegerLinkedList()
{
	_size = 0;
	_numNodes = 0;
}

BigIntegerLinkedList::~BigIntegerLinkedList()
{
}

BigIntegerLinkedList::BigIntegerLinkedList(BigIntegerLinkedList& orig)
{
	long long i = 0;
	while (i < orig._size)
	{
		add(orig[i]);
		i++;
	}
}

BigIntegerLinkedList& BigIntegerLinkedList::operator=(BigIntegerLinkedList& orig)
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

signed char& BigIntegerLinkedList::operator[](long long index)
{
	long long atNode = index / NODEDATASIZE;
	long long indexInNode = index%NODEDATASIZE;
	shared_ptr<Node> n = getNode(atNode);
	return n->_digits[indexInNode];
}

const signed char& BigIntegerLinkedList::operator[](long long index)const
{
	long long atNode = index / NODEDATASIZE;
	long long indexInNode = index%NODEDATASIZE;
	shared_ptr<Node> n = getNode(atNode);
	return n->_digits[indexInNode];
}

void BigIntegerLinkedList::add(const char value)
{
	if (_size == 0LL)
	{
		shared_ptr<Node> nn = makeNewNode(value);
		_head = _tail = nn;
	}
	else if (_size%NODEDATASIZE == 0LL)
	{
		shared_ptr<Node> nn = makeNewNode(value);
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

shared_ptr<BigIntegerLinkedList::Node> BigIntegerLinkedList::makeNewNode(const char value)
{
	shared_ptr<Node> nn = make_shared<Node>();
	nn->_next = nullptr;
	nn->_digits[0] = value;
	nn->_usedDigits = 0;
	nn->_usedDigits++;
	_numNodes++;
	return nn;
}

shared_ptr<BigIntegerLinkedList::Node> BigIntegerLinkedList::getNode(const long long index)const
{
	long long count = 0;
	shared_ptr<Node> cur = _head;
	while (count < index)
	{
		cur = cur->_next;
		count++;
	}

	return cur;
}

ostream& operator<<(ostream& out, const BigIntegerLinkedList& linkedList)
{
	out << linkedList.toString();
	return out;
}

inline string BigIntegerLinkedList::toString()const
{
	string s;
	s.resize(_size);
	long long count = 0;
	while (count < _size)
	{
		s[count] = this->operator[](count);//this->[count] was interpritited as a lambda
		s[count] += 48;
		count++;
	}

	return s;
}

long long BigIntegerLinkedList::size()const
{
	return _size;
}

void BigIntegerLinkedList::clear()
{
	_head = nullptr;
	_tail = nullptr;
	_size = 0;
	_numNodes = 0;
	//smart pointers should clean up the nodes
}