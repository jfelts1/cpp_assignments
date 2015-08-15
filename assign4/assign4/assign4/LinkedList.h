/*
 * James Felts
 *
 * Compilers Used
 * Visual C++ 2015 X64 target use the project settings
 * g++ 5.1 flags used g++-5 -Wall -Wextra -O2 *.cpp -std=c++14
 *
 * range for working at line 526 in linkedList_tester.cpp
 */
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
#include <type_traits>
#include <typeinfo>
#include <sstream>

#define PAGESIZE 4096
//should make each node exactly one page in size
#define NODEDATASIZE (PAGESIZE - sizeof(long long)-sizeof(long long)-sizeof(std::shared_ptr<int>))
#define THROW_OUTOFRANGE throw std::out_of_range("Attempted to access an element out of range");
//from http://stackoverflow.com/a/264088
#define HAS_MEM_FUNC(func, name)                                        \
    template<typename L, typename Sign>                                 \
    struct name {                                                       \
        typedef char yes[1];                                            \
        typedef char no [2];                                            \
        template <typename U, U> struct type_check;                     \
        template <typename _1> static yes &chk(type_check<Sign, &_1::func > *); \
        template <typename   > static no  &chk(...);                    \
        static bool const value = sizeof(chk<L>(0)) == sizeof(yes);     \
    }

/*HAS_MEM_FUNC(operator<, hasLessThan);
hasLessThan<T, std::string(T :: *)()>::value*/

#define IS_SORTABLE_CLASS(name)\
	template<class Q = T>\
	struct name{\
		HAS_MEM_FUNC(operator<, hasLessThan);\
		static bool const value = hasLessThan<T, std::string(Q :: *)()>::value;\
	}

#define IS_SORTABLE_NON_CLASS(name)\
	template<class Q = T>\
	struct name{\
	static bool const value = (std::is_integral<Q>::value || std::is_floating_point<Q>::value ? true : false);\
	}

template<class T>
class LinkedList
{

	friend inline std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList)
	{
		//range for doesn't work here even though it works fine in the tester with the exact same code during my testing line 526 in linkedList_tester.cpp
		/*for (auto val : linkedList)
		{
			out << val << "\n";
		}*/
		for (long long i = 0;i < linkedList.size();i++)
		{
			out << linkedList[i] << "\n";
		}
		return out;
	}

