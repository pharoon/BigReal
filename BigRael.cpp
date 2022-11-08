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