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

using namespace std;

int main()	
{
	// Start of Project
	cout << "--------------------------------------------" << endl;
	cout << "\tProject # 02" << endl;
	cout << "\tAuthor: Ally Baba" << endl;
	cout << "\tDate: " << endl;
	cout << "\tObjectives: Learning cout" << endl;
	cout << "--------------------------------------------" << endl;  
	
	// Variable decleration
	int valueOne;
	int valueTwo;
	int result;
	
	// Assignment to variables
	valueOne = 110;
	valueTwo = 100;
	
	// Adding the integers
	result = valueOne + valueTwo;
	
	// Display the desired result
	cout << "\n\tResult" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "\tThe sum of " << valueOne << " and " << valueTwo << " is: " << result << endl;
	
	
	
	// End of Project
	cout << "\n--------------------------------------------" << endl;
	cout << "\tEnd of project" << endl;
	cout << "--------------------------------------------" << endl;
	
	      
	return 0;

}  // end of main()