
/* 
 * File:   main.cpp
 * Author: Catherine
 *
 * Created on October 18, 2020, 11:01 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"
#include "Problem3.h"
#include "Problem7.h"
#include "Problem2.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
struct CustomerData
{
    string name;
    string address;
    int accountNum;
    double balance;
    double totalChecks;
    double totalDeposits;
};

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl << endl;
}

void prblm1(){
    cout<<"Problem 1"<<endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    CustomerData* customer1 = new CustomerData;
    double newBalance = 0;
    
    cout << "Enter the customer name: ";
    cin >> customer1->name;
    cout << "Enter the Address: ";
    cin.ignore();
    getline(cin, customer1->address);
    cout << "Enter the account number (five digits only): ";
    cin >> customer1->accountNum;
    while (customer1->accountNum > 99999 || customer1->accountNum < 10000){
        cout << "Invalid account number." << endl << "Please enter again: ";
        cin >> customer1->accountNum;
    }
    cout << "Enter the balance at the start of the month: ";
    cin >> customer1->balance;
    cout << "Enter amount of all checks written by the customer this month:" << endl;
    double check;
    char input;
    do {
        cout << "Enter the amount of the check: ";
        cin >> check;
        customer1->totalChecks += check; 
        cout << "Would you like to enter another check(Y/N): ";
        cin >> input;
        input = tolower(input);
    } while(input == 'y');
    cout << "Enter amount of deposits credited to this customer's account:" << endl;
    double deposit;
    do {
        cout << "Enter the amount of the deposit: ";
        cin >> deposit;
        customer1->totalDeposits += deposit; 
        cout << "Would you like to enter another deposit{Y/N): ";
        cin >> input;
        input = tolower(input);
    } while(input == 'y');
   
    cout << "\nCustomer Name: " << setprecision(2) << fixed << customer1->name << endl;
    cout << "Customer Address: " << customer1->address << endl;
    cout << "Customer Account Number: " << customer1->accountNum << endl;
    cout << "Account Balance(start of month): $" << customer1->balance << endl;
    cout << "Total Written Checks Amount: $" << customer1->totalChecks << endl;
    cout << "Total Deposited Money: $" << customer1->totalDeposits << endl << endl;
    
    newBalance = (customer1->balance - customer1->totalChecks) + customer1->totalDeposits;
    cout << "Your new balance is: $" << newBalance << endl;
    if (newBalance < 0){
        cout << "\nYour account has been overdrawn." << endl;
        cout << "There is a $20 fee that will now be charged." << endl;
        newBalance = (newBalance - 20.0);
        cout << "Your new balance is: $" << newBalance << endl;
    }
    cout << "---------------------------------------------------------------------------------" << endl;
    delete customer1;
}

void prblm2(){
    cout<<"Problem 2"<<endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    EmployeeData* employee = new EmployeeData[numEmployees];
    
    for(int i = 0; i < numEmployees; i++){
        cout << "Input the employee name: ";
        cin >> employee[i].name;
        cout << "Input the hours worked by this employee: ";
        cin >> employee[i].hours;
        cout << "Input the pay rate for this employee: ";
        cin >> employee[i].payRate;
        if (employee[i].hours < 0 || employee[i].payRate < 0){
            cout << "Invalid Input. Terminating Program.";
            cout << "\n---------------------------------------------------------------------------------" << endl;
            return;
        }
        
        employee[i].grossPay = calculateGrossPay(employee[i]);
                
        printPayCheck(employee[i]);
    }
    cout << "\n---------------------------------------------------------------------------------" << endl;
}

void prblm3(){
    cout<<"Problem 3"<<endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    cout << "\n---------------------------------------------------------------------------------" << endl;
}

void prblm4(){
    cout<<"problem 4"<<endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    string input;
    
    //get input
    cout << "Input a four-digit integer with the numbers 0 to 7(to encrypt): ";
    cin >> input;
    
    while (input.length() != 4){
        cout << "Invalid Integer. Please Try Again: ";
        cin >> input;
    }
    
    //copy to a char array
    char array[4];
    int intArray[4];
    strcpy(array, input.c_str());
    
    for (int i = 0; i < 4; i++){
        int currentNum = ((int)array[i] - 48);
        if (currentNum < 0 || currentNum > 7){
            cout << "This number is invalid: " << currentNum << endl;
            cout << "Invalid Input. Now terminating program.";
            return;
        }
    }
    
    //loop through to complete the math and swap on each numbers.
    //cast as an int in order to manipulate them as integers
    for (int i = 0; i < 4; i++){
        int currentNum = (((int)array[i] + 5) % 8);
        if (i == 0){
            intArray[2] = currentNum;
        }
        else if (i == 1){
            intArray[3] = currentNum;
        }
        else if (i == 2){
            intArray[0] = currentNum;
        }
        else {
            intArray[1] = currentNum;
        }
    }
        
    cout << "The encrypted number is: ";
    for (int i = 0; i < 4; i++){
        cout << intArray[i];
    }
    cout << endl;
    
    //reversal for decrypt 
    cout << "Input a four-digit integer with the numbers 0 to 7(to decrypt): ";
    cin >> input;
    while (input.length() != 4){
        cout << "Invalid Integer. Please Try Again: ";
        cin >> input;
    }   
    
    strcpy(array, input.c_str());
    
    int decryptArray[4];
    
    for (int i = 0; i < 4; i++){
        int currentNum = (((int)array[i] - 5) % 8);
        if (i == 0){
            decryptArray[2] = currentNum;
        }
        else if (i == 1){
            decryptArray[3] = currentNum;
        }
        else if (i == 2){
            decryptArray[0] = currentNum;
        }
        else {
            decryptArray[1] = currentNum;
        }
    }
    
    cout << "The decrypted number is: ";
    for (int i = 0; i < 4; i++){
        cout << decryptArray[i];
    }
    cout << "\n---------------------------------------------------------------------------------" << endl;
}

void prblm5(){
    cout<<"\nproblem 5"<<endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << setw(25) << left << "Data Type" << setw(25) << left << "The Largest Factorial";
    cout << setw(25) << left << "The Result" << endl;  
    cout << setw(25) << left << "int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl; 
    cout << setw(25) << left << "unsigned int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;
    cout << setw(25) << left << "signed int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;
    cout << setw(25) << left << "short int" << setw(25) << left << "7" << setw(25) << left << "5040" << endl;
    cout << setw(25) << left << "unsigned short int" << setw(25) << left << "8" << setw(25) << left << "40320" << endl;
    cout << setw(25) << left << "signed short int" << setw(25) << left << "7" << setw(25) << left << "5040" << endl;
    cout << setw(25) << left << "long int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;
    cout << setw(25) << left << "signed long int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;
    cout << setw(25) << left << "unsigned long int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;

    cout << setw(25) << left << "unsigned long long int" << setw(25) << left << "20" << setw(25) << left << "2432902008176640000" << endl;
    cout << setw(25) << left << "float" << setw(25) << left << "20" << setw(25) << left << "2432902008176640000" << endl;
    cout << setw(25) << left << "double" << setw(25) << left << "20" << setw(25) << left << "2432902008176640000" << endl;
  
    cout << setw(25) << left << "char" << setw(25) << left << "5" << setw(25) << left << "120" << endl;
    cout << setw(25) << left << "unsigned char" << setw(25) << left << "5" << setw(25) << left << "120" << endl;
    cout << setw(25) << left << "signed char" << setw(25) << left << "5" << setw(25) << left << "120" << endl;
}

void prblm6(){
    cout<<"\nProblem 6"<<endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "Decimal" << setw(20) << left << "Binary" << setw(20) << left << "Octal" << setw(20) << left << "Hexadecimal" << endl;
    cout << setw(20) << left << "2.875" << setw(20) << left << "10.111" << setw(20) << left << "2.7" << setw(20) << left << "2.E" << endl;
    cout << setw(20) << left << ".1796875" << setw(20) << left << ".0010111" << setw(20) << left << ".134" << setw(20) << left << ".2E" << endl;
}

void prblm7(){
    cout<<"problem 7"<<endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    int input;
    cout << "Enter a number to factor into its prime numbers: ";
    cin >> input;    
    while (input < 2 || input > 10000){
        cout << "Invalid Input. Try Again: ";
        cin >> input;
    }
    Primes array = *factor(input);
    
    cout << input << " = ";
    prntPrm(&array);
    cout << "\n---------------------------------------------------------------------------------" << endl;
}   

