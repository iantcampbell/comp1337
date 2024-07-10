/*
	Tom Gibbons
 	Assignment Number: Class work # 145
	File Name:         145 CW Data Processing.cpp
	Course/Section:    COSC 1337 (MW)
	completeed Date    July 2024
	Instructor:        Ally Baba
--------------------------------------------------------

Project Objectives:

Populate Employees with a struct containing derived members
Take user input for struct attributes 
Take hours worked for each employee 
Calculate derived members based on hours worked
Display results to user

*/

// Compiler directives
#include <iostream>             // for cin, cout, endl
#include <iomanip>				// setw, setprecision, left/right. fixed
#include <cmath>				// sine, cosine, pow, trunc, round
#include <stdlib.h>				// srand, rand
#include <ctime>				// time
#include <fstream>				// file reading/writing/appending
#include <string>				// string manipulation
using namespace std;

struct Employee
{
	int id; //Employee ID
	string name; // Employee name
	float wage; // wage (greater than 0)
	int dependents; // must be whole number greater than or equal to 0
	int type; // 0 for salaried (no OT), 1 for hourly, (1.5 OT more than 40)
	
	//derived member
	float grossPay; // salary = hoursworked * wage; check for OT if type == 1
	float insurance; // 100 per dependent
	float tax; // 15 percent of grossPay
	float netPay; // grossPay - insurance - tax
};




// declare the prototype
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
string getStringData(string);
char getCharData(string);

// lesson prototypes
void populateEmployee(Employee[], int);
void displayEmployees(Employee[], int);
void calculatePayRoll(Employee[], int);
float calculateOverTime(float, float);
int getTypeData(string);

// Global
string dashes(110, '-');

int main()	
{	
	cout << fixed << setprecision(2);
	
	// Start of Project
	projectStart();
	// Calling the function
	int employeeCount;
	employeeCount = getIntegerData("Enter the number of employees in the company: ");
	
	Employee * myEmployee;
	myEmployee = new Employee[employeeCount];
	
	populateEmployee(myEmployee, employeeCount);
	calculatePayRoll(myEmployee, employeeCount);
	displayEmployees(myEmployee, employeeCount);
	
	delete []myEmployee;
	// End of Project
	projectEnd();
	
	return 0;

}  // end of main()

/*
	name: populateEmployee(myEmployee, employeeCount);
	input: parameter(arguments): struct Employee, int employeeCount
	output: return None ... void 
	process: populates employee data
	objectives: 
*/
void populateEmployee(Employee myEmployee[], int employeeCount)
{
	for (int ctr = 0; ctr < employeeCount; ctr++)
	{
		myEmployee[ctr].id = getIntegerData("Enter Employee ID: ");
		cin.ignore();
		myEmployee[ctr].name = getStringData("Enter Employee Name: ");
		myEmployee[ctr].wage = getFloatData("Enter Wage (more than 0): $");
		myEmployee[ctr].dependents = getIntegerData("Enter # of dependents (0 or greater): ");
		myEmployee[ctr].type = getTypeData("Enter Type (0 for salaried, 1 for hourly): ");
		cout << dashes << endl;
	}
} // end of populateEmployee

/*
	name: displayEmployees()
	input: parameter(arguments): struct Employee, int employeeCount
	output: return None ... void 
	process: displays Employee data
	objectives: 
*/
void displayEmployees(Employee myEmployee[], int employeeCount)
{
	cout << "\n" << dashes << endl;
	cout << setw(10) << left << "ID" << setw(30) << left << "Name" << setw(10) << "Wage  " << setw(10) << "Dependents" << setw(10) << "Type";
	cout  << setw(10) << "Gross Pay" << setw(10) << "Insurance" << setw(10) << "Tax" << setw(10) << "Net Pay" << endl;
	cout << dashes << endl; 
	for (int ctr = 0; ctr < employeeCount; ctr++)
	{
		cout << setw(10) << left << myEmployee[ctr].id;
		cout << setw(30) << left << myEmployee[ctr].name;
		cout << setw(10) << myEmployee[ctr].wage;
		cout << setw(10) << myEmployee[ctr].dependents;
		cout << setw(10) << myEmployee[ctr].type;
		cout << setw(10) << myEmployee[ctr].grossPay << " $";
		cout << setw(10) << myEmployee[ctr].insurance;
		cout << setw(10) << myEmployee[ctr].tax;
		cout << setw(10) << myEmployee[ctr].netPay << " $" << endl;
	}

} // end of displayEmployees()

