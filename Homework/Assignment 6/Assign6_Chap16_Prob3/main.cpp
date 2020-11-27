
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 27, 2020, 12:52 PM
 * Chapter 16 Problem 3: Minimum/Maximum Templates
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

template <class T1>
T1 minimum(T1 x, T1 y){
    if (x < y){
        return x;
    }
    else
        return y;
}

template <class T1>
T1 maximum(T1 x, T1 y){
    if (x > y){
        return x;
    }
    else
        return y;
}

int main(int argc, char** argv) {

    int num1 = 5;
    int num2 = 7;
    float num3 = 5.6;
    float num4 = 7.5;
    
    cout << "The Min: " << minimum(num1, num2) << endl;
    cout << "The Max: " << setprecision(2) << fixed << maximum(num3, num4) << endl;
    
    
    return 0;
}

