
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 12, 2020, 10:53 PM
 * Chapter 12 Problem 8 Array/File Functions
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void arrayToFile(string,int *, int);
void fileToArray(string,int *, int);

int main(int argc, char** argv) {
    string fileName;
    int size = 10;
    int *array = new int[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Enter the file name: ";
    cin >> fileName;
    
    arrayToFile(fileName, array, size);
    fileToArray(fileName, array, size);
    
    for (int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
    
    return 0;
}

void arrayToFile(string name,int* array,int size){
    ofstream outFile;
    outFile.open(name, ios::out | ios::binary);
    for (int i = 0; i < size; i++){
        outFile << array[i] << endl;
    }
    outFile.close();
}

void fileToArray(string name,int* array,int size){
    ifstream inFile;
    inFile.open(name, ios::in | ios::binary);
    for (int i = 0; i < size; i++){
        inFile >> array[i];
    }
}