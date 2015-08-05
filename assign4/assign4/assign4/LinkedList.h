
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
#define PAGESIZE 4096
#define NODEDATASIZE (PAGESIZE - sizeof(int)-sizeof(long long)-sizeof(std::shared_ptr<int>))
#define THROW_OUTOFRANGE throw std::out_of_range("Attempted to access an element out of range");

template<class T>
class LinkedList
{

	friend inline std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList)
	{
		//faster than iterators
		for (long long i = 0;i < linkedList.size();i++)
		{
			out << linkedList[i] << "\n";
		}
		return out;

	}

public:

	LinkedList()
	{
		m_size = 0;
		m_numNodes = 0;
	}

	virtual ~LinkedList(){}

	//copy constructor
	LinkedList(const LinkedList& orig)
	{
		long long i = 0;
		while (i < orig.m_size)
		{
			add(orig[i]);
			i++;
		}
	}

	//move constructor
	LinkedList(LinkedList&& orig)noexcept : m_head(std::move(orig.m_head)),m_tail(std::move(orig.m_tail)),m_cur(std::move(orig.m_cur)), m_numNodes(orig.m_numNodes), m_size(orig.m_size)
	{
		orig.m_size = -1;
		orig.m_numNodes = -1;
		orig.m_head = nullptr;
		orig.m_tail = nullptr;
		orig.m_cur = nullptr;
	}

	//copy assigment
	LinkedList& operator=(const LinkedList& orig)
	{
		if (&orig != this)
		{
			clear();
			long long i = 0;
			while (i < orig.m_size)
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
			m_head = std::move(orig.m_head);
			m_tail = std::move(orig.m_tail);
			m_cur = std::move(orig.m_cur);
			m_numNodes = orig.m_numNodes;
			orig.m_numNodes = -1;
			m_size = orig.m_size;
			orig.m_size = -1;
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
		if (m_size == 0LL)
		{
			std::shared_ptr<Node> nn = makeNewNode(value);
			m_head = m_tail = nn;
		}
		else if (m_size%m_nodeSize == 0LL)
		{
			std::shared_ptr<Node> nn = makeNewNode(value);
			m_tail->_next = nn;
			m_tail = nn;
		}
		else
		{
			m_tail->_digits[m_tail->_usedDigits] = value;
			m_tail->_usedDigits++;
		}
		m_size++;
	}

	//add the given value at the given index
	void add(const T value, const long long index)
	{
		if (index > m_size - 1 || index < 0)
		{
			THROW_OUTOFRANGE
		}
		T temp = this->operator[](index);
		this->operator[](index) = value;
		for (long long i = index+1;i < m_size;i++)
		{
			std::swap(this->operator[](i), temp);
		}
		add(temp);
	}

	//deletes the first instance found that matches the given input
	//returns true when successfully deleted
	//returns false otherwise
	bool removeByValue(const T value)
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
			m_head = temp.m_head;
			m_tail = temp.m_tail;
			m_cur = temp.m_cur;
			m_size = temp.m_size;
			m_numNodes = temp.m_numNodes;

			return del;
		}
		else
		{
			return false;
		}
	}

	//deletes the element at the given index
	T removeByIndex(const long long index)
	{
		if (index > m_size - 1 || index < 0)
		{
			THROW_OUTOFRANGE
		}
		T ret = this->operator[](index);
		LinkedList temp;
		for (long long i = 0;i < m_size;i++)
		{
			if (index != i)
			{
				temp.add(this->operator[](i));
			}
		}

		m_head = temp.m_head;
		m_tail = temp.m_tail;
		m_cur = temp.m_cur;
		m_size = temp.m_size;
		m_numNodes = temp.m_numNodes;

		return ret;
	}

	//returns true when successfully deleted
	//returns false otherwise
	bool removeAllByValue(const T value)
	{
		if (this->contains(value))
		{
			LinkedList temp;
			bool del = false;
			for (long long i = 0;i < size();i++)
			{
				T tmp = this->operator[](i);
				if (tmp == value)
				{
					del = true;
				}
				else
				{
					temp.add(tmp);
				}
			}
			m_head = temp.m_head;
			m_tail = temp.m_tail;
			m_cur = temp.m_cur;
			m_size = temp.m_size;
			m_numNodes = temp.m_numNodes;

			return del;
		}
		else
		{
			return false;
		}
	}

	bool contains(const T value)
	{
		for (long long i = 0;i < m_size;i++)
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
		long long atNode = index / m_nodeSize;
		long long indexInNode = index%m_nodeSize;
		std::shared_ptr<Node> n = getNode(atNode);
		return n->_digits[indexInNode];
	}

	//returns the value at the given index with bounds checking
	T& at(const long long index)
	{
		if (index > m_size-1 || index < 0)
		{
			THROW_OUTOFRANGE
		}
		return this[index];
	}

	//returns the value at the given index
	const T& operator[](const long long index)const
	{
		long long atNode = index / m_nodeSize;
		long long indexInNode = index%m_nodeSize;
		std::shared_ptr<Node> n = getNode(atNode);
		return n->_digits[indexInNode];
	}

	//returns the value at the given index with bounds checking
	const T& at(const long long index)const
	{
		if (index > m_size - 1 || index < 0)
		{
			THROW_OUTOFRANGE
		}
		return this->operator[](index);
	}
	
	long long size()const 
	{
		return m_size;
	}

	void clear()
	{
		m_head = nullptr;
		m_tail = nullptr;
		m_size = 0;
		m_numNodes = 0;
		//smart pointers should clean up the nodes
	}

	const int m_nodeSize = NODEDATASIZE / sizeof(T)<1 ? 1 : NODEDATASIZE / sizeof(T);

	struct ForwardListIterator : std::iterator<std::forward_iterator_tag, LinkedList<T>>
	{
		ForwardListIterator() {}
		ForwardListIterator(LinkedList<T> val) :m_list(val) {}
		ForwardListIterator(LinkedList<T> val, long long index) :m_list(val), m_curIndex(index) {}
		ForwardListIterator(const ForwardListIterator& lit) : m_list(lit.m_list),m_curIndex(lit.m_curIndex) {}

		ForwardListIterator& operator++()//prefix
		{
			if (m_curIndex < m_list.m_size)
			{
				++m_curIndex;
			}
			return *this;
		}

		ForwardListIterator operator++(int)//postfix
		{
			ForwardListIterator tmp(*this);
			operator++();
			return tmp;
		}

		bool operator==(const ForwardListIterator& rhs)const 
		{ 
			return m_curIndex == rhs.m_curIndex;
		}

		bool operator!=(const ForwardListIterator& rhs)const 
		{
			return m_curIndex != rhs.m_curIndex; 
		}

		T operator*()const 
		{ 
			return m_list[m_curIndex]; 
		}

		T operator->()const 
		{ 
			return m_list[m_curIndex]; 
		}

		operator ForwardListIterator()const
		{
			return ForwardListIterator(m_list, m_curIndex);
		}

	private:
		LinkedList<T> m_list;
		long long m_curIndex = 0;
	};

	ForwardListIterator begin()
	{
		return ForwardListIterator(*this);
	}

	const ForwardListIterator begin()const
	{
		return ForwardListIterator(*this);
	}

	ForwardListIterator end()
	{
		return ForwardListIterator(*this,this->size());
	}

	const ForwardListIterator end()const
	{
		return ForwardListIterator(*this,this->size());
	}
	

	unsigned long long getSizeOfNode()
	{
		return sizeof(Node);
	}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
