
#include <iostream>

using namespace std;

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(float input){                     //Constructor
    Balance = input;
    FreqWithDraw = 0;
    FreqDeposit = 0;
}               

void  SavingsAccount::Transaction(float input){                  //Procedure
    if (input > 0){
        Deposit(input);
    }
    else {
        if (input < Balance){
            throw InvalidWithdrawl();
        }
        else {
            Withdraw(input);
        }
    }
}            

float SavingsAccount::Total(float savint,int time){             //Savings Procedure                                               
    float equation = 1;
    for (int i = 0; i < time; i++){
        equation *= ( 1+ savint);                                 //Balance*(1+savint)^time
    }
    return (equation * Balance);
}            
     
float SavingsAccount::TotalRecursive(float savint,int time){
    //base case (if period is less than 0, no interest
    if (time <= 0){
        return savint;
    }
        return (TotalRecursive(Balance*(1+time), time-1));
    
}

void  SavingsAccount::toString(){  
    
    cout << setprecision(2) << fixed << "Balance: $" << Balance << endl;
    cout << "WithDraws: " << FreqWithDraw << endl;
    cout << "Deposit: " << FreqDeposit << endl;
}  

float SavingsAccount::Withdraw(float transAmount){              //Utility Procedure
    Balance += transAmount;
    FreqWithDraw++;      
    return Balance;
}                  

float SavingsAccount::Deposit(float transAmount){               //Utility Procedure
    Balance += transAmount;
    FreqDeposit++;
    return Balance;
}     