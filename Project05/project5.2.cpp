/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		5
Status: 		WIP
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives

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

// Decleration of prototype 
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
void getEmployeeInfo(employeeMasterInfo&);
int getEmployeeType(string);
int getNumberOfEmployees();

// Global
string dashes(100, '-');

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	// Variable Declarations
	int numberOfEmployees;
	numberOfEmployees = getNumberOfEmployees(); // seeds number of payroll employees and prints header
	employeeMasterInfo employeeMasterFile[numberOfEmployees];
	
	cout << numberOfEmployees << endl;
	
	for (int index = 0; index < numberOfEmployees; index++)
	{
		cout << index << endl;
		getEmployeeInfo(employeeMasterFile[index]);
	}
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main

/*
	name: 
	input:
	output:
	process: 
	objectives: 
*/
void getEmployeeInfo(employeeMasterInfo& employeeInfo)
{
	int employeeId;
	string employeeNameString;
	string employeeName;
	float payRate;
	int type;
	
	employeeInfo.employeeId = getIntegerData("\t\tEmployee id: ");
	employeeInfo.employeeName = getStringData("\t\tEmployee name: ");	
	employeeInfo.payRate = getFloatData("\t\tPay rate: ");
	employeeInfo.type = getEmployeeType("\t\tType: ");
}

/*
	name: 
	input:
	output:
	process: 
	objectives: 
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
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #5" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


