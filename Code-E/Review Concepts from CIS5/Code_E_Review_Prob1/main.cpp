/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on 9/11/2020 3PM
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(char [],int);

const int SIZE=80;//Larger than needed
char array[SIZE]; //Character array larger than needed
int sizeIn,sizeDet;//Number of characters to be read, check against length

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here

    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    for (int j = 0;j < SIZE; j++){
        cin >> array[j];
    }
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char[]){
    int x = 0;
    for (int i = 0; i < SIZE; i++){
    if (array[i] > 0){
        x++;
        }
    }
    return x;
}

/*int  read(char []){
    int sizeDet = sizeof(array)/sizeof(array[0]);
    cout << sizeDet << endl;
    return sizeDet;
}
*/

void sort(char array[],int size){
    bool swap;
    int temp;
    
    do{
        swap = false;
        for (int i = 0; i < sizeIn; i++){
            for (int j=i+1;j<sizeIn;j++){
                if (array[i] > array[j]){
                    temp = array[i];
                    array[i]= array[j];
                    array[j] = temp;
                }
            }
        }
    } while (swap);
}

void print(char array[],int size){
    for(int i = 0; i<size; i++){
        cout << array[i];
    }
    cout << endl;
}

