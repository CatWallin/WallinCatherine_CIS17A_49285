

/* 
 * File:   Prob3Table.tcc
 * Author: Catherine
 *
 * Created on December 14, 2020, 9:44 PM
 */

#ifndef PROB3TABLE_TCC
#define PROB3TABLE_TCC

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <fstream>
#include <iostream>
using namespace std;
#include "Prob3Table.h"

template<class T>
Prob3Table<T>::Prob3Table(char *input, int r, int c){                   
    rows = r;
    cols = c;
    table = new T[rows*cols];
    ifstream inFile;
    inFile.open(input, ios::in);
    
    for (int i = 0; i < r; i++){
        for (int k = 0; k < c; k++){
            inFile >> table[i*c+k];
        }
    }
    
    inFile.close();
    
    calcTable();
    
}

template<class T>
void Prob3Table<T>::calcTable(){
    rowSum = new T[rows];
    //row sum
    for (int i = 0; i < rows; i++){
        int sum = 0;
        for (int k = 0; k < cols; k++){
            sum += table[i*cols+k]; 
        }
        rowSum[i] = sum;
    }
    
    
    //col sum
    colSum = new T[cols];
    for (int i = 0; i < cols; i++){
        int sum = 0;
        for (int k = 0; k < rows; k++){
            sum += table[k*cols+i];
        }
        colSum[i] = sum;
    }
    
    //grand total -- I was going to sum the row sums and the col sums but the example just had one
    grandTotal = 0;
    for (int i = 0; i < cols; i++){
        grandTotal += colSum[i];
    } 
    
}

#endif /* PROB3TABLE_TCC */

