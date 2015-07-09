#include "complex.h"

bool menu(Complex c1, Complex c2);
void getComplexValueFromUser(Complex& complex);

int main()
{
	/*Complex c1(0, -1), c2(0, -1), c3, c4(5,2), c5(1,-5), c6(0,-2), c7(1,1),c8(-2,0), c9;

	cout <<"c1: "<< c1 << "\nc2: " << c2 << endl;

	c3 = c1*c2;
	cout << "c3: " << c3 << endl;
	cout << "c4: " << c4 << "\nc5: " << c5 << "\nc6: " << c6 << "\nc7: " << c7 << "\nc8: " << c8 << "\nc9: " << c9 << endl;
	Complex ci(5, 5);
	cout << "ci: " << ci << endl;
	cin >> ci;
	cout << "ci: " << ci << endl;
	if (ci == c4)
	{
		cout << "ci: " << ci << " is equal to c4: " << c4 << endl;
	}
	else
	{
		cout << "ci: " << ci << " is not equal to c4: " << c4 << endl;
	}

	if (ci != c5)
	{
		cout << "ci: " << ci << " is not equal to c5: " << c5 << endl;
	}
	else
	{
		cout << "ci: " << ci << " is equal to c5: " << c5 << endl;
	}*/

	Complex c1, c2;
	getComplexValueFromUser(c1);
	getComplexValueFromUser(c2);

	while (menu(c1, c2)){};

	return 0;
}

bool menu(Complex c1, Complex c2)
{
	int choice = 0;
	Complex temp;
	string menuText = 
	"Complex Number Menu\n\
1) Quit\n\
2) Add\n\
3) Subtract\n\
4) Multiply\n\
5) New c1\n\
6) New c2\n";

	cout << menuText << endl;

	cin >> choice;
	while (choice > 6 || choice < 1)
	{
		cout << "Invalid Input\n" << endl; 
		cin >> choice;
	}
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