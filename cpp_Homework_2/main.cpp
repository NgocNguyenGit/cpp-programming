//
//  main.cpp
//  cpp_Homework2
//
//  Created by Nguyen Le Khanh Ngoc on 26/10/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//
/*
A large company pays its salespeople on a commission basis.

The salespeople each receive 150€ per week plus 12% of their gross sales for that week.

For example, a salesperson who sells 6000€ worth of chemicals in a week receives 150€ plus 12% of 6000€, or a total of 870€.
 
Develop a C++ program that uses a while statement to input each salesperson’s gross sales for last week and calculates and displays that salesperson’s earnings. Process one salesperson’s figures at a time.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//initialise function
void checkGS (float input, float *number); //determine whether gross sale is positive or not
int main(int argc, const char * argv[]) {
    //initialisation phase
    float total{0}; //initialise salesperson's earnings
    int fixedSalary = 150; //initialise fixed salary 150€ per week
    float percent = 0.12; //initialise 12% commission percent of gross sales
    string name; //initialise name of salesperson
    
    //processing phase
    //prompt for input and read salesperson's gross sales for last week
    cout<<"Enter gross sales for that week or -1 to quit: ";
    float grossSale; //initialise gross sales for that week
    cin>>grossSale;
    
    //loop until sentinel value read from user
    while (grossSale != -1){
        //validate input ONCE
        checkGS (grossSale, &grossSale);
        
        cout<<"                    Enter name of salesperson: ";
        cin>>name;
        //calculates that salesperson’s earnings
        total = fixedSalary + percent * grossSale;
        
        //display headers
        cout<<"\nNAME"<<setw(20)<<"TOTAL"<<endl;
        
        //display that salesperson’s earnings
        cout.width(9);
        cout<<setw(4)<<name<<setw(20)<<total<<endl;
        
        cout<<endl;

        //prompt for input and read salesperson's gross sales for last week
        cout<<"Enter gross sales for that week or -1 to quit: ";
        cin>>grossSale;
    }
    
    //Quit the program
    cout<<"Terminating..."<<endl;
    return 0;
}
void checkGS (float input, float *number){
    if (input < 0 && input != -1){
        cout<<"Invalid amount of gross sales."<<endl;
        cout<<endl;
        //prompt for input and read salesperson's gross sales for last week
        cout<<"Enter gross sales for that week or -1 to quit: ";
        cin>>*number;
    }
}
