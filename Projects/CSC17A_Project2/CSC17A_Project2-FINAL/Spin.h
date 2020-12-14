/* 
 * File:   Spin.h
 * Author: Catherine Wallin
 * Created on November 30, 2020, 9:02 PM
 * Static Class to Spin the game wheel 
 */

#ifndef SPIN_H
#define SPIN_H

class Spin
{
public:
    static int initiateSpin(){
        return rand() % 10 + 1;
    }
};

#endif /* SPIN_H */

