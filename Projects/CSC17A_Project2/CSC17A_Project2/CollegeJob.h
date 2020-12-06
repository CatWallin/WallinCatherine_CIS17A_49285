
/* 
 * File:   CollegeJob.h
 * Author: Catherine Wallin *
 * Created on November 29, 2020, 10:46 AM
 * Inherited Class for College Careers
 */

#ifndef COLLEGEJOB_H
#define COLLEGEJOB_H

#include "Job.h"

class CollegeJob : public Job
{
    private:
        
    public:
        //default constructor
        CollegeJob(){
            degreeRequired = true;
        }
        //constructor
        CollegeJob(string p, double min, double max, float t):Job(p, min, max, t){
            degreeRequired = true;
        }
        virtual void print(){
            cout << "You studied hard and earned your degree!";
        }
        
            
};

#endif /* COLLEGEJOB_H */

