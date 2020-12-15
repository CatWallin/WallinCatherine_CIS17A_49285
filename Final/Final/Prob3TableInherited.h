
/* 
 * File:   Prob3TableInherited.h
 * Author: Catherine Wallin
 * Created on December 12, 2020, 10:25 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

#include "Prob3Table.h"
using namespace std;

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char *,int ,int );        
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};



#endif /* PROB3TABLEINHERITED_H */

