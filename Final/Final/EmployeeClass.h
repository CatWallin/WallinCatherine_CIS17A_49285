
/* 
 * File:   EmployeeClass.h
 * Author: 
 *
 * Created on December 13, 2020, 12:11 AM
 */

#ifndef EMPLOYEECLASS_H
#define EMPLOYEECLASS_H

class Employee
{
    public:
		Employee(char[],char[],float);  //Constructor
		float  CalculatePay(float,int); //Procedure
		float  getGrossPay(float,int);  //Procedure
		float  getNetPay(float);        //Procedure
		void   toString();              //Procedure
		int    setHoursWorked(int);     //Procedure
		float  setHourlyRate(float);    //Procedure
                class  InvalidHoursWorked{};
                class  InvalidHourlyRate{};
	private:
		double Tax(float);      //Utility Procedure
		char   MyName[20];      //Property
		char   JobTitle[20];    //Property
		float  HourlyRate;      //Property
		int    HoursWorked;     //Property
		float  GrossPay;        //Property
		float  NetPay;          //Property
};

#endif /* EMPLOYEECLASS_H */

