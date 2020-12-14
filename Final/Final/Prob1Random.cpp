
#include <iostream>
#include "Prob1Random.h"

using namespace std;

Prob1Random::Prob1Random(const char n,const char *rndseq){       //Constructor
    nset = n;
    set = new char[n];
    for (int i = 0; i < n; i++){
        set[i] = rndseq[i];
    }
        freq = new int[n];
        numRand = 0;
}     
                
Prob1Random::~Prob1Random(void){                     //Destructor     
    delete[] set; 
    delete[] freq;         
}
                
char Prob1Random::randFromSet(void){                 //Returns a random number from the set
    int generatedNum = 0;
    numRand++;
    srand ( time(__null));
    generatedNum = (rand() % nset);
    freq[generatedNum] += 1;
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
