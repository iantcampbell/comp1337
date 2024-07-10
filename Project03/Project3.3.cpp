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

struct foodReport
{
	float foodArray[3][7];
	float totalFood;
};

// Decleration of prototype 
void projectStart();
void projectEnd();
float getFloatData(string);
void populateFoodReport(foodReport &);

float averageFood(foodReport);
float minFood(foodReport);
float maxFood(foodReport);
void printFoodReport(foodReport);

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	// Variable Declarations
	float average;
	float min;
	float max;
	
	// creating an object a variable
	foodReport monkeysFoodReport;
	
	populateFoodReport(monkeysFoodReport);
	cout << endl;
	cout << endl;
	cout << endl;
	printFoodReport(monkeysFoodReport);
	average = averageFood(monkeysFoodReport);
	
	
}

void populateFoodReport(foodReport & monkeysFoodReport)
{
	int monkeyCounter = 0;
	int dayCounter = 0;
	
	cout << "Weekly Food Intake (in pounds)" << endl;
	
	for ( string monkey : { "First", "Second", "Third"} )
    {
    	cout << monkey << " Monkey" << endl;
    	cout << "Enter the food intake for each day" << endl;
    	for ( string day : { "Sunday: ", "Monday: ", "Tusday: ", "Wednesday: ", "Thursday: ", "Friday: ", "Saturday: " } )
    	{
    		float foodWeight = getFloatData(day);
    		monkeysFoodReport.foodArray[monkeyCounter][dayCounter] = foodWeight;
    		monkeysFoodReport.totalFood += foodWeight;
    		dayCounter++;
		} // end of for day : day of the week
		monkeyCounter++;
	} // end of for monkey : first, second, third
}

void printFoodReport(foodReport monkeysFoodReport)
{
	int monkeyCounter = 0;
	int dayCounter = 0;
	cout << "Weekly Food Intake (in pounds)" << endl;
	
	for ( string monkey : { "First", "Second", "Third"} )
    {
    	cout << monkey << " Monkey" << endl;
    	cout << "Food intake for each day" << endl;
    	for ( string day : { "Sunday: ", "Monday: ", "Tusday: ", "Wednesday: ", "Thursday: ", "Friday: ", "Saturday: " } )
    	{
    		cout << day << monkeysFoodReport.foodArray[monkeyCounter][dayCounter] << endl;
    		dayCounter++;
		} // end of for day : day of the week
		monkeyCounter++;
	} // end of for monkey : first, second, third
	cout << "The sum of food eaten was: " << monkeysFoodReport.totalFood << endl;
}


float averageFood(foodReport monkeysFoodReport)
{
	float average; 

	average = monkeysFoodReport.totalFood / 21;
	cout << "The average food eaten per day by all monkeys was: " << average << " pounds" << endl;
	return average;
}

float minFood(foodReport monkeysFoodReport)
{
	float min;
	min = monkeysFoodReport.foodArray[1][1];
	
	for (int monkey = 0; monkey < 3; monkey++)
	{
		for (int day = 0; day < 7; day++)
		{
			if (min > monkeysFoodReport.foodArray[monkey][day])
			{
				min = monkeysFoodReport.foodArray[monkey][day];
			}
		} // end of for day
	} // end of for monkey

	return min;
}

float maxFood(foodReport monkeysFoodReport)
{
	float max;
	max = monkeysFoodReport.foodArray[1][1];
	
	for (int monkey = 0; monkey < 3; monkey++)
	{
		for (int day = 0; day < 7; day++)
		{
			if (max > monkeysFoodReport.foodArray[monkey][day])
			{
				max = monkeysFoodReport.foodArray[monkey][day];
			}
		} // end of for day
	} // end of for monkey

	return max;
}

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

	} // end of while (true)
} // end of int getFloatData()

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
