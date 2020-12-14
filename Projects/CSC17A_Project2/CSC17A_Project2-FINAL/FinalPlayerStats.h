

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
    FinalPlayerStats();
    FinalPlayerStats(const Player &player);
    
    void setFinalScore();
    
    void setFinalPlace(int x);
    
    float getFinalScore(){return finalScore;}
    int getFinalPlace(){return finalPlace;}
        
    void operator--();
    
    friend class GameStats;
};

#endif /* FINALPLAYERSTATS_H */

