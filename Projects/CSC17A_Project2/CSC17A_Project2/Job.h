
/* 
 * File:   Job.h
 * Author: Catherine Wallin
 * Created on November 28, 2020, 12:37 PM
 * Class for Job Info
 */

#ifndef JOB_H
#define JOB_H

#include "JobBase.h"

using namespace std;
class Job : public JobBase
{
protected:
    string position;
    double minSalary;
    double maxSalary;
    float taxes;
    bool degreeRequired;
public:
    //default constructor
    Job() : JobBase(){
//        position = "0";
//        minSalary = 0.0;
//        maxSalary = 0.0;
//        taxes = 0.0;
//        degreeRequired = false;
    }
    //constructor
      Job(string p, double min, double max, float t) : JobBase(p, min, max, t){
//        position = p;
//        minSalary = min;
//        maxSalary = max;
//        taxes = t;
        degreeRequired = false;
    }
    
    //accessor functions 
//    string getPosition(){
//        return position;
//    }
//    double getMinSalary(){
//        return minSalary;
//    }
//    double getMaxSalary(){
//        return maxSalary;
//    }
//    float getTaxes(){
//        return taxes;
//    }
//    bool getDegreeRequired(){
//        return degreeRequired;
//    }    
    virtual void printRequirement(){
        cout << "No Degree Required";
    }
    
//     ~Job(){}
    
};



#endif /* JOB_H */

