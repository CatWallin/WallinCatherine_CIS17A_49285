
/* 
 * File:   Player.h
 * Author: Catherine Wallin
 * Created on November 28, 2020, 12:37 PM
 * Class for player data
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Job.h"

class Player
{
protected:
    Job career;
    double salary;
    bool married;
    bool degree;
    int children;
    double totalMoney;
    double totalDebt;
    int currentBoardPosition;
    int lifeTileCount;
public:
    //default constructor
    Player(){
        salary = 0;
        married = false;
        degree = false;
        children = 0;
        totalMoney = 1000;
        totalDebt = 0;
        currentBoardPosition = 0;
        lifeTileCount = 0;
    }
    //mutator functions
    void setCareer(Job job){        
        career = job;
    }
    void setSalary(int randomNum){
        if (randomNum == 1){
            salary = career.getMinSalary();
        }
        else if (randomNum == 2){
            salary = career.getMinSalary() + 10000;
        }
        else {
            salary = career.getMaxSalary() * .75;
        }
    }
    void setMarried(bool x){
        married = x;
    }
    void setDegree(bool x){
        degree = x;
    }
    void setTotalMoney(double tm){
        totalMoney = tm;
    }
    void setTotalDebt(double td){
        totalDebt = td;
    }
    void setCurrentBoardPosition(int cbp){
        currentBoardPosition = cbp;
    }
    void setLifeTileCount(int ltc){
        lifeTileCount = ltc;
    }
    //accessor functions
    Job getCareer(){
        return career;
    }
    double getSalary(){
        return salary;
    }
    bool getMarried(){
        return married;
    }
    bool getDegree(){
        return degree;
    }
    int getChildren(){
        return children;
    }
    double getTotalMoney(){
        return totalMoney;
    }
    double getTotalDebt(){
        return totalDebt;
    }
    int getCurrentBoardPosition(){
        return currentBoardPosition;
    }
    int getLifeTileCount(){
        return lifeTileCount;
    }
    
    //space functions
    int lifeTileSpace(){
        lifeTileCount++;
        return lifeTileCount;
    }
    double getMoneySpace(){
        totalMoney += 500;
        return totalMoney;
    }
    double payDay(){
        totalMoney += salary;
        return totalMoney;
    }
    //kidSpace: overloaded operator
//    Player operator++(){
//        ++children;
//        return children;
//    }
    double taxesDueSpace(){
        totalMoney -= career.getTaxes();
        return totalMoney;
    }
    float taxRefundSpace(){
        totalMoney += (career.getTaxes() * .25);
        return (career.getTaxes() * .25);
    }
    double getRaiseSpace(){
        if ((career.getMaxSalary()-10000) > salary){
            salary += 10000;
            return salary;
        }
        else{
            salary = career.getMaxSalary();
            return salary;
        }
    }
    //function if caught speeding!
    void caughtSpeeding(){
        totalMoney -= 2000;
    }
    //function if another player was speeding and the current player is a police officer 
    void ticketPayment(){
        totalMoney +=2000;
    }
    
    void movePlayerPiece(int spinNum){
        currentBoardPosition += spinNum;
    }
    
    
};


#endif /* PLAYER_H */