private:
	struct Node
	{
		std::shared_ptr<Node> _next;
		int _usedDigits;
		long long _nodeNumber;
		T _digits[NODEDATASIZE / sizeof(T)<1 ? 1 : NODEDATASIZE / sizeof(T)];
	};

	
	std::shared_ptr<Node> m_head;
	std::shared_ptr<Node> m_tail;
	std::shared_ptr<Node> m_cur = nullptr;
	long long m_numNodes = 0;
	long long m_size = 0;

	inline std::shared_ptr<Node> makeNewNode(const T value)
	{
		std::shared_ptr<Node> nn = std::make_shared<Node>();
		nn->_next = nullptr;
		nn->_digits[0] = value;
		nn->_usedDigits = 0;
		nn->_usedDigits++;
		nn->_nodeNumber = m_numNodes;
		m_numNodes++;
		return nn;
	}

	inline std::shared_ptr<Node> getNode(const long long index)const
	{
		long long count = 0;
		std::shared_ptr<Node> cur = m_head;

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

		if (m_cur == nullptr)
		{
			m_cur = m_head;
		}
		if (m_cur->_nodeNumber == index)
		{
			return m_cur;
		}
		else
		{
			m_cur = m_head;
			while (count < index)
			{
				m_cur = m_cur->_next;
				count++;
			}
			return m_cur;
		}
	}
};
#endif
