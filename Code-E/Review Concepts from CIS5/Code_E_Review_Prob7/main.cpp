/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on 9/15 2PM
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <sstream> 
#include <iomanip>
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(int,unsigned short);//Output true,unsigned or false
bool  reverse(unsigned short,signed short);//Output true,short or false
short subtrct(signed short,int);
int padZerosToNumber(unsigned short, int);
int getReversedValue(unsigned short);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;

    bool isInputValid = 1;
    for (int i = 0; i < strlen(digits); i++){
        if (!isdigit(digits[i])){
            isInputValid = 0;
            cout << "No Conversion Possible" << endl;
            return 0;
        }
    }
    
    int convertedInput = atoi(digits);

    
    //Test if it is in the Range of an unsigned short
    if(!inRange(convertedInput,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    unShort = convertedInput;
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort, snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    snShort = getReversedValue(unShort);
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

bool  inRange(int convertedInput,unsigned short unshort){
    if(convertedInput >= 0 && convertedInput <= 65353){
        return 1;
    }
    
    return 0;
}

int padZerosToNumber(unsigned short unShort, int valueToReverse) {
    
    if (unShort < 10){
        valueToReverse *= 10000;
    }
    else if (unShort >= 10 && unShort < 100){
        valueToReverse *= 1000;
    }
    else if (unShort >= 100 && unShort < 1000){
        valueToReverse *= 100;
    }
    else if (unShort >= 1000 && unShort < 10000){
        valueToReverse *= 10;
    }
    
    return valueToReverse;
}

int getReversedValue(unsigned short unShort) {
    int x = unShort;
    
    int reversed = 0;
    while(x > 0)
    {
        reversed = reversed*10 + x%10;
        x /= 10;
    }
    
    reversed = padZerosToNumber(unShort, reversed);
    
    return reversed;
}

bool reverse(unsigned short unShort,signed short unused){
    int reversed = getReversedValue(unShort);
    
    if (reversed >= -32768 && reversed <= 32767){
        return 1;
    }
    return 0;
}

short subtrct(signed short value,int subtractNum){
    if (value >= subtractNum){
        return value - subtractNum;
    }
    return value;
}