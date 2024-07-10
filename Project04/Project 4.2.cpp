/* 
-------------------------------------------------------------------------
Name:     		Ian Campbell
Date: 			June 30th, 2024
Project #:		4
Status: 		Completed
Class:			COSC 1337 (MW)
-------------------------------------------------------------------------
Objectives

Loop a menu that gets package data from user
Once they are done entering data output a summary
perform input validation and format output
Note: Do not use a two-dimensional array to store the weights and costs.
	used struct
-------------------------------------------------------------------------
*/

struct shippingCost // weight-cost pair for shipping table
{
	int weight;
	float charge;
};

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
char getPackageDestination();
void packageEntryLoop(int& , int& , float&);
bool getPackageDetails(int&);
void displaySummary(int, int, float);

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	// Variable declarations
	char packageDestination;
	float totalCost;
	int acceptedPackageCount = 0;
	int rejectedPackageCount = 0;
	
	packageEntryLoop(acceptedPackageCount, rejectedPackageCount, totalCost);
	
	displaySummary(acceptedPackageCount, rejectedPackageCount, totalCost);
	
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main

/*
	name: 	displaySummary()
	input: 	parameter(arguments): 2 ints, 1 float
	output:
	process:  cout statements
	objectives: display summary before end of program
*/
void displaySummary(int acceptedPackageCount, int rejectedPackageCount, float totalCost)
{
	cout << endl;
	cout << endl;
	cout << "Shipping Transaction Summary" << endl;
	cout << "----------------------------------------------"  << endl;
	cout << "\tNumber of accepted packages:\t" << acceptedPackageCount << endl;
	cout << "\tNumber of rejected packages:\t" << rejectedPackageCount << endl;
	cout << fixed << setprecision(2) << "\tTotal cost: \t\t\t" << totalCost << endl;
	cout << endl;
	
}

/*
	name: getPackageCost()
	input: 	parameter(arguments): 1 int
	output: float 
	process: finds cost of package from table using package weight
	objectives: return cost of package based on weight
*/
float getPackageCost(int packageWeight)
{
	shippingCost shippingCostTable[15]; // table of shipping costs based on weight
	
	shippingCostTable[0].weight = 1;
	shippingCostTable[0].charge = 1.50; 
	
	shippingCostTable[1].weight = 2;
	shippingCostTable[1].charge = 2.10; 
	
	shippingCostTable[2].weight = 3;
	shippingCostTable[2].charge = 4.00; 
	
	shippingCostTable[3].weight = 5;
	shippingCostTable[3].charge = 6.75; 
	
	shippingCostTable[4].weight = 7;
	shippingCostTable[4].charge = 9.90; 
	
	shippingCostTable[5].weight = 10;
	shippingCostTable[5].charge = 14.95; 
	
	shippingCostTable[6].weight = 13;
	shippingCostTable[6].charge = 19.40; 
	
	shippingCostTable[7].weight = 16;
	shippingCostTable[7].charge = 24.20; 
	
	shippingCostTable[8].weight = 20;
	shippingCostTable[8].charge = 27.30; 
	
	shippingCostTable[9].weight = 25;
	shippingCostTable[9].charge = 31.90; 
	
	shippingCostTable[10].weight = 30;
	shippingCostTable[10].charge = 38.50; 
	
	shippingCostTable[11].weight = 35;
	shippingCostTable[11].charge = 43.50; 
	
	shippingCostTable[12].weight = 40;
	shippingCostTable[12].charge = 44.80; 
	
	shippingCostTable[13].weight = 45;
	shippingCostTable[13].charge = 47.40; 
	
	shippingCostTable[14].weight = 50;
	shippingCostTable[14].charge = 55.20; 
	
	for (int index = 0; index < 15; index++) // loop shipping cost table backwards
	{
		if (packageWeight <= shippingCostTable[index].weight)
		{
		//	cout << "weight: " << packageWeight << " cost: " << shippingCostTable[index].charge << endl;
			return shippingCostTable[index].charge;
		}
		
		//return shippingCostTable[14].charge;
	} // end of loop shipping cost table
}

/*
	name: getPackageDetails
	input: 	parameter(arguments): int& packageWeight
	output: bool
	process: get weight and dimensions from user, return true if valid, pass package weight back in int&
	objectives: get and validate package data from user
*/
bool getPackageDetails(int& packageWeight)
{
	int weight;
	int length;
	int width;
	int height;
	int girth;

	weight = getIntegerData("\t\tEnter package weight: ");
	length = getIntegerData("\t\tEnter package length: ");
	width = getIntegerData("\t\tEnter package width: ");
	height = getIntegerData("\t\tEnter package height: ");
	cout << endl;
	
	if (weight < 0 || weight > 50) // invalid package if weight is negative or over 50
	{
		return false;
	}
	else if (length < 0 || length > 72) // invalid package if lenght is negative or over 72in (6ft)
	{
		return false;
		
	}
	else if (width < 0 || width > 72) // invalid package if width is negative or over 72in (6ft)
	{
		return false;
	}
	else if (height < 0 || height > 72) // invalid package if height is negative or over 72in (6ft)
	{
		return false;
	}
	
	// calculate girth
	if (length > height && width > height) // if height is largest
	{
		girth = 2*(length + width);
	}
	else if (length > width) // if width is largest 
	{
		girth = 2*(length + height);
	}
	else // if length is largest
	{
		girth = 2*(width + height);
	}
	
	if (girth > 120) // if girth is over 120in (10 feet)
	{
		return false;
	}
	
	packageWeight = weight; // pass package weight back to main loop
	return true; // valid package
}


