/* 
 * File:   
 * Author: Catherine Wallin
 * Created on 10/4/2020 5PM
 * Purpose:  
 */

//System Libraries
#include <iostream>
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
void calculateSales(SalesData);

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
    calculateSales(North);
    
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
    calculateSales(West);
    cout << "Total Annual sales:" << West.totalAnnual << endl;
    cout << "Average Quarterly Sales:" << West.averageQuarterly << endl;
    
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
    
    

    //Exit stage right!
    return 0;
}



void calculateSales(SalesData a){
    a.totalAnnual = (a.firstQuarter + a.secondQuarter) + (a.thirdQuarter + a.fourthQuarter);
    a.averageQuarterly = (a.totalAnnual / 4);
}