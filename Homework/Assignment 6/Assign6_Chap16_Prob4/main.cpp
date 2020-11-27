/* 
 * File:   main.cpp
 * Author: Catherine Wallin\
 * Created on November 27, 2020, 1:12 PM
 * Chapter 16 Problem 4: Absolute Value Template
 */

#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
T absoluteValue(T num){
    return abs(num);
}

int main(int argc, char** argv) {

    int x = -6;
    float y = -87.56;
    
    cout << "The Absolute Value of " << y << ": " << absoluteValue(y) << endl;
    
    return 0;
}

