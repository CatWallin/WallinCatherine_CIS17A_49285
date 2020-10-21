/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 18, 2020, 8:14 PM
 * Midterm Problem 1
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

struct CustomerData
{
    string name;
    string address;
    int accountNum;
    double balance;
    double totalChecks;
    double totalDeposits;
};

int main(int argc, char** argv) {
   
    CustomerData customer;
    double newBalance = 0;
    
    cout << "Enter the customer name: ";
    cin >> customer.name;
    cout << "Enter the Address: ";
    cin.ignore();
    getline(cin, customer.address);
    cout << "Enter the account number (five digits only): ";
    cin >> customer.accountNum;
    while (customer.accountNum > 99999 || customer.accountNum < 10000){
        cout << "Invalid account number." << endl << "Please enter again: ";
        cin >> customer.accountNum;
    }
    cout << "Enter the balance at the start of the month: ";
    cin >> customer.balance;
    cout << "Enter amount of all checks written by the customer this month:" << endl;
    double check;
    char input;
    do {
        cout << "Enter the amount of the check: ";
        cin >> check;
        customer.totalChecks += check; 
        cout << "Would you like to enter another check(Y/N): ";
        cin >> input;
        input = tolower(input);
    } while(input == 'y');
    cout << "Enter amount of deposits credited to this customer's account:" << endl;
    double deposit;
    do {
        cout << "Enter the amount of the deposit: ";
        cin >> deposit;
        customer.totalDeposits += deposit; 
        cout << "Would you like to enter another deposit{Y/N): ";
        cin >> input;
        input = tolower(input);
    } while(input == 'y');
   
    cout << "Customer Name: " << customer.name << endl;
    cout << "Customer Address: " << customer.address << endl;
    cout << "Customer Account Number: " << customer.accountNum << endl;
    cout << "Account Balance(start of month): $" << customer.balance << endl;
    cout << "Total Written Checks Amount: $" << customer.totalChecks << endl;
    cout << "Total Deposited Money: $" << customer.totalDeposits << endl << endl;
    
    newBalance = (customer.balance - customer.totalChecks) + customer.totalDeposits;
    cout << "Your new balance is: $" << newBalance;
    if (newBalance < 0){
        cout << "\nYour account has been overdrawn." << endl;
        cout << "There is a $20 fee that will now be charged." << endl;
        newBalance = (newBalance - 20.0);
        cout << "Your new balance is: $" << newBalance;
    }
            
    return 0;
}

