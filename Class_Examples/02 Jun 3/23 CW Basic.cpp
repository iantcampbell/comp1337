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
	
	/ Variable decleration
    int width;
    int length;
    int area;
    
    // user entry of var
    cout << "\tEnter the width: ";
    cin >> width;
    cout << "\tEnter a value: ";
    cin >> length;
    
    //add resulting integers
    area = width * length;
    
    //Display the desired result
    cout << "\nResult" << endl;
    cout << "--------------------------"<< endl;
    cout << "\tThe area of " << width << " and "<< length << " is " << area << endl;
	
	// End of Project
	cout << "\n--------------------------------------------" << endl;
	cout << "\tEnd of project" << endl;
	cout << "--------------------------------------------" << endl;
	
	      
	return 0;

}  // end of main()
