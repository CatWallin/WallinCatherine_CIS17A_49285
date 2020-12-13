/* 
 * File:   Prob3Table.h
 * Author: Catherine Wallin
 * Created on December 12, 2020, 10:24 PM
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

template<class T>
class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(char *input,int r,int c){              //Constructor then Destructor
                    table = new T[rows];
                    for (int i = 0; i < rows; i++){
                        table[i] = new T[cols];
                    }
                    
                    for (int i = 0; i < rows; i++){
                        table[i] = input[i];
                    }
                    rows = r;
                    cols = c;

                    for (int i = 0; i < rows; i++){
                        T sum = 0;
                        rowSum = new T[rows];
                        for (int k = 0; i < cols; k++){
                            rowSum[i] += table[i][k]; 
                        }
                    }

                    for (int i = 0; i < cols; i++){
                        T sum = 0;
                        colSum = new T[cols];
                        for (int k = 0; i < rows; k++){
                            colSum[i] += table[k][i]; 
                        }
                }
                
                for (int i = 0; i < rows; i++){
                    grandTotal += rowSum[i];
                } 
                
                for (int i = 0; i < cols; i++){
                    grandTotal += colSum[i];
                } 
                    
                }
                
                ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};

#endif /* PROB3TABLE_H */

