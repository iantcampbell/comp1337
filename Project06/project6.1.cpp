/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		6
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

struct Student
{
	string name;
	int examScores[3];
};

// Decleration of prototype 
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
int getStudentCount();
int getExamScore(int);
void populateStudent(Student*, int);

// Global
string dashes(100, '-');

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	// Variable declaration
	int studentCount;
	
	studentCount = getStudentCount();
	
	// dynamicaaly alloctae memory spaces
	Student *myStudent; // pointer of a struct
	
	myStudent = new Student[studentCount];  // object variable  PROJECT 6
	
	populateStudent(myStudent, studentCount);
	
	delete [] myStudent;
	
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
int getStudentCount()
{
	int studentCount;
	cout << dashes << endl;
	studentCount = getIntegerData("\tHow many students: ");
	cout << dashes << endl;
	return studentCount;
}

int getExamScore(int examIndex)
{
	int examScore;
	string prompt = "\tEnter grade for Exam " + to_string(examIndex) + ":";
	while (true)
	{
		examScore = getIntegerData(prompt);
		
		if (examScore <= 110)
		{
			return examScore;
		}
		
		cout << "\t\tError Message. Maximum grade is 110";
	}
}
// * as the parameter. DOT notationa to access the members
void populateStudent(Student *myStudent, int studentCount)
{
	for (int studentIndex = 0; studentIndex < studentCount; studentIndex++)
	{
		myStudent[studentIndex].name = getStringData("\tEnter name: ");
		for (int examIndex = 0; examIndex < 3; examIndex++)
		{
			myStudent[studentIndex].examScores[examIndex] = getExamScore(examIndex);
		}
		
		cin.ignore();
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
			cout << "\t\tError Message. Non numeric is entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
			
		if (value >= 1 && value <= 10)
		{
			return value;	
		} // end of 	if (value >= 0)
			
		cout << "\t\tError Message. ONLY integers between 1 and 10"  << endl;
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
		
		if (value.length() <= 30)
		{
			return value;
		}
		
		cout << "\t\t\tError Message: Maximum name length is 30 characters."  << endl;
	}
	
} // end of int getStringData(string prompt)

// The function will display the start of the project 
void projectStart()
{
	cout << "----------------------------------------------"  << endl;
	cout << "Project #6" << endl;
	cout << "Written by: Ian Campbell" << endl;
	cout << "Objectives" << endl;
	cout << "----------------------------------------------"  << endl;
	cout << "AllyBabaCookingClass" << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #6" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


