/*
 * James Felts
 *
 * Compilers Used
 * Visual C++ 2015 X64 target use the project settings
 * g++ 5.1 flags used g++-5 -Wall -Wextra -O2 *.cpp -std=c++14
 *
 * range for working at line 526 in linkedList_tester.cpp
 */

#include "LinkedList.h"
#include <cstdlib>
#include <cstdio>
#include <list>
#include <vector>
#include <chrono>
#include <random>
#include <utility>
#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "complex.h"
#define EXITLOOP -1
#define MAX_MENU_CHOICE 17
#define MAX_LIST_CHOICE 4

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::cerr;

void menu();
void testCodeRun();

//these are helper functions that make the code cleaner
int getChoice();
int getListChoice();

//I don't want to add these to the linked list class since that breaks single responibility
template<typename T>
void addToEndOfList(LinkedList<T>& list)
{
	cout << "Enter value to add" << endl;
	T tmp;
	cin >> tmp;
	list.add(tmp);
}

template<typename T>
void addToAnyPointOfList(LinkedList<T>& list)
{
	cout << "Enter value to add" << endl;
	T tmp;
	cin >> tmp;
	cout << "Enter index to add at" << endl;
	long long index = -1;
	cin >> index;
	try
	{
		list.add(tmp,index);
	}
	catch (std::out_of_range& e)
	{
		cerr << e.what() << endl;
	}
}

template<typename T>
void removeByValue(LinkedList<T>& list)
{
	cout << "Enter value to remove" << endl;
	T tmp;
	cin >> tmp;
	cout << ((list.removeByValue(tmp)) ? "true" : "false") << endl;
}

template<typename T>
void removeByIndex(LinkedList<T>& list)
{
	cout << "Enter index to remove" << endl;
	long long index = -1;
	cin >> index;
	try
	{
		list.removeByIndex(index);
	}
	catch (std::out_of_range& e)
	{
		cerr << e.what() << endl;
	}
}

template<typename T>
void removeAllByValue(LinkedList<T>& list)
{
	cout << "Enter value to remove" << endl;
	T tmp;
	cin >> tmp;
	list.removeAllByValue(tmp);
}

template<typename T>
void contains(LinkedList<T>& list)
{
	cout << "Enter value to check for" << endl;
	T tmp;
	cin >> tmp;
	cout << ((list.contains(tmp)) ? "true" : "false") << endl;
}

template<typename T>
void getFromAnIndex(LinkedList<T>& list)
{
	cout << "Enter index to get from" << endl;
	long long index = -1;
	cin >> index;
	try
	{
		cout << list.at(index) << endl;
	}
	catch(std::out_of_range& e)
	{
		cerr << e.what() << endl;
	}
}

int main()
{
	int check = 0;
	//cuts the output time by a factor of 10 or so on windows!
	check = setvbuf(stdout, NULL, _IOFBF, 10000);
	if (check != 0)
	{
		std::cerr << "Unable to set buffer size" << endl;
	}
	menu();
	return EXIT_SUCCESS;
}

