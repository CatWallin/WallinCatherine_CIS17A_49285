
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on December 12, 2020, 8:07 PM
 * Final Problem 2: All Kinds of Sorting
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#include "Prob2Sort.h"

int main(int argc, char** argv) {

    cout<<"The start of Problem 2, the sorting problem"<<endl;
	Prob2Sort<char> rc;
	bool ascending=true;
	ifstream infile;
	infile.open("Problem2.txt",ios::in);
	char *ch2=new char[10*16];
	char *ch2p=ch2;
	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
	infile.close();
	cout<<endl;
	cout<<"Sorting on which column"<<endl;
	int column;
	cin>>column;
	char *zc=rc.sortArray(ch2p,10,16,column,ascending);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<16;j++)
		{
			cout<<zc[i*16+j];
		}
	}
	delete []zc;
	cout<<endl;
    
    return 0;
}

