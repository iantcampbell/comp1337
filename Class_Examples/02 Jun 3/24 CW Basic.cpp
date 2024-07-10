/*
	Ally Baba
 	Assignment Number: Class work# 02
	File Name:         02CWBasic.cpp
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

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project
	cout << "--------------------------------------------" << endl;
	cout << "\tProject # 02" << endl;
	cout << "\tAuthor: Ally Baba" << endl;
	cout << "\tDate: " << endl;
	cout << "\tObjectives: Area of rectangle" << endl;
	cout << "--------------------------------------------" << endl;  
	
	 // Variable decleration
    int examScoreOne;
    int examScoreTwo;
    int examScoreThree;
    float averageExamScore;
    
    // user entry of var
    cout << "\tEnter the first exam score: ";
    cin >> examScoreOne;
    cout << "\tEnter the second exam score: ";
    cin >> examScoreTwo;
    cout << "\tEnter the third exam score: ";
    cin >> examScoreThree;
    
    // get average
    averageExamScore = (float) (examScoreOne + examScoreTwo + examScoreThree) / 3.0;
    
    //Display the desired result
    cout << "\n\tResult" << endl;
    cout << "--------------------------" << endl;
    cout << "\tExam one is " << examScoreOne << endl;
    cout << "\tExam two is " << examScoreTwo << endl;
    cout << "\tExam three is " << examScoreThree << endl;
    cout << "\tThe average exam score is " << averageExamScore << endl;
	
	// End of Project
	cout << "\n--------------------------------------------" << endl;
	cout << "\tEnd of project" << endl;
	cout << "--------------------------------------------" << endl;
	
	      
	return 0;

}  // end of main()
