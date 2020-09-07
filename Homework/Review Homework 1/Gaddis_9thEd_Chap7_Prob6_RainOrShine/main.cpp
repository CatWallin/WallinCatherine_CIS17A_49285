/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on September 6th, 2020, 12:55 PM
 * Purpose:  7.6 Rain or Shine
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip> 
#include <fstream>
using namespace std;

const int numMonths = 3;
const int numDays = 30; 
string weatherType[3] = {"Rainy", "Cloudy", "Sunny"}; //array to hold weather types
char weatherData[numMonths][numDays]; //array to store data from file
char weatherLetter[3] = {'R', 'C', 'S'}; //array to help sort data

void totalWeatherDaysDisplay(int);

int main() {
    int number;
    ifstream inputFile;
    inputFile.open("RainOrShine.txt");
    
     //loop through months and days to sort data and store as an array
    for (int month = 0; month < numMonths; month++){
        for (int day = 0; day < numDays; day++){
            inputFile >> weatherData[month][day];
            }
        }
    //test for data being stored
    for(int row =0; row <3; row++){
        for(int col=0; col<30; col++){
            cout << weatherData[row][col] << " ";
        }
        cout << endl;
    }
    
    //loop to call function to add up data for weather types
    for (int i = 0; i < numMonths; i++){
        totalWeatherDaysDisplay(i);
    }
    return 0;
}

//Function Implementations
//calculates number of days of weather types
void totalWeatherDaysDisplay(int weatherIndex){
    int total = 0;
    int monthTotal[3] = {0,0,0};
 for (int month = 0; month < 3; month++){ //calculating the weather types per month
        for (int day = 0; day < 30; day++){
            if (weatherData[month][day] == weatherLetter[weatherIndex]){
                monthTotal[month]++;
            }
        }
        //displays results
        cout << "The total number of " << weatherType[weatherIndex] << " days for the "
             << month+6 << "th month is " << monthTotal[month] << endl;
        total+= monthTotal[month]; //calculating the total number of weather types for all three months
            }
    cout << "The total number of " << weatherType[weatherIndex] << " days for all three months is "
            << total << endl;
    //display the month with the most rainy days
    if (weatherType[weatherIndex] == "Rainy"){
        if (monthTotal[0] > monthTotal[1] && monthTotal[0] > monthTotal[2]){
            cout << "June is the month with the most rainy days." << endl;
        }
        else if (monthTotal[1] > monthTotal[0] && monthTotal[1] > monthTotal[2]){
            cout << "July is the month with the most rainy days." << endl;
        }
        else{
            cout << "August is the month with the most rainy days." << endl;
        }
        
}
    cout << endl;
}