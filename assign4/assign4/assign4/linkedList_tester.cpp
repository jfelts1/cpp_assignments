/*
 * James Felts
 *
 * Compilers Used
 * Visual C++ 2015 X64 target 
 * g++ 5.1
 */
#include "LinkedList.h"
#include <cstdlib>
#include <cstdio>
#include <list>
#include <vector>
#include <chrono>

using std::cout;
using std::endl;

int main()
{
	int check = 0;
	//cuts the output time by a factor of 10 or so on windows!
	check = setvbuf(stdout, NULL, _IOFBF, 10000);
	if (check != 0)
	{
		std::cerr << "Unable to set buffer size" << endl;
	}

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

	cout << "l == l2 " << ((l == l2) ? "true" : "false") << endl;
	cout << "l != l2 " << ((l != l2) ? "true" : "false") << endl;
	cout << "l == l5 " << ((l == l5) ? "true" : "false") << endl;
	cout << "l == l3 " << ((l == l3) ? "true" : "false") << endl;
	cout << "l != l4 " << ((l != l4) ? "true" : "false") << endl;
	cout << "node size is: " << l.m_nodeSize << endl;
	l.add(999999, 1);
	cout << "l[0]: " << l[0] << endl;
	cout << "l[1]: " << l[1] << endl;
	cout << "l[2]: " << l[2] << endl;
	cout << "l[3]: " << l[3] << endl;
	cout << "l[l.size()-1]: " << l[l.size() - 1] << endl;
	l.removeByValue(999999);
	cout << "l.remove(999999)" << endl;
	cout << "l[0]: " << l[0] << endl;
	cout << "l[1]: " << l[1] << endl;
	cout << "l[2]: " << l[2] << endl;
	cout << "l[3]: " << l[3] << endl;
	cout << "l[l.size()-1]: " << l[l.size() - 1] << endl;
	cout << "l sizeof(Node): " << l.getSizeOfNode() << endl;

	cout << "lltest node size is: " << lltest.m_nodeSize << endl;
	cout << "lltest sizeof(Node): " << lltest.getSizeOfNode() << endl;
	cout << "lltest[0]: " << lltest[0] << endl;
	cout << "lltest[1]: " << lltest[1] << endl;
	lltest.removeByIndex(0);
	cout << "lltest[0]: " << lltest[0] << endl;
	cout << "lltest[1]: " << lltest[1] << endl;

	for (int i = 0;i < 6;i++)
	{
		cout << "lltest[" << i << "]: " << lltest[i] << endl;
	}
	lltest.removeAllByValue(1);
	cout << "Removing 1 from lltest" << endl;

	for (int i = 0;i < 6;i++)
	{
		cout << "lltest[" << i << "]: " << lltest[i] << endl;
	}

	/*std::list<int> test;
	for (int i = 0; i < 50000;i++)
	{
		test.push_back(i);
	}
	for (int i : test)
	{
		cout << i << "\n";
	}
	cout<<endl;*/

	/*std::vector<int> test2;
	for (int i = 0; i < 50000;i++)
	{
		test2.push_back(i);
	}
	for (int i : test2)
	{
		cout << i << "\n";
	}
	cout << endl;*/

	return EXIT_SUCCESS;
}

