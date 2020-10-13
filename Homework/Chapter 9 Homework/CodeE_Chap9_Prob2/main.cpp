#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array

int main(int argc, char*argv[]){

    int *array;
    int size;
    float *medianArray;
    
    cin >> size;
    array = getData(size);
    
    prntDat(array, size);
    
    medianArray = median(array, size);
    
    prntMed(medianArray);
    
	return 0;
}

int *getData(int & i){
    int *array = new int(i);
    for (int j = 0; j<i; j++){
        cin >> array[j];
    }
    return array;
}

void prntDat(int *array,int size){
    for (int i = 0; i < size; i++){
        cout << *(array + i);
        if (!(i+1 == size)){
            cout << " ";
        }
    }
    cout << endl;
}

float *median(int *array,int size){
    float *medianArray = new float(size + 2);
    medianArray[0] = size+2;
    for (int i = 0; i < size; i++){
        medianArray[i+2] = (float)array[i];
    }
    sort(array, array + size);
    if (size%2 == 0){
        medianArray[1] = (float)(array[(size - 1)/2] + array[size/2])/2;   
    }
    else {
        medianArray[1] = (float)array[size/2];
    }
    return medianArray;
}  

void prntMed(float *medianArray){
     for (int i = 0; i < medianArray[0]; i++){
        cout << fixed << setprecision(i==0?0:2) << *(medianArray + i);
        if (!(i+1 == medianArray[0])){
            cout << " ";
        }
    }
}     