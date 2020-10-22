/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Problem7.h"

using namespace std;

Primes *factor(int num){
    Primes *primeNumberResult = new Primes;
    int originalNum = num;
    
    short primeNumbers[] = {2, 3, 5, 7, 11, 13, 17};
    int countofPrimeNumbers = 7;    
        
    int power = 0;
    int numberOfPrimesFound = 0;
    
    // figure out how many prime numbers we have
    for(int p = 0; p < countofPrimeNumbers; p++){
        while(num % primeNumbers[p] == 0){
            num = num / primeNumbers[p];
            power++;
        }
        
        if(power > 0)
        {
            numberOfPrimesFound++;       
        }
        
        power = 0;
    } 
    
    // setup prime result struct
    primeNumberResult->prime = new Prime[numberOfPrimesFound];
    primeNumberResult->nPrimes = (unsigned char)numberOfPrimesFound; //<-----
    
    // create and store prime structs in array
    int primeArrayIndex = 0;
    power = 0;
    num = originalNum;
    
    for(int p = 0; p < countofPrimeNumbers; p++){
        while(num % primeNumbers[p] == 0){
            num = num / primeNumbers[p];
            power++;
        }
        
        if(power > 0)
        {
            Prime *primeNum = new Prime;
            primeNum->prime = primeNumbers[p];
            primeNum->power = (char)power; // <-----
            
            // get primeNum into Prime array
            primeNumberResult->prime[primeArrayIndex] = *primeNum;
            primeArrayIndex++;
        }
        
        power = 0;
    } 
    return primeNumberResult;
}

void prntPrm(Primes *primes){
    
    for(int i = 0; i < (int)primes->nPrimes; i++)
    {
        cout << (int)primes->prime[i].prime;
        cout << "^";
        cout << (int)primes->prime[i].power << " ";
        if ( i < ((int)primes->nPrimes - 1)){
            cout << "* ";
        }
    }
    
}