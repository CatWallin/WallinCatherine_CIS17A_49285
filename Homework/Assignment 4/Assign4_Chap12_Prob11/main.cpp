/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Catherine
 * Created on October 14, 2020, 9:55 PM
 * Chapter 12 Problem 11 - Corporate Sales Data Output 
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

const string CorporateSalesDataFileName = "CorporateSalesData.txt";

struct CorpSalesData 
{
    string division;
    int quarter;
    float quarterSales;
};

void salesInput(string);

int main(int argc, char** argv) {
    
    fstream outputFile;
    outputFile.open(CorporateSalesDataFileName, ios::out);
    outputFile.close();
    
    salesInput("East");
    
    salesInput("West");
    
    salesInput("North");
    
    salesInput("South");
    
    return 0;
}

void salesInput(string division){
    cout << "Input the sales for the " << division << " division:" << endl;
    fstream outputFile;
    outputFile.open(CorporateSalesDataFileName, ios::app);
    for (int i = 0; i < 4; i++){
        CorpSalesData inputSalesData;
        inputSalesData.division = division;
        cout << "Sales for quarter " << i+1 << " ";
        inputSalesData.quarter = i+1;
        cin >> inputSalesData.quarterSales;
        while (inputSalesData.quarterSales < 0){
            cout << "Invalid Input. Try again:";
            cin >> inputSalesData.quarterSales;
        }
        
        outputFile << inputSalesData.division << " " << inputSalesData.quarter << " ";
        outputFile << inputSalesData.quarterSales << endl;
    }
    outputFile.close();
}

