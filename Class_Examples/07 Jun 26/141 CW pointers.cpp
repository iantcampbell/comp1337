/*
	Ally Baba
 	Assignment Number: Class work#125
	File Name:         125CWBasic.cpp
	Course/Section:    COSC 1337 Section <mW>
	completeed Date    June 2024
	Instructor:        Baab Ally
--------------------------------------------------------

Project Objectives:
keep track of student
name, 3 exams scores
	
*/

// Compiler directives Header
#include <iostream>             // for cin, cout, endl
#include <iomanip>				// setw, setprecision, left/right, fixed
#include <cmath>				// sine, cosine, pow, trunc, round... 
#include <stdlib.h> 			// srand, rand
#include <ctime>				// time
#include <fstream>				// file reading/writing/appending
#include <string>				// string manipulation
using namespace std;

struct Employee
{
	string name;
	float wage;
};

// Declare the prototypes
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
string getStringData(string);
char getCharData(string);

void populateEmployee(Employee*, int);
void displayEmployee1(Employee[], int);
void displayEmployee2(Employee*, int);
void displayEmployee3(Employee*, int);

// Global
string dashes(80, '-');

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	int employeeCount;
	employeeCount = getIntegerData("\tEnter how many employee: ");
	cin.ignore();
	
	// dynamicaaly alloctae memory spaces
	Employee *myEmployee; // pointer of a struct
	
	myEmployee = new Employee[employeeCount];  // object variable  PROJECT 6
	
	populateEmployee(myEmployee, employeeCount);
	displayEmployee1(myEmployee, employeeCount);
	displayEmployee2(myEmployee, employeeCount);
	displayEmployee3(myEmployee, employeeCount);
	
	delete [] myEmployee;

	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of mvalue1 = ain()

// 
void displayEmployee3(Employee *myEmployee, int employeeCount)
{
	cout << dashes << endl;
	cout << "\tPointer in parameter. DOT in accessing" << endl;
	for (int ctr = 0; ctr < employeeCount; ctr++)
	{
		cout << "\tName: " << (*myEmployee).name << endl;
		cout << "\tWage: $" << (*myEmployee).wage << endl;
		myEmployee++;
	}
}

// 
void displayEmployee2(Employee *myEmployee, int employeeCount)
{
	cout << dashes << endl;
	cout << "\tPointer in parameter. -> in accessing" << endl;
	for (int ctr = 0; ctr < employeeCount; ctr++)
	{
		cout << "\tName: " << myEmployee->name << endl;
		cout << "\tWage: $" << myEmployee->wage << endl;
		myEmployee++;
	}
}

// 
void displayEmployee1(Employee myEmployee[], int employeeCount)
{
	cout << dashes << endl;
	cout << "\tINDEX in parameter. DOT in accessing" << endl;
	for (int ctr = 0; ctr < employeeCount; ctr++)
	{
		cout << "\tName: " << myEmployee[ctr].name << endl;
		cout << "\tWage: $" << myEmployee[ctr].wage << endl;
	}
}

// * as the parameter. -> arrow notation to access the members
void populateEmployee(Employee *myEmployee, int employeeCount)
{
	for (int ctr = 0; ctr < employeeCount; ctr++)
	{
		myEmployee->name = getStringData("\tEnter name: ");
		myEmployee->wage = getFloatData("\tEnter wage: $" );
		cin.ignore();
		
		myEmployee++;
	}	
}
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
	cout << "\n" << dashes << endl;
	cout << "\tEnd of project" << endl;
	cout << dashes << endl;
	
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
	cout << dashes << endl;
	cout << "\tProject #130" << endl;
	cout << "\tAuthor: Ally Baba" << endl;
	cout << "\tDate: " << endl;
	cout << "\tObjectives: Pointers" << endl;
	cout << dashes << endl;
	
} // end of projectStart()