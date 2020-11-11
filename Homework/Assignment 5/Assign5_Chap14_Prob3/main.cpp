/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 7, 2020, 7:22 PM
 * Chapter 14 Problem 3: Day of the Year Modification
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
    string month;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string englishMonth[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
public:
    DayOfYear(int dayOfYear){
        this->dayOfYear = dayOfYear;
    }
    DayOfYear(string month, int day){
        int monthNumber = -1;
        bool validMonth = false;
        this->month = month;
        this->day = day;
        for (int i = 0; i < 12; i++){
            if (month == englishMonth[i]){
                validMonth = true;
                monthNumber = i;
            }
        }
        if (validMonth == false){
            throw "Month is not valid!";
        }
        if (day > daysInMonth[monthNumber] || day < 1){
            throw "Day is not valid for the given month!";
        }
        dayOfYear = 0;
        for (int i = 0; i < monthNumber; i++){
            dayOfYear += daysInMonth[i];
        }
        dayOfYear += day;
    }
    void print(){
        int daysInMonthTotal = 0;
        int counter = 0;
        while (dayOfYear > daysInMonthTotal){
            daysInMonthTotal += daysInMonth[counter];
            counter++;
        }
        cout << "Day " << dayOfYear << " is " << englishMonth[counter-1] << " ";
        cout << daysInMonth[counter-1] - (daysInMonthTotal-dayOfYear) << endl;
    }
    void operator++(){
        dayOfYear += 1;
    }
    friend void operator--(DayOfYear&);
};

void operator--(DayOfYear &dayOfYear){
    dayOfYear.dayOfYear -= 1;
}


int main(int argc, char** argv) {
    
    try {
        DayOfYear day = DayOfYear("December", 25);
        day.print();
    } catch (const char* message) {
        cerr << message << endl;
    }
    DayOfYear day = DayOfYear(1);
    day.print();
    ++day;
    day.print();
    --day;
    day.print();
    
    return 0;
}



