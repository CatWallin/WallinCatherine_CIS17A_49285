/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
using namespace std;

#include "Prob3Table.h"

Prob3Table::Prob3Table(char *input,int r,int c){              //Constructor then Destructor          
    table = new T[rows];
    for (int i = 0; i < rows; i++){
        table[i] = new T[cols];       
    }
                        
    for (int i = 0; i < rows; i++){
        table[i] = input[i];
    }
    rows = r;
    cols = c;
    
    for (int i = 0; i < rows; i++){
        T sum = 0;
        rowSum = new T[rows];
        for (int k = 0; i < cols; k++){
            rowSum[i] += table[i][k]; 
        }
    }

    for (int i = 0; i < cols; i++){
        T sum = 0;
        colSum = new T[cols];
        for (int k = 0; i < rows; k++){
            colSum[i] += table[k][i]; 
        }
    }
    
    for (int i = 0; i < rows; i++){
        grandTotal += rowSum[i];
    } 
    
    for (int i = 0; i < cols; i++){
        grandTotal += colSum[i];
    } 
}