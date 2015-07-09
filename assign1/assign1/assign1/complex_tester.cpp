#include "complex.h"

int main()
{
	Complex c1(0, -1), c2(0, -1), c3, c4(5,2), c5(1,-5), c6(0,-2), c7(1,1),c8(-2,0), c9;

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
	}



	return 0;
}