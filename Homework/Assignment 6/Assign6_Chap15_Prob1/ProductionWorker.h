/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductionWorker.h
 * Author: Catherine
 *
 * Created on November 24, 2020, 12:42 PM
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "Employee.h"
#include <string>

class ProductionWorker : public Employee{
private:
    int shift;
    double hourlyPayRate;
public:
    ProductionWorker(int s, double h) : Employee(){
        shift = s;
        hourlyPayRate = h;
    }
    void setShift(int s){
        shift = s;
    }
    void setHourlyPayRate(double h){
        hourlyPayRate = h;
    }
    int getShift(){
        return shift;
    }
    double getHourlyPayRate(){
        return hourlyPayRate;
    }
};

#endif /* PRODUCTIONWORKER_H */

