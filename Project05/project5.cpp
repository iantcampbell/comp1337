/* 
-------------------------------------------------------------------------
Name:     		Ian Campbell
Date: 			July 6th, 2024
Project #:		5
Status: 		Complete
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives
write a payroll program for AllyBaba Automotive Group.
create and use a struct to hold the general employee information for one employee
Ideally, you should use an array of structs to hold the employee information for all employees
-------------------------------------------------------------------------
*/

#include <iostream>             // for cin, cout, endl
#include <iomanip>				// setw, setprecision, left/right, fixed
#include <cmath>				// sine, cosine, pow, trunc, round... 
#include <stdlib.h> 			// srand, rand
#include <ctime>				// time
#include <fstream>				// file reading/writing/appending
#include <string>				// string manipulation
#include <cstring>
#include <limits>
using namespace std;

struct employeeMasterInfo // weight-cost pair for shipping table
{
	int employeeId;
	string employeeName; 
	float payRate; // hourly
	int type;
};

struct payrollInfo
{
	float grossPay;
	float tax;
	float netPay;
};

// Decleration of prototype 
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
void getEmployeeInfo(employeeMasterInfo&, int);
int getEmployeeType(string);
int getNumberOfEmployees();
void calculatePay(employeeMasterInfo, payrollInfo&);
void summary(int);
float getHoursWorked(string);

// Global
string dashes(100, '-');

