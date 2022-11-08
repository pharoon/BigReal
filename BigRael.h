// Created by mostafa on 11/8/2022.

#ifndef MAIN_CPP_BIGRAEL_H
#define MAIN_CPP_BIGRAEL_H
#include <iostream>
#include "BigDecimalIntClass.h"

class BigReal {
    //Member variables
    BigDecimalInt dec_part, frac_part;
    size_t size_frac{};
public :
    //Constructor
    BigReal() = default;

    explicit BigReal(double num_param);

    explicit BigReal(BigDecimalInt Bigint_param){
        dec_part = Bigint_param;
    }

    explicit BigReal(std::string num_param);

    //Functions (methods)

    //getter methods


    //Setter methods

    //operators methods


};

class BigRael {

};


#endif //MAIN_CPP_BIGRAEL_H
