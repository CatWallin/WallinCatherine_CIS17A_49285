/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Catherine
 * Created on October 14, 2020, 11:51 PM
 * Chapter 12 Problem 1 File Head Program
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv) {
    
    string fileName;
    fstream inputFile;

    cout << "Please enter the name of a file: ";
    cin >> fileName;
    
    inputFile.open(fileName, ios::in);
    
    for (int i = 0; i < 10; i++){
        if (inputFile.eof()){
            cout << "The entire file has been displayed." << endl;
            break;
        }
        string line;
        getline(inputFile, line);
        cout << line << endl;
    }
    
    inputFile.close();
    
    return 0;
}

