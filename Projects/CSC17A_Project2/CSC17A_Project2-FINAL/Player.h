
/* 
 * File:   Player.h
 * Author: Catherine Wallin
 * Created on November 28, 2020, 12:37 PM
 * Class for player data
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Job.h"
#include "CollegeJob.h"
#include "JobBase.h"

class Player
{
protected:
    JobBase* career;
    float salary;
    bool married;
    bool degree;
    int children;
    float totalMoney;
    float totalDebt;
    int currentBoardPosition;
    int lifeTileCount;
public:
    //default constructor
    Player(); 
    
    //copy constructor -- used to copy starting player data into a new object 
    Player(const Player &player);
    
    //mutator functions
    void setCareer(JobBase* job);
    void setSalary(int randomNum);
    void setMarried(bool x);
    void setDegree(bool x);
    void setTotalMoney(float tm);
    void setTotalDebt(float td);
    void setCurrentBoardPosition(int cbp);
    void setLifeTileCount(int ltc);
    
    //accessor functions
    JobBase* getCareer(){return career;}
    float getSalary(){return salary;}
    bool getMarried(){return married;}
    bool getDegree(){return degree;}
    int getChildren(){return children;}
    float getTotalMoney(){return totalMoney;}
    float getTotalDebt(){return totalDebt;}
    int getCurrentBoardPosition(){return currentBoardPosition;}
    int getLifeTileCount(){return lifeTileCount;}
    
    //space functions
    int lifeTileSpace();
    float getMoneySpace(int num);
    float payDay();
    void payPlayer(int num);
    void paidByPlayer(int num);
    
    //kidSpace: overloaded operator
    int operator++();
    
    float taxesDueSpace();
    float taxRefundSpace();
    float getRaiseSpace();
    
    void changeSalary(float newSalary);
    
    //function if caught speeding!
    void caughtSpeeding();
    
    //function if another player was speeding and the current player is a police officer 
    void ticketPayment();
    
    //overloaded operator for player's board position
    void operator+=(int spinResult);
    
    void payDebt();
    
    class InvalidSalary{};  
    
    
};

#endif /* PLAYER_H */

