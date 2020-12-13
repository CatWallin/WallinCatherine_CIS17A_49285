
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on December 12, 2020, 8:07 PM
 * Final Problem 3: Spreadsheet Stuff
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#include "Prob3TableInherited.h"


int main(int argc, char** argv) {

    cout<<"Entering problem number 3"<<endl;
	int rows=5;
	int cols=6;
        
        ifstream infile;
	infile.open("Problem3.txt",ios::in);
        
        
	Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
	const int *naugT=tab.getTable();
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<naugT[i*cols+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	const int *augT=tab.getAugTable();
	for(int i=0;i<=rows;i++)
	{
		for(int j=0;j<=cols;j++)
		{
			cout<<augT[i*(cols+1)+j]<<" ";
		}
		cout<<endl;
	}
    
    
    return 0;
}

