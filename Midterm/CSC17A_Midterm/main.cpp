
/* 
 * File:   main.cpp
 * Author: Catherine
 *
 * Created on October 18, 2020, 11:01 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
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
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl << endl;
}

void prblm1(){
    cout<<"Problem 1"<<endl;
}


void prblm2(){
    cout<<"Problem 2"<<endl;
}


void prblm3(){
    cout<<"Problem 3"<<endl;
}


void prblm4(){
    cout<<"problem 4"<<endl;
}

void prblm5(){
    cout<<"\nproblem 5"<<endl;
    cout << setw(25) << left << "Data Type" << setw(25) << left << "The Largest Factorial";
    cout << setw(25) << left << "The Result" << endl;  
    cout << setw(25) << left << "int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl; 
    cout << setw(25) << left << "unsigned int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;
    cout << setw(25) << left << "signed int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;
    cout << setw(25) << left << "short int" << setw(25) << left << "7" << setw(25) << left << "5040" << endl;
    cout << setw(25) << left << "unsigned short int" << setw(25) << left << "8" << setw(25) << left << "40320" << endl;
    cout << setw(25) << left << "signed short int" << setw(25) << left << "7" << setw(25) << left << "5040" << endl;
    cout << setw(25) << left << "long int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;
    cout << setw(25) << left << "signed long int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;
    cout << setw(25) << left << "unsigned long int" << setw(25) << left << "12" << setw(25) << left << "479001600" << endl;

    cout << setw(25) << left << "unsigned long long int" << setw(25) << left << "20" << setw(25) << left << "2432902008176640000" << endl;
    cout << setw(25) << left << "float" << setw(25) << left << "20" << setw(25) << left << "2432902008176640000" << endl;
    cout << setw(25) << left << "double" << setw(25) << left << "20" << setw(25) << left << "2432902008176640000" << endl;
  
    cout << setw(25) << left << "char" << setw(25) << left << "5" << setw(25) << left << "120" << endl;
    cout << setw(25) << left << "unsigned char" << setw(25) << left << "5" << setw(25) << left << "120" << endl;
    cout << setw(25) << left << "signed char" << setw(25) << left << "5" << setw(25) << left << "120" << endl;
}

void prblm6(){
    cout<<"\nProblem 6"<<endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "Decimal" << setw(20) << left << "Binary" << setw(20) << left << "Octal" << setw(20) << left << "Hexadecimal" << endl;
    cout << setw(20) << left << "2.875" << setw(20) << left << "10.111" << setw(20) << left << "2.7" << setw(20) << left << "2.E" << endl;
    cout << setw(20) << left << ".1796875" << setw(20) << left << ".0010111" << setw(20) << left << ".134" << setw(20) << left << ".2E" << endl;
}

void prblm7(){
    cout<<"problem 7"<<endl;
}