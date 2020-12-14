/* 
 * File:   GameStats.h
 * Author: Catherine Wallin
 * Created on December 2, 2020, 8:56 PM
 * Class to hold Game Stats
 */

#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "FinalPlayerStats.h"


class GameStats
{
private:
    int maxBoardPosition;
    float maxMoney;
    float minMoney;
    float maxScore;
    int winner;
public:
    GameStats();
    
    //accessor functions
    int getMaxBoardPosition(){return maxBoardPosition;}
    float getMaxMoney(){return maxMoney;}
    float getMinMoney(){return minMoney;}
    float getMaxScore(){return maxScore;}
    int getWinner(){return winner;}
    
    //setter functions
    void setMaxBoardPos(int newMax);
    void setMaxMoney(float newMaxMoney);
    void setMinMoney(float newMin);
   
    //template to compare starting and ending variables 
    template <typename T>
    bool compare(T x, T y){
        return (x == y)? true: false;
    }
    
    void determineWinner(FinalPlayerStats* player, int numPlayers){
        for (int i = 0; i < numPlayers; i++){
            if (player[i].finalScore > maxScore){
                maxScore = player[i].finalScore;
            }
            if (player[i].finalPlace == 1){
                winner = i+1;
            }
        }
    }
    
};

#endif /* GAMESTATS_H */

