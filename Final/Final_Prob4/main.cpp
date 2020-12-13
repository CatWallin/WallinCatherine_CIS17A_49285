
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on December 12, 2020, 8:07 PM
 * Final Problem 4: Savings Account Class
 */

#include <cstdlib>

using namespace std;

#include "SavingsAccount.h"

int main(int argc, char** argv) {

    SavingsAccount mine(-300);

	for(int i=1;i<=10;i++)
	{   
            try
            {
                mine.Transaction((float)(rand()%500)*(rand()%3-1));
            }
            catch (SavingsAccount::InvalidWithdrawl){
                cout << "Error: Withdrawl amount exceeds the balance!" << endl;
            }
	}
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
    
    
    return 0;
}

