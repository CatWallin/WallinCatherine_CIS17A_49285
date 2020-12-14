
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
public:
    //default constructor
    Job() : JobBase(){
    }
    //constructor
      Job(string p, float min, float max, float t) : JobBase(p, min, max, t){
        degreeRequired = false;
    }

    virtual void printRequirement(){
        cout << "No Degree Required";
    }
    
    ~Job(){}
    
};

#endif /* JOB_H */

