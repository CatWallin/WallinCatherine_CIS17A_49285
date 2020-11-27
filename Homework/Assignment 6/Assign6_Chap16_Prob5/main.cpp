/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 27, 2020, 1:31 PM
 * Chapter 16 Problem 5: Total Template
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
T total(T numOfValues){
    T total = 0;
    T input = 0;
    cout << endl;
    for (int i = 1; i <= numOfValues; i++){
        cout << "Enter Value #" << i << ": ";
        cin >> input;
        total += input;
    }
    return total;
}

int main(int argc, char** argv) {

    int numOfValuesInt = 5;
    float numOfValuesFloat = 6;
      
    
    cout << total(numOfValuesInt);
    cout << setprecision(2) << fixed << total(numOfValuesFloat);
    
    
    return 0;
}

