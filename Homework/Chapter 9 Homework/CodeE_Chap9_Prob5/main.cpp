#include <iostream>

using namespace std;

int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

int main(){
	
	int rows, columns;
    int **array;
    int result;

    cin >> rows;
    cin >> columns;
    array = getData(rows, columns);
    
    prntDat(array, rows, columns);

	result = sum(array, rows, columns);
	
	cout << result;
	
    destroy(array, rows, columns);

	
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

void prntDat(const int* const *array,int r,int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << array[i][j];
            if (!(j+1 == c)){
                cout << " ";
            }
        }
        cout << endl;
    }
}

void destroy(int **array,int r,int c){
    delete []array;
}

int sum(const int * const *array, int r,int c){
    int result = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            result = result + array[i][j];
        }
    }
    return result;
}