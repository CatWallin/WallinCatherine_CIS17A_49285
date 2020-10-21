

/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 18, 2020, 11:07 PM
 * Midterm Problem 5
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    
    char n;
    unsigned long long int fact = 1;
    unsigned long long int maxAllowed = 255;
    n = 50;
    int maxNum = 0;
    int maxFact = 0;
   
    cout << n << endl;
    
    for (int i = 1; i <= n; i++){
        fact = fact*i;
        if (fact > maxNum && fact <= maxAllowed){
            maxNum = fact;
            maxFact = i;
        }
    }
    cout << maxNum << " " << maxFact << endl;
    
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
    
    
    return 0;
}

