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
    double maxMoney;
public:
    GameStats(){
        maxBoardPosition = 0;
        maxMoney = 0;
    };
    
    //accessor functions
    int getMaxBoardPosition(){
        return maxBoardPosition;
    }
    double getMaxMoney(){
        return maxMoney;
    }
    
    //setter functions
    void setMaxBoardPos(int newMax){
        maxBoardPosition = newMax;
    }
    void setMaxMoney(double newMaxMoney){
        maxMoney = newMaxMoney;
    }
    
    //template to compare starting and ending variables 
    template <typename T>
    bool compare(T x, T y){
        return (x == y)? true: false;
    }
    
};

#endif /* GAMESTATS_H */

