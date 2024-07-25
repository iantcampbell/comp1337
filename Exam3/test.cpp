/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		Exam 3 Project
Status: 		WIP
Class:			COSC 1337

-------------------------------------------------------------------------
Projct Objectives:


-------------------------------------------------------------------------
*/

// Compiler directives Header
#include "header.h"
using namespace std;

// Decleration of prototype 


int main()
{
	// Displays start of project 
	projectStart();
	
	// write your code below
	string input = "NoNsenSE";
	string lowerCase;
	
	for (int index = 0; index < input.length(); index++)
	{
		lowerCase += tolower(input[index]);
	}
	
	
	cout << lowerCase << endl;
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main