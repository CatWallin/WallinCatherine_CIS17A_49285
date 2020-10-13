/* 
 * File:   
 * Author: Catherine Wallin
 * Created on 10/9/2020
 * Purpose:  
 */

#include <iostream>
#include <iomanip>

using namespace std;

enum months {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
            SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

struct WeatherData
{
    float totalRainfall,
        lowTemp,
        highTemp,
        averageTemp;
};

int main(){
	
	WeatherData weatherArray[12];
	float totalRainfall = 0;
	float averageRainfall;
    int lowestTemp = 1000;
    int highestTemp = 0;
    float averageTemp;

    for (int i = 0; i < JULY; i++){
        cout << "Enter the total rainfall for the month:" << endl;
        cin >> weatherArray[i].totalRainfall;
        cout << "Enter the high temp:" << endl;
        cin >> weatherArray[i].highTemp;
        cout << "Enter the low temp:" << endl;
        cin >> weatherArray[i].lowTemp;
    }
    

    for (int i = 0; i < JULY; i++){
        totalRainfall += weatherArray[i].totalRainfall;
    }
    averageRainfall = totalRainfall / 6;
    cout << setprecision(2) << fixed << "Average monthly rainfall:" << averageRainfall << endl;
    
    for (int i = 0; i < JULY; i++){
        if (weatherArray[i].lowTemp < lowestTemp){
            lowestTemp = weatherArray[i].lowTemp;
        }
    }

    for (int i = 0; i < JULY; i++){
        if (highestTemp < weatherArray[i].highTemp){
            highestTemp = weatherArray[i].highTemp;
        }
    }

    for (int i = 0; i < JULY; i++){
        weatherArray[i].averageTemp = (weatherArray[i].highTemp + weatherArray[i].lowTemp) / 2;
    }
    
    float totalTemp = 0;
    for (int i = 0; i < JULY; i++){
        totalTemp += weatherArray[i].averageTemp;
    }
    averageTemp = totalTemp/6;
    
    cout << "High Temp:" << highestTemp << endl;
    cout << "Low Temp:" << lowestTemp << endl;
    cout << "Average Temp:" << setprecision(1) << averageTemp;

	return 0;
}
