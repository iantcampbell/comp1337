/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		2
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
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
void mainMenu(float);
float getInitialBalance();
float getTransactionData(string, bool&);
void deposit(float&);
int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	// Variable Declarations
	char selection;
	bool loopMenu = true;
	float balance;
	bool valid = true;
	
	balance = getInitialBalance();
	
	while (loopMenu) // Menu
	{
		mainMenu(balance);
		selection = getCharData("\tMake selection: ");

		if (selection == 'D')
		{
			deposit(balance);
		}
		else if (selection == 'W')
		{
			cout << "Withdraw" << endl;
		}
		else if (selection == 'E')
		{
			cout << "End" << endl;
			loopMenu = false;
		}
	} // end of while(loopMenu)
	
	cout << "End of loop" << endl;;
	cout << balance;
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main


/*
	name: 	mainMenu()
	input: 	parameter(arguments): None
	output: menu text
	returns: None
	process: display 
	objectives: display
*/
void mainMenu(float balance)
{
	cout << "\n--------------------------------------------" << endl;
	cout << "\tBalance Your Checkbook" << endl;
	cout << "\tYour current balance is: " << balance << endl;
	cout << "--------------------------------------------" << endl;
	cout << "\tChoose a type of transaction" << endl;
	cout << "\t\tD ................................. Deposit" << endl;
	cout << "\t\tW ................................. Withdraw" << endl;
	cout << "\t\tE ................................. Exit" << endl;
	cout << "--------------------------------------------" << endl;

} // end of mainMenu()


/*
	name: 	getInitialBalance()
	input: 	parameter(arguments): None
	output: prompts user for initial alance
	returns: float 
	process: prompt user for balance and get float
	objectives: get intitial checkbook balance from user
*/
float getInitialBalance()
{
	//Variable declarations
	float balance;

	cout << "--------------------------------------------" << endl;
	cout << "\tHow much money was in your account at the start of the month?" << endl;
	balance = getFloatData("$"); // user input
	return balance;

} // end of getInitialBalance()


/*
	name: 	getTransactionData()
	input: 	parameter(string prompt, bool& valid): prompt asks user for input, valid confirms it's a valid number (float or int) 
	output: prompt from input, confirms intent to return to main menu if user input not number
	returns: float
	process: ask for input, confirm it's a number, if not a number confirm return to main menu
	objectives: get information for a transaction from the user
*/
float getTransactionData(string prompt, bool& validTransaction)
{
	
	float value;
	bool promptAgain = true;
	
	cout << prompt;
	
	while(true) // infinite loop
	{
		cout << prompt;
		if (!(cin >> value)) // if not a number confirm return to menu
		{
			cout << "\t\tYour entry was not a valid number." << endl;
			cout << "\t\tTo confirm returning to the Main Menu enter 'M'." << endl;
			cout << "\t\tOtherwise please enter a valid number for the transaction." << endl;
			cout << "--------------------------------------------" << endl;
		
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
			
			if (!(cin >> value)) // confirmation of return to menu
			{
				cout << "\t\tReturning to the Main Menu." << endl;
				validTransaction = false;
				return 0;
			}
		}
		else if (value > 0.0)
		{
			promptAgain = false;
			return value;
		}
		else
		{
			cout << "\t\tPlease enter a positive number." << endl;
		}
		
	}// end while infinite loop

	
} // end of int getTransactionData()


/*
	name: 	deposit()
	input: 	parameter(string prompt, bool& valid): prompt asks user for input, valid confirms it's a valid number (float or int) 
	output: prompt from input, confirms intent to return to main menu if user input not number
	returns: float
	process: ask for input, confirm it's a number, if not a number confirm return to main menu
	objectives: get information for a transaction from the user
*/
void deposit(float& balance)
{
	float depositValue;
	bool validTransaction = true;
	
	cout << "--------------------------------------------" << endl;
	cout << "Enter 'M' to return to the Main Menu" << endl;
	depositValue = getTransactionData("Enter how much money was deposited: $", validTransaction);
	
	if (validTransaction)
	{
		balance = balance + depositValue;
		cout << "You deposited $" << depositValue << endl;
	}
	
} // end of int getTransactionData()

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
	
	cout << prompt;
	
	while (!(cin >> value))
		{
			cout << "\t\tError Message. Non numeric is entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
	return value;
	
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
	cout << "Project #2" << endl;
	cout << "Written by: Ian Campbell" << endl;
	cout << "Objectives" << endl;
	cout << "----------------------------------------------"  << endl;
	cout << "\tThis program will help you balance your checkbook" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #2" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


