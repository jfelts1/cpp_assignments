#include "BigInteger.h"
using namespace std;

int main()
{
	BigInteger test;
	cout << "enter big Int 1" << endl;
	cin >> test;
	BigInteger test2;
	cout << "enter big int 2" << endl;
	cin >> test2;
	BigInteger test3;

	string s = "Enter choice:\n 1: add\n2: substract\n3:equal\n4:not equal\n5:>\n6:<\n7: new int 1\n8:new int 2\n9:quit";
	cout << s << endl;
	int choice = 0;
	while (choice != 9)
	{
		cout << s << endl;
		cin >> choice;
		if (choice == 1)
		{
			test3 = test + test2;
			cout << test3<<endl;
		}
		else if (choice == 2)
		{
			test3 = test - test2;
			cout << test3<<endl;
		}
		else if (choice == 3)
		{
			bool t = test == test2;
			cout << t << endl;
		}
		else if (choice == 4)
		{
			bool t = test != test2;
			cout << t << endl;
		}
		else if (choice == 5)
		{
			bool t = test > test2;
			cout << t << endl;
		}
		else if (choice == 6)
		{
			bool t = test < test2;
			cout << t << endl;
		}
		else if (choice == 7)
		{
			cin >> test;
		}
		else if (choice == 8)
		{
			cin >> test2;
		}
	}



	return 0;
}

