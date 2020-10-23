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
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << setw(25) << left << "Decimal" << setw(25) << left << "4 byte float(Hex Rep))" << setw(25) << left << "Negative" << endl;
    cout << setw(25) << left << "2.875" << setw(25) << left << "5C000002" << setw(25) << left << "DC000002" << endl;
    cout << setw(25) << left << ".1796875" << setw(25) << left << "5C0000FB" << setw(25) << left << "DC0000FB" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "Float" << setw(20) << left << "Decimal" << endl;
    cout << setw(20) << left << "59999901" << setw(20) << left << "11,744,050" << endl;
    cout << setw(20) << left << "59999902" << setw(20) << left << "23,488,100" << endl;
    cout << setw(20) << left << "A66667FE" << setw(20) << left << "-5,872,024 * 2^103" << endl;
    
    
    return 0;
}

