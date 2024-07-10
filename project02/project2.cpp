/*
-------------------------------------------------------------------------
Name:		Ian Campbell
Date:		June 16, 2024
Project #:	2
Status: 	Complete
Class:		COSC 1337 (MW)
-------------------------------------------------------------------------
Objectives
Write a program to help balance a checkbook at the end of the month. 
Includes entering intiial balance, transaction data and error handling
-------------------------------------------------------------------------
*/

#include <iostream>				// for cin, cout, endl
#include <iomanip>
#include <string>
#include <cctype> 				// for toupper()
#include <cmath>
using namespace std;

// Decleration of prototype
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char confirm();
char getMenuChoice(string);
string getStringData(string);
void mainMenu(float, int, float);
float getInitialBalance();
float getTransactionData(string);
void deposit(float&);
void withdraw(float&, int&, float&);
bool endOfMonth(float, int, float);

int main()
{
	// Displays start of project
	projectStart();

	// START YOUR CODING BELOW

	// Variable Declarations
	char selection;
	bool loopMenu = true;
	float balance;
	int checkCounter;
	float overdraftFees;
	bool valid = true;

	balance = getInitialBalance();
	checkCounter = 0;
	overdraftFees = 0;
	
	while (loopMenu) // Menu
	{
		mainMenu(balance, checkCounter, overdraftFees);
		selection = getMenuChoice("\tMake selection: ");

		if (selection == 'D')
		{
			deposit(balance);
		}
		else if (selection == 'W')
		{
			withdraw(balance, checkCounter, overdraftFees);
		}
		else if (selection == 'E')
		{
			loopMenu = endOfMonth(balance, checkCounter, overdraftFees);
		}
	} // end of while(loopMenu)

	// Displays end of project
	projectEnd();

	return 0;
}// end of main



/*
	name: 	mainMenu()
	input: 	parameter(arguments): float balance, int checkCounter, float OverdraftFees
	output: 
	process: display
	objectives: display
*/
void mainMenu(float balance, int checkCounter, float overdraftFees)
{
	float checkFee = 0.25;
	
	cout << "\n--------------------------------------------" << endl;
	cout << "\tBalance Your Checkbook" << endl;
	cout << fixed << setprecision(2) << "\tYour current balance is: $" << balance << endl;
	cout << fixed << setprecision(2) << "\tYou have $" << checkCounter*checkFee << " in transaction fees." << endl;
	cout << fixed << setprecision(2) << "\tYou have $" << overdraftFees << " in overdraft fees." << endl;
	cout << endl;
	cout << "\tChoose a type of transaction" << endl;
	cout << "\t\tD ................................. Deposit" << endl;
	cout << "\t\tW ................................. Withdraw" << endl;
	cout << "\t\tE ................................. Exit" << endl;
	cout << "--------------------------------------------" << endl;

} // end of mainMenu()


/*
	name: 	getInitialBalance()
	input: 	parameter(arguments): None
	output: return float
	process: prompt user for balance and get float
	objectives: get intitial checkbook balance from user
*/
float getInitialBalance()
{
	//Variable declarations
	float balance;
	string name;
	
	
	cout << "--------------------------------------------" << endl;
	name = getStringData("\tName: ");
	cout << "\tHow much money was in your account at the start of the month? ";
	balance = getFloatData("$"); // user input
	return balance;

} // end of getInitialBalance()



/*
	name: 	getMenuChoice()
	input: 	parameter(arguments): string
	output: return char
	process: gets and menu entry char
	objectives: gets char
*/
char getMenuChoice(string display)
{
	char value;
	
	while (true)
	{
		cout << display;
		cin >> value;
	
		value = toupper(value);
	
		// how to limit data entry
		if (value == 'D' || value == 'W' || value == 'E')
		{
			return value;	
		}
		cout << "\t\tERR message! Not a recognized menu option: Enter D, W, E" << endl;
	}	
} // end of getMenuChoice()

