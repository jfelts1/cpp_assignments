
#include "LinkedList.h"
#include <cstdlib>

using std::cout;
using std::endl;

int main()
{
	LinkedList<int> l;
	for (int i = 0;i < 5000;i++)
	{
		l.add(i);
	}
	for (int j = 0;j < 5000;j++)
	{
		cout << l[j]<< endl;
	}

	cout << "node size is: " << l._nodeSize << endl;
	return EXIT_SUCCESS;
}

