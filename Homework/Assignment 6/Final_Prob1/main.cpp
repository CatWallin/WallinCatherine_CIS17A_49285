
/* 
 * File:   main.cpp
 * Author: Catherine Wallin
 * Created on December 12, 2020, 7:25 PM
 * Problem 1: Random Sequence 
 */

#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {

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
    
    return 0;
}

