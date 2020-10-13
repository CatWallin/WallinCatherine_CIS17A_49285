#include <iostream>
#include <iomanip>

using namespace std;

struct WeatherData
{
    string month;
    int totalRainfall,
        lowTemp,
        highTemp,
        averageTemp;
};

int main(){
	
	WeatherData weatherArray[12];
	float totalRainfall = 0;
	float averageRainfall;
    int lowestTemp = 0;
    int highestTemp = 0;
    float averageTemp;

    for (int i = 0; i < 12; i++){
        cin >> weatherArray[i].month;
        cin >> weatherArray[i].totalRainfall;
        cin >> weatherArray[i].lowTemp;
        cin >> weatherArray[i].highTemp;
    }
    

    for (int i = 0; i < 12; i++){
        totalRainfall += weatherArray[i].totalRainfall;
    }
    averageRainfall = totalRainfall / 12;
    cout << setprecision(1) << fixed << "Average Rainfall " << averageRainfall;
    cout << " inches/month" << endl;
    
    int lowIndex = 0;
    for (int i = 0; i < 12; i++){
        if (weatherArray[i].lowTemp < lowestTemp){
            lowestTemp = weatherArray[i].lowTemp;
            lowIndex = i;
        }
    }
    cout << "Lowest  Temperature " << weatherArray[lowIndex].month << "  ";
    cout << weatherArray[lowIndex].lowTemp << " Degrees Fahrenheit" << endl;
    
    int highIndex = 0;
    for (int i = 0; i < 12; i++){
        if (highestTemp < weatherArray[i].highTemp){
            highestTemp = weatherArray[i].highTemp;
            highIndex = i;
        }
    }
    cout << "Highest Temperature " << weatherArray[highIndex].month << "  ";
    cout << weatherArray[highIndex].highTemp << " Degrees Fahrenheit" << endl;

    for (int i = 0; i < 12; i++){
        weatherArray[i].averageTemp = (weatherArray[i].highTemp + weatherArray[i].lowTemp) / 2;
    }
    
    float totalTemp = 0;
    for (int i = 0; i < 12; i++){
        totalTemp += weatherArray[i].averageTemp;
    }
    averageTemp = totalTemp/12;
    
    cout << "Average Temperature for the year ";
    cout << setprecision(0) << fixed << averageTemp;
    cout << " Degrees Fahrenheit" << endl;

	return 0;
}
