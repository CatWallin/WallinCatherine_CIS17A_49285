
#include <iostream>
#include <string.h>
#include "Prob1Random.h"

using namespace std;

Prob1Random::Prob1Random(const char n,const char *rndseq){       //Constructor
    numRand = 0;
    nset = n;
    set = new char[nset];
    for (int i = 0; i < nset; i++){
        set[i] = rndseq[i];
    }
        freq = new int[nset];
        for (int i = 0; i < nset; i++){
            freq[i] = 0;
        }
}     
                
Prob1Random::~Prob1Random(void){                     //Destructor     
    delete[] set; 
    delete[] freq;         
}
                
char Prob1Random::randFromSet(void){                 //Returns a random number from the set
    int generatedNum = (rand() % nset);
    numRand++;
    freq[generatedNum]++;
    return set[generatedNum];
    
}
                 
int * Prob1Random::getFreq(void) const{              //Returns the frequency histogram
    return freq;
}
                  
char * Prob1Random::getSet(void) const{               //Returns the set used
    return set;     
}
                  
int Prob1Random::getNumRand(void) const{             //Gets the number of times randFromSet has
    return numRand;                                 //been called             
}               
