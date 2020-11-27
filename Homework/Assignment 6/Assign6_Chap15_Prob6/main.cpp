
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 24, 2020, 1:58 PM
 * Chapter 15 Problem 6: Essay Class
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#include "Essay.h"

int main(int argc, char** argv) {

    int g, s, l, c;
    
    cout << "Please enter the score for the essay of the following categories: " << endl;
    cout << "Grammer(30 points max): ";
    cin >> g;
    cout << "Spelling(20 points max): ";
    cin >> s;
    cout << "Correct Length(20 points max): ";
    cin >> l;
    cout << "Content(30 points max): ";
    cin >> c;
    
    Essay essay1 = Essay(g, s, l, c);
    
    cout << "Essay Score: " << essay1.getScore() << endl;
    cout << "Letter Grade: " << essay1.getLetterGrade() << endl;
    
    return 0;
}

