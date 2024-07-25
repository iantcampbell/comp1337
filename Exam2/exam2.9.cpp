/* 
-------------------------------------------------------------------------
Name:     		Ian Campbell
Date: 			July 13th, 2024
Project #:		Exam 2 Project
Status: 		Completed
Class:			COSC 1337

-------------------------------------------------------------------------
Projct Objectives:
Build a point of sale system
handle 15 items max
handle bad inputs
clean formatting
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
	string name;
	float price;
	int totalSold;
};

struct Cart
{
	int id;
	string name;
	int totalInCart;
};

// Decleration of prototype 
void projectStart();
void projectEnd();
int buildShoppingMenu(Menu*);
void mainMenu(Menu*, int);
char getMenuSelector();
void transactionMenu(Menu*, int);
void buildShoppingCart(Menu*, Cart*, int);
string getTransactionSelector(int);
void displayMenu(Menu*, int);
void getSaleWeight(Menu*, Cart*, int);
void updateDailySales(Menu*, Cart*, int);
void dailySummary(Menu*, int);
int getIntegerData(string);

// Global decleration
const string longDashes(50, '-');
const string shortDashes(25, '-');
const string error("\t--ERROR MESSAGE: ");

int main()
{
	cout << fixed << setprecision(2);
	
	projectStart(); // Displays start of project 
	
	int itemCount = 0; // count of items on the menu
	
	Menu *shoppingMenu; // pointer to menu struct
	shoppingMenu = new Menu[16]; // max size menu of 15, not using 0 to make index match ID
	
	itemCount = buildShoppingMenu(shoppingMenu); // fills in shopping menu array
	
	mainMenu(shoppingMenu, itemCount); // loops new transactions until user ends
	
	dailySummary(shoppingMenu, itemCount); // prints summary
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main


/*
	name: buildShoppingMenu()
	input: Menu* for array of Menu struct
	output: int count of items on menu
	process: loop file, build struct keeping count of items
	objectives: return shopping menu and count of items
*/
int buildShoppingMenu(Menu* shoppingMenu)
{
	ifstream readFile;
	string name;
	string priceString;
	float price;
	int itemCount = 0;
	
	readFile.open("menu.txt");
	if (!readFile)
	{
		cout << error << "Couldn't find 'menu.txt' in buildShoppingMenu()." << endl;
		return 0;
	}
	else
	{
		while (!readFile.eof())
		{
			

			readFile >> name;
			
			if (readFile.eof())
			{
				if (itemCount > 15) // if item count in file is greater than 15, return 0 and close with error
				{
					cout << error << "To many items in 'menu.txt' in buildShoppingMenu()." << endl;
					return 0;
				} // end of if itemCount > 15
				
				return itemCount; // return item count at end of file
			}
			
			readFile >> priceString;
			
			try // stof price line in file
			{
				price = stof(priceString);
			}
			catch(...) // catch errors for stof on second line
			{
				cout << error << "Could not convert price to string in buildShoppingMenu()." << endl;
				return 0; // return 0 if second line could not be converted to a float
			}
			
			shoppingMenu -> name = name;
			shoppingMenu -> price = price;
			itemCount++;
			shoppingMenu -> id = itemCount;
			shoppingMenu -> totalSold = 0;
			shoppingMenu++;	
		}
		
		if (itemCount > 15) // if item count in file is greater than 15, return 0 and close with error
		{
			cout << error << "To many items in 'menu.txt' in buildShoppingMenu()." << endl;
			return 0;
		} // end of if itemCount > 15
		
		return itemCount; // return item count at end of file after exiting loop
	}
} // end of buildShoppingMenu()

/*
	name: mainMenu()
	input: Menu* for array of Menu struct, int itemCount
	output: 
	process: loop main menu until user enters Q
	objectives: loop main menu until exit
*/
void mainMenu(Menu* shoppingMenu, int itemCount)
{
	char mainMenuSelection;
	bool continueMainMenu = true;
	
	while (continueMainMenu)
	{
		// Static menu text
		cout << longDashes << endl;
		cout << "AllyBaba Grocery Store" << endl;
		cout << longDashes << endl;
		cout << "Main Menu" << endl;
		cout << endl;
		cout << "S to Shop" << endl;
		cout << "Q to Quit" << endl;
		cout << shortDashes << endl; 
		
		mainMenuSelection = getMenuSelector(); // get char selector from user
		
		if (mainMenuSelection == 'S') // start a new transaction
		{
			transactionMenu(shoppingMenu, itemCount);	
		}
		else // exit main menu
		{
			continueMainMenu = false;	
		} // end of menu selection if/else
		
	} // end of main menu loop
	
} // end of mainMenu()

