/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on October 12, 2020, 11:17 PM
 * Chapter 12 Problem 7: Sentence Filter 
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string inputFileName;
    string outputFileName;
    string sentence;
    
    cout << "Enter the name for the input file: ";
    cin >> inputFileName;
    cout << "Enter the name for the output file:";
    cin >> outputFileName;
    
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    
    if (!inputFile || !outputFile){
        cout << "Error";
        return 0;
    }
    
    while (getline(inputFile, sentence)){
        for (int i = 0; i < sentence.length(); i++){
            if (i == 0){
                outputFile.put((char)toupper(sentence[i]));
            }
            else {
                outputFile.put((char)tolower(sentence[i]));
            }
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}

