
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 24, 2020, 1:08 PM
 * Chapter 15 Problem 4: Time Format
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Time.h"
#include "MilTime.h"
using namespace std;


int main(int argc, char** argv) {

    int militaryTime, seconds;
    
    cout << "Please enter the time in military format: ";
    cin >> militaryTime;
    while (militaryTime > 2359 || militaryTime < 0){
        cout << "Invalid Input, please try again: ";
        cin >> militaryTime;
    }
    cout << "Please enter the seconds: ";
    cin >> seconds;
    while (seconds > 59 || seconds < 0){
        cout << "Invalid Input, please try again: ";
        cin >> seconds;
    }
    
    MilTime time1 = MilTime(militaryTime, seconds);
    
    cout << "Military Format" << setw(20) << "Standard Format" << endl;
    cout << time1.getMilHours() << ":" << time1.getSec();
    cout << setw(20) << time1.getHour() << ":" << time1.getMin() << ":";
    cout << time1.getSec();
    if (time1.getMilHours() < 1200){
        cout << " AM";
    }
    else {
        cout << " PM";
    }
    
    
    return 0;
}