/*
	name: 	confirm()
	input: 	parameter(arguments): 
	output: return char
	process: asks user for Y or N to confirm
	objectives: get char
*/
char confirm()
{
	char value;
	
	while (true)
	{
		cout << "\tEnter Y to continue or N to return to the Main Menu: ";
		cin >> value;
	
		value = toupper(value);
	
		// how to limit data entry
		if (value == 'Y' || value == 'N')
		{
			return value;	
		}
		cout << "\t\tERR message! Please confirm you are done entering transactions with Y or enter N to return to the Main Menu" << endl;
	}	
} // end of confirm()


/*
	name: 	getFloatData()
	input: 	parameter(arguments): string
	output: return float
	process: asks user for float
	objectives: get float
*/
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
	name: 	endOfMonth()
	input: 	parameter(arguments): float balance, int checkCounter, float overdraftFees
	output: return bool
	process: confirm user is done with program and output results
	objectives: output results or return to menu
*/
bool endOfMonth(float balance, int checkCounter, float overdraftFees)
{
	//Variable declarations
	char selection;
	float checkFee = 0.25;
	float totalServiceCharge;
	float finalBalance;

	cout << "\n--------------------------------------------" << endl;
	cout << "\tAre you sure you are done entering transactions for the month?" << endl;
	selection = confirm();

	if (selection != 'Y')
	{
		return true;
	}

	totalServiceCharge = checkCounter * checkFee;
	finalBalance = balance - totalServiceCharge - overdraftFees;

	cout << "\n--------------------------------------------" << endl;
	cout << "END OF MONTH SUMMARY" << endl;
	cout << fixed << setprecision(2) << "\tYou were charged $" << overdraftFees << " in overdraft fees" << endl;
	cout << fixed << setprecision(2) << "\tYour balance before transaction fees was $" << balance << endl;
	cout << fixed << setprecision(2) << "\tYour transaction fees totaled $" << totalServiceCharge<< endl;
	cout << fixed << setprecision(2) << "\tYour overdraft fees totaled $" << totalServiceCharge<< endl;
	cout << endl;
	cout << fixed << setprecision(2) << "Your final balance is $" << finalBalance<< endl;

	return false;

} // end of endOfMonth()



/*
	name: 	getTransactionData()
	input: 	parameter(arguments): string prompt
	output: returns float
	process: prompt user for balance and get float, if no numeric is entered twice return to menu, must be positive
	objectives: get float from user
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
			cout << "\t\t\tYou need to enter a positive value" << endl;
		}

	} // 	while (!(cin >> value))
	return value;
	
} // end of getTransactionData()


/*
	name: 	deposit()
	input: 	parameter(arguments): string prompt
	output: 
	process: prompt user for deposit info
	objectives: get transaction info from user
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
		balance = balance + depositValue;
		cout << fixed << setprecision(2) << "\t\tYou deposited $" << depositValue << " for a total balance of $" << balance << endl;
		
	}	
		
}//end of deposit()


/*
	name: 	withdraw()
	input: 	parameter(arguments): string prompt
	output: 
	process: prompt user for withdrawl info
	objectives: get transaction info from user
*/
void withdraw(float& balance, int& checkCounter, float& overdraftFees)
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
			overdraftFees = overdraftFees + 100;
			checkCounter++;
			cout << "\t\t\tYour available balance could not cover the withdrawl." << endl;
			cout << "\t\t\tYour accout will be charged a $100 overdraft fee." << endl;
		}// end of if withdrawValue overdrafts account
		else // if withdrawValue doesn't overdraft account
		{
			checkCounter++;
			balance = balance - withdrawValue;
			cout << fixed << setprecision(2) << "\t\tYou withdrew $" << withdrawValue << " for a total balance of $" << balance << endl;
			cout << "\t\tYou have used " << checkCounter << " checks." << endl;			
		} // end of withdrawValue doesn't overdraft account
	}// end of if withdrawValue isn't 0 update balance and check counts	
		
}// end of withdraw()


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
	cout << "Balance Your Checkbook" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #2" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


