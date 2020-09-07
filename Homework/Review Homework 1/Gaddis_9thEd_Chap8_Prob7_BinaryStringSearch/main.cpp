/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on September 6th, 2020, 1:01 PM
 * Purpose:  8.7 Binary String Search
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> 
#include <string>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void selectionSort(string [], int);
bool binarySearchString(string [], string, int);

//Execution of Code Begins Here
int main() {
    //Set the random number seed here
    
    //Declare all variables for this function
    int numNames = 20;
    string names[numNames] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                              "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                              "Taylor, Terri", "Johnson, Jill",
                              "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                              "James, Jean", "Weaver, Jim", "Pore, Bob",
                              "Ruthford, Greg", "Javens, Renee", 
                              "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon",
                              "Holland, Beth" };
    
    //Initialize all known variables
    string search;
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    selectionSort(names, numNames);
    
    cout << "Enter the name you would like to search: " << endl;
    getline(cin, search);
    
    //call function to search for the name and let user know if it is on the list or not
    if (binarySearchString(names, search, numNames) == true){
        cout << search << " is on the list.";
    }
    else 
        cout << search << " is not on the list.";
    
    //Display the Inputs/Outputs
  
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations
void selectionSort(string names[], int arraySize){
    int startScan, minIndex;
    string minName;
    for (startScan = 0; startScan<(arraySize-1); startScan++){
        minName = names[startScan];
        minIndex = startScan;
        for (int index = startScan +1;index<arraySize; index++){
            if(names[index]<minName){
                minName = names[index];
                minIndex=index;
            }
        }
    names[minIndex] = names[startScan];
    names[startScan] = minName;
        
        
    }
}

bool binarySearchString(string names[], string search, int arraySize){
    int first = 0,
    last = arraySize - 1,
    middle, 
    position = -1;
    bool found = false;
    
    while (first <= last){
        middle = (first + last) / 2;
        if (names[middle] == search){
            return true;
        }
        else if (names[middle] > search){
            last = middle -1;
        }
        else{
            first = middle +1;
        }
    }
    return false;
}