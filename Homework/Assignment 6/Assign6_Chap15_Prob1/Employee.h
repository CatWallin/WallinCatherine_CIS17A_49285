/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Catherine
 *
 * Created on November 24, 2020, 12:42 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
protected:
    string employeeName;
    int employeeNum;
    string hireDate;
public:
    Employee(){
        employeeName = "0";
        employeeNum = 0;
        hireDate = "0/0/0";
    }
    Employee(string n, int num, string h){
        employeeName = n;
        employeeNum = num;
        hireDate = h;
    }
    void setEmployeeName(string n){
        employeeName = n;
    }
    void setEmployeeNum(int num){
        employeeNum = num;
    }
    void setHireDate(string h){
        hireDate = h;
    }
    string getEmployeeName(){
        return employeeName;
    }
    int getEmployeeNum(){
        return employeeNum;
    }
    string getHireDate(){
        return hireDate;
    }
};

#endif /* EMPLOYEE_H */

