/*
* James Felts
* should be able to handle up to (2^64) digit numbers in theory
* limited to about 16000 digits due to string length limitions
*
* no multiplication and substraction is buggy
*
* compilers used
* Visual c++ 2013 targeting x64
* g++ 4.9.2 doesn't compile
*/
#include "BigInteger.h"
using namespace std;


BigInteger::BigInteger()
{
	_negative = false;
}

BigInteger::~BigInteger()
{
}

BigInteger::BigInteger(BigInteger& orig)
{
	_negative = orig.isNegative();
	long long i = 0;
	while (i < orig.numDigits())
	{
		_list.add(orig[i]);
		i++;
	}
}

BigInteger& BigInteger::operator=(BigInteger& orig)
{
	if (&orig != this)
	{
		_list.clear();
		_list = orig._list;
	}
	else
	{
		_negative = false;
	}
	return *this;
}


bool BigInteger::isNegative()const
{
	return _negative;
}

istream& operator>>(istream& in, BigInteger& bigInt)
{
	bigInt.clear();
	if (!bigInt.fillList(in))
	{
		cout << "Error filling list" << endl;
	}
	return in;
}

bool BigInteger::fillList(istream& in)
{
	string s;
	in >> s;

	long long count = 0;
	while (count < s.size())
	{
		if (isdigit(s[count]))
		{
			_list.add(s[count]-48);
		}
		else if (count == 0 && s[count] == '-')
		{
			_negative = true;
		}
		else
		{
			return false;
		}
		count++;
	}
	return true;
}

inline string BigInteger::toString()const
{
	string s;
	if (_negative)
	{
		s.push_back('-');
	}
	s.append(_list.toString());
	return s;
}

ostream& operator<<(ostream& out, const BigInteger& bigInt)
{
	out << bigInt.toString();
	return out;
}

char BigInteger::operator[](long long index)const
{
	return _list[index];
}

bool BigInteger::operator==(const BigInteger& in)const
{
	if (_list.size() == in.numDigits())
	{
		long long i = 0;
		while (i < _list.size())
		{
			if (_list[i] != in[i])
			{
				return false;
			}
			i++;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool BigInteger::operator!=(const BigInteger&in)const
{
	return !(*this == in);
}

inline long long BigInteger::numDigits()const
{
	return _list.size();
}

bool BigInteger::operator<(const BigInteger& in)const
{
	if (_list.size() == in.numDigits())
	{
		if (*this == in)
		{
			return false;
		}
		else
		{
			long long i = 0;
			while (i < _list.size())
			{
				if (_list[i] < in[i])
				{
					return true;
				}
				i++;
			}
			return false;
		}
	}
	else if (_list.size() < in.numDigits())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BigInteger::operator>(const BigInteger& in)const
{
	if (_list.size() == in.numDigits())
	{
		if (*this == in)
		{
			return false;
		}
		else
		{
			long long i = 0;
			while (i < _list.size())
			{
				if (_list[i] > in[i])
				{
					return true;
				}
				i++;
			}
			return false;
		}
	}
	else if (_list.size() > in.numDigits())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BigInteger::operator<=(const BigInteger& in)const
{
	if (*this == in)
	{
		return true;
	}
	else if (*this < in)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BigInteger::operator>=(const BigInteger& in)const
{
	if (*this == in)
	{
		return true;
	}
	else if (*this > in)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BigInteger::addDigit(const char digit)
{
	_list.add(digit);
}


//Sorry but this is full of Hack, I procastinated too long for a proper implimenation :(
BigInteger BigInteger::operator+(const BigInteger& in)const
{
	BigInteger out;
	string s;//this is a hack but I realised that the math would be displayed backwards too late to do a proper implimentaion
	char carry, temp;
	carry = 0;
	temp = 0;
	long long i1 = _list.size()-1;
	long long i2 = in.numDigits()-1;
	while (i1 >= 0 && i2 >= 0)
	{
		temp = (carry + _list[i1] + in[i2])%10;
		carry = (carry + _list[i1] + in[i2]) / 10;
		s.push_back(temp);
		i1--;
		i2--;
	}
	if (i1 >= 0)
	{
		while (i1 >= 0)
		{
			temp = (_list[i1] + carry) % 10;
			carry = (carry + _list[i1]) / 10;
			s.push_back(temp);
			i1--;
		}
	}
	if (i2 >= 0)
	{
		while (i2 >= 0)
		{
			temp = (in[i2] + carry) % 10;
			carry = (carry + in[i2]) / 10;
			s.push_back(temp);
			i2--;
		}
	}
	if (carry != 0)
	{
		s.push_back(carry);
	}

	//more hack
	long long count = s.size()-1;
	while (count >= 0)
	{
		out.addDigit(s[count]);
		count--;
	}

	return out;
}

BigInteger BigInteger::operator-(const BigInteger& in)const
{
	BigInteger out;
	string s;//this is a hack but I realised that the math would be displayed backwards too late to do a proper implimentaion
	signed char carry, temp;
	carry = 0;
	temp = 0;
	long long i1 = _list.size() - 1;
	long long i2 = in.numDigits() - 1;
	while (i1 >= 0 && i2 >= 0)
	{
		temp = ((_list[i1] - carry) - in[i2]) % 10;
		if (temp < 0)
		{
			temp = 10 - abs(temp);
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		
		s.push_back(temp);
		i1--;
		i2--;
	}
	if (i1 >= 0)
	{
		while (i1 >= 0)
		{
			temp = (_list[i1] - carry) % 10;
			carry = (_list[i1]-carry) / 10;
			s.push_back(temp);
			i1--;
		}
	}
	if (i2 >= 0)
	{
		while (i2 >= 0)
		{
			temp = (in[i2] - carry) % 10;
			carry = (in[i2] - carry) / 10;
			s.push_back(temp);
			i2--;
		}
	}
	if (carry != 0)
	{
		out._negative = true;
	}

	//more hack
	long long count = s.size() - 1;
	while (count >= 0)
	{
		out.addDigit(s[count]);
		count--;
	}

	return out;
}


void BigInteger::clear()
{
	_list.clear();
	_negative = false;
}