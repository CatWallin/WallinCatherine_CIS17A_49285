/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Catherine
 * Created on October 20, 2020, 9:46 AM
 * Midterm Problem 7
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

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

int main(int argc, char** argv) {

    int input = 120;
    
    cout << "Enter a number to factor into its prime numbers: ";
    //cin >> input;    
    while (input < 2 || input > 10000){
        cout << "Invalid Input. Try Again: ";
        cin >> input;
    }
    Primes array = *factor(input);
    
    prntPrm(Primes *array);
    
    return 0;
}

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
            cout << primeNumbers[p] << " " << power << endl;
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
    
    for(int aaron = 0; aaron < 3; aaron++)
    {
        cout << primeNumberResult->prime[aaron].prime;
        cout << "^";
        cout << primeNumberResult->prime[aaron].power << " " << endl;
    }
   
    return primeNumberResult;
}

void prntPrm(Primes *primes){
    
    for(int aaron = 0; aaron < 3; aaron++)
    {
        cout << primeNumberResult->prime[aaron].prime;
        cout << "^";
        cout << primeNumberResult->prime[aaron].power << " " << endl;
    }
    
}