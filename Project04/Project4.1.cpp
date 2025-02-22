/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		4
Status: 		WIP
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives

-------------------------------------------------------------------------
*/

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>
#include <ctime>
#include <cctype> 				// for toupper()
#include <cstdlib> 				// for random numbers
#include <fstream>              // filestream header
#include <cmath>
using namespace std;

struct shippingCost
{
	int weight;
	float charge;
};

// Decleration of prototype 
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
char getMenuChoice(string);
void packageEntryLoop(int&, int&, float&);
bool getPackageDetails(float&);

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	// Variable Declarations
	int acceptedPackageCount = 0;
	int rejectedPackageCount = 0;
	float totalCost = 0.00;
	
	
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main

void packageEntryLoop(int& acceptedPackageCount, int& rejectedPackageCount, float& totalCost)
{
	bool continueLoop = true;
	char menuSelection;
	bool packageValid; 
	float packageCost;
	
	while (continueLoop)
	{
		cout << "Menu" << endl;
		cout << "----------------------------------------------------------------------------------------" << endl;
		menuSelection = getMenuChoice();
		
		
		if (menuSelection == X)
		{
			continueLoop = false;
		}
		else
		{
			packageCost = 0.00; // resets cost for new package
			packageValid = getPackageDetails(packageCost, menuSelection);
		}
	}
	
}

bool getPackageDetails(float& packageCost, char menuSelection)
{
	int weight;
	int length;
	int width;
	int height;
	
	if (menuSelection == 'T')
	{
		cout << "\tShipping to Texas" << endl;
	}
	else if (menuSelection == 'O')
	{
		cout << "Shipping out of state" << endl;
	}
	else if (menuSelection == 'F')
	{
		cout << "Shipping out of country" << endl;
	}
	cout << "\tEnter package weight and the 3 dimensions." << endl << endl;
	cout << "\t\tEnter package weight: ";
	cin >> weight;
	cout << endl << "\t\tEnter package length: ";
	cin >> weight;
	cout << endl << "\t\tEnter package width: ";
	cin >> weight;
	cout << endl << "\t\tEnter package height: ";
	cin >> height;
	cout endl;
}

/*
	name: 	getMenuChoice()
	input: 	parameter(arguments): string
	output: return char
	process: gets and menu entry char
	objectives: gets char
*/
char getMenuChoice()
{
	char value;
	
	while (true)
	{
		value = getCharData("Enter Location - (T)exas | (O)ut of state | (F)oreign | E(x)it)")
	
		// how to limit data entry
		if (value == 'T' || value == 'O' || value == 'F' || value == 'X')
		{
			return value;	
		}
		cout << "\t\tERR message! Not a recognized menu option: Enter D, W, E" << endl;
	}	
} // end of getMenuChoice()

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
			
			cout << "\t\tError Message. Selection does not exist"  << endl;
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
			
		if (value >= 1 && value <= 10)
		{
			return value;	
		} // end of 	if (value >= 0)
			
		cout << "\t\tError Message. ONLY integers between 1 and 10"  << endl;
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
	cout << "----------------------------------------------"  << endl;
	cout << "Project #4" << endl;
	cout << "Written by: Ally baba" << endl;
	cout << "Objectives" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #4" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


