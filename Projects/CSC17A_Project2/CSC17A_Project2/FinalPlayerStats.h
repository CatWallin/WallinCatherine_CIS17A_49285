

/* 
 * File:   FinalPlayerStats.h
 * Author: Catherine
 *
 * Created on December 10, 2020, 7:16 PM
 */

#ifndef FINALPLAYERSTATS_H
#define FINALPLAYERSTATS_H

#include "Player.h"

class FinalPlayerStats : public Player {
private:
    int finalPlace;
    float finalScore;
public:
    FinalPlayerStats() : Player(){
        finalPlace = 0;
        finalScore = 0;
    }
    
    FinalPlayerStats(const Player &player) : Player(player){
        finalPlace = 0;
        finalScore = 0;
    }
    
    void setFinalScore(){
        finalScore = totalMoney + (lifeTileCount * 5000);
        finalScore -= totalDebt;
    }
    
    void setFinalPlace(int x){
        finalPlace = x;
    }
    
    float getFinalScore(){
        return finalScore;
    }
    
    int getFinalPlace(){
        return finalPlace;
    }
        
    void operator--(){
        finalPlace--;
    }
    


};

#endif /* FINALPLAYERSTATS_H */

