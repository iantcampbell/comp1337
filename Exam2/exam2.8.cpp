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
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
int getTransacitonMenu(Menu*);
void mainMenu(Menu*, int);
char getMainMenuSelection();
void transactionMenu(Menu*, int);
void displayTransactionMenu(Menu*, int);
string getTransactionMenuSelection(int);
int getSaleWeight(Menu*, Cart*, int);
void buildShoppingCart(Menu*, Cart*, int);
void displayCart(Menu*, Cart*, int);
void dailySummary(Menu*, int);

// Global decleration
const string dashes(40, '-');

int main()
{
	cout << fixed << setprecision(2);
	// Displays start of project 
	projectStart();
	
	// write your code below
	
	int menuItemCount = 0; // count of items on the menu

	Menu *shoppingMenu; // pointer to menu struct
	shoppingMenu = new Menu[16]; // max size menu of 15, not using 0 to make index match ID
	
	menuItemCount = getTransacitonMenu(shoppingMenu);
	mainMenu(shoppingMenu, menuItemCount);
	
	cout << "Item count " << menuItemCount << endl;
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main


int getTransacitonMenu(Menu* shoppingMenu)
{
	ifstream readFile;
	string name;
	string priceString;
	float price;
	int itemCount = 0;
	
	readFile.open("menu.txt");
	if (!readFile)
	{
		cout << "\t\tERR message! No employee.txt file" << endl;
		return 0;
	}
	else
	{
		while (!readFile.eof())
		{
			

			readFile >> name;
			
			if (readFile.eof())
			{
				if (itemCount > 15)
				{
					cout << "\t\tErr message! Too many items in file" << endl;
					return 0;
				}
				return itemCount;
			}
			
			readFile >> priceString;
			price = stof(priceString);
			
			shoppingMenu -> name = name;
			shoppingMenu -> price = price;
			itemCount++;
			shoppingMenu -> id = itemCount;
			shoppingMenu++;	
		}
		
		if (itemCount > 15)
		{
			cout << "\t\tErr message! Too many items in file" << endl;
			return 0;
		}
		
		return itemCount;
	}
}

void mainMenu(Menu* shoppingMenu, int menuItemCount)
{
	char mainMenuSelection;
	bool cont = true;
	
	while (cont)
	{
		cout << dashes << endl;
		cout << "AllyBaba Grocery Store" << endl;
		cout << dashes << endl;
		cout << "Main Menu" << endl;
		cout << endl;
		cout << "S to Shop" << endl;
		cout << "Q to Quit" << endl;
		cout << dashes << endl;
		mainMenuSelection = getMainMenuSelection();
		
		if (mainMenuSelection = 'S')
		{
			transactionMenu(shoppingMenu, menuItemCount);	
		}
		else
		{
			cont = false;	
		} 
	}
	
	dailySummary(shoppingMenu, menuItemCount);
}

void dailySummary(Menu* shoppingMenu, int menuItemCount)
{
	float subTotal = 0;
	float tax;
	float totalSales;
	
	cout << "\tDaily Sales Transaction Summary" << endl;
	cout << dashes << endl;
	cout << endl;
	cout << "\tItems Sold for Today" << endl;
	for (int index = 1; index <= menuItemCount; index++) // loop displays the items in the menu array for the transaction menu
	{
		if (shoppingMenu -> totalSold > 0)
		{
			cout << "\t" << shoppingMenu -> name << setw(20) << shoppingMenu -> totalSold << "lb, " << "$" << shoppingMenu -> price << endl;
			subTotal += (shoppingMenu -> totalSold * shoppingMenu -> price);
		}
		shoppingMenu++;
	}
	
	tax = subTotal * 0.0825;
	totalSales = subTotal + tax;
	
	cout << dashes << endl;
	cout << "\tSub Total: $" << subTotal << endl;
	cout << "\tTax: $" << tax << endl;
	cout << dashes << endl;
	cout << "\tTotal Sales: $" << totalSales << endl;
}
char getMainMenuSelection()
{
	char value;
	while (true)
	{
		value = getCharData("Make your selection: ");
	
		if (value == 'S' || value == 'Q')
		{
			return value;	
		}
		cout << "\t\tERR message getMainMenuSelection()! Not a recognized menu option: Enter S or Q" << endl;
	}		
}

void transactionMenu(Menu* shoppingMenu, int menuItemCount)
{
	string transactionMenuSelection;
	int transactionMenuSelectionID;
	int poundsSold;
	bool cont = true;
	
	while (cont)
	{
		
		Cart *shoppingCart; // pointer to menu struct
		shoppingCart = new Cart[menuItemCount]; // max size menu of 15
		
		buildShoppingCart(shoppingMenu, shoppingCart, menuItemCount);
		
		while (!(transactionMenuSelection == "T" || transactionMenuSelection == "X" || transactionMenuSelection == "t" || transactionMenuSelection == "x"))
		{
			cout << dashes << endl;
			cout << "AllyBaba Grocery Store" << endl;
			cout << dashes << endl;
			cout << "Shopping" << endl;	
			cout << "\tID" << endl;
			displayTransactionMenu(shoppingMenu, menuItemCount);
			cout << endl;
			cout << "\tEnter 'T' to complete your transaction" << endl;
			cout << "\tEnter 'X' to cancel your transaction" << endl;
			cout << endl;
			transactionMenuSelection = getTransactionMenuSelection(menuItemCount);
			
			try 
			{
				stoi(transactionMenuSelection);
				transactionMenuSelectionID = stoi(transactionMenuSelection);
				poundsSold = getSaleWeight(shoppingMenu, shoppingCart, transactionMenuSelectionID);
    		}
    		catch(...) // error handling done elsewhere, only fails are other valid menu options
    		{
			}	
		} // end of while not x or t
		
		if ((transactionMenuSelection == "T" || transactionMenuSelection == "t"))
		{
			displayCart(shoppingMenu, shoppingCart, menuItemCount);
			cout << "\t\t\t TRANSACTION PROCESSED" << endl;
			cout << dashes << endl;
			cout << endl;
			cont = false;
		}
		else if ((transactionMenuSelection == "X" || transactionMenuSelection == "x"))
		{
			cont = false;
			cout << "\t\t\t TRANSACTION CANCELLED" << endl;
			cout << dashes << endl;
			cout << endl;
		}
	
		delete [] shoppingCart;		
	} // end of while cont

} // end of transactionMenu()

void displayCart(Menu* shoppingMenu, Cart* shoppingCart, int menuItemCount)
{
	cout << "\tGrocery List" << endl;
	for (int index = 1; index <= menuItemCount; index++) // loop displays the items in the menu array for the transaction menu
	{
		if (shoppingCart -> totalInCart > 0)
		{
			cout << "\t" << shoppingCart -> name << setw(20) << shoppingCart -> totalInCart << "lb, " << "$" << shoppingMenu -> price << endl;
			shoppingMenu -> totalSold += shoppingCart -> totalInCart;
		}
		shoppingMenu++;
		shoppingCart++;
	}
	
} // end of displayCart();
void buildShoppingCart(Menu* shoppingMenu, Cart* shoppingCart, int menuItemCount)
{
	for (int index = 1; index <= menuItemCount; index++) // loop displays the items in the menu array for the transaction menu
	{
		shoppingCart -> id = shoppingMenu -> id;
		shoppingCart -> name = shoppingMenu -> name;
		shoppingCart -> totalInCart = 0;
		shoppingMenu++;
		shoppingCart++;
	}
}

void displayTransactionMenu(Menu* shoppingMenu, int menuItemCount)
{
	for (int index = 1; index <= menuItemCount; index++) // loop displays the items in the menu array for the transaction menu
	{
		cout << "\t" << index << setw(20) << shoppingMenu -> name << ": " << shoppingMenu -> price << endl;		
		shoppingMenu++;
	}
}
string getTransactionMenuSelection(int menuItemCount)
{
	while (true)
	{
		string value;
		value = getStringData("\tMake your selection: ");
		if (value == "T" || value == "X" || value == "t" || value == "x") // if selection is a valid single letter menu choice return
		{
			return value;	
		}
		
		if (stoi(value) <= menuItemCount && stoi(value) > 0)
		{
			return value;
		}
		
		cout << "\t\tERR message! Not a recognized menu option getTransactionMenuSelection" << endl;
		
	}		
}

int getSaleWeight(Menu* shoppingMenu, Cart* shoppingCart, int transactionMenuSelectionID)
{
	int poundsPurchased;
	float cost;
	shoppingMenu += (transactionMenuSelectionID - 1); // jump to correct array pointer
	shoppingCart += (transactionMenuSelectionID - 1);
	cout << "\tPounds of " << shoppingMenu -> name;
	poundsPurchased = getIntegerData(": ");
	cost = shoppingMenu -> price * poundsPurchased;
	cout << "\tSale: " << poundsPurchased << " lb of " << shoppingMenu -> name << " costs $" << cost << endl;
	cout << endl;
	shoppingCart -> totalInCart += poundsPurchased;
	return poundsPurchased;
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
			cin.clear();
			cin.ignore(120, '\n');
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
			cout << "\t\tError Message. Non numeric is entered in getFloatData()"  << endl;
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
			cout << "\t\t\tError Message. Non numeric was entered in getIntegerData()"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // c;lear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
		
		if(cin.fail()) // confirm integer entry
		{
			cout << "\t\t\tError Message. Non integer was entered in getIntegerData()"  << endl;
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

// This function will return a string data entered by users
string getStringData(string prompt)
{
	string value;
	while (true)
	{
		cout << prompt;
		cin >> value;
		
		cin.clear();
		if (value.length() <= 2)
		{
			return value;
		}
			
		cout << "\t\tERR message! Not a recognized menu option getStringData()" << endl;		
	}	
} // end of int getStringData(string prompt)

// The function will display the start of the project 
void projectStart()
{
	cout << dashes << endl;
	cout << "\tExam 2 Project " << endl;
	cout << "\tWritten by: Ian Campbell" << endl;
	cout << "\tDate: July 12th, 2024" << endl;
	cout << dashes  << endl;
	cout << "\t Allybaba POS" << endl;
	cout << dashes  << endl;
	cout << "\tProject Objectives" << endl;
	cout << "\t\tGlorify the great Ally Baba's name" << endl;
	cout << "\t\tBy writing a Point of Sale system for a grocery store" << endl;
	cout << "\t\tInspired by his genius" << endl;
	cout << dashes  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << dashes  << endl;
	cout << "\tEnd of Exam 2 Project" << endl;
	cout << dashes << endl;
} // end of projectEnd()