public:

	LinkedList()
	{}

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
			m_tail->m_next = nn;
			m_tail = nn;
		}
		else
		{
			m_tail->m_digits[m_tail->m_usedDigits] = value;
			m_tail->m_usedDigits++;
		}
		m_size++;
	}

	//add the given value at the given index
	//on error
	//throws std::out_of_range
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
	//on error
	//throws std::out_of_range
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

	//checks if the list contains the given value
	//returns true if found
	//false otherwise
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
		return n->m_digits[indexInNode];
	}

	//returns the value at the given index with bounds checking
	//on error
	//throws std::out_of_range
	T& at(const long long index)
	{
		if (index > m_size-1 || index < 0)
		{
			THROW_OUTOFRANGE
		}
		return this->operator[](index);
	}

	//returns the value at the given index
	const T& operator[](const long long index)const
	{
		long long atNode = index / m_nodeSize;
		long long indexInNode = index%m_nodeSize;
		std::shared_ptr<Node> n = getNode(atNode);
		return n->m_digits[indexInNode];
	}

	//returns the value at the given index with bounds checking
	//on error
	//throws std::out_of_range
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
		m_cur = nullptr;
		m_size = 0;
		m_numNodes = 0;
		//smart pointers should clean up the nodes
	}

	const int m_nodeSize = NODEDATASIZE / sizeof(T)<1 ? 1 : NODEDATASIZE / sizeof(T);

	struct ListIterator : std::iterator<std::random_access_iterator_tag, T>
	{
		ListIterator() {}
		ListIterator(LinkedList<T>* val) :m_list(val) {}
		ListIterator(LinkedList<T>* val, long long index) :m_list(val), m_curIndex(index) {}
		ListIterator(const ListIterator& lit) : m_list(lit.m_list),m_curIndex(lit.m_curIndex) {}

		ListIterator& operator++()//prefix
		{
			if (m_curIndex < m_list->m_size)
			{
				++m_curIndex;
			}
			return *this;
		}

		ListIterator operator++(int)//postfix
		{
			ListIterator tmp(*this);
			operator++();
			return tmp;
		}

		ListIterator& operator--()//prefix
		{
			if (m_curIndex > 0)
			{
				--m_curIndex;
			}
			return *this;
		}

		ListIterator operator--(int)//postfix
		{
			ListIterator tmp(*this);
			operator--();
			return tmp;
		}

		ListIterator operator+(const size_t in)
		{
			ListIterator tmp(*this);
			return tmp += in;
		}


		ListIterator& operator+=(const size_t in)
		{
			m_curIndex += in;
			return *this;
		}

		ListIterator operator-(const size_t in)
		{
			ListIterator tmp(*this);
			return tmp -= in;
		}

		ListIterator& operator-=(const size_t in)
		{
			m_curIndex -= in;
			return *this;
		}

		long long operator-(const ListIterator in)
		{
			return m_curIndex - in.m_curIndex;
		}

		bool operator==(const ListIterator& rhs)const 
		{ 
			return m_curIndex == rhs.m_curIndex;
		}

		bool operator!=(const ListIterator& rhs)const 
		{
			return m_curIndex != rhs.m_curIndex; 
		}

		bool operator<(const ListIterator& rhs)const
		{
			return m_curIndex < rhs.m_curIndex;
		}

		bool operator<=(const ListIterator& rhs)const
		{
			if (m_curIndex == rhs.m_curIndex)
			{
				return true;
			}
			else
			{
				return this->operator<(rhs);
			}
		}

		bool operator>(const ListIterator& rhs)const
		{
			return m_curIndex > rhs.m_curIndex;
		}

		bool operator>=(const ListIterator& rhs)const
		{
			if (m_curIndex == rhs.m_curIndex)
			{
				return true;
			}
			else
			{
				return this->operator>(rhs);
			}
		}

		T& operator*()
		{ 
			return m_list->operator[](m_curIndex); 
		}

		T& operator->()
		{ 
			return m_list->operator[](m_curIndex); 
		}

		T& operator[](const long long in)
		{
			return m_list->operator[](in);
		}

		operator ListIterator()const
		{
			return ListIterator(m_list, m_curIndex);
		}

	private:
		LinkedList<T>* m_list;
		long long m_curIndex = 0;
	};

	ListIterator begin()
	{
		return ListIterator(this);
	}

	const ListIterator begin()const
	{
		return ListIterator(this);
	}

	ListIterator end()
	{
		return ListIterator(this,this->size());
	}

	const ListIterator end()const
	{
		return ListIterator(this,this->size());
	}

	IS_SORTABLE_NON_CLASS(isSortableNonClass);

	template<class Q = T>
	typename std::enable_if<std::is_class<Q>::value,void>::type
	sort()
	{
		sortClassHelper();
	}

	template<class Q = T>
	typename std::enable_if<(!(std::is_class<Q>::value) && isSortableNonClass<Q>::value), void>::type
		sort()
	{
		std::sort(begin(),end(),[](const T& l, const T& r) {return l < r;});
	}

	template<class Q = T>
	typename std::enable_if<(!(std::is_class<Q>::value) && !(isSortableNonClass<Q>::value)),void>::type
		sort()
	{
		std::cerr << "Unable to sort the type:" << typeid(this->at(0)).name() << std::endl;
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
		std::shared_ptr<Node> m_next;
		long long m_usedDigits;
		long long m_nodeNumber;
		T m_digits[NODEDATASIZE / sizeof(T)<1 ? 1 : NODEDATASIZE / sizeof(T)];
	};

	std::shared_ptr<Node> m_head = nullptr;
	std::shared_ptr<Node> m_tail = nullptr;
	std::shared_ptr<Node> m_cur = nullptr;
	long long m_numNodes = 0;
	long long m_size = 0;

	IS_SORTABLE_CLASS(isSortableClass);

	template<class Q = T>
	typename std::enable_if<isSortableClass<Q>::value, void>::type
		sortClassHelper()
	{
		std::sort(begin(),end(),[](const T& l, const T& r) {return l < r;});
	}

	template<class Q = T>
	typename std::enable_if<!(isSortableClass<Q>::value),void>::type
		sortClassHelper()
	{
		std::cerr << "Unable to sort the type:" << typeid(this->at(0)).name() << std::endl;
	}

	inline std::shared_ptr<Node> makeNewNode(const T value)
	{
		std::shared_ptr<Node> nn = std::make_shared<Node>();
		nn->m_next = nullptr;
		nn->m_digits[0] = value;
		nn->m_usedDigits = 0;
		nn->m_usedDigits++;
		nn->m_nodeNumber = m_numNodes;
		m_numNodes++;
		return nn;
	}

	inline std::shared_ptr<Node> getNode(const long long index)const
	{
		long long count = 0;
		std::shared_ptr<Node> cur = m_head;

		while (count < index)
		{
			cur = cur->m_next;
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
		if (m_cur->m_nodeNumber == index)
		{
			return m_cur;
		}
		else
		{
			m_cur = m_head;
			while (count < index)
			{
				m_cur = m_cur->m_next;
				count++;
			}
			return m_cur;
		}
	}
};
#endif
