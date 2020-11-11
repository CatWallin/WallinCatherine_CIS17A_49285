/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 7, 2020, 7:22 PM
 * Chapter 14 Problem 2: Day of the Year
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class DayOfYear
{
private:
    int dayOfYear;
    int day;
    int month;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string englishMonth[12] = {"January ", "February ", "March ", "April ", "May ", "June ", "July ", "August ", "September ", "October ", "November ", "December "};
public:
    DayOfYear(int dayOfYear){
        this->dayOfYear = dayOfYear;
    }
    void print(){
        int daysInMonthTotal = 0;
        int counter = 0;
        while (dayOfYear > daysInMonthTotal){
            daysInMonthTotal += daysInMonth[counter];
            counter++;
        }
        cout << "Day " << dayOfYear << " is " << englishMonth[counter-1];
        cout << daysInMonth[counter-1] - (daysInMonthTotal-dayOfYear) << endl;
    }
};

int main(int argc, char** argv) {

    int dayOfYear;
    
    for (int i = 1; i <= 365; i++){
        DayOfYear day = DayOfYear(i);
        day.print();
    }
    
    
    return 0;
}

