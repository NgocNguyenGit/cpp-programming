//
//  Polynomial.h
//  cpp_Midterm2
//
//  Created by Nguyen Le Khanh Ngoc on 11/11/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h
#include <iostream>
#include <vector>
#include "Term.h"
#include <string>
using namespace std;
class Polynomial {
    friend ostream& operator<< (ostream& output, const Polynomial& p);
public:
    //Constructor
    explicit Polynomial ();             //default
    explicit Polynomial (string num);
    explicit Polynomial (vector<Term> terms);
    //Parse and set string of each polynomial to vector's term
    void parsePoly (const string str);
    //Operator overload: multiply, print out
    Polynomial operator*(const Polynomial& p);
    //evaluate
    void evaluate ();
    
private:
    vector<Term> t;
    string num;
};
#endif /* Polynomial_h */