void menu()
{
	mt19937 mtrand;
	LinkedList<int> intList;
	LinkedList<int> intList2;
	LinkedList<long long> longlongList;
	LinkedList<Complex> complexList;

	int choice = 0;
	int listChoice = 0;
	while (choice != EXITLOOP)
	{
		choice = getChoice();
		listChoice = 0;
		switch (choice)
		{
		default:
			break;
		case 1://add to end of list
			listChoice = getListChoice();
			//can't think of a way to avoid similar switch statments everywhere without passing all the lists everywhere
			//and templated functions don't seem to work with function pointers
			switch (listChoice)
			{
			case 1:
				addToEndOfList(intList);
				break;
			case 2:
				addToEndOfList(intList2);
				break;
			case 3:
				addToEndOfList(longlongList);
				break;
			case 4:
				addToEndOfList(complexList);
				break;
			}
			break;
		case 2://add to any point of list
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				addToAnyPointOfList(intList);
				break;
			case 2:
				addToAnyPointOfList(intList2);
				break;
			case 3:
				addToAnyPointOfList(longlongList);
				break;
			case 4:
				addToAnyPointOfList(complexList);
				break;
			}
			break;
		case 3://copy intList to intList2
			intList2 = intList;
			break;
		case 4://move intList to intList2
			intList2 = std::move(intList);
			break;
		case 5://check if intList == intList2
			cout << ((intList == intList2) ? "true" : "false") << endl;
			break;
		case 6:// check if intList != intList2
			cout << ((intList != intList2) ? "true" : "false") << endl;
			break;
		case 7://concat intList and intList2
			intList = intList + intList2;
			break;
		case 8://remove by value
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				removeByValue(intList);
				break;
			case 2:
				removeByValue(intList2);
				break;
			case 3:
				removeByValue(longlongList);
				break;
			case 4:
				removeByValue(complexList);
				break;
			}
			break;
		case 9://remove by index
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				removeByIndex(intList);
				break;
			case 2:
				removeByIndex(intList2);
				break;
			case 3:
				removeByIndex(longlongList);
				break;
			case 4:
				removeByIndex(complexList);
				break;
			}
			break;
		case 10://remove all by value
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				removeAllByValue(intList);
				break;
			case 2:
				removeAllByValue(intList2);
				break;
			case 3:
				removeAllByValue(longlongList);
				break;
			case 4:
				removeAllByValue(complexList);
				break;
			}
			break;
		case 11://contain value
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				contains(intList);
				break;
			case 2:
				contains(intList2);
				break;
			case 3:
				contains(longlongList);
				break;
			case 4:
				contains(complexList);
				break;
			}
			break;
		case 12://get froma specified index
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				getFromAnIndex(intList);
				break;
			case 2:
				getFromAnIndex(intList2);
				break;
			case 3:
				getFromAnIndex(longlongList);
				break;
			case 4:
				getFromAnIndex(complexList);
				break;
			}
			break;
		case 13://get list size
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				cout << intList.size() << endl;
				break;
			case 2:
				cout<< intList2.size() << endl;
				break;
			case 3:
				cout << longlongList.size() << endl;
				break;
			case 4:
				cout << complexList.size() << endl;
				break;
			}
			break;
		case 14://clear list
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				intList.clear();
				break;
			case 2:
				intList2.clear();
				break;
			case 3:
				longlongList.clear();
				break;
			case 4:
				complexList.clear();
				break;
			}
			break;
		case 15://sort a list
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				intList.sort();
				break;
			case 2:
				intList2.sort();
				break;
			case 3:
				longlongList.sort();
				break;
			case 4:
				complexList.sort();
				break;
			}
			break;
		case 16://display a list
			listChoice = getListChoice();
			switch (listChoice)
			{
			case 1:
				cout << intList << endl;
				break;
			case 2:
				cout << intList2 << endl;
				break;
			case 3:
				cout << longlongList << endl;
				break;
			case 4:
				cout << complexList << endl;
				break;
			}
			break;
		case 17://test code run
			testCodeRun();
			break;
		}

	}


	return;
}

int getChoice()
{

	string menuChoices = R"(
Choices
 1: add to end of list
 2: add to any point in list
 3: copy intList to intList2 using copy assignment
 4: move intList to intList2
 5: check if intList is equal to intList2
 6: check if intList is diffrent to intList2
 7: concat intList and intList2
 8: remove by value
 9: remove by index
10: remove all by value
11: contain value
12: get from a specified index
13: get list size
14: clear a list
15: sort a list (uses iterator)
16: display list
17: run my test code block (prints a lot to the screen)
-1: quit
)"s;

	string tmp;
	int choice = 0;
	while (choice == 0)
	{
		cout << menuChoices << endl;
		cout << "Enter choice" << endl;
		cin >> tmp;
		try
		{
			choice = std::stol(tmp);
			if (!(choice == EXITLOOP || (choice >= 1 && choice <= MAX_MENU_CHOICE)))
			{
				throw std::out_of_range("Out of range");
			}
		}
		catch (std::out_of_range&)
		{
			choice = 0;
			cerr << "Number out of range" << endl;
		}
		catch (std::invalid_argument&)
		{
			choice = 0;
			cerr << "Invalid Input" << endl;
		}
	}
	return choice;
}

int getListChoice()
{

	string listChoices = R"(
List Choices
1: intList
2: intList2
3: longlongList
4: complexList
)"s;

	string tmp;
	int choice = 0;
	while (choice == 0)
	{
		cout << listChoices << endl;
		cout << "Enter choice" << endl;
		cin >> tmp;
		try
		{
			choice = std::stol(tmp);
			if (!((choice >= 1 && choice <= MAX_LIST_CHOICE)))
			{
				throw std::out_of_range("Out of range");
			}
		}
		catch (std::out_of_range&)
		{
			choice = 0;
			cerr << "Number out of range" << endl;
		}
		catch (std::invalid_argument&)
		{
			choice = 0;
			cerr << "Invalid Input" << endl;
		}
	}
	cout << endl;
	return choice;
}

