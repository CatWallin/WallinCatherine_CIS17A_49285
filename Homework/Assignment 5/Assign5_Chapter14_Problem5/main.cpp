
/* 
 * File:   main.cpp
 * Author: Catherine Wallin 
 * Created on November 11, 2020, 12:46 PM
 * CHapter 14 Problem 5: Time Off
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "NumDays.h"

class TimeOff
{
private:
    string employeeName;
    int employeeID;
    NumDays maxSickDays, sickTaken, maxVacation, vacTaken, maxUnpaid, unpaidTaken;
public:
    TimeOff(string name, int id, double maxSickDays, double sickTaken, double maxVacation, double vacTaken, double maxUnpaid, double unpaidTaken){
        employeeName = name;
        employeeID = id;
        setMaxSickDays(maxSickDays);
        setSickTaken(sickTaken);
        setMaxVacation(maxVacation);
        setVacTaken(vacTaken);
        setMaxUnpaid(maxUnpaid);
        setUnpaidTaken(unpaidTaken);
    }
    
    void setEmployeeName(string name){
        employeeName = name;
    }
    void setEmployeeID(int id){
        employeeID = id;
    }
    void setMaxSickDays(float hours){
        maxSickDays.setWorkHours(hours);
    }
    void setSickTaken(float hours){
        sickTaken.setWorkHours(hours);
    }
    void setMaxVacation(float hours){
        maxVacation.setWorkHours(hours);
    }
    void setVacTaken(float hours){
        vacTaken.setWorkHours(hours);
    }
    void setMaxUnpaid(float hours){
        maxUnpaid.setWorkHours(hours);
    }
    void setUnpaidTaken(float hours){
        unpaidTaken.setWorkHours(hours);
    }
};


int main(int argc, char** argv) {

    return 0;
}

