/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on DATE AND TIME HERE
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int );//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //return 0;
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array, rowDet);
    
    //return 0;
    
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int  read(char array[][COLMAX], int rowDet){
    int j = 0;
    string input;
    int maxInput = 0;
    
    while (j < rowDet){
        //cin >> input;
        
        cin >> array[j];
        
        //cout << "input size " << input.size() << endl; 
        
        //char cstr[s.size() + 1];
	    //input.copy(array[j], input.size());
	    //array[j][input.size()] = '\0';
	
        //strcpy(array[j][input.length()], input.c_str()); 
        // for(int x = 0; x < input.length(); x++)
        // {
        //     array[j][x] = input[x];
        // }
        
        //j++;
        string max = array[j];
        
        if (max.length() > maxInput){
        maxInput = max.length();
        }
        
        

        
        j++;
        }
    // for (int i = 0; i < 3; i++){
    //     cout << array[i] << endl;
    //}
    
    
    return maxInput;
}

void sort(char array[][COLMAX],int ROW,int COL){
    // bool swap;
    // int temp;
    // do{
    //     swap = false;
    //     for (int i = 0, j = 1; i < ROW; i++){
    //             if (array[i]>array[j]){
    //                 temp = array[i];
    //                 array[i]= array[j];
    //                 array[j] = temp;
    //             }
    //         }
    //     }
    // } while (swap);
    
    int result;    
		//Performs a run through number of strings	
		for ( int pass = 0; pass < ROW - 1 ; ++pass )
		{
			//Runs through each string for compare		
			for ( int j = 0; j < ROW - 1 - pass; ++j )
			{		
				//Perform string compare and return value store as result                
				result = strcmp (array[j], array[j+1]);		
				//If value is less than 0 then perform swap function to rearrange                
				if (result > 0)		   
					swap ( array[j] , array[j+1] );		
			}//for		 	
		}//for
}

void print(const char array[][COLMAX],int rowDet,int colIn){
     for (int i = 0; i < rowDet; i++){
        cout << array[i] << endl;
        }
}
