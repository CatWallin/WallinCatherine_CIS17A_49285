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
        
        }
    
};

int main(int argc, char** argv) {

    return 0;
}

