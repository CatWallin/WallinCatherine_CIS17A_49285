/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "Problem2.h"

using namespace std;

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
    cout << "Pay to the Order of: " << setw(25) << left << array.name;  
    cout << "$" << setprecision(2) << fixed << array.grossPay << endl;
    cout << "Amount: ";
    translateNumber(array.grossPay);
    cout << "\nSignature: " << endl << endl;
}

void translateNumber(double pay){
    string englishNum[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string englishTeen[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    int payWholeNum = (int)pay; 
    float decimalPortion = (pay-payWholeNum) * 100;
    unsigned char n1000s,n100s,n10s,n1s;
        n1000s=payWholeNum/1000;   //Shift 3 places to the left
        n100s=payWholeNum%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=(payWholeNum%100/10);   //Remainder of division of 100 then shift 1 left
        n1s=(payWholeNum%10);        //Remainder of division by 10
        
        if (pay >= 30000){
            cout << "Number unable to be converted: Over $30,000.";
            return;
        }
        
        if (n1000s >= 1 && n1000s < 10){
            cout << englishNum[n1000s] << " Thousand ";
        }
        else if (n1000s >= 10 && n1000s < 20){
            cout << englishTeen[n1000s-10] << " Thousand ";
        }
        else if (n1000s >=20 && n1000s < 30){
            cout << "Twenty " << ((n1000s-20)==0?"": englishNum[n1000s-20]) << " Thousand ";
        }
        
        //Output the number of 100's
        if (n100s >= 1 && n100s <= 9){
            cout << englishNum[n100s] << " Hundred ";
        }
        
        if (n10s == 1 && n1s > 0){
            cout << englishTeen[n1s] << " ";
        }
        
        else {
            //Output the number of 10's
            //Using Independent If Statements
            if(n10s==9)cout<<"Ninety ";
            if(n10s==8)cout<<"Eighty ";
            if(n10s==7)cout<<"Seventy ";
            if(n10s==6)cout<<"Sixty ";
            if(n10s==5)cout<<"Fifty ";
            if(n10s==4)cout<<"Fourty ";
            if(n10s==3)cout<<"Thirty ";
            if(n10s==2)cout<<"Twenty ";
            if(n10s==1)cout<<"Ten ";
            
            if (n1s >= 1 && n1s <= 9){
                cout << englishNum[n1s] << " ";
            }
        }
        cout << " and " << setprecision(0) << fixed << decimalPortion << "/100";
}