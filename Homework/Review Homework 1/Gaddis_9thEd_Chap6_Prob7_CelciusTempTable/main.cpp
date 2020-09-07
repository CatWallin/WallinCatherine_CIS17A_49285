/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on September 6th, 2020, 12:39 PM
 * Purpose:  6.7 Celcius Temperature Table
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> 
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
float celsius(int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    for (int i = 0; i < 21; i++){ //loop to display the conversion
        cout << i << " Fahrenheit = " << celsius(i) << " Celsius" << endl;
    }
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
float celsius(int i){
    return (5.0/9.0 * (i - 32.0)); //Fahrenheit to Celsius conversion
}