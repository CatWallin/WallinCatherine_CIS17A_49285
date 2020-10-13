#include <iostream>

using namespace std;

int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(){

    int rows, columns;
    int **array;
    int **augArray;

    cin >> rows;
    cin >> columns;
    array = getData(rows, columns);
    
    printDat(array, rows, columns);
    
    int augColumns = columns + 1;
    int augRows = rows + 1;
    augArray = augment(array, augRows, augColumns);
    cout << endl;
    printDat(augArray, augRows, augColumns);

	return 0;
}


int **getData(int & r,int & c){
    int **array = new int*[r];
    for(int i = 0; i < r; ++i){
        array[i] = new int[c];
    }
    for (int j = 0; j < r; j++){
        for (int k = 0; k < c; k++){
            cin >> array[j][k];
        }
    }
    return array;
}

void printDat(const int * const *array,int r,int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << array[i][j];
            if (!(j+1 == c)){
                cout << " ";
            }
        }
        if (!(i+1 == r)){
        cout << endl;
        }
    }
}

int **augment(const int * const *array,int r,int c){
    int **augArray = new int*[r];
    for(int i = 0; i < r; ++i){
        augArray[i] = new int[c];
    }
    for (int i = 0; i < r; i++){
        augArray[i][0] = 0;
    }
    for (int i = 0; i < c; i++){
        augArray[0][i] = 0;
    }
    
    for (int i = 0; i < r-1; i++){
        for (int j = 0; j < c-1; j++){
            augArray[i+1][j+1] = array[i][j];
        }
    }
    return augArray;
}

void destroy(int **,int){
    
}