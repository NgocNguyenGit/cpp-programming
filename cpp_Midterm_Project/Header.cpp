//
//  Header.cpp
//  cpp_Midterm2
//
//  Created by Nguyen Le Khanh Ngoc on 11/11/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//
#include <iostream>
#include "Header.h"
#include <string>
using namespace std;
void printHeader(){
    cout<<endl;
    cout<<"Format | (coefficient)(variable name)^(exponent)"<<endl;
    cout<<"–––––––|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"<<endl;
    cout<<"Rules  | Terms must be SIMPLIFIED"<<endl;
    cout<<"       | Each term includes coefficient    –– (integer, max. 1 value)"<<endl;
    cout<<"       |                    variable names –– (alphabetical character, ascending order)"<<endl;
    cout<<"       |                    exponents according to each variable –– (integer, 0 <= value < 10)"<<endl;
    cout<<"       | NO SPACE ACCEPTED"<<endl;
    cout<<"–––––––|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"<<endl;
    cout<<"Example| ACCEPT -4x^2y^3z+2x NOT -4x^2y^3zx^6 NOR -4x^2 + 3"<<endl;
    cout<<"–––––––|––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"<<endl;
    cout<<"Note   | Values for evaluation phase can be in DOUBLE type"<<endl;
}

void printPhase(string str){
    string asterisk = "********************";
    cout<<"\n"<<asterisk<<str<<asterisk<<endl;
}

void printAction(){
    cout<<"1 – Format rule"<<endl;
    cout<<"2 – Polynomial Calculator"<<endl;
    cout<<"3 – Quit"<<endl;
    cout<<"Enter action: ";
}
