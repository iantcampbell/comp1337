/*
-------------------------------------------------------------------------
Name:     		Ian Campbell
Date: 			June 16th, 2024
Project #:		2
Status: 		WIP
Class:			COSC 1337 (MW)
-------------------------------------------------------------------------
Objectives
Write a C++ program to help you balance your checkbook at the end of the month. The
program should have the user enter the initial balance followed by a series of
transactions. For each transaction, first have the user enter a transaction type. The
valid transaction types are:
W - Withdraw monies
D –Deposit monies
E – End of Transaction
For checks and deposits, the user should be prompted to enter the transaction amount
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
#include <stdexcept>
using namespace std;

// Decleration of prototype 
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
void mainMenu();
float getInitialBalance();
void withdraw(float&, int&);
void deposit(float&);
int main();
bool endOfMonth(float&, int&);
getTransactionData(string, bool&);

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW

	//Variable declaration
	char selection;
	float balance;
	int checkCounter = 0;
	bool loopMenu = true;
	balance = getInitialBalance();

	while (loopMenu) // Menu
	{
		mainMenu();
		selection = getCharData("\tMake selection: ");

		if (selection == 'D')
		{
			deposit(balance);
		}
		else if (selection == 'W')
		{
			withdraw(balance, checkCounter);
		}
		else if (selection == 'E')
		{
			loopMenu = endOfMonth(balance, checkCounter);
		}
	} // end of while(loopMenu)


	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main

/*
	name: 	mainMenu()
	input: 	parameter(arguments): None
	output:
	process: display
	objectives: display
*/
void mainMenu()
{
	cout << "\n--------------------------------------------" << endl;
	cout << "\tBalance Your Checkbook" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "\tChoose a type of transaction" << endl;
	cout << "\t\tD ................................. deposit" << endl;
	cout << "\t\tW ................................. withdraw" << endl;
	cout << "\t\tE ................................. Exit" << endl;
	cout << "--------------------------------------------" << endl;

} // end of mainMenu()

/*
	name: 	getInitialBalance()
	input: 	parameter(arguments): None
	output: Initial balance for checkbook as float
	process: Prompt user for balance and get float
	objectives: get float
*/
float getInitialBalance()
{
	//Variable declarations
	float balance;

	cout << "\n--------------------------------------------" << endl;
	cout << "\tWelcome to Ian's program to balance your checkbook" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "\tHow much money was in your account at the start of the month?" << endl;
	balance = getFloatData("$"); // user input
	return balance;

} // end of getInitialBalance()

/*
	name: 	deposit(float& balance)
	input: 	parameter(float& balance): reference variable for the running balance
	output: none
	process: Prompt user for balance and get float
	objectives: update balance after depoist in the form of a reference variable
*/
void deposit(float& balance)
{
	//Variable declarations
	float deposit;
	bool invalid = false;
	
	cout << "\n--------------------------------------------" << endl;
	cout << "\tDEPOSIT" << endl;
	cout << "\tTo return to the main menu enter 'M'" << endl;
	cout << "--------------------------------------------" << endl;
	deposit = getTransactionData("This deposit was for $", invalid); // user input

	if (invalid) // non float input
	{
		cout << "\tReturning to Main Menu" << endl;
		break;
	}
	else if (deposit << 0.0) // negative input
	{
		cout << "\tOnly positive entries are valid, please enter a positive value" << endl;
		deposit = getFloatData("This deposit was for $"); // Fix user input for invalid number
	}
	else // valid input
	{
		balance = balance + deposit;
	}

} // end of deposit()

/*
	name: 	withdraw(float& balance, int& checkCounter)
	input: 	parameter(float& balance, int& checkCounter): reference variables for the running balance and the count of checks
	output: none
	process: Prompt user for balance and get float
	objectives: update balance after depoist in the form of a reference variable
*/
void withdraw(float& balance, int& checkCounter)
{
	//Variable declarations
	float withdraw;
	float overdraftFee = 100;
	bool invalid = false;

	cout << "\n--------------------------------------------" << endl;
	cout << "\tWITHDRAW" << endl;
	cout << "\tTo return to the main menu enter 'M'" << endl;
	cout << "--------------------------------------------" << endl;
	withdraw = getFloatData("This withdraw was for $"); // user input

	if (!is_float(withdraw)) // non float input
	{
		cout << "\tYour input was not a number, returning to Main Menu" << endl;
		break;
	}
	else if (withdraw << 0.0) // negative input
	{
		cout << "\tOnly positive entries are valid, please enter a positive value" << endl;
		withdraw = getFloatData("This withdraw was for $"); // Fix user input for invalid number
	}
	else if (balance < withdraw) // overdraft
	{
		cout << "\tThis withdraw was greater than your balance." << endl;
		cout << "\tIt will not be processed." << endl;
		cout << "\tYour account will be charged a $100 overdraft fee." << endl;
		balance = balance - overdraftFee;
	}
	else // valid input
	{
		balance = balance - withdraw;
		checkCounter++;
	}

} // end of withdraw()

/*
	name: 	endOfMonth(float& balance, int& checkCounter)
	input: 	parameter(float& balance, int& checkCounter): reference variables for the running balance and the count of checks
	output: final end of month balance
	process: calculates and prints checkbook data for the end of the month
	objectives: calculate and output info after all transactions are entered
*/
bool endOfMonth(float& balance, int& checkCounter)
{
	//Variable declarations
	char selection;
	float checkFee = 0.25;
	float totalServiceCharge;
	float finalBalance;

	cout << "\n--------------------------------------------" << endl;
	cout << "\tAre you sure you are done entering transactions for the month?" << endl;
	selection = getCharData("\tEnter 'Y' to confirm");

	if (selection != "Y")
	{
		return true;
	}

	totalServiceCharge = checkCounter * checkFee;
	finalBalance = balance - totalServiceCharge;

	cout << "\n--------------------------------------------" << endl;
	cout << "\tYour balance before check fees was $" << balance << endl;
	cout << "\tYour check fees totaled $" << totalServiceCharge << endl;
	cout << "\tYour final balance is $" << finalBalance << endl;

	return false;

} // end of endOfMonth()

/*
	name: 	endOfMonth(float& balance, int& checkCounter)
	input: 	parameter(float& balance, int& checkCounter): reference variables for the running balance and the count of checks
	output: final end of month balance
	process: calculates and prints checkbook data for the end of the month
	objectives: calculate and output info after all transactions are entered
*/
float getTransactionData(string prompt, bool& valid)
{
	float value;
	
	cout << prompt;
	
	if (!(cin >> value))
	{
	}
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
	cout << "Project #2" << endl;
	cout << "Written by: Ally baba" << endl;
	cout << "Objectives" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #2" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


