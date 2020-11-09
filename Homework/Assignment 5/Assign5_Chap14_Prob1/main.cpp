/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 7, 2020, 7:19 PM
 * Chapter 14 Problem 1: Numbers Class 
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Numbers
{
private:
    int number;
    string hundred = "Hundred ";
    string thousand = "Thousand ";
    string englishNum[10] = {"Zero ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    string englishTeen[10] = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    string englishTens[10] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
public: 
    Numbers(int number){
        this->number = number;
    }
    
    void print(){
        unsigned char n1000s,n100s,n10s,n1s;
        n1000s=number/1000;   
        n100s=number%1000/100;
        n10s=(number%100/10);   
        n1s=(number%10);        
        if (n1000s >=1 && n1000s < 10){
            cout << englishNum[n1000s] << thousand;
        }
        if (n100s >=1 && n100s <=9){
            cout << englishNum[n100s] << hundred;
        }
        if (n10s == 1 && n1s > 0){
            cout << englishTeen[n1s];
        }
        else {
            cout << englishTens[n10s];
            
            if (n1s >= 0 && n1s <= 9){
                cout << englishNum[n1s];
            }
        }
        
        
    }
    
};

int main(int argc, char** argv) {

    int number;
    
    cout << "Enter a number between 0 and 9999: ";
    cin >> number;
    while (number < 0 || number > 9999){
        cout << "Invalid Entry, please try again: ";
        cin >> number;
    }
    Numbers number1 = Numbers(number);
    number1.print();    
    
    return 0;
}

