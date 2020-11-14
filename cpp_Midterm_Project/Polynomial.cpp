//
//  Polynomial.cpp
//  cpp_Midterm2
//
//  Created by Nguyen Le Khanh Ngoc on 11/11/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//
#include "Polynomial.h"
#include <string>           //string type
#include <string.h>
#include <vector>           //vector
#include <ctype.h>          //isalpha
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;
//Constructor
Polynomial::Polynomial (string num){
    //Polynomial
    cout<<"p"<<num<<": ";
    string f;
    cin>>f;
    parsePoly(f);
}

//Constructor
Polynomial::Polynomial(vector<Term> terms){
    t.reserve(terms.size());
    t.insert(t.end(), terms.begin(), terms.end());
}

//Parse and set string to each term
void Polynomial::parsePoly(const string str){
    size_t position = 0;                  //point each char in string
    string temp, term;
    
    for (int i = 0; i < str.size(); i++){
        //reach + or - => save to temp data on the left
        if (str[i] != '+' && str[i] != '-'){
            temp += str[i];
        }
        else{
            temp += ";";
            temp += str[i];
        }
    }
    //add ; after an element
    temp += ";";
    
    //error handling e.g. ;-4xy;+2
    if (temp[0] == ';'){
        temp.erase(0,1);
    }
    
    while ((position = temp.find(";")) != string::npos) {  //reach ; => push back the left term && erase it
        term = temp.substr(0, position);
        t.push_back(Term(term));
        temp.erase(0, position + 1);
    }
}

Polynomial Polynomial::operator* (const Polynomial& p){
    vector<Term> new_terms;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < p.t.size(); j++){
            new_terms.push_back(t[i] * p.t[j]);
        }
    }
    
    return Polynomial(new_terms);
}

ostream& operator<< (ostream& output, const Polynomial& p){
    cout<<"p1 * p2 = p3: ";
    for (int i = 0; i < p.t.size(); ++i){
        for (int j = 0; j < p.t[i].getElement().size(); ++j){
            //first element always contains coeff
            if (j == 0){
                //if 1x => x
                if(p.t[i].getElement()[j+1].getCoeff() == 1){ //e.g. test: p1:-3x^2-1 result = 3x^2+3x^3y+1+xy
                                                              //           p2:-1-xy   instead= 3x^2+3x^3y+1+1xy
                    if(p.t[i].getElement()[j].getCoeff() == 1){
                        output<<"";
                    } else if (p.t[i].getElement()[j].getCoeff() == -1){
                        output<<"-";
                    } else {
                        output<<p.t[i].getElement()[j].getCoeff();
                    }
                } else {
                    output<<p.t[i].getElement()[j].getCoeff();
                }
            } else { //if 1x^1 => print only 1x else print e.g. x^2
                if (p.t[i].getElement()[j].getExp() == 1){
                    output<<p.t[i].getElement()[j].getVar();
                } else {
                    output<<p.t[i].getElement()[j].getVar()<<"^"<< p.t[i].getElement()[j].getExp();
                }
            }
        }
        
        if (i != p.t.size() -1){ //error handling: trailing plus otherwise -4x^2y+3+
            //error handling: no add + before negative coeff e.g. -36x^2 instead +-36x^2
            if (p.t[i+1].getElement()[0].getCoeff() < 0){
                continue;
            }
            cout << "+";
        }
    }
    
    
    return output << endl;
}

//evaluate
void Polynomial::evaluate(){
    vector<char> store_var;
    vector<double> store_value;
    double temp;
    long double sum{0.0};

    for (int i = 0; i < t.size(); ++i){
        for (int j = 0; j < t[i].getElement().size(); ++j){
            if (isalpha (t[i].getElement()[j].getVar())){
                //check if variable already print or not
                if (find(store_var.begin(), store_var.end(), t[i].getElement()[j].getVar()) != store_var.end()) {
                    continue;
                }
                cout<<t[i].getElement()[j].getVar()<<": ";
                cin>>temp;
                store_value.push_back(temp);
                store_var.push_back(t[i].getElement()[j].getVar());
                
                //sum of terms
            }
        }
    }
    for (int i = 0; i < t.size(); ++i){
        sum += t[i].evaluateTerm(store_var, store_value);
    }
    cout<<"Result: "<<sum<<endl;
}
