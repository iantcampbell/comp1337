/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		3
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

// Decleration of prototype 
void projectStart();
void projectEnd();
float getFloatData(string);
string getStringData(string);
void getFoodAmounts(monkeysFood.monkeysFoodArray&);
void printTable(float);
float average(float);
float max(float);
float min(float);

struct monkeysFood
{
	float monkeysFoodArray[3][7];
};

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	// Variable Declarations
	monkeysFood.monkeysFoodArray foodArray;
	
	getFoodAmounts(foodArray);
	cout << foodArray;
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main

void getFoodAmounts(monkeysFood&)
{
	
	int monkeyCounter = 0;
	int dayCounter = 0;
	
	for ( auto monkey : { "first", "second", "third"} )
    {
    	for ( auto day : { "Sunday", "Monday", "Tusday", "Wednesday", "Thursday", "Friday", "Saturday" } )
    	{
    		prompt = "How much food did the " + monkey + " eat on " + day + ": ";
			float food = getFloatData(prompt);
			monkeysFood[monkeyCounter][dayCounter] = food;
			dayCounter++
		}
		monkeyCounter++
    }
    cout << "END OF getFoodAmounts()" << endl;
    
}
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
	cout << "Project #3" << endl;
	cout << "Written by: Ally baba" << endl;
	cout << "Objectives" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #3" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


