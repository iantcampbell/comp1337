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
	string name;
	
	// user's entry of var
	cout << "\tEnter your name: ";
	cin >> name;  // accepts data until a blank
	
	// Display the desired result
	cout << "\n\tResult" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "\tName is: " << name << endl;
	
	// End of Project
	cout << "\n--------------------------------------------" << endl;
	cout << "\tEnd of project" << endl;
	cout << "--------------------------------------------" << endl;
	
	      
	return 0;

}  // end of main()
