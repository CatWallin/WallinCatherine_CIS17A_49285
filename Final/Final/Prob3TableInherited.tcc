
/* 
 * File:   Prob3TableInherited.tcc
 * Author: Catherine
 *
 * Created on December 14, 2020, 9:14 PM
 */

#ifndef PROB3TABLEINHERITED_TCC
#define PROB3TABLEINHERITED_TCC


#include <iostream>
using namespace std;

//#include "Prob3TableInherited.h"

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char *input,int r,int c):Prob3Table<T>(input, r, c){     
//    augTable = new T[r+1];
//    for (int i = 0; i < r; i++){
//        augTable[i] = new T[c+1];
//    } 
    int augRows = r + 1;
    int augCols = c + 1;
    
    augTable = new T[(augRows)*(augCols)];
        
    for (int i = 0; i < r; i++){
        for (int k = 0; k < c; k++){
            augTable[i*augCols+k] = this->table[i*this->cols+k];
        }
    }
    
    for (int i = 0; i < r; i++){
        augTable[i*augCols+c] = (int)this->rowSum[i];
    }
    
    for (int i = 0; i < c; i++){
        augTable[r*augCols+i] = this->colSum[i];
    }
    
    augTable[r*augCols+c] = this->grandTotal;
    
}     


#endif /* PROB3TABLEINHERITED_TCC */

