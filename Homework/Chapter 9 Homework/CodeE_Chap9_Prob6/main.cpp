#include <iostream>

using namespace std;

int *getData(int &);            //Read the array
int *augment(const int *,int);  //Augment and copy the original array
void prntAry(const int *,int);  //Print the array

int main(){
	
	int *array;
	int size;
    int *augArray;
    int augSize;
    
    cin >> size;
    augSize = size + 1;
    array = getData(size);
	
	augArray = augment(array, size);
	
	prntAry(array, size);
	cout << endl;
	prntAry(augArray, augSize);
	
	return 0;
}

int *getData(int & i){
    int *array = new int(i);
    for(int j = 0; j < i; j++){
        cin >> array[j];
    }
    return array;
}

int *augment(const int *array,int size){
    int *augArray = new int(size+1);
    augArray[0] = 0;
    for (int i = 1; i < size+1; i++){
        augArray[i] = array[i-1];
    }
    return augArray;
}

void prntAry(const int *array,int size){
    for (int i = 0; i < size; i++){
        cout << array[i];
        if (!(i == size-1)){
            cout << " ";
        }
    }
}
