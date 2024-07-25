// include guard
#ifndef __HEADER_H_INCLUDED__

// definition startng
#define ____HEADER_H_INCLUDED__

/*
	Ally Baba
 	Assignment Number: Heaer.h
	File Name:         heaer.h
	Course/Section:    COSC 1337 Section <MW>
	completeed Date    July 2024
	Instructor:        Baab Ally
--------------------------------------------------------

Project Objectives:
header file
*/

// Compiler directives Header
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

// Global
string dashes(100, '-');
string shortDashes(50, '-');
string error = "\tERROR MESSAGE: ";

/*
	name: 	getCharData()
	input: 	parameter(arguments): string
	output: return char
	process: gets and entry char
	objectives: gets char
*/
void errorMessage(string display)
{
	cout << endl;
	cout << "\tERROR MESSAGE: " << display << endl;
	cout << endl;
} // end of getStringData()


/*
	name: 	getCharData()
	input: 	parameter(arguments): string
	output: return char
	process: gets and entry char
	objectives: gets char
*/
char getCharData(string display)
{
	char value;
	
	while (true)
	{
		cout << display;
		cin >> value;
	
		value = toupper(value);
		
		errorMessage("Selection does not exist.");
	}	
} // end of getStringData()

/*
	name: 	getStringData()
	input: 	parameter(arguments): string
	output: return string
	process: gets and entry string
	objectives: gets string
*/
string getStringData(string display)
{
	string value;
	
	cout << display;
	getline(cin, value);
	
	return value;
	
} // end of getStringData()


/*
	name: 	getIntegerData()
	input: 	parameter(arguments): string
	output: return int
	process: gets integer data from users
	objectives: integer entry
*/
int getIntegerData(string prompt)
{
	int value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value))
		{
			errorMessage("Error Message. Non numeric was entered");
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // c;lear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
		if (value >= 0)
		{
			return value;
		}	
		errorMessage("Value must be positive");
	} // end of while (true)
} // end of int getIntegerData()

/*
	name: 	getFloatData()
	input: 	parameter(arguments): string
	output: return float
	process: gets float data from users
	objectives: integer entry
*/
float getFloatData(string display)
{
	float value;
	
	while (true)
	{
		cout << display;
		
		while (!(cin >> value))
		{
			errorMessage("Invalid entry, please enter a number.");
			cin.clear(); 			// clears the cin
			cin.ignore(120, '\n'); // clears the inout upto 120 chars or entered
			cout << display;
		}
	
		if (value >= 0)
		{
			return value;
		}
		errorMessage("Value cannot be negative");
	}
} // end of getFloatData()


/*
	name: 	projectEnd()
	input: 	parameter(arguments): None
	output: return None ... void
	process: displays
	objectives: Displays the end of project
*/
// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #8" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()

/*
	name: 	projectStart()
	input: 	parameter(arguments): None
	output: return None ... void
	process: displays
	objectives: Displays the start of project
*/

// The function will display the start of the project 
void projectStart()
{
	cout << "----------------------------------------------"  << endl;
	cout << "Project #8" << endl;
	cout << "Written by: Ian Campbell" << endl;
	cout << "Objectives" << endl;
	cout << "Write an object oriented program to load employee data from a file." << endl;
	cout << "Then output a file with weekly payroll data from a separate file of hours worked." << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

#endif

