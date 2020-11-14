//
//  main.cpp
//  cpp_Homework1
//
//  Created by Nguyen Le Khanh Ngoc on 30/10/2020.
//  Copyright © 2020 Nguyen Le Khanh Ngoc. All rights reserved.
//
/*
 Develop a C++ program that will determine whether a department-store
 customer has exceeded the credit limit on a charge account. For each customer, the following facts
 are available:
 a) Account number (an integer)
 b) Balance at the beginning of the month
 c) Total of all items charged by this customer this month
 d) Total of all credits applied to this customers account this month
 e) Allowed credit limit
 The program should use a while statement to input each of these facts, calculate the new balance
 (= beginning balance + charges – credits) and determine whether the new balance exceeds the
 customer’s credit limit. For those customers whose credit limit is exceeded, the program should display
 the customer’s account number, credit limit, new balance and the message “Credit Limit Exceeded.”
 */

#include <iostream>
#include <string>
using namespace std;
void checkInput (float input, string text, float *number); //determine whether input is positive or not ONCE
void checkAccount (int input, int *number); //determine whether input is positive and different from -1 or not ONCE

int main(int argc, const char * argv[]) {
    //initialisation phase
    int accountNumber; //initialise account number (an integer)
    float balance; //initialise balance at the beginning of the month
    float totalCharge; //initialise total of all items charged by this customer this month
    float totalCredit; //initialise total of all credits applied to this customers account this month
    float creditLimit; //initialise allowed credit limit
    
    //processing phase
    //prompt for input and read account number from user
    cout<<"Enter account number or -1 to quit: ";
    cin>>accountNumber;
    
    //loop until sentinel value read from user
    while (accountNumber != -1){
        checkAccount (accountNumber, &accountNumber);
        
        //prompt for beginning input and read from user: balance, charges, credit, credit limit
        cout<<"Enter balance at the beginning of the month: ";
        cin>>balance;
        checkInput (balance, "balance at the beginning of the month", &balance);
        
        cout<<"Enter total of all items charged this month: ";
        cin>>totalCharge;
        checkInput (totalCharge, "total of all items charged this month", &totalCharge);
        
        cout<<"      Enter total of all credits this month: ";
        cin>>totalCredit;
        checkInput (totalCredit, "total of all credits this month", &totalCredit);
        
        cout<<"                 Enter allowed credit limit: ";
        cin>>creditLimit;
        checkInput (creditLimit, "allowed credit limit", &creditLimit);
        
        balance = balance + totalCharge - totalCredit; //calculate the new balance
        
        //determine whether the new balance exceeds the customer’s credit limit
        //print receipt
        cout<<"\n****     RECEIPT     ****"<<endl; //print out header of receipt
        
        if (balance <= creditLimit){ //case 1: new balance does not exceed the credit limit
            cout<<"New balance is: "<<balance<<endl;
            cout<<"Credit limit didn't exceed.\n"<<endl;
        } else {                     //case 2: new balance exceeds the credit limit
            cout<<"Account number is: "<<accountNumber<<endl;
            cout<<"  Credit limit is: "<<creditLimit<<endl;
            cout<<"   New balance is: "<<balance<<endl;
            cout<<"Credit Limit Exceeded.\n"<<endl;
        }
        balance = 0; //reset balance
        
        //prompt for input and read next account number from user
        cout<<"Enter account number or -1 to quit: ";
        cin>>accountNumber;
    }
    
    //termination phase
    cout<<"Terminating..."<<endl;
    return 0;
}
void checkInput (float input, string text, float *number){
    if (input < 0){
        cout<<"Input should not be negative."<<endl;
        cout<<"Enter "<<text<<": ";
        cin>>*number;
    }
}
void checkAccount (int input, int *number){
    if (input < 0 && input != -1){
        cout<<"Account should be positive."<<endl;
        cout<<"Enter account number or -1 to quit: ";
        cin>>*number;
    }
}
