/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on September 5th, 2020, 12:36 PM
 * Purpose:  5.11 Population Prediction
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> 
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
bool validateStartPop(int);
bool validatePopIncr(int);
bool validateDays(int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    float startPop;
    int days;
    float popIncr;
    float popIncrDec;
    float updaPop;
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    do {
        cout << "Enter the starting number of organisms: ";
        cin >> startPop;
    }
    while (validateStartPop(startPop) == false);
    
    do {
        cout << "Enter the average daily population increase(percentage): ";
        cin >> popIncr;
    }
    while (validatePopIncr(popIncr) == false);
    
    do {
        cout << "Enter the number of days they will multiply: ";
        cin >> days;
    }
    while (validateDays(days) == false);
    
    popIncrDec = (popIncr/100);
    cout << popIncrDec;
    updaPop = startPop;
 
    for (int i = 0;i < days; i++){
        updaPop += (updaPop * popIncrDec);
        cout << "Day " << (i+1) << ": " << updaPop << endl;      
    }
    
    //Display the Inputs/Outputs
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations

bool validateStartPop(int startPop){
    if(startPop < 2){
        return false;
    }
    else{
        return true;
    }
}

bool validatePopIncr(int popIncr){
    if(popIncr < 0){
        return false;
    }
    else {
        return true;
    }
}

bool validateDays(int days){
    if(days < 1){
        return false;
    }
    else {
        return true;
    }
}