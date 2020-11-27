
/* 
 * File:   main.cpp
 * Author: Catherine
 * Created on November 25, 2020, 2:20 PM
 * Chapter 16 Problem 1: Date Exceptions
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#include "Date.h"

int main(int argc, char** argv) {

    Date date1 = Date();
    
    try
    {
    date1.setDate(12, 25, 2020);
    date1.printDateMonthDateYear();
    }
    catch (Date::InvalidMonth){
        cout << "Oops: Invalid Month was Entered." << endl;
    }
    catch (Date::InvalidDay){
        cout << "Whoops: Invalid Day was Entered!" << endl;
    }
    
    return 0;
}

