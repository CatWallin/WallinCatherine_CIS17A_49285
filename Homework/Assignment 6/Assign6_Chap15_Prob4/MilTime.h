/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MilTime.h
 * Author: Catherine
 *
 * Created on November 24, 2020, 1:32 PM
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

class MilTime: public Time
{
private:
    int milHours;
    int milSeconds;
public:
    MilTime(int h, int s){
        milHours = h;
        milSeconds = s;
        if (milHours < 100){
            hour = 12;
        }
        else if ((milHours/100) <= 12){
            hour = (milHours/100);
        }
        else 
            hour = (milHours/100) - 12;
        min = milHours % 100;
        sec = milSeconds;
    }
    void setTime(int h, int s){
        milHours = h;
        milSeconds = s;
        if (milHours < 100){
            hour = 12;
        }
        else if ((milHours/100) <= 12){
            hour = (milHours/100);
        }
        else 
            hour = (milHours/100) - 2;
        min = milHours % 100;
        sec = milSeconds;
    }
    int getMilHours(){
        return milHours;
    }
    int getStandHr(){
        return hour;
    }
        
};



#endif /* MILTIME_H */

