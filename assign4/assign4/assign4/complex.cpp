/*
 * James Felts
 * Compilers Used
 * Visual C++ 2013
 * g++ 4.92
 * Visual C++ 2015 X64 target use the project settings
 * g++ 5.1 flags used g++-5 -Wall -Wextra -O2 *.cpp -std=c++14
 * 
 * doesn't handle spaces in input but can handle certain expressions like
 * just i or -i or simpily numbers like 5 or -9
 */
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

bool Complex::operator==(const Complex& in)const
{
	if (_realPart == in.getRealPart() && _imaginaryPart == in.getImaginaryPart())
	{
		return true;
	}
	return false;
}

bool Complex::operator!=(const Complex& in)const
{
	return !(*this == in);
}

ostream& operator<<(ostream& out, const Complex& complex)
{
	complex.displayRealPart();
	complex.displayImaginaryPart();
	
	if (complex.getRealPart() == 0 && complex.getImaginaryPart() == 0)
	{
		out << 0;
	}
	return out;
}

inline void Complex::displayRealPart()const
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

inline void Complex::displayImaginaryPart()const
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
		size_t delimIndex = findDelimIndex(s, n);
		complex.setImaginaryPart(s, delimIndex,n);
		complex.setRealPart(s, delimIndex);

	}


	return in;
}

inline size_t findDelimIndex(const string& in, const string::size_type& pos)
{
	size_t index = pos;
	size_t delimIndex = 0;

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

inline void Complex::setImaginaryPart(const string& in, const size_t& delimIndex, const string::size_type& iPos)
{
	if (in == "i")
	{
		_imaginaryPart = 1;
	}
	else if (in == "-i")
	{
		_imaginaryPart = -1;
	}
	else
	{
		string imag = in.substr(delimIndex, iPos-delimIndex);
		_imaginaryPart = stod(imag);
	}
}

inline void Complex::setRealPart(const string& in, const size_t& delimIndex)
{
	//if the delim is the first thing in the string the real part is 0
	if (delimIndex != 0)
	{
		string real = in.substr(0, delimIndex);
		_realPart = stod(real);
	}
	else
	{
		_realPart = 0;
	}

}
