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
	private:
		float length;
		
	public:
		// setting the private data members .. setters
		void setLength(float value)
		{
			length = value;
		}
		
		// get the values stired in the private members... getters
		float getLength()
		{
			return length;
		}
};

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	
	// create an object .. instance of the class .. instantiation
	Box myBox;
	float value;
	value = getFloatData("\tEnter length: ");
	
	myBox.setLength(value);  // uisng the setter to assign values to provate members
	
	cout << "\tLength is: " << myBox.getLength() << endl;
	
	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of main()


