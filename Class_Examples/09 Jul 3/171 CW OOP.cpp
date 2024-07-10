/*
	Ally Baba
 	Assignment Number: Class work#147
	File Name:         147CWBasic.cpp
	Course/Section:    COSC 1337 Section <mW>
	completeed Date    July 2024
	Instructor:        Baab Ally
--------------------------------------------------------
Project Objectives:
	
*/

// Compiler directives Header
#include "header.h"
using namespace std;

// blueprint.. template.. blank form.. class
class Box
{
	public:
		float length;
	
};  // end of class Box

// project prototypes


int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	
	// create an object .. instance of the class .. instantiation
	Box myBox;
	
	myBox.length = 12;
	
	cout << "\tLength: " << myBox.length << endl;

	
	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of main()


