#include <iostream>

using namespace std;

int *getData(int &);
int *sumAry(const int *,int);
void prntAry(const int *,int);

int main(){

    int *array;
    int size;
    int *sumArray;

    cin >> size;
    array = getData(size); 
    
    prntAry(array, size);
    cout << endl;
    
    sumArray = sumAry(array, size);
    
    prntAry(sumArray, size);

	return 0;
}



int *getData(int & i){
    int *array = new int(i);
    for(int j = 0; j < i; j++){
        cin >> array[j];
    }
    return array;
}

int *sumAry(const int *array,int i){
    int *sumArray = new int(i);
    sumArray[0] = array[0];
    for (int j = 1; j < i; j++){
        sumArray[j] = array[j] + sumArray[j-1];
    }
    return sumArray;
} 

void prntAry(const int *array,int size){
    for (int i = 0; i < size; i++){
        cout << *(array + i);
        if (!(i+1 == size)){
            cout << " ";
        }
    }
}