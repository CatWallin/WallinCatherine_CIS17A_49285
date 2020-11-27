
/* 
 * File:   GradedActivity.h
 * Author: Catherine
 *
 * Created on November 25, 2020, 1:17 PM
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
protected:
    double score;
public:
    //default constructor
    GradedActivity(){
        score = 0.0;
    }
    //constructor
    GradedActivity(double s){
        score = s;
    }
    
    //mutator function
    void setScore(double s){
        score = s;
    }
    
    //accessor functions
    double getScore(){
        return score;
    }
    
    virtual char getLetterGrade(){
        if (score > 89){
            return 'A';
        }
        else if (score > 79){
            return 'B';
        }
        else if (score > 69){
            return 'C';
        }
        else if (score > 59){
            return 'D';
        }
        else
            return 'F';
    }
    
};

#endif /* GRADEDACTIVITY_H */

