/*
	Ally Baba
 	Assignment Number: Class work# 68
	File Name:         108CWBasic.cpp
	Course/Section:    COSC 1337 Section <mW>
	completeed Date    June 2024
	Instructor:        Baab Ally
--------------------------------------------------------

Project Objectives:
	Keep track of 7 days of temperature  for 3 weeks
*/

// Compiler directives
#include <iostream>             // for cin, cout, endl
#include <iomanip>				// setw, setprecision, left/right, fixed
#include <cmath>				// sine, cosine, pow, trunc, round... 
#include <stdlib.h> 			// srand, rand
#include <ctime>				// time
#include <fstream>				// file reading/writing/appending
#include <string>				// string manipulation
using namespace std;

// form... template... prototype... struct
// record 3 exam scorew for a student (float), average, name 
// create the struct
// populate and display the values

struct Student
{
	// data member;
	string name;
	float examScore[3];
	
	// derived data memeber
	float examAverage;
	
}; // end of struct

// Declare the prototypes
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
string getStringData(string);
char getCharData(string);

Student populateStudent();
void displayStudent(Student);
void findExamAverage(Student &);

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	
	// creating an object a variable
	
	Student myStudent;
	
	myStudent = populateStudent();
	
	findExamAverage(myStudent);
	
	displayStudent(myStudent);
	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of main()

/*
	name: 	findExamAverage()
	input: 	parameter(arguments): string
	output: return char
	process: gets and entry char
	objectives: gets char
*/
void findExamAverage(Student & myStudent)
{
	float sumExam;
	
	sumExam = 0;
	
	for (int ctr = 0; ctr < 3; ctr++)
	{
		sumExam = sumExam + myStudent.examScore[ctr];
	}
	
	myStudent.examAverage = sumExam / 3;
} // end of void findExamAverage(Student & myStudent)

/*
	name: 	displayStudent()
	input: 	parameter(arguments): string
	output: return char
	process: gets and entry char
	objectives: gets char
*/
void displayStudent(Student myStudent)
{
	string message;
	
	cout << "\n\n\tName: " << myStudent.name << endl;
	
	for (int ctr = 0; ctr < 3; ctr++)
	{
		message = "\tScore for exam " + to_string(ctr + 1) + ": ";
		cout << message << myStudent.examScore[ctr] << endl;	
	}
	cout << "\tAverage: " << myStudent.examAverage << endl;
}

/*
	name: 	populateStudent()
	input: 	parameter(arguments): string
	output: return char
	process: gets and entry char
	objectives: gets char
*/
Student populateStudent()
{
	Student tempStudent;
	string message;
	
	tempStudent.name = getStringData("\tEnter name: ");
	
	for (int ctr = 0; ctr < 3; ctr++)
	{
		message = "\tEnter score for exam " + to_string(ctr + 1) + ": ";
		tempStudent.examScore[ctr] = getFloatData(message);	
	}

	
	return tempStudent;	
} // end of void populateEmployee()


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
	
		// how to limit data entry
		if (value == 'D' || value == 'W' || value == 'E')
		{
			return value;	
		}
		cout << "\t\tERR message! Enter D, W, E" << endl;
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
int getIntegerData(string display)
{
	int value;
	
	while (true)
	{
		cout << display;
		
		while (!(cin >> value))
		{
			cout << "\t\tERR message! Enter numbers ONLY" << endl;
			cin.clear(); 			// clears the cin
			cin.ignore(120, '\n'); // clears the inout upto 120 chars or entered
			cout << display;
		}
		
		// input constraint
		if (value > 0 && value <= 10)
		{
			return value;	
		}
		cout << "\t\tERR message! Enter values between 1 and 10" << endl;
		
	} // end of while (true)

	
} // end of getIntegerData()

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
			cout << "\t\tERR message! Enter numbers ONLY" << endl;
			cin.clear(); 			// clears the cin
			cin.ignore(120, '\n'); // clears the inout upto 120 chars or entered
			cout << display;
		}
	
		if (value > 0 && value <= 110)
		{
			return value;
		}
		cout << "\t\tERR message! Enter values between 1 and 10" << endl;
	}
} // end of getFloatData()

/*
	name: 	displayResult()
	input: 	parameter(arguments): examScoreOne, examScoreTwo, examScoreThree, averageExamScore
	output: return None ... void
	process: displays the results
	objectives: Displays the rsults of the avreage
*/
void displayResults(string name, float examScoreOne, float examScoreTwo, float examScoreThree, float averageExamScore)
{
	cout << "\n\tResult" << endl;
    cout << "--------------------------" << endl;
    cout << "\tName: " << name << endl;
    cout << "\tExam one is " << examScoreOne << endl;
    cout << "\tExam two is " << examScoreTwo << endl;
    cout << "\tExam three is " << examScoreThree << endl;
    cout << "\tThe average exam score is " << averageExamScore << endl;
    
} // end of displayResults()

/*
	name: 	projectEnd()
	input: 	parameter(arguments): None
	output: return None ... void
	process: displays
	objectives: Displays the end of project
*/
void projectEnd()
{
	cout << "\n--------------------------------------------" << endl;
	cout << "\tEnd of project" << endl;
	cout << "--------------------------------------------" << endl;
	
} // end of projectEnd()

/*
	name: 	projectStart()
	input: 	parameter(arguments): None
	output: return None ... void
	process: displays
	objectives: Displays the start of project
*/

void projectStart()
{
	cout << "--------------------------------------------" << endl;
	cout << "\tProject # 108" << endl;
	cout << "\tAuthor: Ally Baba" << endl;
	cout << "\tDate: " << endl;
	cout << "\tObjectives: Arrays" << endl;
	cout << "--------------------------------------------" << endl;
	
} // end of projectStart()