/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Libraries
#include <iostream>//I/O


using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"
#include "Problem3.h"

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0;
//    int nModes=0;
//    if(nModes!=0)stats->mode->data=new int[nModes];
    
    int maxFrequency = 1;
    int frequency = 1;
    int modeTotal = 0;
    int currentValue = array->data[0];
    for (int i = 1; i < array->size; i++){
        if (array->data[i] == currentValue){
            frequency++;
            if (frequency > maxFrequency && frequency >= 2){
                maxFrequency = frequency;
                modeTotal = 1;
            }
        }
        else {
            currentValue = array->data[i];
            frequency = 1;
        }
    }
    
    
    currentValue = array->data[0];
    frequency = 1;
    modeTotal = 0;
    for (int i = 1; i < array->size; i++){
        if (array->data[i] == currentValue){
            frequency++;
        }
        else {
            if (frequency == maxFrequency && frequency >= 2){
                modeTotal++;
            }
            frequency = 1;
            currentValue = array->data[i];
        }
    }
    
    stats->mode->size=modeTotal;
    stats->modFreq=maxFrequency;
    stats->mode->data=new int[modeTotal];
    
    currentValue = array->data[0];
    frequency = 1;
    int modeArrayIndex = 0;
    for (int i = 1; i < array->size; i++){
        if (array->data[i] == currentValue){
            frequency++;
        }
        else {
            if (frequency == maxFrequency){
                stats->mode->data[modeArrayIndex] = currentValue;
                modeArrayIndex++;
            }
            frequency = 1;
            currentValue = array->data[i];
        }
    }
    
    if (array->size % 2 == 0){
        stats->median = (float)(array->data[(array->size - 1)/2] + array->data[array->size/2])/2;
    }
    else {
        stats->median = (float)array->data[array->size/2];
    }
    
    float sum = 0;
    float average = 0;
    for (int i = 0; i < array->size; i++){
        sum += array->data[i];
    }
    average = sum / array->size;
    
    stats->avg = average;
    cout << average;
    
    return stats;
}