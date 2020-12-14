
#include <iostream>
using namespace std;
#include "GameStats.h"

GameStats::GameStats(){
    maxBoardPosition = 0;
    maxMoney = 0;
    minMoney = 0;
    maxScore = 0;
    winner = 0;
};

void GameStats::setMaxBoardPos(int newMax){
    maxBoardPosition = newMax;
}
    
void GameStats::setMaxMoney(float newMaxMoney){
    maxMoney = newMaxMoney;
}
    
void GameStats::setMinMoney(float newMin){
    minMoney = newMin;
}

