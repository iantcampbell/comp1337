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
// PUBLic...  3 sides of a triangle and a methods that will find the perimeter

class Triangle
{
	public:
		// attributes
		float sideOne;
		float sideTwo;
		float sideThree;
		
		// methods
		float findPerimeter()
		{
			return sideOne + sideTwo + sideThree;
		}
};


int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	
	// create an object .. instance of the class .. instantiation
	Triangle myTriangle;
	
	myTriangle.sideOne = 3;
	myTriangle.sideTwo = 4;
	myTriangle.sideThree = 5;
	
	cout << "\tArea is: " << myTriangle.findPerimeter() << endl;
	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of main()