int main()
{
	cout << fixed << setprecision(2);
	
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	// Variable Declarations
	int numberOfEmployees;
	numberOfEmployees = getNumberOfEmployees(); // seeds number of payroll employees and prints header
	employeeMasterInfo employeeMasterFile[numberOfEmployees];
	payrollInfo employeePayrollFile[numberOfEmployees];
	float totalGrossPay = 0;
	float totalNetPay = 0;
	
	for (int index = 0; index < numberOfEmployees; index++) // build employeeMasterFile
	{
		getEmployeeInfo(employeeMasterFile[index], index);
	}
		cout << endl;
		cout << "\tEnter timecard information for each employee:" << endl;
			
	for (int index = 0; index < numberOfEmployees; index++) // calculate Payroll
	{

		calculatePay(employeeMasterFile[index], employeePayrollFile[index]);
	}
	
	summary(numberOfEmployees);
	for (int index = 0; index < numberOfEmployees; index++) // output Payroll summary for each employee
	{
		cout << left << setw(5) << employeeMasterFile[index].employeeId << setw(20) << employeeMasterFile[index].employeeName << setw(8) << employeePayrollFile[index].grossPay << setw(8) << employeePayrollFile[index].tax << setw(8) << employeePayrollFile[index].netPay << endl; 
		totalGrossPay += employeePayrollFile[index].grossPay;
		totalNetPay += employeePayrollFile[index].netPay;
	}
	cout << "Total Gross Pay: $" << totalGrossPay << endl;
	cout << "Total Net Pay: $" << totalNetPay << endl;
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main

/*
	name: getEmployeeInfo()
	input: employeeMasterInfo&
	output:
	process: gets and updates employee info on master file
	objectives: get info on employee for master file
*/
void getEmployeeInfo(employeeMasterInfo& employeeInfo, int employeeCount)
{
	int employeeId;
	string employeeNameString;
	string employeeName;
	float payRate;
	int type;
	
	employeeCount ++;
	cout << "\tEnter information for employee #" << employeeCount << endl;
	employeeInfo.employeeId = getIntegerData("\t\tEmployee id: ");
	employeeInfo.employeeName = getStringData("\t\tEmployee name: ");	
	employeeInfo.payRate = getFloatData("\t\tPay rate: ");
	employeeInfo.type = getEmployeeType("\t\tType: ");
	cout << endl;
}

/*
	name: getEmployeeType
	input: string
	output: int 0 or 1
	process: gets int, confirms 0 or 1
	objectives: get employee type in form of int
*/
int getEmployeeType(string prompt)
{
	int type;
	
	while (true)
	{
		type = getIntegerData(prompt);
		if (type == 0 || type == 1) // confirm type is valid entry (0 or 1)
		{
			return type;
		} // end of valid entry check
		
		cout << "\t\tError Message. Type must be a 1 or a 0"  << endl;
	}
}

/*
	name: calculatePay
	input: employeeMasterInfo, payrollInfo&
	output: 
	process: calculates pay from hours worked and employee master file information
	objectives: calculate employee pay
*/
void calculatePay(employeeMasterInfo employeeInfo, payrollInfo& employeePay)
{
	float hoursWorked;
	float gross;
	float tax;
	float net;
	
	hoursWorked = getHoursWorked(employeeInfo.employeeName);
	
	if (employeeInfo.type == 0) // union
	{
		if (hoursWorked <= 40) // no overtime
		{
			gross = hoursWorked * employeeInfo.payRate;
		}
		else // overtime
		{
			gross = (40 * employeeInfo.payRate) + ((hoursWorked - 40) * (employeeInfo.payRate * 1.5));
		}
	}
	else // management
	{
		gross = hoursWorked * employeeInfo.payRate;
	}
	
	tax = gross * 0.15;
	net = gross - tax;
	
	employeePay.grossPay = gross;
	employeePay.tax = tax;
	employeePay.netPay = net;
}

/*
	name: getNumberOfEmployees
	input:
	output: int
	process: gets number of employees in form of int
	objectives: get number of employees
*/
int getNumberOfEmployees()
{
	// Program header and get number of employees
	int numberOfEmployees;
	cout << "AllyBaba Automotive Group" << endl;
	cout << dashes << endl;
	numberOfEmployees = getIntegerData("\tNumber of payrolls to be processed: ");
	cout << dashes << endl;	
	return numberOfEmployees;
}

/*
	name: getHoursWorked
	input: string
	output: float
	process: gets hours worked in float
	objectives: get hours worked
*/
float getHoursWorked(string employeeName)
{
	float hoursWorked;
	string prompt = "\t\tHours worked for " + employeeName + ": ";
	
	while (true)
	{
		hoursWorked = getFloatData(prompt);
		if (hoursWorked < 168)
		{
			return hoursWorked;
		}
		
		cout << "There are only 168 hours in a week" << endl;
	}
}

/*
	name: summary
	input: int numberOfEmployees
	output: 
	process: prints summary header
	objectives: print summary header
*/
void summary(int numberOfEmployees)
{
	cout << "Summary: Payroll Report" << endl;
	cout << dashes << endl;
	cout << "Number of Employee processed: " << numberOfEmployees << endl;
	cout << dashes << endl;	
	cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(8) << "Gross Pay" << setw(8) << "Tax" << setw(8) << "Net Pay" << endl;
	cout << dashes << endl;
}
// This function will get a char value from the user
char getCharData(string prompt)
{
	char value;
	
	while (true)
	{
			cout << prompt;
			cin >> value;
	
			value = toupper(value);
			
			return value;	
			
			cout << "\t\tError Message. Selection does not exist"  << endl;
	} // end of while(true)

} // end of int getFloatData()

// This function will get a float value from the user
float getFloatData(string prompt)
{
	float value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value))
		{
			cout << "\t\t\tError Message. Non numeric is entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
			
		if (value > 0)
		{
			return value;	
		} // end of 	if (value >= 0)
			
		cout << "\t\t\tError Message. Value must be positive."  << endl;
	} // end of while (true)
} // end of int getFloatData()

// This function will get an integer value from the user
int getIntegerData(string prompt)
{
	int value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value))
		{
			cout << "\t\t\tError Message. Non numeric was entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // c;lear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
		
		if(cin.fail()) // confirm integer entry
		{
			cout << "\t\t\tError Message. Non integer was entered"  << endl;
			cin.clear();
			cin.ignore(120, '\n');
			cout << prompt;
		}
		else if (value >= 0)
		{
			return value;
		}	
		
		cout << "\t\t\tError Message: Please enter a positive number"  << endl;
			
	} // end of while (true)
} // end of int getIntegerData()

// This function will return a string data entered by users
string getStringData(string prompt)
{
	string value;
		
	while (true)
	{
		cout << prompt;
		cin.ignore();
		getline(cin, value, '\n'); // accepts spaces in the entry
		
		if (value.length() <= 20)
		{
			return value;
		}
		
		cin.clear();
		cout << "\t\t\tError Message: Maximum name length is 20 characters."  << endl;
	}
	
} // end of int getStringData(string prompt)

// The function will display the start of the project 
void projectStart()
{
	cout << "----------------------------------------------"  << endl;
	cout << "Project #5" << endl;
	cout << "Written by: Ally baba" << endl;
	cout << "Objectives" << endl;
	cout << "AllyBaba Automotive Group Payroll Program" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #5" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


