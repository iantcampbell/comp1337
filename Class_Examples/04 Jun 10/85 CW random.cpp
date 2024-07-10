/*
	Ally Baba
 	Assignment Number: Class work# 68
	File Name:         68CWBasic.cpp
	Course/Section:    COSC 1337 Section <mW>
	completeed Date    June 2024
	Instructor:        Baab Ally
--------------------------------------------------------

Project Objectives:
	The project will display the area of rectangle
	user will enter length and width (int)
*/

// Compiler directives
#include <iostream>             // for cin, cout, endl
#include <iomanip>				// setw, setprecision, left/right, fixed
#include <cmath>				// sine, cosine, pow, trunc, round... 
#include <stdlib.h> 			// srand, rand
#include <ctime>				// time
#include <fstream>				// file reading/writing/appending
using namespace std;

// Declare the prototypes
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
string getStringData(string);
char getCharData(string);

void displayResults(string, float, float, float, float);
void mainMenu();
void displayBalance(float, float);

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	ifstream readFile;
	int id;
	float wage;
	float hours;
	
	readFile.open("payroll.txt");
	
	if (!readFile)
	{
		cout << "\t\tERR message! No employee.txt file" << endl;
	}
	else
	{
		while (!readFile.eof())
		{
			readFile >> id;
			readFile >> wage;
			readFile >> hours;
						
			if (readFile.eof())
			{
				break;
			}
			
			cout << "Id: "  << id << " wage: $" << wage << " hours: "<< hours << endl;
			

		}
		readFile.close();
	}
	
	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of main()

/*
	name: 	display balance()
	input: 	parameter(arguments): 
	output: 
	process: display
	objectives: display
*/
void displayBalance(float balance, float serviceCharge)
{
	cout << "------------------------" << endl;
	cout << "\tTransaction Balance" << endl;
	cout << "------------------------" << endl;
	cout << "\tBalance: $" << balance << endl;
	cout << "\tAccrued service Charge: $" << serviceCharge << endl;
	cout << "------------------------" << endl;
}
/*
	name: 	mainMenu()
	input: 	parameter(arguments): None
	output: 
	process: display
	objectives: display
*/
void mainMenu()
{
	cout << "\n--------------------------------------------" << endl;
	cout << "\tAllyBaba Quiz" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "\t\tD ................................. deposit" << endl;
	cout << "\t\tW ................................. withdraw" << endl;
	cout << "\t\tE ................................. Exit" << endl;
	cout << "--------------------------------------------" << endl;
		
} // end of mainMenu()

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
		cin >> value;
	
		if (value > 0)
		{
			return value;	
		}
		cout << "\t\tERR message! Enter values more than 0" << endl;
		
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
	
		if (value > 0)
		{
			return value;
		}
		cout << "\t\tERR message! Enter values more than 0" << endl;
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
	cout << "\tProject # 76" << endl;
	cout << "\tAuthor: Ally Baba" << endl;
	cout << "\tDate: " << endl;
	cout << "\tObjectives: Files read/write/append" << endl;
	cout << "--------------------------------------------" << endl;
	
} // end of projectStart()
