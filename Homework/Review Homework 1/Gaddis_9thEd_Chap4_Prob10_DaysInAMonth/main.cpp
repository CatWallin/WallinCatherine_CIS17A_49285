/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on September 5th, 2020, 11:30 AM
 * Purpose:  4.10 Days in a Month
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> 
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void checkLeapYear(int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    int month, year;
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;
    
    //Display the Inputs/Outputs

    if (month == 2){
        checkLeapYear(year);
    }
    else{
        if (month == 1){
            cout << "January of " << year << " has 31 days." << endl;
        }
        else if (month == 3){
            cout << "March of " << year << " has 31 days." << endl;
        }
        else if (month == 4){
            cout << "April of " << year << " has 30 days." << endl;
        }
        else if (month == 5){
            cout << "May of " << year << " has 31 days." << endl;
        }
        else if (month == 6){
            cout << "June of " << year << " has 30 days." << endl;
        }
        else if (month == 7){
            cout << "July of " << year << " has 31 days." << endl;
        }
        else if (month == 8){
            cout << "August of " << year << " has 31 days." << endl;
        }
        else if (month == 9){
            cout << "September of " << year << " has 30 days." << endl;
        }
        else if (month == 10){
            cout << "October of " << year << " has 31 days." << endl;
        }
        else if (month == 11){
            cout << "November of " << year << " has 30 days." << endl;
        }
        else if (month == 12){
            cout << "December of " << year << " has 31 days." << endl;
        }
        else {
            cout << "invalid entry";
        }
    }
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
 }

//Function Implementations

void checkLeapYear(int year){
    if(year % 100 == 0 && year % 400 == 0){
        cout << "February of " << year << " has 29 days." << endl;
    }
    else if(year % 4 == 0){
        cout << "February of " << year << " has 29 days." << endl;
    }
    else{
        cout << "February of " << year << " has 28 days." << endl;
    }
    return;
}