/*
	name: getMenuSelector()
	input: none
	output: char S or Q
	process: get char input and validate, then return
	objectives: get menu selector from user
*/
char getMenuSelector()
{
	char value;
	
	while (true)
	{
		cout << "Make your selection: ";
		cin >> value;
		cout << endl;
		
		value = toupper(value);
		cin.clear();
		cin.ignore(120, '\n');
		
		if (value == 'S' || value == 'Q') // if value is valid menu selector return
		{
			return value;	
		} // end of if input validation
		
		cout << error << "Invalid menu selection in getMenuSelector(), please enter S or Q." << endl;
		
	}	// end of while loop	
} // end of getMenuSelector()

/*
	name: transactionMenu
	input: Menu*, int
	output: 
	process: loop transaction menu getting info for each transaction
	objectives: loop transaction menu getting info for each transaction
*/
void transactionMenu(Menu* shoppingMenu, int itemCount)
{
	// new shopping cart for the transaction
	Cart *shoppingCart; 
	shoppingCart = new Cart[itemCount];
	buildShoppingCart(shoppingMenu, shoppingCart, itemCount);
	
	string transactionSelector;
	int itemId;
	bool continueTransaction = true;
	
	
	while (continueTransaction)
	{
		cout << shortDashes << endl;
		cout << "AllyBaba Grocery Store" << endl;
		cout << shortDashes << endl;
		cout << "Grocery Items" << endl;
		displayMenu(shoppingMenu, itemCount);
	
		transactionSelector = getTransactionSelector(itemCount);
		
		// if complete or cancel transaction
		if (transactionSelector == "T" || transactionSelector == "X" || transactionSelector == "t" || transactionSelector == "x")
		{
			continueTransaction = false;
		} // end of if complete or cancel transaction
		else // else not terminating transaction
		{
			itemId = stoi(transactionSelector); // stoi error handling in getTransactionSelector() should always convert
			getSaleWeight(shoppingMenu, shoppingCart, itemId);
			
		} // end of not terminating transaction
	}
	
	if (transactionSelector == "T" || transactionSelector == "t") // if transaction is complete
	{
		updateDailySales(shoppingMenu, shoppingCart, itemCount);
		cout << shortDashes << endl;
		cout << "\tTRANSACTION COMPLETE" << endl;
		cout << shortDashes << endl;
		cout << endl;
		
	} // end of if transaction complete
	else // if transaction is cancelled 
	{
		cout << shortDashes << endl;
		cout << "\tTRANSACTION CANCELLED" << endl;
		cout << shortDashes << endl;
		cout << endl;
	} // end of if transaction cancelled

} // end of transactionMenu


/*
	name: buildShoppingCart()
	input:  Menu* shoppingMenu, Cart* shoppingCart, int itemCount
	output: shoppingCart data in array with pointer to struct
	process: loop and build cart from menu array
	objectives: build cart for individual transaction
*/
void buildShoppingCart(Menu* shoppingMenu, Cart* shoppingCart, int itemCount)
{
	for (int index = 1; index <= itemCount; index++) // loop displays the items in the menu array for the transaction menu
	{
		shoppingCart -> id = shoppingMenu -> id;
		shoppingCart -> name = shoppingMenu -> name;
		shoppingCart -> totalInCart = 0; // sets total items purchased to 0
		shoppingMenu++;
		shoppingCart++;
	}
} // end of buildShoppingCart()

/*
	name: getTransactionSelector()
	input: int
	output: string
	process: gets input from user and validates
	objectives: get transaction selector from user
*/
string getTransactionSelector(int itemCount)
{
	string value;
	int numericValue;
	
	while (true)
	{
		cout << "\tMake your selection: ";
		cin >> value;
		
		cin.clear();
		
		if (value.length() <= 2) // all options longer than 2 are invalid
		{
			try // try conversion to int
			{
				numericValue = stoi(value);
				if (numericValue > 0 && numericValue <= itemCount) // if valid item ID range return
				{
					return value;
				}
				else
				{
					cout << error << "Invalid item ID chosen in getTransactionSelector()." << endl;
				}
			} // end of conversion to int success
			catch(...) // if conversion to int fails
			{
				if (value == "T" || value == "X" || value == "t" || value == "x") // check if valid character input
				{
					return value;
				}
				else
				{
					cout << error << "Invalid selector in getTransactionSelector(), please choose T, X, or an Item ID." << endl;
				}
			}// end of conversion to int failure
		} // end of if length
		else // else length
		{
			cout << error << "Selector length is too long in getTransactionSelector(), please choose T, X, or an Item ID." << endl;
		} // end of else length
	}
	
}// end of getTransactionSelector()

/*
	name: displayMenu()
	input: Menu*, int
	output: 
	process: loop Menu array and print
	objectives: display shopping menu
*/
void displayMenu(Menu* shoppingMenu, int itemCount)
{
	for (int index = 1; index <= itemCount; index++) // loop displays the items in the menu array for the transaction menu
	{
		cout << "\tID: " << index << setw(20) << right << shoppingMenu -> name << ": " << shoppingMenu -> price << endl;		
		shoppingMenu++;
	}	
	cout << endl;
} // end of displayMenu()

