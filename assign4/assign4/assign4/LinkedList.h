
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once

#ifdef _WIN32
//disable the spammy warnings that can't be acted on in Visual C++
#pragma warning(disable: 4514 4711 4710 4820)
#endif

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <iterator>
//should make each node exactly one page in size
#define NODEDATASIZE (4096 - sizeof(short)-sizeof(long long)-sizeof(std::shared_ptr<int>))
#define THROW_OUTOFRANGE throw std::out_of_range("Attempted to access an element out of range");

template<class T>
class LinkedList
{

	friend inline std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList)
	{
		for (auto val : linkedList)
		{
			out << val << "\n";
		}
		/*for (long long i = 0;i < linkedList.size();i++)
		{
			out << linkedList[i] << "\n";
		}*/
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

	//copy constructor
	LinkedList(const LinkedList& orig)
	{
		long long i = 0;
		while (i < orig._size)
		{
			add(orig[i]);
			i++;
		}
	}

	//move constructor
	LinkedList(LinkedList&& orig)noexcept : _head(std::move(orig._head)),_tail(std::move(orig._tail)),_cur(std::move(orig._cur)), _numNodes(orig._numNodes), _size(orig._size)
	{
		orig._size = -1;
		orig._numNodes = -1;
		orig._head = nullptr;
		orig._tail = nullptr;
		orig._cur = nullptr;
	}

	//copy assigment
	LinkedList& operator=(const LinkedList& orig)
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

	//move assignment
	LinkedList& operator=(LinkedList&& orig)
	{
		if (&orig != this)
		{
			clear();
			_head = std::move(orig._head);
			_tail = std::move(orig._tail);
			_cur = std::move(orig._cur);
			_numNodes = orig._numNodes;
			orig._numNodes = -1;
			_size = orig._size;
			orig._size = -1;
		}
		return *this;
	}

	inline bool operator==(const LinkedList& rhs)const
	{
		if (size() == rhs.size())
		{
			for (int i = 0;i < size();i++)
			{
				if (this->operator[](i) != rhs[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	T* begin()
	{
		return &this->operator[](0);
	}

	const T* begin()const
	{
		return &this->operator[](0);
	}

	T* end()
	{
		return &this->operator[](_size);
	}
	
	const T* end()const
	{
		return &this->operator[](_size);
	}

	inline bool operator!=(const LinkedList& rhs)const
	{
		return !(*this == rhs);
	}

	inline LinkedList operator+(const LinkedList& rhs)const
	{
		LinkedList<T> out(*this);
		for (long long i = 0;i < rhs.size();i++)
		{
			out.add(rhs[i]);
		}

		return out;
	}

	//adds the given value to the end of the list
	void add(const T value)
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

	//add the given value at the given index
	void add(const T value, const long long index)
	{
		if (index > _size - 1 || index < 0)
		{
			THROW_OUTOFRANGE
		}
		T temp = this->operator[](index);
		this->operator[](index) = value;
		for (long long i = index+1;i < _size;i++)
		{
			std::swap(this->operator[](i), temp);
		}
		add(temp);
	}

	//deletes the first instance found that matches the given input
	//returns true when successfully deleted
	//returns false otherwise
	bool remove(const T value)
	{
		if (this->contains(value))
		{
			LinkedList temp;
			bool del = false;
			for (long long i = 0;i < size();i++)
			{
				T tmp = this->operator[](i);
				if(tmp==value && del == false)
				{ 
					del = true;
				}
				else
				{
					temp.add(tmp);
				}
			}
			_head = temp._head;
			_tail = temp._tail;
			_cur = temp._cur;
			_size = temp._size;
			_numNodes = temp._numNodes;

			return del;
		}
		else
		{
			return false;
		}
	}

	bool contains(const T value)
	{
		for (long long i = 0;i < _size;i++)
		{
			if (this->operator[](i) == value)
			{
				return true;
			}
		}
		return false;
	}

	//returns the value at the given index
	T& operator[](const long long index)
	{
		long long atNode = index / _nodeSize;
		long long indexInNode = index%_nodeSize;
		std::shared_ptr<Node> n = getNode(atNode);
		return n->_digits[indexInNode];
	}

	//returns the value at the given index with bounds checking
	T& at(const long long index)
	{
		if (index > _size-1 || index < 0)
		{
			THROW_OUTOFRANGE
		}
		return this[index];
	}

	//returns the value at the given index
	const T& operator[](const long long index)const
	{
		long long atNode = index / _nodeSize;
		long long indexInNode = index%_nodeSize;
		std::shared_ptr<Node> n = getNode(atNode);
		return n->_digits[indexInNode];
	}

	//returns the value at the given index with bounds checking
	const T& at(const long long index)const
	{
		if (index > _size - 1 || index < 0)
		{
			THROW_OUTOFRANGE
		}
		return this->operator[](index);
	}
	
	long long size()const 
	{
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

	struct ListIterator : std::iterator<std::forward_iterator_tag, T>
	{
		ListIterator(T* val) :p(val) {}
		ListIterator(const ListIterator& lit) : p(lit.p) {}
		ListIterator& operator++()
		{
			++p;
			return *this;
		}
		ListIterator operator++(int)
		{
			ListIterator tmp(*tmp);
			operator++();
			return tmp;
		}
		bool operator==(const ListIterator& rhs) { return p == rhs.p; }
		bool operator!=(const ListIterator& rhs) { return p != rhs.p; }
		T& operator*() { return *p; }
	private:
		T* p;
	};
	unsigned long long getSizeOfNodePtr()
	{
		return sizeof(std::shared_ptr<Node>);
	}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
private:
	struct Node
	{
		std::shared_ptr<Node> _next;
		short _usedDigits;
		long long _nodeNumber;
		T _digits[NODEDATASIZE / sizeof(T)<1 ? 1 : NODEDATASIZE / sizeof(T)];
	};

	
	std::shared_ptr<Node> _head;
	std::shared_ptr<Node> _tail;
	std::shared_ptr<Node> _cur = nullptr;
	long long _numNodes = 0;
	long long _size = 0;

	inline std::shared_ptr<Node> makeNewNode(const T value)
	{
		std::shared_ptr<Node> nn = std::make_shared<Node>();
		nn->_next = nullptr;
		nn->_digits[0] = value;
		nn->_usedDigits = 0;
		nn->_usedDigits++;
		nn->_nodeNumber = _numNodes;
		_numNodes++;
		return nn;
	}

	inline std::shared_ptr<Node> getNode(const long long index)const
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

	inline std::shared_ptr<Node> getNode(const long long index)
	{
		long long count = 0;

		if (_cur == nullptr)
		{
			_cur = _head;
		}
		if (_cur->_nodeNumber == index)
		{
			return _cur;
		}
		else
		{
			_cur = _head;
			while (count < index)
			{
				_cur = _cur->_next;
				count++;
			}
			return _cur;
		}
	}
};
#endif
