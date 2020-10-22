/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Problem7.h
 * Author: Catherine
 *
 * Created on October 21, 2020, 10:14 PM
 */

#ifndef PROBLEM7_H
#define PROBLEM7_H

struct Prime 
{
    unsigned short prime;
    unsigned char power;
};
struct Primes
{
    unsigned char nPrimes;
    Prime *prime;
};

Primes *factor(int);    //Input an integer, return all prime factors
void prntPrm(Primes *);  //Output all prime factors

#endif /* PROBLEM7_H */

