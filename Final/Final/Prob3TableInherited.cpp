
#include <iostream>
using namespace std;

#include "Prob3TableInherited.h"

Prob3TableInherited::Prob3TableInherited(char *input,int r,int c):Prob3Table(input, r, c){     //Constructor
    augTable = new T[r];
    for (int i = 0; i < r; i++){
        augTable[i] = new T[c];
    }  
}      