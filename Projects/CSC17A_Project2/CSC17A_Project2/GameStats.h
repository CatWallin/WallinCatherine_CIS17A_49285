/* 
 * File:   GameStats.h
 * Author: Catherine Wallin
 * Created on December 2, 2020, 8:56 PM
 * Class to hold Game Stats
 */

#ifndef GAMESTATS_H
#define GAMESTATS_H

class GameStats
{
private:
    int maxBoardPosition;
    float maxMoney;
    float minMoney;
    float midMoney;
public:
    GameStats(){
        maxBoardPosition = 0;
        maxMoney = 0;
        minMoney = 0;
    };
    
    //accessor functions
    int getMaxBoardPosition(){
        return maxBoardPosition;
    }
    float getMaxMoney(){
        return maxMoney;
    }
    float getMinMoney(){
        return minMoney;
    }
    
    //setter functions
    void setMaxBoardPos(int newMax){
        maxBoardPosition = newMax;
    }
    void setMaxMoney(double newMaxMoney){
        maxMoney = newMaxMoney;
    }
    void setMinMoney(double newMin){
        minMoney = newMin;
    }
   
    //template to compare starting and ending variables 
    template <typename T>
    bool compare(T x, T y){
        return (x == y)? true: false;
    }
    
};

#endif /* GAMESTATS_H */

