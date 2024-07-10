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
float getTransactionData(string);
void deposit(float&);
void withdraw(float&, float&);


int main()
{
	// Displays start of project
	projectStart();

	// START YOUR CODING BELOW

	// Variable Declarations
	char selection;
	bool loopMenu = true;
	float balance;
	float checkCounter;
	bool valid = true;

	balance = getInitialBalance();
	checkCounter = 0;
	
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
			withdraw(balance, checkCounter);
		}
		else if (selection == 'E')
		{
			cout << "End" << endl;
			loopMenu = false;
		}
		else
		{
			cout << "Please enter a valid menu option" << endl;
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
	cout << "\tYour current balance is: $" << balance << endl;
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
	cout << "\tHow much money was in your account at the start of the month? ";
	balance = getFloatData("$"); // user input
	return balance;

} // end of getInitialBalance()



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

} // end of  getCharData()

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
	
} // end of getFloatData()



/*
	name: 	getTransactionData()
	input: 	parameter(arguments): string prompt
	output: prompts user for the value of the transaction
	returns: float 
	process: prompt user for balance and get float, if no numeric is entered twice return to menu, must be positive
	objectives: get transaction value from user
*/
float getTransactionData(string prompt)
{
	float value;
	
	while (true)
	{
		cout << "\t\t" << prompt;
		
		if (!(cin >> value)) // if (!(cin >> value))
		{
			cout << "\t\tTo confirm you want to return to the Main Menu enter 'M'"  << endl;
			cout << "\t\tOtherwise please enter a valid input" << endl;
			cout << "\t\t" << prompt;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
			
			if (!(cin >> value)) // if (!(cin >> value)) second check
			{
				cout << "\t\tReturning to Main Menu"  << endl;
				cin.clear(); // clear error buffer
				cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
				return 0;
			} // end of if (!(cin >> value)) second check
			
		} // end of if (!(cin >> value))
		else if (value > 0)
		{
			return value;
		}
		else
		{
			cout << "\t\tYou need to enter a positive value" << endl;
		}

	} // 	while (!(cin >> value))
	return value;
	
} // end of getTransactionData()


/*
	name: 	deposit()
	input: 	parameter(arguments): string prompt
	output: prompts user for the value of the transaction
	returns: float 
	process: prompt user for balance and get float, if no numeric is entered twice return to menu, must be positive
	objectives: get transaction value from user
*/
void deposit(float& balance)
{
	
	// Variable Declarations
	float depositValue;
	
	cout << "--------------------------------------------" << endl;
	cout << "\tDEPOSIT" << endl;
	cout << "\t\tEnter 'M' to return to the Main Menu" << endl;

	
	depositValue = getTransactionData("Money deposited in transaction: $");
	
	if (!(depositValue == 0))
	{
		cout << "\tYou deposited $" << depositValue << endl;
		balance = balance + depositValue;
	}	
		
}//end of deposit()


/*
	name: 	withdraw()
	input: 	parameter(arguments): string prompt
	output: prompts user for the value of the transaction
	returns: float 
	process: prompt user for balance and get float, if no numeric is entered twice return to menu, must be positive
	objectives: get transaction value from user
*/
void withdraw(float& balance, float& checkCounter)
{
	
	// Variable Declarations
	float withdrawValue;
	
	cout << "--------------------------------------------" << endl;
	cout << "\tWITHDRAWL" << endl;
	cout << "\t\tEnter 'M' to return to the Main Menu" << endl;

	
	withdrawValue = getTransactionData("Money withdrawn in transaction: $");
	
	if (!(withdrawValue == 0)) // if withdrawValue isn't 0 update balance and check counts
	{
		if ((balance - withdrawValue) < 0) // if withdrawValue overdrafts account
		{
			balance = balance - 100;
			cout << "\tYour account balance could not cover the withdrawl." << endl;
			cout << "\tYour accout will be charged a $100 overdraft fee." << endl;
		}// end of if withdrawValue overdrafts account
		else // if withdrawValue doesn't overdraft account
		{
			checkCounter++;
			balance = balance - withdrawValue;
			cout << "\tYou withdrew $" << withdrawValue << endl;
			cout << "\tYou have used " << checkCounter << " checks." << endl;			
		} // end of withdrawValue doesn't overdraft account
	}// end of if withdrawValue isn't 0 update balance and check counts	
		
}// end of withdraw()



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


