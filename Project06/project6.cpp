/* 
-------------------------------------------------------------------------
Name:     		Ian Campbell
Date: 			July 7th, 2024
Project #:		6
Status: 		Complete
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives
Input student name and test grades
Validate data
Store in pointer array
output summary
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

struct Student // weight-cost pair for shipping table
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
void populateStudent(Student*, int);
void sortGrades(Student*, int);
void displayStudent(Student*, int);
float getStudentAverage(int, int, int);
char getLetterGrade(float, int&, int&, int&, int&, int&);


// Global
string dashes(100, '-');

int main()
{
	cout << fixed << setprecision(2);
	
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	int studentCount;
	studentCount = getStudentCount();
	
	// dynamicaaly alloctae memory spaces
	Student *myStudent; // pointer of a struct
	
	myStudent = new Student[studentCount];
	
	populateStudent(myStudent, studentCount);
	sortGrades(myStudent, studentCount);
	displayStudent(myStudent, studentCount);
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main

/*
	name: getStudentCount
	input: 
	output: int, count of students from user
	process: get count of students greater than 0, return as int
	objectives: get count of students
*/
int getStudentCount()
{
	int studentCount;
	cout << "AllyBaba Cooking Class" << endl;
	cout << dashes << endl;
	studentCount = getIntegerData("\tHow many students: ");
	cout << dashes << endl;
	cout << endl;
	cin.ignore();
	return studentCount;
}

/*
	name: populateStudent
	input: Student *myStudent, int studentCount
	output:
	process: gets info from user for student, saves to array
	objectives: get and save info for student
*/
void populateStudent(Student *myStudent, int studentCount)
{
	for (int ctr = 0; ctr < studentCount; ctr++)
	{
		cout << "Student #" << to_string(ctr+1) << endl;
		cout << dashes << endl;
		myStudent->name = getStringData("\tEnter the name: ");
		myStudent->examScores[0] = getIntegerData("\tEnter the grade for Exam 1: ");
		myStudent->examScores[1] = getIntegerData("\tEnter the grade for Exam 2: ");
		myStudent->examScores[2] = getIntegerData("\tEnter the grade for Exam 3: ");
		cout << endl;
		cin.ignore();

		myStudent++;
	}	
}

/*
	name: sortGrades
	input: Student *myStudent, int studentCount
	output: 
	process: sort the 3 exam scores inside the array
	objectives: sort the 3 exam scores
*/
void sortGrades(Student *myStudent, int studentCount)
{
	for (int ctr = 0; ctr < studentCount; ctr++)
	{
		if (myStudent->examScores[0] > myStudent->examScores[2]) // confirm lower of exam 1 and 2 is in first
		{
			swap(myStudent->examScores[0], myStudent->examScores[2]);
		}
		if (myStudent->examScores[0] > myStudent->examScores[1]) // confirm lowest score is in first
		{
			swap(myStudent->examScores[0], myStudent->examScores[1]);
		}
		if (myStudent->examScores[1] > myStudent->examScores[2]) // confirm highest score is in last
		{
			swap(myStudent->examScores[1], myStudent->examScores[2]);
		}
		
		myStudent++;
	}
}

/*
	name: displayStudent
	input: (Student *myStudent, int studentCount
	output:
	process: displays summary data for students
	objectives: 
*/
void displayStudent(Student *myStudent, int studentCount)
{
	char letterGrade;
	float studentAverage;
	float classTotal;
	float classAverage;
	int aCounter = 0;
	int bCounter = 0;
	int cCounter = 0;
	int dCounter = 0;
	int fCounter = 0;
	string studentScores;
	
	cout << endl;
	cout << endl;
	cout << dashes << endl;
	cout << "Semester Summary: AllyBaba Cooking Class" << endl;
	cout << dashes << endl;
	cout << left << setw(30) << "\tName" << setw(20)  << "Scores" << setw(12) << "Letter Grade" << endl;
	cout << dashes << endl;
	
	for (int ctr = 0; ctr < studentCount; ctr++) // each students score output in table
	{
		
		studentAverage = getStudentAverage(myStudent->examScores[0], myStudent->examScores[1], myStudent->examScores[2]);
		classTotal += studentAverage;
		letterGrade = getLetterGrade(studentAverage, aCounter, bCounter, cCounter, dCounter, fCounter);
		studentScores = to_string(myStudent->examScores[0]) + ", " + to_string(myStudent->examScores[1]) + ", " + to_string(myStudent->examScores[2]);
		cout << left << "\t" << setw(30) << myStudent -> name << setw(20) << studentScores << setw(12) << letterGrade << endl;
		
		myStudent++;
	} // end loop for student scores table
	
	classAverage = classTotal / studentCount;
	
	cout << endl; // summary data
	cout << "Number of students: " << studentCount << endl;
	cout << "Class Average: " << classAverage << endl;
	cout << "Number of A's: " << aCounter << endl;
	cout << "Number of B's: " << bCounter << endl;
	cout << "Number of C's: " << cCounter << endl;
	cout << "Number of D's: " << dCounter << endl;
	cout << "Number of F's: " << fCounter << endl;
}

/*
	name: getStudentAverage
	input: int examOne, int examTwo, int examThree
	output: float
	process: averages exam scores, returns as float
	objectives: average exam scores
*/
float getStudentAverage(int examOne, int examTwo, int examThree)
{
	float total;
	float average;
	
	total = examOne+examTwo+examThree;
	
	average = total / 3;
	
	return average;
}

/*
	name: getLetterGrade
	input: float studentAverage, int& aCounter, int& bCounter, int& cCounter, int& dCounter, int& fCounter
	output: char letter grade
	process: compare average to grade ranges, return letter grade, update counter
	objectives: convert average to letter grade
*/
char getLetterGrade(float studentAverage, int& aCounter, int& bCounter, int& cCounter, int& dCounter, int& fCounter)
{
	if (studentAverage >= 90)
	{
		aCounter++;
		return 'A';		
	}
	else if (studentAverage >= 80)
	{
		bCounter++;
		return 'B';
	
	}
	else if (studentAverage >= 70)
	{
		cCounter++;
		return 'C';
	}
	else if (studentAverage >= 60)
	{
		dCounter++;
		return 'D';
	}
	else
	{
		fCounter++;
		return 'F';
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
		else if (value >= 0 && value <= 110)
		{
			return value;
		}	
		
		cout << "\t\t\tError Message: Please enter a score between 0 and 110"  << endl;
			
	} // end of while (true)
} // end of int getIntegerData()

// This function will return a string data entered by users
string getStringData(string prompt)
{
	string value;
		
	while (true)
	{
		cout << prompt;
		cin.clear();
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
	cout << "AllyBaba Cooking Class Exam Scores" << endl;;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #6" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


