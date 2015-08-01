
#include "LinkedList.h"
#include <cstdlib>

int main()
{
	LinkedList<int> l;
	for (int i = 0;i < 5000;i++)
	{
		l.add(i);
	}
	for (int j = 0;j < 5000;j++)
	{
		std::cout << l[j]<< std::endl;
	}
	return EXIT_SUCCESS;
}

