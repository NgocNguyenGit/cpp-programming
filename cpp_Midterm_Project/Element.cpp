//
//  Element.cpp
//  cpp_Midterm2
//
//  Created by Nguyen Le Khanh Ngoc on 11/11/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//

#include <iostream>
#include "Element.h"
//Constructor - default
Element::Element(){
    e_coeff = 0;
    e_var = 0;
    e_exp = 0;
}

//Constructor - 1 parameter: coeff
Element::Element (int coeff){                   //4, -5
    e_coeff = coeff;
    e_exp = 0;                                  //no matter var
}

//Constructor - 2 parameter: var + exp
Element::Element (int var, int exp){            //x^2
    e_coeff = 1;
    e_var = var;
    e_exp = exp;
}

//Constructor - 2 parameter: coeff + var
Element::Element (int coeff, char var){         //4x, -5x
    e_coeff = coeff;
    e_var = var;
    e_exp = 1; 
}

//Constructor - 3 parameter: coeff + var + exp
Element::Element (int coeff, char var, int exp){//3x^2, -x^2
    e_coeff = coeff;
    e_var = var;
    e_exp = exp;
}

//get function - values to be used in polynomial
int Element::getCoeff () const {
    return e_coeff;
}
char Element::getVar () const {
    return e_var;
}
int Element::getExp () const {
    return e_exp;
}
