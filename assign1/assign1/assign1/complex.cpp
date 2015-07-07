#include "complex.h"

Complex::Complex(double realPart, double imaginaryPart)
{
	_realPart = realPart;
	_imaginaryPart = imaginaryPart;
}

Complex::~Complex()
{
}

Complex Complex::operator+(const Complex& in)const
{
	Complex out;

	out._realPart = _realPart + in.getRealPart();
	out._imaginaryPart = _imaginaryPart + in.getImaginaryPart();

	return out;
}

Complex Complex::operator-(const Complex& in)const
{
	Complex out;

	out._realPart = _realPart - in.getRealPart();
	out._imaginaryPart = _imaginaryPart - in.getImaginaryPart();

	return out;
}

Complex Complex::operator*(const Complex& in)const
{
	Complex out;

	out._realPart = _realPart * in.getRealPart() - _imaginaryPart*in.getImaginaryPart();
	out._imaginaryPart = _imaginaryPart*in.getRealPart() + _realPart*in.getImaginaryPart();

	return out;
}

ostream& operator<<(ostream& out, const Complex& complex)
{
	complex.displayRealPart();
	complex.displayImaginaryPart();
	
	if (complex.getRealPart() == 0 && complex.getImaginaryPart() == 0)
	{
		out << 0;
	}

	out << endl;
	return out;
}

void Complex::displayRealPart()const
{
	if (getRealPart() != 0)
	{
		cout << getRealPart();
		//positive values don't include a + sign when output, so they must added manualy
		if (getImaginaryPart() > 0)
		{
			cout << "+";
		}
	}
}

void Complex::displayImaginaryPart()const
{
	if (getImaginaryPart() != 0)
	{
		if (getImaginaryPart() == 1)
		{
			cout << "i";
		}
		else if (getImaginaryPart() == -1)
		{
			cout << "-i";
		}
		else
		{
			cout << getImaginaryPart() << "i";
		}
	}
}

istream& operator>>(istream& in, Complex& complex)
{
	string s;
	getline(cin, s);
	string::size_type n;
	n = s.find('i');
	//if there is no i assume the number is non-zero in the real only
	if (n == string::npos)
	{
		complex._realPart = stod(s);
		complex._imaginaryPart = 0;
	}
	else
	{
		int delimIndex = complex.findDelimIndex(s, n);
		complex._imaginaryPart = complex.findImaginaryPart(s, delimIndex,n);
		complex._realPart = complex.findRealPart(s, delimIndex);

	}


	return in;
}

int Complex::findDelimIndex(const string& in, const string::size_type& pos)
{
	int index = pos;
	int delimIndex = 0;

	while (index > 0)
	{
		if (in[index] == '-' || in[index] == '+')
		{
			delimIndex = index;
			index -= pos;
		}
		index--;
	}

	return delimIndex;
}

double Complex::findImaginaryPart(const string& in, const int& delimIndex, const string::size_type& iPos)
{
	string imag = in.substr(delimIndex, iPos-delimIndex);
	return stod(imag);
}

double Complex::findRealPart(const string& in, const int& delimIndex)
{
	//if the delim is the first thing in the string the real part is 0
	if (delimIndex != 0)
	{
		string real = in.substr(0, delimIndex);
		return stod(real);
	}
	else
	{
		return 0;
	}

}