/* 
-------------------------------------------------------------------------
Name:     		Ian Campbell
Date: 			June 23, 2024
Project #:		3
Status: 		Completed
Class:			COSC 1337 (MW)
-------------------------------------------------------------------------
Objectives
A local zoo wants to keep track of how many pounds of food each of its
three monkeys eats each day during a typical week.
Write a program that collects and stores this information in a two-dimensional 3 x 7
array, where each row represents a different monkey, and each column
represents a different day of the week.
The program should first have the user input the data for each monkey
from the keyboard.
The number of pounds of food eaten by one monkey in one day should be
a floating-point value.
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
	foodReport monkeysFoodReport; // contains float foodArray[3][7]
	
	populateFoodReport(monkeysFoodReport);
	printFoodReport(monkeysFoodReport);
	average = averageFood(monkeysFoodReport);
	min = minFood(monkeysFoodReport);
	max = maxFood(monkeysFoodReport);
	
	
} // end of main

/*
	name: populateFoodReport()
	input: foodReport
	output: none
	process: asks user for food consumed by monkeys and stores in report
	objectives: collect data for report
*/
void populateFoodReport(foodReport & monkeysFoodReport)
{
	int monkeyCounter = 0;
	int dayCounter;
	
	cout << "Weekly Food Intake (in pounds)" << endl;
	
	for ( string monkey : { "First", "Second", "Third"} )
    {
    	cout << "\t" << monkey << " Monkey" << endl;
    	cout << "\t\tEnter the food intake for each day" << endl;
    	dayCounter = 0;
    	for ( string day : { "\t\t\tSunday: ", "\t\t\tMonday: ", "\t\t\tTusday: ", "\t\t\tWednesday: ", "\t\t\tThursday: ", "\t\t\tFriday: ", "\t\t\tSaturday: " } )
    	{
    		float foodWeight = getFloatData(day);
    		monkeysFoodReport.foodArray[monkeyCounter][dayCounter] = foodWeight;
    		dayCounter++;
		} // end of for day : day of the week
		monkeyCounter++;
	} // end of for monkey : first, second, third
}

/*
	name: printFoodReport()
	input: foodReport
	output: none
	process: iterates through data in food report and prints it
	objectives: output report
*/
void printFoodReport(foodReport monkeysFoodReport)
{
	int monkeyCounter = 0;
	int dayCounter;
	cout << "--------------------------------------------" << endl;
	cout << "Weekly Monkey Food Intake Summary" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Pounds of Food Eaten by Monkey for Each day of the week" << endl << endl;
	cout << "Monkey\t\t" << "Sun\t" << "Mon\t" << "Tue\t" << "Wed\t" << "Thu\t" << "Fri\t" << "Sat\t" << endl;
	for ( string monkey : { "1", "2", "3"} )
    {
    	cout << setw(3.5)<< monkey << "\t\t";
    	dayCounter = 0;
    	for ( string day : { "Sunday: ", "Monday: ", "Tusday: ", "Wednesday: ", "Thursday: ", "Friday: ", "Saturday: " } )
    	{
    		cout << fixed << setprecision(1) << monkeysFoodReport.foodArray[monkeyCounter][dayCounter] << "\t";
    		dayCounter++;
		} // end of for day : day of the week
		cout << endl;
		monkeyCounter++;
	} // end of for monkey : first, second, third
}

/*
	name: averageFood
	input: foodReport
	output: float
	process: calculates sum of food consumed and divides by 21 
	objectives: calculate average
*/
float averageFood(foodReport monkeysFoodReport)
{
	float average; 
	float sum = 0;
	
	for (int monkey = 0; monkey < 3; monkey++)
	{
		for (int day = 0; day < 7; day++)
		{
			sum += monkeysFoodReport.foodArray[monkey][day];
		}
	}
	average =  sum / 21;
	cout << fixed << setprecision(2) << "The average food eaten per day by all monkeys was:" << setw(20) << right << average << " pounds" << endl;
	return average;
}

/*
	name: minFood()
	input: foodReport
	output: return float
	process: loops food consumed saving smallest value
	objectives: find min food consumed on a single day from report
*/
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

	cout << fixed << setprecision(2) << "The minimum food eaten per day by all monkeys was:" << setw(20) << right << min << " pounds" << endl;
	return min;
}

/*
	name: maxFood()
	input: foodReport
	output: return float
	process: loops food consumed saving largest value
	objectives: find max food consumed on a single day from report
*/
float maxFood(foodReport monkeysFoodReport)
{
	float max;
	max = monkeysFoodReport.foodArray[1][1];
	
	for (int monkey = 0; monkey < 3; monkey++)
	{
		for (int day = 0; day < 7; day++)
		{
			if (max < monkeysFoodReport.foodArray[monkey][day])
			{
				max = monkeysFoodReport.foodArray[monkey][day];
			}
		} // end of for day
	} // end of for monkey

	cout << fixed << setprecision(2) << "The maximum food eaten per day by all monkeys was:" << setw(20) << right << max << " pounds" << endl;
	return max;
} // end of maxFood()

// This function will get a float value from the user, confirms non numeric and positive
float getFloatData(string prompt)
{
	float value;
	
	while (true)
	{
		cout << prompt;
		if (!(cin >> value))
		{
			cout << "\t\tError Message. Non numeric is entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
		} // 	while (!(cin >> value))
		else if (value > 0.0)
		{
			return value;
		}
		else
		{
			cout << "\t\tPlease enter a positive number." << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
		}
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
	cout << "AllyBaba Zoo" << endl;
	cout << "--------------------------------------------" << endl;
} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "----------------------------------------------"  << endl;
	cout << "End of Project #3" << endl;
	cout << "----------------------------------------------"  << endl;
} // end of projectEnd()
