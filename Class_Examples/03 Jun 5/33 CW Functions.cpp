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

void findAverageExamScore(float, float, float, float&);
void displayResults(string, float, float, float, float);

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	
	// Variable decleration
    float examScoreOne;
    float examScoreTwo;
    float examScoreThree;
    float averageExamScore;
    string name;
    
    // user entry of var
    name = getStringData("\tEnter your name: ");
    examScoreOne = getFloatData("\tEnter the first exam score: ");
    examScoreTwo = getFloatData("\tEnter the second exam score: ");
    examScoreThree = getFloatData("\tEnter the third exam score: ");
    
    // get average
    findAverageExamScore(examScoreOne, examScoreTwo, examScoreThree, averageExamScore);
    
    //Display the desired result
    displayResults(name, examScoreOne, examScoreTwo, examScoreThree, averageExamScore);
	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of main()


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
	name: 	findAverageExamScore()
	input: 	parameter(arguments): examScoreOne, examScoreTwo, examScoreThree
	output: return float
	process: adds the exams and divide by 3
	objectives: findin average
*/
void findAverageExamScore(float examScoreOne, float examScoreTwo, float examScoreThree, float &averageExamScore)
{
	
	averageExamScore = (examScoreOne + examScoreTwo + examScoreThree) / 3.0;

} // end of findAverageExamScore()

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
