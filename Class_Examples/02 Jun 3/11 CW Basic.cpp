/*
	Ally Baba
 	Assignment Number: Class work# 02
	File Name:         02CWBasic.cpp
	Course/Section:    COSC 1337 Section <TTH>
	completeed Date    June 2024
	Instructor:        Baab Ally
--------------------------------------------------------

Project Objectives:
	The project will work with cout statements, declare variables, assignment
*/

// Compiler directives
#include <iostream>             // for cin, cout, endl
#include <iomanip>				// setw, setprecision, left/right, fixed
using namespace std;

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project
	cout << "--------------------------------------------" << endl;
	cout << "\tProject # 02" << endl;
	cout << "\tAuthor: Ally Baba" << endl;
	cout << "\tDate: " << endl;
	cout << "\tObjectives: Learning cout, cin, assignment, calculation" << endl;
	cout << "--------------------------------------------" << endl;  
	
	// Variable decleration
	int valueOne;
	int valueTwo;
	float result;
	
	// Users defined values for variables
	cout << "\tUser entry" << endl;
	cout << "\tEnter value1: ";
	cin >> valueOne;
	cout << "\tEnter value2: ";
	cin >> valueTwo;
	
	// Dividing the numbers
	result = (float) valueOne / valueTwo;
	
	// Display the desired result
	cout << "\n\tResult" << endl;
	cout << "--------------------------------------------" << endl;
	cout << left << setw(20) << "Value 1: " << right << setw(10) << (float) valueOne << endl;
	cout << left << setw(20) << "Value 2: " << right << setw(10) << (float) valueTwo << endl;
	cout << left << setw(20) << "The sum: " << right << setw(10) << result << endl;
	
	
	
	// End of Project
	cout << "\n--------------------------------------------" << endl;
	cout << "\tEnd of project" << endl;
	cout << "--------------------------------------------" << endl;
	
	      
	return 0;

}  // end of main()
