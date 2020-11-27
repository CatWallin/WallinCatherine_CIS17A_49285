
/* 
 * File:   Date.h
 * Author: Catherine
 *
 * Created on November 25, 2020, 2:22 PM
 */

#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

using namespace std;

class Date
{
private:
    int month, day, year;
    string englishMonth[12] = {"January", "February", "March", "April", "May", 
                                "June", "July", "August", "September",
                                "October", "November", "December"};
    
public:
    Date(){
        month = 0;
        day = 0;
        year = 0;
    }
    
    ~Date(){
    }
    
    class InvalidDay //class declaration 
    {  
    };
    
    class InvalidMonth //class declaration 
    {
    };
    
    void setDate(int m, int d, int y){
        if (m < 1 || m > 12){
            throw InvalidMonth();
        }
        if (d < 1 || d > 31){
            throw InvalidDay();
        }
        month = m;
        day = d;
        year = y;
    }
    
    void printDateMonthDateYear(){
        cout << month << "/" << day << "/" << year << endl;
    }
    
    void printDateMonthNameDateYear(){
        cout << englishMonth[month - 1] << " " << day << "," << year << endl;
    }
    
    void printDateDateMonthNameYear(){
        cout << day << " " << englishMonth[month - 1] << " " << year << endl;
    }
    
};

#endif /* DATE_H */

