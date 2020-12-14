
/* 
 * File:   CollegeJob.h
 * Author: Catherine Wallin *
 * Created on November 29, 2020, 10:46 AM
 * Inherited Class for College Careers
 */

#ifndef COLLEGEJOB_H
#define COLLEGEJOB_H

#include "JobBase.h"
#include "Job.h"

using namespace std;

class CollegeJob : public JobBase
{
    private:
        
    public:
        //default constructor
        CollegeJob(){
            degreeRequired = true;
        }
        //constructor
        CollegeJob(string p, float min, float max, float t):JobBase(p, min, max, t){
            degreeRequired = true;
        }
        void printRequirement(){
            cout << "**Degree Required**";
        }
};

#endif /* COLLEGEJOB_H */

