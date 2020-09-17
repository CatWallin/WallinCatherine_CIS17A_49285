/* 
 * File: main.cpp
 * Author: Catherine Wallin
 * Date: 9/7/2020 4:13PM
 * Purpose: CodeE A2 More Test Output Format
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    
    //Initialize or input data here
    
    //Display initial conditions, headings here
    double a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    cout << setw(9) << a << setw(10);
    cout << setprecision(1) << fixed << a;
    cout << setw(10) << setprecision(2) << fixed << a << endl;
    
    cout << setw(9) << setprecision(0) << fixed << b << setw(10);
    cout << setprecision(1) << fixed << b;
    cout << setw(10) << setprecision(2) << fixed << b << endl;
    
    cout << setw(9) << setprecision(0) << fixed << c << setw(10);
    cout << setprecision(1) << fixed << c;
    cout << setw(10) << setprecision(2) << fixed << c << endl;
    
    cout << setw(9) << setprecision(0) << fixed << d << setw(10);
    cout << setprecision(1) << fixed << d;
    cout << setw(10) << setprecision(2) << fixed << d;
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}