/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on 9/15 1PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int,int);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;    
    
    //input array size
    cout << "Input a table and output the Augment row,col and total sums." << endl;
    cin >> row;
    cout << "First input the number of rows and cols. <20 for each" << endl;
    cin >> col;
    
    //Input the original table
    cout << "Now input the table." << endl;
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int array[][COLMAX],int row,int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cin >> array[i][j];
        }
    }
}

void sum(const int array[][COLMAX],int row,int col,int augAry[][COLMAX]){
    
    for (int i = 0; i < row; i++){
        for (int j =0; j < col; j++){
            augAry[i][j] = array[i][j];
        }
    }
    
    // for (int i = 0; i < row; i++){
    //     for (int j = 0; j < col; j++){
    //         cout << augAry[i][j] << " ";
    //     }
    //     cout << endl;
    //}
    for (int i = 0; i < row; i++){
        int sum = 0;
        for (int j = 0; j < col; j++){
            //augAry[i][col+1] = augAry[i][col+1] + augAry[i][j];
            sum += augAry[i][j];
        }
        //cout << "YO here is the sum " << sum << endl;
        augAry[i][col] = sum;
    }
    
    for (int i = 0; i < col+1; i++){
        int sum = 0;
        for (int j = 0; j < row; j++){
            sum += augAry[j][i];
        }
        augAry[row][i] = sum;
    }
    
    // for (int i = 0; i < row+1; i++){
    //     for (int j = 0; j < col+1; j++){
    //         cout << augAry[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
    
void print(const int printing[][COLMAX],int x,int y,int){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cout << setw(10) << printing[i][j];
        }
        cout << endl;
}
}

