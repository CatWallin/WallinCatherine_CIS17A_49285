/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 30, 2020, 4:09 PM
 * Chapter 13 Problem 1: Date
 */

#include <cstdlib>
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
    
    void setDate(int m, int d, int y){
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


int main(int argc, char** argv) {
    
    Date date;
    int m, d, y;
    
    cout << "Enter the month: ";
    cin >> m;
    while (m > 12 || m < 1){
        cout << "Invalid Month. Please try again: ";
        cin >> m;
    }
    cout << "Enter the day: ";
    cin >> d;
    while (d > 31 || d < 1){
        cout << "Invalid Day. Please try again: ";
        cin >> d;
    }
    cout << "Enter the year: ";
    cin >> y;
    
    date.setDate(m, d, y);
         
    date.printDateMonthDateYear();
    date.printDateMonthNameDateYear();
    date.printDateDateMonthNameYear();
    
    return 0;
}