/*
	name: calculatePayRoll()
	input: parameter(arguments): struct Employee, int employeeCount
	output: return None ... void 
	process: calculates Payroll data for the derived struct member
	objectives: attributes for insurance, tax, net pay
*/
void calculatePayRoll(Employee myEmployee[], int employeeCount)
{
	float hoursWorked;
	for (int ctr = 0; ctr < employeeCount; ctr++)
	{
		cout << dashes << endl;
		cout << "Employee ID " << myEmployee[ctr].id << "  " << myEmployee[ctr].name << endl;
		hoursWorked = getFloatData("Enter # of hours worked: ");
		
		if (myEmployee[ctr].type == 0)
		{
			myEmployee[ctr].grossPay = myEmployee[ctr].wage * hoursWorked;
		}
		else
		{
			myEmployee[ctr].grossPay = calculateOverTime(hoursWorked, myEmployee[ctr].wage);
		}
	
		myEmployee[ctr].insurance = 100 * myEmployee[ctr].dependents;
		myEmployee[ctr].tax = myEmployee[ctr].grossPay * .15;
		myEmployee[ctr].netPay = myEmployee[ctr].grossPay - myEmployee[ctr].insurance - myEmployee[ctr].tax;
	}
} // end of calculatePayRoll

/*
	name: calculateOverTime()
	input: parameter(arguments): float hoursWorked, float wage
	output: return float overTime
	process: displays Employee data
	objectives: 
*/

float calculateOverTime(float hoursWorked, float wage)
{
	float overTime;
	if (hoursWorked <= 40)
	{
		return hoursWorked * wage;
	}
	else
	{
		overTime = hoursWorked - 40;
		return 40 * wage  + overTime * wage * 1.5; 
	}
} // end of calculateOverTime

/*
	name: projectEnd()
	input: parameter(arguments): None
	output: return None ... void 
	process: displays
	objectives: Displays the end of project
*/
void projectEnd()
{
	cout << "\n---------------------------" << endl;
	cout << "\tEnd of Project" << endl;
	cout << "---------------------------" << endl;
} // end of projectEnd()

/*
	name: projectStart()
	input: parameter(arguments): None
	output: return None ... void 
	process: displays
	objectives: Displays the start of project
*/
void projectStart()
{
	cout << "---------------------------" << endl;
	cout << "\tProject # 142" << endl;
	cout << "\tAuthor: Tom  Gibbons" << endl;
	cout << "\tDate: July 2024" << endl;
	cout << "\tObjectives: Data Processing" << endl;
	cout << "---------------------------" << endl;
} // end of projectStart()

/*
	name: getTypeData()
	input: parameter(arguments): string
	output: return int limited to 0 or 1
	process: gets integer data from users
	objectives: integer entry
*/
int getTypeData(string display)
{
	int value;
	
	while (true)
	{
		cout << display;
		
		while (!(cin >> value))
		{
			cout << "\t\tERR message! Enter numbers ONLY" << endl;
			cin.clear(); // clears the buffer
			cin.ignore(120, '\n'); // clears the input up to 120 chars or entered
			cout << display;
		}
		
		// input constraint
		
		if (value == 0 || value == 1)
		{
			return value;
		}
		cout << "\t\tERR message! Unacceptable Input." << endl;
	} 
	
	
} // end of getTypeData()
/*
	name: getIntegerData()
	input: parameter(arguments): string
	output: return None ... int
	process: gets integer data from users
	objectives: integer entry
*/
int getIntegerData(string display)
{
	int value;
	
	while (true)
	{
		cout << display;
		
		while (!(cin >> value))
		{
			cout << "\t\tERR message! Enter numbers ONLY" << endl;
			cin.clear(); // clears the buffer
			cin.ignore(120, '\n'); // clears the input up to 120 chars or entered
			cout << display;
		}
		
		// input constraint
		
		if (value >= 0)
		{
			return value;
		}
		cout << "\t\tERR message! Enter values greater or equal to zero" << endl;
	}
	
	
} // end of displayResult()

/*
	name: getAverageExamScore()
	input: parameter(arguments):
	output: return float
	process: adds the exams and divide by 3
	objectives: finding average
*/

float getFloatData(string display)
{
	float value;
	
	while (true)
	{
		cout << display;
		while (!(cin >> value))
		{
			cout << "\t\tERR message! Enter numbers ONLY" << endl;
			cin.clear(); // clears the buffer
			cin.ignore(120, '\n'); // clears the input up to 120 chars or entered
			cout << display;
		}
		
		if (value > 0)
		{
			return value;
		}
		cout << "\t\tERR message! Enter values more than 0" << endl;
	}
	
	

	return value;
}
/*
	name: getStringData()
	input: parameter(arguments): string
	output: return string
	process: gets an entry string
	objectives: gets string
*/
string getStringData(string display)
{
	string value;
	
	cout << display;
	getline(cin, value);
	return value;
}
/*
	name: geCharData()
	input: parameter(arguments): string
	output: return char
	process: gets an entry string
	objectives: gets string
*/
char getCharData(string display)
{
	char value;
	
	while (true)
	{
		cout << display;
		cin >> value;
	
		value = toupper(value);
		
		// how to limit data entry
		if (value == '+' || value == '-' || value == '*' || value == 'E')
		{
			return value;
		}
		cout << "\t\tERR message! Enter +, -, *, E" << endl;
	}
	
	
	
}
