
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on November 24, 2020, 11:21 AM
 * CHapter 15 Problem 1: Employee and Production Worker Classes
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include "ProductionWorker.h"




int main(int argc, char** argv) {

    ProductionWorker worker1 = ProductionWorker(1, 15.00);
    worker1.setEmployeeName("Hammy Scott");
    worker1.setEmployeeNum(12345);
    worker1.setHireDate("02/12/2019");
    
    cout << "Employee Name: " << worker1.getEmployeeName() << endl;
    cout << "Number: " << worker1.getEmployeeNum() << endl;
    cout << "Hire Date: " << worker1.getHireDate() << endl;
    cout << "Shift: " << worker1.getShift() << endl;
    cout << "Hourly Pay Rate: $" << setprecision(2) << fixed << worker1.getHourlyPayRate() << endl;
    
    
    return 0;
}

