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
	int id;
	int name;
	float cost;
	int totalSold;
};

struct Cart
{
	int id;
	int name;
	float cost;
	int totalInCart;
};

// Decleration of prototype 
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
int getMenu(Menu*);
void displayMenu(Menu*);

// Global decleration
const string dashes(40, '-');

int main()
{
	// Displays start of project 
	projectStart();
	
	// write your code below
	
	int menuItemCount; // count of items on the menu

	Menu *shoppingMenu; // pointer to menu struct
	shoppingMenu = new Menu[15]; // max size menu of 15
	
	menuItemCount = getMenu(shoppingMenu);
	
	cout << "Item count " << menuItemCount << endl;
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main


int getMenu(Menu* shoppingMenu)
{
	ifstream readFile;
	int itemCount = 0;
	
	readFile.open("menu.txt");
	if (!readFile)
	{
		cout << "\t\tERR message! No employee.txt file" << endl;
	}
	else
	{
		while (!readFile.eof())
		{

			
			readFile >> shoppingMenu -> name;
			
			if (readFile.eof())
			{
				return itemCount;
			}		
			
			readFile >> shoppingMenu -> cost;
			itemCount++;
			shoppingMenu -> id = itemCount;
			
			cout << "id: " << shoppingMenu -> id << ", name: " << shoppingMenu -> name << ", cost: " << shoppingMenu -> cost << endl;		
		}
		
		if (itemCount > 15)
		{
			cout << "\t\tErr message! Too many items in file" << endl;
			return 0;
		}
	}
}

void displayMenu(Menu* shoppingMenu, int menuItemCount)
{
	
	for (int index = 0; index < menuItemCount; index++)
	{
		cout << "index: " << index << ", id: " << shoppingMenu -> id << ", name: " << shoppingMenu -> name << ", cost: " << shoppingMenu -> cost << endl;
		shoppingMenu++;
	}
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


