/* 
 * File:   SavingsAccount.h
 * Author: Catherine Wallin
 * Created on December 12, 2020, 11:30 PM
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <iomanip>

using namespace std;

class SavingsAccount
{
    public:
		SavingsAccount(float input){                     //Constructor
                    balance = input;
                    freqWithDraw = 0;
                    freqDeposit = 0;
                }               
		void  Transaction(float input){                  //Procedure
                    if (input > 0){
                        Deposit(input);
                    }
                    else {
                        if (input < balance){
                            throw InvalidWithdrawl();
                        }
                        else {
                            Withdraw(input);
                        }
                    }
                }            
		float Total(float savint,int time){             //Savings Procedure
                    return balance;
                }            
                    
                	         
		float TotalRecursive(float savint,int time){
                    return balance;
                }
		void  toString(){                               //Output Properties
                    cout << setprecision(2) << fixed << "Balance: $" << balance << endl;
                    cout << "WithDraws: " << freqWithDraw << endl;
                    cout << "Deposit: " << freqDeposit << endl;
                }            
                
                class InvalidWithdrawl{};
                
	private:
		float Withdraw(float transAmount){              //Utility Procedure
                    balance += transAmount;
                    freqWithDraw++;      
                    return balance;
                }                  
		float Deposit(float transAmount){               //Utility Procedure
                    balance += transAmount;
                    freqDeposit++;
                    return balance;
                }                   
		float balance;                                  //Property
		int   freqWithDraw;                             //Property
		int   freqDeposit;                              //Property
};

#endif /* SAVINGSACCOUNT_H */

