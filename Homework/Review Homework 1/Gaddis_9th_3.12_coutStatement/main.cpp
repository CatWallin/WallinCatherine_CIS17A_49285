/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on September 5th, 2020, 11:12 AM
 * Purpose:  HW 3.12: cout statement divSales displayed in 8 spaces
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> 
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    float divSales = 567.2565;
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    cout << setw(8) << setprecision(2) << fixed << divSales << endl;
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations