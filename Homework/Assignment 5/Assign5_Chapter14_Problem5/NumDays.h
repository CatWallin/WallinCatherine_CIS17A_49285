/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: Catherine
 *
 * Created on November 11, 2020, 1:07 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <string>

class NumDays
{
private:
    float workHours;
    float days;
public: 
    NumDays(float workHours){
        this->workHours = workHours;
        days = workHours/8.00;
    }
    void setDays(float days){
        this->days = days;
        this->workHours = days * 8.00;
    }
    float getWorkHours(){
        return workHours;
    }
    float getDays(){
        return days;
    }
    void setWorkHours(float hours){
        workHours = hours;
        days = workHours/8.00;
    }
    float operator+(NumDays x){
        workHours += x.workHours;
        days = workHours/8.00;
        return workHours;
    }
    float operator-(NumDays x){
        workHours -= x.workHours;
        days = workHours/8.00;
        return workHours - x.workHours;
    }
    void operator++(){
        ++workHours;
        days = workHours/8.00;
    }
    void operator++(int){
        NumDays temp(workHours);
        workHours++;
        days = workHours/8.00;
    }
    void operator--(){
        --workHours;
        days = workHours/8.00;
    }
    void operator--(int){
        NumDays temp(workHours);
        workHours--;
        days = workHours/8.00;
    }
};

#endif /* NUMDAYS_H */

