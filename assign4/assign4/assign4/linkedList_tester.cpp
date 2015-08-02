/*
 *James Felts
 *
 * Compilers Used
 * Visual C++ 2015 X64 target 
 */
#include "LinkedList.h"
#include <cstdlib>
#include <cstdio>

using std::cout;
using std::endl;

int main()
{
	LinkedList<int> l;
	LinkedList<int> l2;
	for (int i = 0;i < 50000;i++)
	{
		l.add(i);
	}
	//copy constructor test
	LinkedList<int> l3(l);

	LinkedList<int> l4;
	int check = 0;
	//cuts the output time by a factor of 10 or so on windows!
	check = setvbuf(stdout, NULL, _IOFBF,10000);
	if (check != 0)
	{
		std::cerr << "Unable to set buffer size" << endl;
	}

	cout << l << endl;
	//assignment test
	l2 = l;
	//addition operator test
	l4 = l + l2;

	//cout << "l2" << l2 << endl;
	cout << l3 << endl;
	cout << l4 << endl;
	cout << "l == l2 " << ((l == l2) ? "true" : "false") << endl;
	cout << "l != l2 " << ((l != l2) ? "true" : "false") << endl;
	cout << "l == l3 " << ((l == l3) ? "true" : "false") << endl;
	cout << "l != l4 " << ((l != l4) ? "true" : "false") << endl;
	cout << "node size is: " << l._nodeSize << endl;

	return EXIT_SUCCESS;
}

