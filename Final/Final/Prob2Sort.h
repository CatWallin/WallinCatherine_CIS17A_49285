
/* 
 * File:   Prob2Sort.h
 * Author: Catherine Wallin
 * Created on December 12, 2020, 10:01 PM
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

using namespace std;

template<class T>
class Prob2Sort
{
	private:
		int *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort(){index=NULL;};                   //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		T * sortArray(const T*,int,bool);           //Sorts a single column array
		T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 

#endif /* PROB2SORT_H */

