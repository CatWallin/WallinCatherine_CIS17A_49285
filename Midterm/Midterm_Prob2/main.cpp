

/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 18, 2020, 9:03 PM
 * Midterm Problem 2
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <iomanip>

using namespace std;

struct EmployeeData
{
    string name;
    int hours;
    float payRate;
    double grossPay;
};

double calculateGrossPay(struct EmployeeData);
void printPayCheck(struct EmployeeData);
string translateNumber(double);

int main() {
    
    int numEmployees = 10;
    EmployeeData employee[numEmployees];
    
    for(int i = 0; i < numEmployees; i++){
        cout << "Input the employee name: ";
        cin >> employee[i].name;
        cout << "Input the hours worked by this employee: ";
        cin >> employee[i].hours;
        cout << "Input the pay rate for this employee: ";
        cin >> employee[i].payRate;
        
        employee[i].grossPay = calculateGrossPay(employee[i]);
        cout << employee[i].grossPay << endl;
        
        printPayCheck(employee[i]);
        
    }
    
    
    
    
    
    return 0;
}

double calculateGrossPay(EmployeeData array){
    double grossPay;
    int doubleTime;
    int tripleTime;
    if (array.hours <= 40){
        grossPay = array.hours * array.payRate;
    }
    else if (array.hours > 40 && array.hours <= 50){
        grossPay = 40 * array.payRate;
        doubleTime = array.hours - 40;
        grossPay = grossPay + (doubleTime * (array.payRate * 2));
    }
    else {
        grossPay = 40 * array.payRate;
        grossPay = grossPay + (10 * (array.payRate * 2)); 
        tripleTime = array.hours - 50;
        grossPay = grossPay + (tripleTime * (array.payRate * 3));
    }
    
    
    return grossPay;
}

void printPayCheck(EmployeeData array){
    cout << endl << endl << "Company" << endl;
    cout << "Address" << endl;
    cout << "Pay to the Order of: " << setw(20) << left << array.name;  
    cout << "$" << setprecision(2) << fixed << array.grossPay << endl;
    cout << "Amount: " << endl;
    cout << "Signature: " << endl << endl;
}

string translateNumber(double pay){
   
}