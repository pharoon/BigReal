#include <iostream>
#include "bigreal.h"


BigDecimalInt bigreal::getwhole()
{
	return whole;
}
BigDecimalInt bigreal::getfraction()
{
	return fraction;
}
bool bigreal:: operator==(bigreal anotherreal)
{
	if ((this->whole == anotherreal.getwhole()) && (this->fraction == anotherreal.getfraction()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool bigreal :: operator>(bigreal other)
{
	if (signof == '+')
	{
		if (other.sign() == '-')
		{
			return true;
		}
		else
		{
			if (whole == other.getwhole())
			{
				if (fraction > other.getfraction())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (whole > other.getwhole())
			{
				return true;
			}
			else if (whole < other.getwhole())
			{
				return false;
			}
		}
	}
	else if (signof == '-')
	{
		if (other.sign() == '+')
		{
			return false;
		}
		else if (other.sign() == '-')
		{
			if (whole < other.getwhole())
			{
				return true;
			}
			if (whole == other.getwhole())
			{
				if (fraction < other.getfraction())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
}

bool bigreal::operator<(bigreal other)
{
	if (signof == '-')
	{
		if (other.sign() == '+')
		{
			return true;
		}
		else
		{
			if (other.getwhole() < whole)
			{
				return true;
			}
			else if (other.getwhole() == whole)
			{
				if (other.getfraction() < fraction)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	else if (signof == '+')
	{
		if (other.sign() == '-')
		{
			return false;
		}
		else
		{
			if (other.getwhole() > whole)
			{
				return true;
			}
			else if (other.getwhole() == whole)
			{
				if (other.fraction > fraction)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
}

int bigreal::size()
{
	return whole.size() + fraction.size();
}

int bigreal::sign()
{
	return signof;
}

ostream& operator<<(ostream& out, bigreal num)
{
	out << num.getwhole() << "." << num.getfraction();
	return out;
}
istream& operator>>(istream& in, bigreal num)
{
	string input;
	in >> input;
	if (input[0] == '-')
		num.signof = '-';
	else
		num.signof = '+';
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '.')
		{
			string whole;
			string fraction;
			for (int j = 0; j < i; j++)
			{
				whole[j] = input[j];
				fraction[j] = input[i + j];
			}
			BigDecimalInt newwhole(whole);
			BigDecimalInt newfraction(fraction);
			num.whole = newwhole;
			num.fraction = newfraction;
		}
	}
	return in;
}
