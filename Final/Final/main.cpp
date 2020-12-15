/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on December 13, 2020, 1:55 
 * Final CSC-17A
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

//user libraries
#include "EmployeeClass.h"
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "Prob3Table.h"
#include "Prob3Table.tcc"
#include "Prob3TableInherited.h"
#include "Prob3TableInherited.tcc"
#include "SavingsAccount.h"

void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();

int main(int argc, char** argv) {

    char choice;
    
    do{
        menu();
        cin>>choice;
        //choice = '1';

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='6');
    
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl << endl;
}

void prblm1(){
    char n=5;
	char rndseq[]={19,34,57,79,126};
	int ntimes=100000;
	Prob1Random a(n,rndseq);
	for(int i=1;i<=ntimes;i++)
	{
		a.randFromSet();
	}
	int *x=a.getFreq();
	char *y=a.getSet();
	for(int i=0;i<n;i++)
	{
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}
	cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

void prblm2(){
//    cout<<"The start of Problem 2, the sorting problem"<<endl;
//	Prob2Sort<char> rc;
//	bool ascending=true;
//	ifstream infile;
//	infile.open("Problem2.txt",ios::in);
//	char *ch2=new char[10*16];
//	char *ch2p=ch2;
//	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
//	infile.close();
//	cout<<endl;
//	cout<<"Sorting on which column"<<endl;
//	int column;
//	cin>>column;
//	char *zc=rc.sortArray(ch2p,10,16,column,ascending);
//	for(int i=0;i<10;i++)
//	{
//		for(int j=0;j<16;j++)
//		{
//			cout<<zc[i*16+j];
//		}
//	}
//	delete []zc;
//	cout<<endl;
}

void prblm3(){
    cout<<"Entering problem number 3"<<endl;
	int rows=5;
	int cols=6;
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
}

void prblm4(){
    SavingsAccount mine(-300);
        
        for(int i=1;i<=10;i++)
	{
            try{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));
            }
            catch (SavingsAccount::InvalidWithdrawl){
                cout << "Withdraw not allowed!" << endl;
            }
        }    
   
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
}

void prblm5(){
    
    Employee Mark("Mark", "Boss", 0);
    try
    {
        Mark.setHourlyRate(215.50);
    }
    catch (Employee::InvalidHourlyRate){
        cout << "Unacceptable Hourly Rate" << endl;
    }
    try
    {
        Mark.setHoursWorked(-3);
	Mark.toString();
    }
    catch (Employee::InvalidHoursWorked){
        cout << "Unacceptable Hours Worked" << endl;
    }
	
	Mark.CalculatePay(Mark.setHourlyRate(20.0),
		Mark.setHoursWorked(25));
	Mark.toString();
 	Mark.CalculatePay(Mark.setHourlyRate(40.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(60.0),
		Mark.setHoursWorked(25));
	Mark.toString();

    Employee Mary("Mary","VP",50.0);
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(40));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(50));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(60));
	Mary.toString();
}

void prblm6(){
    
}