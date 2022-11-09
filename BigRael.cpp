// Created by mostafa on 11/8/2022.

#include "BigRael.h"
BigReal::BigReal(double num_param){
    string num, frac;

    num = std::to_string(num_param);
    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i] == '0' ){
            num.pop_back();

        }else{
            break;
        }

    }

    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i]== '.'){
            num.pop_back();
            break;
        }
        frac = num[i] + frac;
        num.pop_back();
    }

    BigDecimalInt dec_temp(num), frac_temp(frac);
    dec_part =  dec_temp;
    frac_part = frac_temp;
}

BigReal::BigReal(std::string num_param){
std::regex filter("(\\+|-)?[0-9]+(.)?[0-9]?");
if (!std::regex_match(num_param,filter)) {
throw std::invalid_argument("number");
}

string frac;
for (int i = num_param.size() - 1; i >= 0; i--) {
if (num_param[i] == '0' ){
num_param.pop_back();
}else{
break;
}
}

for (int i = num_param.size() - 1; i >= 0; i--) {
if (num_param[i]== '.'){
num_param.pop_back();
break;
}
frac = num_param[i] + frac;
num_param.pop_back();
}

BigDecimalInt dec_temp(num_param), frac_temp(frac);
dec_part =  dec_temp;
frac_part = frac_temp;
}

//setters and getters//
BigDecimalInt BigReal::getwhole()
{
    return dec_part;
}
BigDecimalInt BigReal::getfrac()
{
    return frac_part;
}
void BigReal::setwhole(BigDecimalInt whole)
{
	dec_part = whole;
}
void BigReal::setfrac(BigDecimalInt frac)
{
	frac_part = frac;
}
//functions//
int BigReal::size()
{
	return dec_part.size() + frac_part.size();
}

char BigReal::sign()
{
	if (dec_part.Sign()) {
		return '+';
	}
	else
		return '-';
	;
}
//overloaded operators//
bool BigReal:: operator==(BigReal anotherreal)
{
	if ((this->dec_part == anotherreal.getwhole()) && (this->frac_part == anotherreal.getfrac()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BigReal :: operator>(BigReal other)
{
	if (this->sign() == '+')
	{
		if (other.sign() == '-')
		{
			return true;
		}
		else
		{
			if (dec_part == other.getwhole())
			{
				if (frac_part > other.getfrac())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (dec_part > other.getwhole())
			{
				return true;
			}
			else if (dec_part < other.getwhole())
			{
				return false;
			}
		}
	}
	else if (this->sign() == '-')
	{
		if (other.sign() == '+')
		{
			return false;
		}
		else if (other.sign() == '-')
		{
			if (dec_part < other.getwhole())
			{
				return true;
			}
			if (dec_part == other.getwhole())
			{
				if (frac_part < other.getfrac())
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

bool BigReal::operator<(BigReal other)
{
	if (this->sign() == '-')
	{
		if (other.sign() == '+')
		{
			return true;
		}
		else
		{
			if (other.getwhole() < dec_part)
			{
				return true;
			}
			else if (other.getwhole() == dec_part)
			{
				if (other.getfrac() < frac_part)
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
	else if (this->sign() == '+')
	{
		if (other.sign() == '-')
		{
			return false;
		}
		else
		{
			if (other.getwhole() > dec_part)
			{
				return true;
			}
			else if (other.getwhole() == dec_part)
			{
				if (other.getfrac() > frac_part)
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
ostream& operator<<(ostream& out, BigReal num)
{
	if (num.sign() == '-')
	{
		out << num.getwhole() << "." << num.getfrac() << endl;
	}
	else
		out << num.sign() << num.getwhole() << "." << num.getfrac();
	return out;
}
istream& operator>>(istream& in, BigReal& num)
{
	string input,whole, fraction;
	in >> input;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '.')
		{

			for (int j = 0; j < i; j++)
			{
				int x = i + 1;
				whole.push_back(input[j]);
			}
			for (int x = i + 1; x < input.size(); x++)
			{
				fraction.push_back(input[x]);
			}
		}
	}
	BigDecimalInt temp_dec(whole);
	BigDecimalInt temp_frac(fraction);
	num.setwhole(temp_dec);
	num.setfrac(temp_frac);
	return in;
}



