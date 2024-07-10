/*
	Ally Baba
 	Assignment Number: Class work#147
	File Name:         147CWBasic.cpp
	Course/Section:    COSC 1337 Section <mW>
	completeed Date    July 2024
	Instructor:        Baab Ally
--------------------------------------------------------

Project Objectives:
keep track of student
name, 3 exams scores
	
*/

// Compiler directives Header
#include <iostream>             // for cin, cout, endl
#include <iomanip>				// setw, setprecision, left/right, fixed
#include <cmath>				// sine, cosine, pow, trunc, round... 
#include <stdlib.h> 			// srand, rand
#include <ctime>				// time
#include <fstream>				// file reading/writing/appending
#include <string>				// string manipulation
using namespace std;

// Declare the prototypes
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
string getStringData(string);
char getCharData(string);

// project prototypes
void mainMenu();
void subMenu();
void shoppingSpree();

// Global
string dashes(100, '-');

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	
	char cmd;
	
	while (true)
	{
		mainMenu();
		cmd = getCharData("\tMake your selection: ");
		cin.ignore();
		
		if (cmd == 'S')
		{
			cout << "\tShopping spree" << endl;
			shoppingSpree();
		}
		else
		{
			cout << "\tStore closed.  End of the day" << endl;
			break;
		}
	}

	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of mvalue1 = ain()

/*
*/
void shoppingSpree()
{
	string selection;
	int index;
	
	while (true)
	{
		subMenu();
		selection = getStringData("\t\tMake your choice: ");
		
		if (selection == "T"  || selection == "t")
		{
			cout << "\tEnd of transaction" << endl;
			break;
		}
		else if (selection == "X"  || selection == "x")
		{
			cout <<"\t\tCancel Transaction" << endl;
			break;
		}
		else
		{
			try
			{
				index = stoi(selection); // string to integer conversion
				
				if (index == 1)
				{
					cout << "\tSelected Chicken" << endl;
				}
				else if (index == 2)
				{
					cout << "\tSelected Beef" << endl;
				}
				else if (index == 3)
				{
					cout << "\tSeleted Shrimp" << endl;
				}
				else
				{
					cout << "\tInvalid selection" << endl;
				}
				
			}
			catch(...)
			{
				cout << "\t\tError Message! Not valid selection" << endl;	
			}
		}
	}
}

/*
*/
void mainMenu()
{
	cout << dashes << endl;
	cout << "\tAllyBaba Al Carte" << endl;
	cout << dashes << endl;
	cout << "\tS                      Shopping" << endl;
	cout << "\tQ                      Quit " << endl;
	cout << dashes << endl;
}

/*
*/
void subMenu()
{
	cout << dashes << endl;
	cout << "\tAllyBaba Al Carte" << endl;
	cout << "\t\tFood Items" << endl;
	cout << dashes << endl;
	cout << "\t1                      Chicken ($3.00)" << endl;
	cout << "\t2                      Beef  ($2.00)" << endl;
	cout << "\t3                      Shrimp  ($5.00)" << endl;
	cout << dashes << endl;
	cout << "\tT                      End of Tranaction " << endl;
	cout << "\tX                      Cancel Transaction " << endl;
}

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
	
	while (true)
	{
		cout << display;
		cin >> value;
	
		value = toupper(value);
	
		// how to limit data entry
		if (value == 'S' || value == 'Q')
		{
			return value;	
		}
		cout << "\t\tERR message! Enter S, Q" << endl;
	}	
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
	
	while (true)
	{
		cout << display;
		
		while (!(cin >> value))
		{
			cout << "\t\tERR message! Enter numbers ONLY" << endl;
			cin.clear(); 			// clears the cin
			cin.ignore(120, '\n'); // clears the inout upto 120 chars or entered
			cout << display;
		}
		
		// input constraint
		if (value > 0 && value <= 10)
		{
			return value;	
		}
		cout << "\t\tERR message! Enter values between 1 and 10" << endl;
		
	} // end of while (true)

	
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
	
	while (true)
	{
		cout << display;
		
		while (!(cin >> value))
		{
			cout << "\t\tERR message! Enter numbers ONLY" << endl;
			cin.clear(); 			// clears the cin
			cin.ignore(120, '\n'); // clears the inout upto 120 chars or entered
			cout << display;
		}
	
		if (value > 0 && value <= 110)
		{
			return value;
		}
		cout << "\t\tERR message! Enter values between 1 and 10" << endl;
	}
} // end of getFloatData()


/*
	name: 	projectEnd()
	input: 	parameter(arguments): None
	output: return None ... void
	process: displays
	objectives: Displays the end of project
*/
void projectEnd()
{
	cout << "\n" << dashes << endl;
	cout << "\tEnd of project" << endl;
	cout << dashes << endl;
	
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
	cout << dashes << endl;
	cout << "\tProject #147" << endl;
	cout << "\tAuthor: Ally Baba" << endl;
	cout << "\tDate: July 2024" << endl;
	cout << "\tObjectives: Data processing" << endl;
	cout << dashes << endl;
	
} // end of projectStart()