/*
	name: 	packageEntryLoop()
	input: 	parameter(arguments): int& acceptedPackageCount, int& rejectedPackageCount, float& totalCost
	output:
	process:  loop collecting package info
	objectives: main program loop, gets package info and keeps record
*/
void packageEntryLoop(int& acceptedPackageCount, int& rejectedPackageCount, float& totalCost)
{
	bool continueLoop = true;
	char packageDestination;
	bool validPackage;
	int packageWeight;
	string destination;
	string mailTo;
	float shippingCharge;
	float serviceCharge;
	float packageCost;
	
	
	while (continueLoop) // main program loop
	{
		cout << "Menu" << endl;
		cout << "----------------------------------------------------------------------------------------" << endl;
		packageDestination = getPackageDestination();
		
		
		if (packageDestination == 'X') // Exit loop if user selects 'X'
		{
			continueLoop = false;
		} // end of exit loop
		else // get a new packages info
		{
			
		
			if (packageDestination == 'T') // prints package destination and sets service charge 
			{
				serviceCharge = 0.00;
				mailTo = "Mail to Texas";
				destination = "Texas";
				cout << endl << "\tShipping to Texas" << endl;
				cout << "\tEnter weights in pounds and package deminsions in inches" << endl;
				//Texas
			}
			else if (packageDestination == 'O')
			{
				serviceCharge = 35.00;
				mailTo = "Mail out of state";
				destination = "Out of state";
				cout << endl << "\tShipping out of state" << endl;
				cout << "\tEnter weights in pounds and package deminsions in inches" << endl;
				// Out of state
			}
			else if (packageDestination == 'F')
			{
				serviceCharge = 40.00;
				mailTo = "Mail out of country";
				destination = "Out of country";
				cout << endl << "\tShipping out of country" << endl;
				cout << "\tEnter weights in pounds and package deminsions in inches" << endl;
				// Foreign
			} // end of package destination processing
			
			validPackage = getPackageDetails(packageWeight);
			
			if (validPackage) // valid package output
			{
				shippingCharge = getPackageCost(packageWeight);
				packageCost = serviceCharge + shippingCharge;
				totalCost += packageCost;
				
				cout << "\tTransation Completed: " << mailTo << endl;
				cout << "----------------------------------------------"  << endl;
				cout << "\t\tLocation\t" << destination << endl;
				cout << "\t\tStatus\t\tAccepted" << endl;
				cout << "\t\tWeight\t\t" << packageWeight << " lb" << endl;
				cout << fixed << setprecision(2) << "\t\tCost\t\t$" << packageCost << endl;
				
				acceptedPackageCount++;
				cout << "\t\tTotal packages being shipped: " << acceptedPackageCount << endl;
				cout << endl;	
			}
			else // invalid package output
			{
				cout << "\tTransation Completed: Rejected " << mailTo << endl;
				cout << "----------------------------------------------"  << endl;
				cout << "\t\tLocation\t" << destination << endl;
				cout << "\t\tStatus\t\tRejected" << endl;
				cout << "\t\tWeight\t\t" << packageWeight << " lb" << endl;
				cout << "\t\tCost\t\tN/A" << endl;
				
				rejectedPackageCount++;
				cout << "\t\tTotal packages being shipped: " << acceptedPackageCount << endl;
				cout << endl;
			} // end of package output		
			
			
		}
	} // end of main program loop
	
} // end of packageEntryLoop

/*
	name: 	getPackageDestination()
	input: 	parameter(arguments):
	output: return char
	process:  menu entry char and verifies valid
	objectives: gets char
*/
char getPackageDestination()
{
	char value;
	
	while (true)
	{
		value = getCharData("Enter Location - (T)exas | (O)ut of state | (F)oreign | E(X)it): ");
	
		if (value == 'T' || value == 'O' || value == 'F' || value == 'X')
		{
			return value;	
		}
		cout << "\t\tERR message! Not a recognized menu option: Enter T, O, F, or X" << endl;
	}	
} // end of getPackageDestination()


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
	cout << "Written by: Ian Campbell" << endl;
	cout << "Objectives: AllyBaba Shipping Service Program" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #4" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()


