//
//  Term.h
//  cpp_Midterm2
//
//  Created by Nguyen Le Khanh Ngoc on 11/11/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//

#ifndef Term_h
#define Term_h
#include <iostream>
#include <string>
#include <vector>
#include "Element.h"
using namespace std;
class Term {
public:
    //Constructor
    explicit Term ();
    explicit Term (string str);
    explicit Term (vector<Element> elements);
    //Parse and set string of each term to vector's element
    void parseTerm (string str);
    //Operator overload for two terms
    Term operator* (const Term& t);
    //Get vector element
    vector<Element> getElement () const;
    //Evaluate in term
    double evaluateTerm (vector<char> store_var, vector<double> store_value);
private:
    vector<Element> e;
};
#endif /* Term_h */
