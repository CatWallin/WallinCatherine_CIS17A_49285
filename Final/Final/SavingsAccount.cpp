
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
    float total = Balance;
    return Balance;
}            
     
float SavingsAccount::TotalRecursive(float savint,int time){
    return Balance;
}

void  SavingsAccount::toString(){                               //Output Properties
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