/*
	name: getSaleWeight()
	input: Menu*, Cart*, int
	output: 
	process: get and validate input
	objectives: Get weight of items being purchased from user
*/
void getSaleWeight(Menu* shoppingMenu, Cart* shoppingCart, int itemId)
{
	int poundsPurchased;
	float cost;
	
	shoppingMenu += (itemId - 1); // jump to correct array pointer
	shoppingCart += (itemId - 1);
	
	cout << "\tPounds of " << shoppingMenu -> name;
	poundsPurchased = getIntegerData(": ");
	cost = shoppingMenu -> price * poundsPurchased;
	cout << "\tSale: " << poundsPurchased << " lb of " << shoppingMenu -> name << " costs $" << cost << endl;
	cout << endl;
	shoppingCart -> totalInCart += poundsPurchased;
} // end of getSaleWeight

/*
	name: updateDailySales()
	input: Menu*, Cart*, int
	output: 
	process: loop cart and display info while updating totals
	objectives: update daily totals and display transaction summary
*/
void updateDailySales(Menu* shoppingMenu, Cart* shoppingCart, int itemCount)
{
	float itemTotal;
	float subTotal = 0;
	float tax = 0;
	float total = 0;
	
	//Displays purchased grocery list and updates daily totals
	cout << endl;
	cout << shortDashes << endl;
	cout << "\tGrocery List" << endl;
	cout << endl;
	for (int index = 1; index <= itemCount; index++) // loop cart array
	{
		if (shoppingCart -> totalInCart > 0)
		{
			itemTotal = shoppingCart -> totalInCart * shoppingMenu -> price;
			cout << "\t" << shoppingCart -> name << ": " << shoppingCart -> totalInCart << "lb, " << "$" << itemTotal << endl;
			shoppingMenu -> totalSold += shoppingCart -> totalInCart;
			subTotal += itemTotal;
		}

		shoppingMenu++;
		shoppingCart++;
	} // end of looping cart array
	
	tax = subTotal * 0.0825;
	total = subTotal + tax;
	
	// summary of transaction
	cout << shortDashes << endl;
	cout << "\tSub Total: $" << subTotal << endl;
	cout << "\tSales Tax (8.25%): $" << tax << endl;
	cout << "\tTotal: $" << total << endl;
} // end of updateDailySales

/*
	name: dailySummary()
	input: Menu* and int
	output:
	process: loop menu and display summary
	objectives: display summary at program close
*/
void dailySummary(Menu* shoppingMenu, int itemCount)
{
	float itemTotal;
	float subTotal = 0;
	float tax;
	float total;
	
	cout << endl;
	cout << longDashes << endl;
	cout << "Daily Sales Transaction Summary" << endl;
	cout << shortDashes << endl;
	cout << "\tItems Sold Today" << endl;
	cout << endl;
	
	for (int index = 1; index <= itemCount; index++) // loop cart array to display item summary
	{
		if (shoppingMenu -> totalSold > 0) // skip if none sold
		{
			itemTotal = shoppingMenu -> totalSold * shoppingMenu -> price;
			cout << "\t" << shoppingMenu -> name << ": " << shoppingMenu -> totalSold << "lb, " << "$" << itemTotal << endl;
			subTotal += itemTotal;
		} // end of skip if none sold

		shoppingMenu++;
	} // end of looping cart array
	
	tax = subTotal * 0.0825;
	total = subTotal + tax;	
	
	// total summary
	cout << shortDashes << endl;
	cout << "\tSub Total: $" << subTotal << endl;
	cout << "\tSales Tax (8.25%): $" << tax << endl;
	cout << shortDashes << endl;
	cout << "\tTotal: $" << total << endl;
	cout << endl;
	cout << endl;
	cout << "END OF POS" << endl;
	cout << endl;
} // end of daily summary

// This function will get an integer value from the user
int getIntegerData(string prompt)
{
	int value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value))
		{
			cout << error << "Non numeric was entered in getIntegerData()"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // c;lear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
		
		if(cin.fail()) // confirm integer entry
		{
			cout << error << "Non integer was entered in getIntegerData()" << endl;
			cin.clear();
			cin.ignore(120, '\n');
			cout << prompt;
		}
		else
		{
			return value;
		}
	}
}

// The function will display the start of the project 
void projectStart()
{
	cout << longDashes << endl;
	cout << "Exam 2 Project " << endl;
	cout << "Written by: Ian Campbell" << endl;
	cout << "Date: July 12th, 2024" << endl;
	cout << longDashes  << endl;
	cout << "AllyBaba's' POS" << endl;
	cout << longDashes  << endl;
	cout << "Project Objectives" << endl;
	cout << "\tGlorify the great AllyBaba's name" << endl;
	cout << "\tBy writing a Point of Sale system for a grocery store" << endl;
	cout << "\tInspired by his genius and teachings" << endl;
	cout << longDashes  << endl;
} // end of projectStart()
// The function will display the end of the project 
void projectEnd()
{
	cout << longDashes  << endl;
	cout << "\tEnd of Exam 2 Project" << endl;
	cout << longDashes << endl;
} // end of projectEnd()


