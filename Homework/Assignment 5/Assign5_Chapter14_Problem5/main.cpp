
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
    NumDays maxSickDays = NumDays(0); 
    NumDays sickTaken = NumDays(0);
    NumDays maxVacation = NumDays(0);
    NumDays vacTaken = NumDays(0);
    NumDays maxUnpaid = NumDays(0);
    NumDays unpaidTaken = NumDays(0);
    
public:
    TimeOff(string name, int id){
        employeeName = name;
        employeeID = id;
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
        if (hours > 240){
            maxVacation.setWorkHours(240);
        }
        else {
            maxVacation.setWorkHours(hours);
        }
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
    
    string getEmployeeName(){
        return employeeName;
    }
    int getEmployeeID(){
        return employeeID;
    }
    NumDays getMaxSickDays(){
        return maxSickDays;
    }
    NumDays getSickTaken(){
        return sickTaken;
    }
    NumDays getMaxVacation(){
        return maxVacation;
    }
    NumDays getVacTaken(){
        return vacTaken;
    }
    NumDays getMaxUnpaid(){
        return maxUnpaid;
    }
    NumDays getUnpaidTaken(){
        return unpaidTaken;
    }
};


int main(int argc, char** argv) {

    TimeOff employee1 = TimeOff("Lido", 54321);
    employee1.setMaxVacation(500);
    employee1.setMaxSickDays(12);
    cout << employee1.getMaxSickDays().getDays() << endl;
    cout << employee1.getMaxSickDays().getWorkHours() << endl;
    cout << employee1.getMaxVacation().getWorkHours() << endl;
    cout << "Name: " << employee1.getEmployeeName() << endl;
    cout << "ID: " << employee1.getEmployeeID() << endl;
    
    return 0;
}

