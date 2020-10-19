/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Catherine
 * Created on October 14, 2020, 11:49 PM
 * Chapter 12 Problem 12 Corporate Sales Data Input
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <valarray>
#include <iomanip>

using namespace std;

const string CorporateSalesDataFileName = "CorporateSalesData.txt";

struct CorpSalesData
{
    string division;
    int quarter;
    float quarterSales;
};

float totalSalesEachQuart(CorpSalesData*, int);
float totalSalesEachDiv(CorpSalesData*, string);
float totalYearlySales(CorpSalesData*);


int main(int argc, char** argv) {
    
    fstream inputFile;
    inputFile.open(CorporateSalesDataFileName, ios::in | ios::binary);
    CorpSalesData salesData[16];
    
    for (int i = 0; i < 16; i++){
        string line;
        getline(inputFile, line);
        string delimiter = " ";
        size_t pos = 0;
        pos = line.find(delimiter);
        salesData[i].division = line.substr(0, pos);
        string word = salesData[i].division;
        line.erase(0, pos + delimiter.length());
        string quarter = line.substr(0, line.find(delimiter));
        salesData[i].quarter = stoi(quarter);
        line.erase(0, delimiter.length());
        string quarterSales = line;
        salesData[i].quarterSales = stoi(quarterSales);
    }
    
    inputFile.close();
    
    cout << "Total Sales for each Quarter:" << setprecision(2) << fixed << endl;
    float quarter1Sales = totalSalesEachQuart(salesData, 1);
    float quarter2Sales = totalSalesEachQuart(salesData, 2);
    float quarter3Sales = totalSalesEachQuart(salesData, 3);
    float quarter4Sales = totalSalesEachQuart(salesData, 4);
    cout << "1st Quarter: $" << quarter1Sales << endl;
    cout << "2nd Quarter: $" << quarter2Sales << endl;
    cout << "3rd Quarter: $" << quarter3Sales << endl;
    cout << "4th Quarter: $" << quarter4Sales << endl;
    
    cout << endl << "Total Sales for each Division:" << endl;
    float westSales = totalSalesEachDiv(salesData, "West");
    float eastSales = totalSalesEachDiv(salesData, "East");
    float northSales = totalSalesEachDiv(salesData, "North");
    float southSales = totalSalesEachDiv(salesData, "South");
    cout << "West Division: $" << westSales << endl;
    cout << "East Division: $" << eastSales << endl;
    cout << "North Division: $" << northSales << endl;
    cout << "South Division: $" << southSales << endl;
    
    cout << endl << "Total Yearly Corporate Sales: $" << totalYearlySales(salesData) << endl;
    
    cout << endl <<  "Average Quarterly Sales for the Divisions:" << endl;
    cout << "West Division: $" << westSales/4 << endl;
    cout << "East Division: $" << eastSales/4 << endl;
    cout << "North Division: $" << northSales/4 << endl;
    cout << "South Division: $" << southSales/4 << endl;
            
    cout << endl << "The Lowest quarter for the Corporation: $";
    int lowest = 0;
    if (quarter1Sales < quarter2Sales){
        lowest = quarter1Sales;
    }
    else {
        lowest = quarter2Sales;
    }
    if (quarter3Sales < lowest){
        lowest = quarter3Sales;
    }
    if (quarter4Sales < lowest){
        lowest = quarter4Sales;
    }
    cout << lowest << endl;
    
    cout << endl << "The Highest quarter for the Corporation: $";
    int highest = 0;
    if (quarter1Sales > quarter2Sales){
        highest = quarter1Sales;
    }
    else {
        highest = quarter2Sales;
    }
    if (quarter3Sales > highest){
        highest = quarter3Sales;
    }
    if (quarter4Sales > highest){
        highest = quarter4Sales;
    }
    cout << highest << endl;
    
    
    
    return 0;
}

float totalSalesEachQuart(CorpSalesData* salesData, int a){
    float result = 0;
    for (int i = 0; i < 16; i++){
        if (salesData[i].quarter == a){
            result += salesData[i].quarterSales;
        }
    }
    return result;
}
float totalSalesEachDiv(CorpSalesData* salesData, string a){
    float result = 0;
    for (int i = 0; i < 16; i++){
        if (salesData[i].division == a){
            result += salesData[i].quarterSales;
        }
    }
    return result;
}
float totalYearlySales(CorpSalesData* salesData){
    float result = 0;
    for (int i = 0; i < 16; i++){
        result += salesData[i].quarterSales;
    }
    return result;
}

