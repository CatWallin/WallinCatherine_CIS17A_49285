#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int *getData(int &);
int *sort(const int *,int);
int *reverse(const int *,int);
void prntDat(const int *,int); 

int main(int argc, char*argv[]){
    
	int *array;
	int size;
	int *sortedArray;
	int *reversedArray;
	
	cin >> size;
	array = getData(size);
	
    sortedArray = sort(array, size);
    
    prntDat(sortedArray, size); 
    cout << endl;
	
	reversedArray = reverse(sortedArray, size);
	
	prntDat(reversedArray, size);
	
	return 0;
}


int *getData(int & i){
    int *array = new int[i];
    int j = 0;
    do {
        cin >> array[j];
        j++;
    } while (j < i);
    return array;
}

int *sort(const int *array,int size){
    int *sortedArray = new int[size];
    //int sortedArray[size];
    for (int i = 0; i < size; i++){
        sortedArray[i] = array[i];
    }
    sort(sortedArray, sortedArray+size);
    
    return sortedArray;                       
}    

int *reverse(const int *array,int size){
    int *reversedArray = new int[size];
    int reversed = 0;
    for (int i = size -1; i >= 0; i--){
        reversedArray[reversed] = array[i];
        reversed++;
    }
    return reversedArray;
}

void prntDat(const int *array,int size){
    for (int i = 0; i < size; i++){
        cout << *(array + i);
        if (!(i+1 == size)){
            cout << " ";
        }
    }
}