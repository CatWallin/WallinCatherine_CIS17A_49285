/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Problem2.h
 * Author: Catherine
 *
 * Created on October 21, 2020, 11:57 PM
 */

#ifndef PROBLEM2_H
#define PROBLEM2_H

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctype.h>
#include <iomanip>

using namespace std;

struct EmployeeData
{
    string name;
    int hours;
    float payRate;
    double grossPay;
};

double calculateGrossPay(struct EmployeeData);
void printPayCheck(struct EmployeeData);
void translateNumber(double);

#endif /* PROBLEM2_H */

