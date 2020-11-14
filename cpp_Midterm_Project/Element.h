//
//  Element.h
//  cpp_Midterm2
//
//  Created by Nguyen Le Khanh Ngoc on 11/11/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//

#ifndef Element_h
#define Element_h
class Element {
public:
    //Constructor
    explicit Element();
    explicit Element (int coeff);                   //4, -5
    explicit Element (int var, int exp);            //x^2
    explicit Element (int coeff, char var);         //4x, -5x
    explicit Element (int coeff, char var, int exp);//3x^2, -x^2
    int getCoeff () const;
    char getVar () const;
    int getExp () const;
private:
    int e_coeff;
    char e_var = '\0';
    int e_exp;
};

#endif /* Element_h */
