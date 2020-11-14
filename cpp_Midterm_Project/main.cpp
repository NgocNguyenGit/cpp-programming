//
//  main.cpp
//  cpp_Midterm2
//
//  Created by Nguyen Le Khanh Ngoc on 11/11/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//

#include <iostream>
#include "Polynomial.h"   //Polynomial header
#include "Header.h"       //Default header
using namespace std;

int main(int argc, const char * argv[]) {
    int action;
    printAction();
    cin>>action; //initialise action to take
    
    //loop until sentinel value read from user
    while (action != 3){ //sentinel value
        if (action == 1){
             printHeader();
        }
        
        if (action == 2) {
            printPhase("    Data Input Phase    ");
            Polynomial p1("1");
            Polynomial p2("2");
            
            printPhase("  Multiplication Phase  ");
            Polynomial p3 = p1 * p2;
            cout<<p3;
            
            printPhase("    Evaluation Phase    ");
            p3.evaluate();
        }
        
        cout<<endl;
        printAction();
        cin>>action;
    }
    
    //Quit the program
    cout<<"Terminating..."<<endl;
    
    return 0;
}
