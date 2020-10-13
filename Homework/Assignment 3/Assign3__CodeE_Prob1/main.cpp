/* 
 * File:   
 * Author: Catherine Wallin
 * Created on 10/4/2020 5PM
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

struct SalesData 
{
    string division;
    float firstQuarter;
    float secondQuarter;
    float thirdQuarter;
    float fourthQuarter;
    float totalAnnual;
    float averageQuarterly;
};

//Function Prototypes
float calculateSales(SalesData);
float calculateAverage(SalesData);

//Execution Begins Here
int main(int argc, char** argv) {
    
    SalesData North;
    SalesData West;
    SalesData East;
    SalesData South;
    
    //north sales
    cout << "North" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> North.firstQuarter;
    cout << "Enter second-quarter sales:" << endl;
    cin >> North.secondQuarter;
    cout << "Enter third-quarter sales:" << endl;
    cin >> North.thirdQuarter;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> North.fourthQuarter;
    North.totalAnnual = calculateSales(North);
    cout << setprecision(2) << fixed << "Total Annual sales:$" << North.totalAnnual << endl;
    North.averageQuarterly = calculateAverage(North);
    cout << "Average Quarterly Sales:$" << North.averageQuarterly << endl;
    
    //west sales
    cout << "West" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> West.firstQuarter;
    cout << "Enter second-quarter sales:" << endl;
    cin >> West.secondQuarter;
    cout << "Enter third-quarter sales:" << endl;
    cin >> West.thirdQuarter;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> West.fourthQuarter;
    West.totalAnnual = calculateSales(West);
    cout << "Total Annual sales:$" << West.totalAnnual << endl;
    West.averageQuarterly = calculateAverage(West);
    cout << "Average Quarterly Sales:$" << West.averageQuarterly << endl;
    
    //east sales
    cout << "East" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> East.firstQuarter;
    cout << "Enter second-quarter sales:" << endl;
    cin >> East.secondQuarter;
    cout << "Enter third-quarter sales:" << endl;
    cin >> East.thirdQuarter;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> East.fourthQuarter;
    East.totalAnnual = calculateSales(East);
    cout << "Total Annual sales:$" << East.totalAnnual << endl;
    East.averageQuarterly = calculateAverage(East);
    cout << "Average Quarterly Sales:$" << East.averageQuarterly << endl;
    
    //south sales
    cout << "South" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> South.firstQuarter;
    cout << "Enter second-quarter sales:" << endl;
    cin >> South.secondQuarter;
    cout << "Enter third-quarter sales:" << endl;
    cin >> South.thirdQuarter;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> South.fourthQuarter;
    South.totalAnnual = calculateSales(South);
    cout << "Total Annual sales:$" << South.totalAnnual << endl;
    South.averageQuarterly = calculateAverage(South);
    cout << "Average Quarterly Sales:$" << South.averageQuarterly;
    

    //Exit stage right!
    return 0;
}



float calculateSales(SalesData a){
    return a.firstQuarter + a.secondQuarter + a.thirdQuarter + a.fourthQuarter;
}

float calculateAverage(SalesData a){
    return a.totalAnnual / 4;
}
