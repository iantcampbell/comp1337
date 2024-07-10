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

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>
#include <ctime>
#include <cctype> 				// for toupper()
#include <cstdlib> 				// for random numbers
#include <fstream>              // filestream header
#include <cmath>
using namespace std;

struct employeeMasterInfo // weight-cost pair for shipping table
{
	int employeeId;
	char[20] employeeName; 
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
employeeMasterInfo getEmployeeInfo();
int getEmployeeId(string);
string getEmployeeName(string);
float getPayRate(string);
int getEmployeeType(string);

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	// Variable declarations
	
	
	
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
	string employeeName;
	float payRate;
	int type;
	
	employeeId = getIntegerData("\t\tEmployee id: ");
	
	
	
	
	type = getEmployeeType("\t\tType: ");
	
	employeeInfo.employeeId = employeeId;
	employeeInfo.employeeName = employeeName;
	employeeInfo.payRate = payRate;
	employeeInfo.type = type;
}

/*
	name: 
	input:
	output:
	process: 
	objectives: 
*/
void getEmployeeName(string prompt, employeeMasterInfo.employeeName& em)
{
	
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
		type = getIntegerDate(prompt);
		if (type == 0 || type == 1) // confirm type is valid entry (0 or 1)
		{
			return type;
		} // end of valid entry check
		
		cout << "\t\tError Message. Type must be a 1 or a 0"  << endl;
	}
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
		else if (value > 0)
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