void testCodeRun()
{
	mt19937 mtrand;
	LinkedList<Complex> comp;
	for (int i = 0;i < 10;i++)
	{
		comp.add(Complex((int)mtrand(), (int)mtrand()));
	}
	//comp.sort();


	LinkedList<int> l;
	LinkedList<int> l2;
	for (int i = 0;i < 50000;i++)
	{
		l.add(i);
	}
	//copy constructor test
	LinkedList<int> l3(l);

	LinkedList<int> l4;

	cout << l << endl;
	//copy assignment test
	l2 = l;
	//addition operator test and move assignment test
	l4 = l + l2;

	LinkedList<int> l5 = std::move(l2);

	cout << l3 << endl;
	cout << l4 << endl;

	LinkedList<long long> lltest;

	for (int i = 0;i < 50000;i++)
	{
		lltest.add(i);
	}
	cout << lltest << endl;

	for (int i = 0;i < 50000;i++)
	{
		lltest.add(i);
	}


	//iterator test with range for
	for (auto val : lltest)
	{
		cout << val << "\n";
	}
	cout << endl;

	LinkedList<long long> test;
	for (int i = 0;i < 10;i++)
	{
		test.add((int)mtrand());
	}

	cout << "\nrandom series of numbers" << endl;
	cout << test << endl;
	test.sort();

	cout << "\nafter sorting\n" << endl;
	cout << test << endl;
	cout << comp << endl;
	cout << "\ntry to sort an unsortable type" << endl;
	comp.sort();

	cout << "\ncomparison checks" << endl;
	cout << "l == l2 " << ((l == l2) ? "true" : "false") << endl;
	cout << "l != l2 " << ((l != l2) ? "true" : "false") << endl;
	cout << "l == l5 " << ((l == l5) ? "true" : "false") << endl;
	cout << "l == l3 " << ((l == l3) ? "true" : "false") << endl;
	cout << "l != l4 " << ((l != l4) ? "true" : "false") << endl;

	cout << "\nremoval checks" << endl;
	cout << "adding 999999 to pos 1" << endl;
	l.add(999999, 1);
	cout << "l[0]: " << l[0] << endl;
	cout << "l[1]: " << l[1] << endl;
	cout << "l[2]: " << l[2] << endl;
	cout << "l[3]: " << l[3] << endl;
	cout << "l[l.size()-1]: " << l[l.size() - 1] << endl;
	l.removeByValue(999999);
	cout << "l.removebyValue(999999)" << endl;
	cout << "l[0]: " << l[0] << endl;
	cout << "l[1]: " << l[1] << endl;
	cout << "l[2]: " << l[2] << endl;
	cout << "l[3]: " << l[3] << endl;
	cout << "l[l.size()-1]: " << l[l.size() - 1] << endl;

	cout << "\nnode size values" << endl;
	cout << "lnode size is (indices per node): " << l.m_nodeSize << endl;
	cout << "l sizeof(Node) (bytes): " << l.getSizeOfNode() << endl;
	cout << "comp sizeof(Node) (bytes): " << test.getSizeOfNode() << endl;

	cout << "lltest node size is (indices per node): " << lltest.m_nodeSize << endl;
	cout << "lltest sizeof(Node) (bytes): " << lltest.getSizeOfNode() << endl;
	cout << "\nremove by index test" << endl;
	cout << "lltest[0]: " << lltest[0] << endl;
	cout << "lltest[1]: " << lltest[1] << endl;
	lltest.removeByIndex(0);
	cout << "remove at index 0" << endl;
	cout << "lltest[0]: " << lltest[0] << endl;
	cout << "lltest[1]: " << lltest[1] << endl;

	for (int i = 0;i < 6;i++)
	{
		cout << "lltest[" << i << "]: " << lltest[i] << endl;
	}
	lltest.removeAllByValue(1);
	cout << "\nRemoving all 1 from lltest" << endl;

	for (int i = 0;i < 6;i++)
	{
		cout << "lltest[" << i << "]: " << lltest[i] << endl;
	}
}
