
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 27, 2020, 12:35 PM
 * Chapter 16 Problem 2:
 *  */

#include <cstdlib>
#include <iostream>

using namespace std;

#include "MilTime.h"

int main(int argc, char** argv) {

    try {
        MilTime time1 = MilTime(2230, 80);
        cout << time1.getMilHours() << endl;
    }
    catch (MilTime::BadHour)
    {
        cout << "Invalid Hour!" << endl;
    }
    catch (MilTime::BadSeconds)
    {
        cout << "Invalid Seconds!" << endl;
    }
    
    
    return 0;
}

