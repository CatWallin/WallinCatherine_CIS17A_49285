
/* 
 * File:   Prob2Sort.tcc
 * Author: Catherine
 *
 * Created on December 15, 2020, 10:19 AM
 */

#ifndef PROB2SORT_TCC
#define PROB2SORT_TCC

#include <cstring>
#include <iostream>
using namespace std;
#include "Prob2Sort.h"

//Sorts a single column array -- array, size, ascending
template<class T>
T * Prob2Sort<T>::sortArray(const T* input,int arraySize,bool ascending){
    T* array = new T[arraySize];
    index = new int[arraySize];
    
    //set index values
    for (int i = 0; i < arraySize; i++){
        index[i]=i;
    }
    //copy inputed array 
    for(int i = 0; i < arraySize; i++){
        array[i] = input[i];
    }
    //sort
    //for
    
    return array;                  
                
}
                
    //array, rows, cols, colToSort, ascending  
template<class T>
T * Prob2Sort<T>::sortArray(const T* input,int r,int c,int sortCol,bool ascending){   
    
    T* array = new T[r*c];
    index = new int[r];
    //T* colSortArray = new T[r];
    
    for (int i = 0; i < (r*c); i++){
        array[i] = input[i];
    }
    
    
   
    
//    do{
//        swap = false;
//        for (int i = 0; i < c*r; i++){
//            for (int k = c; k < r*c; k++){
//                if (ascending){
//                    if (array[i*c+sortCol] > array[k*c+sortCol]){
//                        temp = array[i*c+sortCol];
//                        array[i*c+sortCol] = array[k*c+sortCol];
//                        array[k*c+sortCol] = temp;
//                    }
//                }
//                else{
//
//                }
//            }
//        } 
//    } while(swap);

    return array;
}   

#endif /* PROB2SORT_TCC */

