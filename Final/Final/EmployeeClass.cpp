#include <iostream>
#include <string.h>
using namespace std;
#include "EmployeeClass.h"

Employee::Employee(char name[], char title[], float rate){
    strcpy(MyName, name);
    strcpy(JobTitle, title);
    HourlyRate = setHourlyRate(rate);
    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;
}

float Employee::CalculatePay(float x, int y){
    getNetPay(getGrossPay(setHourlyRate(x), setHoursWorked(y)));
    return NetPay;
}

float Employee::getGrossPay(float payRate, int hours){
    if (hours <= 40){
        GrossPay = hours * payRate;
    }
    else if (hours > 40 && hours <= 50){
        GrossPay = 40 * payRate;
        float timeAndAHalf = hours - 40;
        GrossPay = GrossPay + (timeAndAHalf * (payRate * 1.5));
    }
    else {
        GrossPay = 40 * payRate;
        GrossPay = GrossPay + (10 * (payRate * 1.5));
        float doubleTime = hours - 50;
        GrossPay = GrossPay + (doubleTime * (payRate * 2));
    }
    return GrossPay;
}

double Employee::Tax(float gross){
    double tax = 0;
    if (gross <= 500){
        tax = .1 * gross;
    }
    else if (gross > 500 && gross <= 1000){
        tax = .1 * 500;
        tax = tax + ((gross - 500) * .2);
    }
    else {
        tax = .1 * 500;
        tax += (.2 * 500);
        tax = tax + ((gross - 1000) * .3);
    }
    return tax;
}

float Employee::getNetPay(float gross){
    NetPay = getGrossPay(HourlyRate, HoursWorked) - Tax(getGrossPay(HourlyRate, HoursWorked));
    return NetPay;
}

void Employee::toString(){
    cout << "Name: " << MyName << "  Job Title: " << JobTitle << endl;
    cout << "Hourly Rate: " << HourlyRate << " Hours Worked: " << HoursWorked;
    cout << " Gross Pay: " << GrossPay << " Net Pay: " << NetPay << endl;
}

int Employee::setHoursWorked(int hours){
    if (hours < 0 || hours > 84){
        throw InvalidHoursWorked();
    }
    HoursWorked = hours;
    return HoursWorked;
}

float Employee::setHourlyRate(float rate){
    if (rate < 0 || rate > 200){
        throw InvalidHourlyRate();
    }
    HourlyRate = rate;
    return HourlyRate;
}