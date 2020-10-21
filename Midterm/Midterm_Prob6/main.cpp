/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 20, 2020, 9:46 AM
 * Midterm Problem 6
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << setw(20) << left << "Decimal" << setw(20) << left << "Binary" << setw(20) << left << "Octal" << setw(20) << left << "Hexadecimal" << endl;
    cout << setw(20) << left << "2.875" << setw(20) << left << "10.111" << setw(20) << left << "2.7" << setw(20) << left << "2.E" << endl;
    cout << setw(20) << left << ".1796875" << setw(20) << left << ".0010111" << setw(20) << left << ".134" << setw(20) << left << ".2E" << endl;
    
    
    return 0;
}

