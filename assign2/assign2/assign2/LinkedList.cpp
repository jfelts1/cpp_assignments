#include "LinkedList.h"

using namespace std;

BigIntegerLinkedList::BigIntegerLinkedList()
{
}


BigIntegerLinkedList::~BigIntegerLinkedList()
{
	while (_head != nullptr)
	{
		Node* temp = _head->_next;
		delete _head;
		_head = temp;
	}
	_head = nullptr;
	_tail = nullptr;
}


void BigIntegerLinkedList::add(const char value)
{
	if (_size == 0LL)
	{
		Node* nn = makeNewNode(value);
		_head = _tail = nn;
	}
	else if (_size%NODEDATASIZE == 0LL)
	{
		Node* nn = makeNewNode(value);
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

BigIntegerLinkedList::Node* BigIntegerLinkedList::makeNewNode(const char value)
{
	Node* nn = new Node();
	nn->_next = nullptr;
	nn->_digits[0] = value;
	nn->_usedDigits = 0;
	nn->_usedDigits++;
	_numNodes++;
	return nn;
}

ostream& operator<<(ostream& out, const BigIntegerLinkedList& linkedList)
{

	return out;
}