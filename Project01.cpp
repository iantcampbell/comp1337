/*
-------------------------------------------------------------------------
Name:     		Ian Campbell
Date: 			June 8th, 2024
Project #:		1
Status: 		WIP
Class:			COSC 1337 (MW)
-------------------------------------------------------------------------
Project Objectives
	A movie theater only keeps a percentage of the revenue earned from ticket sales.
	The remainder goes to the movie distributor.  Write a program that will calculate a gross income for a movie for a single show.
	It will also calculate the amounts distributed to the theater and the movie distributor.

	The program will ask the user to enter the name of the movie, and how many adult and child tickets were sold.

	The price of an adult ticket is $20.00, and a child ticket is $10.00.  T
	he theater keeps 40 percent of the box office Income and the rest goes to the movie distributor.
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

// Decleration of prototype
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
char getCharData(string);
string getStringData(string);
void displayResults(string, float, float, float);
int main()
{
	// Displays start of project
	projectStart();

	// Enter the name of the movie, the number of adult tickets sold, and the number of child tickets solf
	// The program will compute the total income and the split for the theater and distributor
	// WRITE THE CODES BELOW

	// Constants and declarations
	float adultTicketPrice = 20.00; // in $
	float childTicketPrice = 10.00; // in $
	float theaterIncomeSplit = .4; // percentage of ticket income the theater keeps, 1.00 = 100%
	string movieTitle;
	int adultTicketCount;
	int childTicketCount;
	float incomeFromMovie;
	float theaterIncome;
	float distributorIncome;

	// this code gets info about the movie and ticket sales from the program user
	cout << "Ally Baba Box Office" << endl;
	cout << "----------------------------------------"  << endl;

	movieTitle = getStringData("\tEnter the name of the movie: ");
	adultTicketCount = getIntegerData("\tNumber of adult tickets sold: ");
	childTicketCount = getIntegerData("\tNumber of child tickets sold: ");
	cout << "----------------------------------------"  << endl;

	// this code calculates the total income and the splits for the theater and distributor
	incomeFromMovie = (adultTicketCount*adultTicketPrice)+(childTicketCount*childTicketPrice);
	theaterIncome = incomeFromMovie*theaterIncomeSplit;
	distributorIncome = incomeFromMovie-theaterIncome;

	//display the results
	displayResults(movieTitle, incomeFromMovie, theaterIncome, distributorIncome);

	// Displays end of project
	projectEnd();

    return 0;

}// end of main

// This function display the information gathered and calculated by the program
void displayResults(string titleOfTheMovie, float incomeFromTheMovie, float incomeForTheTheater, float incomeForTheDistributor)
{
	cout << "----------------------------------------"  << endl;
	cout << "Movie Income Distribution Summary" << endl;
	cout << "----------------------------------------"  << endl;

	cout << "\tMovie name: " << titleOfTheMovie << endl;
	cout << "\tTotal box office income: $" << incomeFromTheMovie << endl;
	cout << endl;
	cout << "\tIncome sent to the movie distributor: $" << incomeForTheDistributor << endl;
	cout << "\tIncome the theater will keep: $" << incomeForTheTheater << endl;
}
// end of displayResults

// This function will gets a char value from the user
char getCharData(string prompt)
{
	char value;

	cout << prompt;
	cin >> value;

	return value;

} // end of getCharData()

// This function will get a float value from the user
float getFloatData(string prompt)
{
	float value;

	cout << prompt;
	cin >> value;

	return value;

} // end of getFloatData()

// This function will get an integer value from the user
int getIntegerData(string prompt)
{
	int value;

	cout << prompt;
	cin >> value;

	return value;
} // end of getIntegerData()

// This function will return a string data entered by users
string getStringData(string prompt)
{
	string value;

	cout << prompt;
	getline(cin, value, '\n'); // accepts spaces in the entry

	return value;

} // end of getStringData(string prompt)

// The function will display the start of the project
void projectStart()
{
	cout << "----------------------------------------"  << endl;
	cout << "Project 1" << endl;
	cout << "Written by: Ian Campbell" << endl;
	cout << "June 8th, 2024" << endl;
	cout << "Objectives: Finds the Income dictribution for distributor and theater" << endl;
	cout << "----------------------------------------"  << endl;
} // end of projectStart()

// The function will display the end of the project
void projectEnd()
{
	cout << "----------------------------------------"  << endl;
	cout << "End of Project 1" << endl;
	cout << "----------------------------------------"  << endl;
} // end of projectEnd()


