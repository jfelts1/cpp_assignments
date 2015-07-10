#include "complex.h"
#include <limits>

bool menu(Complex& c1, Complex& c2);
void getComplexValueFromUser(Complex& complex);

int main()
{
	Complex c1, c2;
	getComplexValueFromUser(c1);
	getComplexValueFromUser(c2);

	while (menu(c1, c2)){};

	return 0;
}

bool menu(Complex& c1, Complex& c2)
{
	int choice = 0;
	Complex temp;
	string menuText = 
	"\nComplex Number Menu\n\
1) Quit\n\
2) Add\n\
3) Subtract\n\
4) Multiply\n\
5) New c1\n\
6) New c2\n\
7) Equal\n\
8) Not Equal\n";

	cout << menuText << endl;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl<<endl;

	cin >> choice;
	while (choice > 8 || choice < 1)
	{
		cout << "Invalid Input\n" << endl; 
		cin >> choice;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch (choice)
	{
		case 1:
			return false;
			break;
		case 2:
			temp = c1 + c2;
			cout << temp << endl;
			break;
		case 3:
			temp = c1 - c2;
			cout << temp << endl;
			break;
		case 4:
			temp = c1 * c2;
			cout << temp << endl;
			break;
		case 5:
			getComplexValueFromUser(c1);
			break;
		case 6:
			getComplexValueFromUser(c2);
			break;
		case 7:
			if (c1 == c2)
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}
			break;
		case 8:
			if (c1 != c2)
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}
			break;
		default:
			break;
	}
	
	return true;
}

inline void getComplexValueFromUser(Complex& complex)
{
	cout << "Enter a complex number." << endl;
	cin >> complex;
}