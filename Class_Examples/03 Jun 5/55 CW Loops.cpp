/*
	Ally Baba
 	Assignment Number: Class work# 02
	File Name:         32CWBasic.cpp
	Course/Section:    COSC 1337 Section <TTH>
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

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	
	// display all baba 10 times.. 0 to 9 or 1 to 10
	
	// Variable decleration
	int counter;
	
	counter = 1;
	
	while (counter <= 10)
	{
		cout << "\tAlly Baba" << endl;
		
		// last statement is to increment the counter
		counter = counter + 1;
	} // end of 	while (counter <= 10)

	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of main()

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
	cout << "\t\t+ ................................. Addition" << endl;
	cout << "\t\t- ................................. Subtraction" << endl;
	cout << "\t\t* ................................. Multiplication" << endl;
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
	
	cout << display;
	cin >> value;
	
	value = toupper(value);
	
	return value;
	
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
	
	cout << display;
	cin >> value;
	
	return value;
	
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
	
	cout << display;
	cin >> value;
	
	return value;
	
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
	cout << "\tProject # 02" << endl;
	cout << "\tAuthor: Ally Baba" << endl;
	cout << "\tDate: " << endl;
	cout << "\tObjectives: Area of rectangle" << endl;
	cout << "--------------------------------------------" << endl;
	
} // end of projectStart()
