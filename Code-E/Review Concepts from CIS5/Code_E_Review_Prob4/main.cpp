/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on 9/14/2020 6PM
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

void read(vector<int> &even, vector<int> &odd){
    int expectedInput;
    cout << "Input the number of integers to input." << endl;
    cin >> expectedInput;
    cout << "Input each number." << endl;
    int x;
    for (int i = 0; i < expectedInput; i++){
        cin >> x;
        if (x%2 == 0){
            even.insert(even.end(),x);
            }
        else {
            odd.insert(odd.end(), x);
        }
    }
    return;
}

void copy(vector<int> even, vector<int> odd,int array[][COLMAX]){
    for (int i = 0; i < even.size();i++){
            array[i][0] = even.at(i);
    }
    for (int i = 0; i < odd.size();i++){
            array[i][1] = odd.at(i);
    }
}

void prntVec(vector<int> even, vector<int> odd,int width){
    cout << "    Vector      Even       Odd" << endl;
    int size = (odd.size() > even.size()) ? odd.size() : even.size();
    for (int i = 0; i < size; i++){
        cout << setw(width) << "";
        for (int j =0; j < 2; j++){
            if ((j == 0 && i < even.size())){
                cout << setw(width) << even.at(i);
            }
            else if ((j == 1 && i < odd.size())){
                cout << setw(width) << odd.at(i);
            }
            else {
                cout << setw(width) << "";
            }
        }
        cout << endl;
    }
}

void prntAry(const int array[][COLMAX],int evenSize,int oddSize,int width){
    cout << "     Array      Even       Odd" << endl;
    int size = (oddSize > evenSize) ? oddSize : evenSize;
    for (int i = 0; i < size; i++){
        cout << setw(width) << "";
        for (int j = 0; j < 2; j++){
            if ((j == 0 && i < evenSize) || (j == 1 && i < oddSize)){
                cout << setw(width) << array[i][j];
            }
            else{
                cout << setw(width) << "";
            }
        }
        cout << endl;
    }
}