/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StartingPlayerStats.h
 * Author: Catherine Wallin
 * Created on December 5, 2020, 10:39 AM
 * Class to hold starting player stats
 */

#ifndef STARTINGPLAYERSTATS_H
#define STARTINGPLAYERSTATS_H

#include "Player.h"

class StartingPlayerStats : public Player
{
    private:
        
    public:
        StartingPlayerStats(){};
        //copy constructor to store the player's starting stats
        StartingPlayerStats(Player const &d){};
        //StartingPlayerStats(const StartingPlayerStats &d) : Player(d){};
    
};

#endif /* STARTINGPLAYERSTATS_H */

