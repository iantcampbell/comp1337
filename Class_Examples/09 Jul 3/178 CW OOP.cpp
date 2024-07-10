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
// PUBLic...  2 angles... find the sum of 2 angles

class Angles
{
	public:
		// attributes
		float angleOne;
		float angleTwo;
		
		// methods
		float findAngleSum()
		{
			return angleOne + angleTwo;
		}
		
		string findAngleType()
		{
			if (findAngleSum() < 90)
			{
				return "Acute angles";
			}
			else if (findAngleSum() == 90)
			{
				return "Right angles";
			}
			else if (findAngleSum() < 180)
			{
				return "Obtuse angles";
			}
		}
}; // end of class


int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	
	// create an object .. instance of the class .. instantiation
	Angles myAngles;
	
	myAngles.angleOne= getFloatData("\tEnter angle 1: ");
	myAngles.angleTwo = getFloatData("\tEnter angle 2: ");
	
	cout << "\tSum is: " << myAngles.findAngleSum() << endl;
	cout << "\tAngle Type is: " << myAngles.findAngleType() << endl;
	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of main()


