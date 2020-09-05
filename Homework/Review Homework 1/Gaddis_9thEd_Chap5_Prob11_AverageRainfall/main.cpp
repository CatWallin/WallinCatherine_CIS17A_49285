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
    unsigned short int startPop;
    short days;
    short popIncr;
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    
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