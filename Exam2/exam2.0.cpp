/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		Exam 2 Project
Status: 		WIP
Class:			COSC 1337

-------------------------------------------------------------------------
Projct Objectives:


-------------------------------------------------------------------------
*/

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>
#include <ctime>
#include <cctype> 				//for toupper()
#include <cstdlib> 				//for random numbers
#include <fstream>               //includes filestream header
#include <cmath>

using namespace std;

struct Menu
{
	
};

struct Cart
{
	
};

// Decleration of prototype 
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);

// Global decleration
const string dashes(40, '-');

int main()
{
	// Displays start of project 
	projectStart();
	
	// write your code below
	
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main


// This function will get a char value from the user
char getCharData(string prompt)
{
	char value;
	
	while (true)
	{
			cout << prompt;
			cin >> value;
	
			value = toupper(value);
			
			return value;	
			
			//cout << "\t\tError Message. Selection does not exist"  << endl;
	} // end of while(true)

} // end of int getFloatData()

// This function will get a float value from the user
float getFloatData(string prompt)
{
	float value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value))
		{
			cout << "\t\tError Message. Non numeric is entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
			
		return value;	
			
		//cout << "\t\tError Message. ONLY integers"  << endl;
	} // end of while (true)
} // end of int getFloatData()

// This function will get an integer value from the user
int getIntegerData(string prompt)
{
	int value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value))
		{
			cout << "\t\t\tError Message. Non numeric is entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // c;lear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
			
		return value;
		
		//cout << "\t\tError Message. ONLY integers"  << endl
			
	} // end of while (true)
} // end of int getIntegerData()

// This function will return a string data entered by users
string getStringData(string prompt)
{
	string value;
	cout << prompt;
	getline(cin, value, '\n'); // accepts spaces in the entry
	
	return value;
	
} // end of int getStringData(string prompt)

// The function will display the start of the project 
void projectStart()
{
	cout << dashes << endl;
	cout << "\tExam 2 Project " << endl;
	cout << "\tWritten by: Ally baba" << endl;
	cout << "\tDate: " << endl;
	cout << dashes  << endl;
	cout << "\t Allybaba POS" << endl;
	cout << dashes  << endl;
	cout << "\tProject Objectives" << endl;
	cout << "\t\t" << endl;
	cout << "\t " << endl;
	cout << dashes  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << dashes  << endl;
	cout << "\tEnd of Exam 2 Project" << endl;
	cout << dashes << endl;
} // end of projectEnd()


