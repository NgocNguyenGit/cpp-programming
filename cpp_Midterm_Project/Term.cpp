//
//  Term.cpp
//  cpp_Midterm2
//
//  Created by Nguyen Le Khanh Ngoc on 11/11/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//
#include "Term.h"
#include "Element.h"
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
//Constructor - default
Term::Term (){
    
}

//Constructor - 1 parameter: str => parse + extract each element (coeff, var, exp)
Term::Term (string str){
    parseTerm(str);
}

//Constructor - 1 parameter: vector<Element> =>
Term::Term (vector<Element> elements){
    e.reserve(elements.size()); //make a place for data input
    e.insert(e.end(), elements.begin(), elements.end()); //insert value from begin to end
}

//Parse and set string to each element: e.g. -4x^2y^3z => -4x^2  y^3  z
void Term::parseTerm(string str){
    int index = 0;                   //point first char in string
    string temp;
    
    while (!isalpha(str[index])){    //first char is a numeric char
        temp += str[index];
        str.erase(0, 1);
        
        if (str == ""){
            break;
        }
    }
    
    //Extract coeff
    if (temp == "" || temp == "+"){
        e.push_back(Element(1));
    } else if (temp == "-"){
        e.push_back(Element(-1));
    } else {
        e.push_back(Element(stoi(temp)));
    }
    
    //Extract the rest. Rule: Exponent < 10
    for (int i = 0; i < str.size(); ++i){
        if(isalpha(str[i])){
            if(str[i+1] == '^'){
                e.push_back(Element(str[i], str[i+2] - '0')); //convert char to int
                i += 2; //x^6zy^3 => move to z
            } else {
                e.push_back(Element(str[i], 1)); //zy^3 => z^1
            }
        }
    }
}

//Operator overload for multiplying two terms
Term Term::operator* (const Term& t){
    int new_coeff{1};
    vector<Element> new_elements;
    vector<char> new_var;
    vector<int> new_exp;
    
    //Multiply coeffs of each element in term
    for (int i = 0; i < e.size(); ++i){
        new_coeff *= e[i].getCoeff();
    }
    //Multiply coeffs of each term in poly
    for (int i = 0; i < t.e.size(); ++i){
        new_coeff *= t.e[i].getCoeff();
    }
    new_elements.push_back(Element(new_coeff));
    
    //Get var + exp of each element
    for (int i = 0; i < e.size(); i++){
        new_var.push_back(e[i].getVar());
        new_exp.push_back(e[i].getExp());
    }
    
    //find var in terms
    for (int i = 0; i < t.e.size(); i++){
        auto  it = find(new_var.begin(), new_var.end(), t.e[i].getVar());
        if (it == new_var.end()) // not found
        {
            new_var.push_back(t.e[i].getVar());
            new_exp.push_back(t.e[i].getExp());
        }
        else
        {
            new_exp[it - new_var.begin()] += t.e[i].getExp();
        }
    }
    
    for (int i = 0; i < new_var.size(); i++)
    {
        if (new_exp[i] != 0){
            new_elements.push_back(Element(new_var[i], new_exp[i]));
        }
    }
    return Term(new_elements);
}

vector<Element> Term::getElement () const {
    return e;
}

//Evaluate in term
double Term::evaluateTerm (vector<char> store_var, vector<double> store_value){
    double result{1};
    for (int i = 0; i < e.size(); ++i){
        result = result * e[i].getCoeff();
        
        if (find(store_var.begin(), store_var.end(), e[i].getVar()) != store_var.end()){
            result = result * pow(store_value[find(store_var.begin(), store_var.end(), e[i].getVar()) - store_var.begin()], e[i].getExp());
        }
    }
    return result;
}
