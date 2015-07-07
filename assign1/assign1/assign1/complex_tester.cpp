#include "complex.h"

int main()
{
	Complex c1(0, -1), c2(0, -1), c3, c4(5,2), c5(1,-5), c6(0,-2), c7(1,1),c8(-2,0), c9;

	cout <<"c1: "<< c1 << "c2: " << c2 << endl;

	c3 = c1*c2;
	cout << "c3: " << c3 << endl;
	cout << "c4: " << c4 << "c5: " << c5 << "c6: " << c6 << "c7: " << c7 << "c8: " << c8 << "c9: " << c9 << endl;
	Complex ci(5, 5);
	cout << "ci: " << ci << endl;
	cin >> ci;
	cout << "ci: " << ci << endl;




	return 0;
}