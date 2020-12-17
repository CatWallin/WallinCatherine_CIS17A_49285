
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
    
    T temp;
    if (ascending){
        for(int i = 0; i < arraySize; i++){
            for(int j = 0; j < arraySize; j ++){
                if(array[i]<array[j]){
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    temp = index[i];
                    index[i] = index[j];
                    index[j] = temp;
                }
            }
        }
    }
    else {
        for(int i = 0; i < arraySize; i++){
            for(int j = 0; j < arraySize; j++){
                if(array[i]>array[j]){
                        temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                        temp = index[i];
                        index[i] = index[j];
                        index[j] = temp;
                }
            }
        }
    }
    
    return array;                  
                
}
                
    //array, rows, cols, colToSort, ascending  
template<class T>
T * Prob2Sort<T>::sortArray(const T* input,int r,int c,int sortCol,bool ascending){   
    
    //declare new arrays
    T* array = new T[r*c];
    index = new int[r*c];
    //char* colToSort = new char[r];
     
    //copy input to array
    for (int i = 0; i < (r*c); i++){
        array[i] = input[i];
        index[i] = input[i];
    }
    
   
    
    T temp;
    //sort
    if (ascending){
        for(int i = (sortCol-1); i < r*c; i += c){
            for(int j = (i + c); j < r*c; j += c){
                if(array[i]<array[j]){
                    for (int k = 0; k < c; k++){
                        temp = array[i-(sortCol)+k];
                        array[i-(sortCol)+k] = array[j-(sortCol)+k];
                        array[j-(sortCol)+k] = temp;
                    }
                }
            }
        }
    }
    else {
        for(int i = (sortCol-1); i < r*c; i += c){
            for(int j = (i + c); j < r*c; j += c){
                if(array[i]>array[j]){
                    for (int k = 0; k < c; k++){
                        temp = array[i-(sortCol)+k];
                        array[i-(sortCol)+k] = array[j-(sortCol)+k];
                        array[j-(sortCol)+k] = temp;
                    }
                }
            }
        }
    }
    
    return array;
}   

#endif /* PROB2SORT_TCC */

