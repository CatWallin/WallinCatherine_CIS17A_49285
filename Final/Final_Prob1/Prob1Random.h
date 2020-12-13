
/* 
 * File:   Prob1Random.h
 * Author: Catherine Wallin
 * Created on December 12, 2020, 8:06 PM
 */

#ifndef PROB1RANDOM_H
#define PROB1RANDOM_H
#include <time.h>

class Prob1Random
{
	private:
		char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		Prob1Random(const char n,const char *rndseq){       //Constructor
                    nset = n;
                    set = new char[n];
                    for (int i = 0; i < n; i++){
                        set[i] = rndseq[i];
                    }
                    freq = new int[n];
                    numRand = 0;
                };     
                
		~Prob1Random(void){                     //Destructor
                    delete[] set;
                    delete[] freq;
                }
                    
                char randFromSet(void){                 //Returns a random number from the set
                    int generatedNum = 0;
                    numRand++;
                    srand ( time(__null));
                    generatedNum = (rand() % nset);
                    freq[generatedNum] += 1;
                    return set[generatedNum];
                }
                
                int *getFreq(void) const{              //Returns the frequency histogram
                    return freq;
                }
                
                char *getSet(void) const{               //Returns the set used
                    return set;
                }
                
                int getNumRand(void) const{             //Gets the number of times randFromSet has
                    return numRand;                     //been called  
                }               
};


#endif /* PROB1RANDOM_H */

