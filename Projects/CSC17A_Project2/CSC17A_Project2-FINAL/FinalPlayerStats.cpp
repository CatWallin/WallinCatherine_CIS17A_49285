
#include <iostream>
using namespace std;
#include "FinalPlayerStats.h"

FinalPlayerStats::FinalPlayerStats() : Player(){
    finalPlace = 0;
    finalScore = 0;
}

FinalPlayerStats::FinalPlayerStats(const Player &player) : Player(player){
    finalPlace = 0;
    finalScore = 0;
}

void FinalPlayerStats::setFinalScore(){
    finalScore = totalMoney + (lifeTileCount * 5000);
    finalScore -= totalDebt;
}

void FinalPlayerStats::setFinalPlace(int x){
    finalPlace = x;
}

void FinalPlayerStats::operator--(){
        finalPlace--;
    }