

/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 18, 2020, 10:27 PM
 * Midterm Prob4
 */

#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    
    string input;
    
    //get input
    cout << "Input a four-digit integer with the numbers 0 to 7(to encrypt): ";
    cin >> input;
    
    while (input.length() != 4){
        cout << "Invalid Integer. Please Try Again: ";
        cin >> input;
    }
    
    //copy to a char array
    char array[4];
    int intArray[4];
    strcpy(array, input.c_str());
    
    for (int i = 0; i < 4; i++){
        int currentNum = ((int)array[i] - 48);
        if (currentNum < 0 || currentNum > 7){
            cout << "This number is invalid: " << currentNum << endl;
            cout << "Invalid Input. Now terminating program.";
            return 0;
        }
    }
    
    //loop through to complete the math and swap on each numbers.
    //cast as an int in order to manipulate them as integers
    for (int i = 0; i < 4; i++){
        int currentNum = (((int)array[i] + 5) % 8);
        if (i == 0){
            intArray[2] = currentNum;
        }
        else if (i == 1){
            intArray[3] = currentNum;
        }
        else if (i == 2){
            intArray[0] = currentNum;
        }
        else {
            intArray[1] = currentNum;
        }
    }
        
    cout << "The encrypted number is: ";
    for (int i = 0; i < 4; i++){
        cout << intArray[i];
    }
    cout << endl;
    
    //reversal for decrypt 
    cout << "Input a four-digit integer with the numbers 0 to 7(to decrypt): ";
    cin >> input;
    while (input.length() != 4){
        cout << "Invalid Integer. Please Try Again: ";
        cin >> input;
    }   
    
    strcpy(array, input.c_str());
    
    int decryptArray[4];
    
    for (int i = 0; i < 4; i++){
        int currentNum = (((int)array[i] - 5) % 8);
        if (i == 0){
            decryptArray[2] = currentNum;
        }
        else if (i == 1){
            decryptArray[3] = currentNum;
        }
        else if (i == 2){
            decryptArray[0] = currentNum;
        }
        else {
            decryptArray[1] = currentNum;
        }
    }
    
    cout << "The decrypted number is: ";
    for (int i = 0; i < 4; i++){
        cout << decryptArray[i];
    }
    
    return 0;
}

