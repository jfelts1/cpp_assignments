
#include "LinkedList.h"
#include <cstdlib>

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
	for (int j = 0;j < 5000;j++)
	{
		cout << l[j]<< endl;
	}
	l2 = l;
	for (int j = 0;j < 5000;j++)
	{
		cout << l2[j] << endl;
	}
	cout << "node size is: " << l._nodeSize << endl;
	return EXIT_SUCCESS;
}

