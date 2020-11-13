/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 7, 2020, 7:23 PM
 * Chapter 14 Problem 4: NumDays Class
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class NumDays
{
private:
    float workHours;
    float days;
public: 
    NumDays(int workHours){
        this->workHours = workHours;
        days = workHours/8.00;
    }
    float getWorkHours(){
        return workHours;
    }
    float getDays(){
        return days;
    }
    float operator+(NumDays x){
        workHours += x.workHours;
        days = workHours/8.00;
        return workHours;
    }
    float operator-(NumDays x){
        workHours -= x.workHours;
        days = workHours/8.00;
        return workHours - x.workHours;
    }
    void operator++(){
        ++workHours;
        days = workHours/8.00;
    }
    void operator++(int){
        NumDays temp(workHours);
        workHours++;
        days = workHours/8.00;
    }
    void operator--(){
        --workHours;
        days = workHours/8.00;
    }
    void operator--(int){
        NumDays temp(workHours);
        workHours--;
        days = workHours/8.00;
    }
};

int main(int argc, char** argv) {

    NumDays day = NumDays(12);
    
    cout << "Work Hours: " << day.getWorkHours() << endl;
    cout << "Days: " << setprecision(2) << fixed << day.getDays() << endl;
    
    return 0;
}

