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
	//copy assignment test
	l2 = l;
	//addition operator test and move assignment test
	l4 = l + l2;

	LinkedList<int> l5 = std::move(l2);

	cout << l3 << endl;
	cout << l4 << endl;
	cout << "l == l2 " << ((l == l2) ? "true" : "false") << endl;
	cout << "l != l2 " << ((l != l2) ? "true" : "false") << endl;
	cout << "l == l5 " << ((l == l5) ? "true" : "false") << endl;
	cout << "l == l3 " << ((l == l3) ? "true" : "false") << endl;
	cout << "l != l4 " << ((l != l4) ? "true" : "false") << endl;
	cout << "node size is: " << l._nodeSize << endl;
	l.add(999999, 1);
	cout << "l[0]: " << l[0] << endl;
	cout << "l[1]: " << l[1] << endl;
	cout << "l[2]: " << l[2] << endl;
	cout << "l[3]: " << l[3] << endl;
	cout << "l[l.size()-1]: " << l[l.size()-1] << endl;
	l.remove(999999);
	cout << "l.remove(999999)" << endl;
	cout << "l[0]: " << l[0] << endl;
	cout << "l[1]: " << l[1] << endl;
	cout << "l[2]: " << l[2] << endl;
	cout << "l[3]: " << l[3] << endl;
	cout << "l[l.size()-1]: " << l[l.size() - 1] << endl;

	return EXIT_SUCCESS;
}

