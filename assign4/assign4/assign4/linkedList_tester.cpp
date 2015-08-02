
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
	int check = 0;
	//cuts the output time in half on windows!
	check = setvbuf(stdout, NULL, _IOFBF,10000);
	if (check != 0)
	{
		std::cerr << "Unable to set buffer size" << endl;
	}

	cout << l << endl;
	//assignment test
	l2 = l;
	l.clear();
	cout << "l2" << l2 << endl;
	cout << "l == l2 " << ((l == l2) ? "false": "true") << endl;
	cout << "node size is: " << l._nodeSize << endl;
	return EXIT_SUCCESS;
}

