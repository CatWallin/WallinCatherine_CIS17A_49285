/* 
 * File:   SavingsAccount.h
 * Author: 
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
		SavingsAccount(float);               //Constructor
		void  Transaction(float);            //Procedure
		float Total(float=0,int=0);	         //Savings Procedure
		float TotalRecursive(float=0,int=0);
		void  toString();                    //Output Properties
                class InvalidWithdrawl{};
    private:
		float Withdraw(float);               //Utility Procedure
		float Deposit(float);                //Utility Procedure
		float Balance;                       //Property
		int   FreqWithDraw;                  //Property
		int   FreqDeposit;                   //Property
                
};

#endif /* SAVINGSACCOUNT_H */

