
/* 
 * File:   JobBase.h
 * Author: Catherine Wallin
 * Created on December 9, 2020, 9:23 PM
 */



#ifndef JOBBASE_H
#define JOBBASE_H

using namespace std;

class JobBase
{
protected:
    string position;
    double minSalary;
    double maxSalary;
    float taxes;
    bool degreeRequired;   
    
public:
    JobBase(){
        position = "0";
        minSalary = 0.0;
        maxSalary = 0.0;
        taxes = 0.0;
        degreeRequired = false;
    }
    JobBase(string p, double min, double max, float t){
        position = p;
        minSalary = min;
        maxSalary = max;
        taxes = t;
    }
    string getPosition(){
        return position;
    }
    double getMinSalary(){
        return minSalary;
    }
    double getMaxSalary(){
        return maxSalary;
    }
    float getTaxes(){
        return taxes;
    }
    bool getDegreeRequired(){
        return degreeRequired;
    }    
    virtual void printRequirement() = 0;
    
    
    
    
};



#endif /* JOBBASE_H */

