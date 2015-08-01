
#include "LinkedList.h"
#include <cstdlib>
#include <cstdio>

using std::cout;
using std::endl;

int main()
{
	LinkedList<int> l;
	LinkedList<int> l2;
	for (int i = 0;i < 5000;i++)
	{
		l.add(i);
	}
	int check = 0;
	//cuts the output time in half!
	check = setvbuf(stdout, NULL, _IOFBF,10000);
	if (check != 0)
	{
		std::cerr << "Unable to set buffer size" << endl;
	}

	for (int j = 0;j < 5000;j++)
	{
		cout << l[j]<< endl;
	}
	//deep copy test
	l2 = l;
	l.clear();
	for (int j = 0;j < 5000;j++)
	{
		cout << l2[j] << endl;
	}
	cout << "node size is: " << l._nodeSize << endl;
	return EXIT_SUCCESS;
}

