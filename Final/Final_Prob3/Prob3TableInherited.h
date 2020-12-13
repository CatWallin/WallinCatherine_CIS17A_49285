
/* 
 * File:   Prob3TableInherited.h
 * Author: Catherine Wallin
 * Created on December 12, 2020, 10:25 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

#include "Prob3Table.h"

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char *input,int r,int c):Prob3Table(input, r, c){     //Constructor
                    augTable = new T[r];
                    for (int i = 0; i < r; i++){
                        augTable[i] = new T[c];
                    }
                }          
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};

#endif /* PROB3TABLEINHERITED_H */

