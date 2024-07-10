/*
	Ally Baba
 	Assignment Number: Class work# 68
	File Name:         68CWBasic.cpp
	Course/Section:    COSC 1337 Section <mW>
	completeed Date    June 2024
	Instructor:        Baab Ally
--------------------------------------------------------

Project Objectives:
	Keep track of 7 days of temperature  for 3 weeks
*/

// Compiler directives
#include <iostream>             // for cin, cout, endl
#include <iomanip>				// setw, setprecision, left/right, fixed
#include <cmath>				// sine, cosine, pow, trunc, round... 
#include <stdlib.h> 			// srand, rand
#include <ctime>				// time
#include <fstream>				// file reading/writing/appending
#include <string>				// string manipulation
using namespace std;

// Declare the prototypes
void projectStart();
void projectEnd();
int getIntegerData(string);
float getFloatData(string);
string getStringData(string);
char getCharData(string);

void populateTemperature(float[][7]);
void displayTemperature(float[][7], float);
void findAverageTemperature(float[][7], float &);

int main()	
{
	cout << fixed << setprecision(2);
	
	// Start of Project  
	projectStart(); // calling the function
	
	// var decelration
	float temperature[3][7];
	float avgTemperature;
	
	populateTemperature(temperature);
	
	findAverageTemperature(temperature, avgTemperature);
	
	displayTemperature(temperature, avgTemperature);

	
	// End of Project
	projectEnd();
	      
	return 0;

}  // end of main()

/*
	name: 	findAverageTemperature()
	input: 	parameter(arguments): flaot array
	output: None
	process: loop for 7 days to get the temperature
	objectives: temperature for a week
*/
void findAverageTemperature(float temperature[][7], float &avgTemperature)
{
	float sumTemperature;
	
	sumTemperature = 0;
	
	for (int week = 0; week < 3; week++)
	{
		
		for (int day = 0; day < 7; day++)
		{
			sumTemperature = sumTemperature + temperature[week][day];
		} // end of for (int day = 0; day < 7; day++)
		
	} // end of 	for (int week = 0; week < 3; week++)
	
	avgTemperature = sumTemperature / 21;
	
} // end of findAverageTemperature()



/*
	name: 	displayTemperature()
	input: 	parameter(arguments): flaot array
	output: None
	process: loop for 7 days to get the temperature
	objectives: temperature for a week
*/
void displayTemperature(float temperature[][7], float avgTemperature)
{
	string message;
	string weekDays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
	string dashes(80, '-');
	
	cout <<"\n\n\tResult" << endl;
	
	cout << dashes << endl;
	cout << setw(20) << "Week";
	for (int day = 0; day < 7; day++)
	{
		cout << setw(10) << weekDays[day];
	}
	
	cout << "\n";
	
	cout << dashes << endl;
	
	for (int week = 0; week < 3; week++)
	{
		cout << setw(20) << week + 1;
		
		for (int day = 0; day < 7; day++)
		{

			cout << setw(10) << temperature[week][day];
		} // end of for (int ctr = 0; ctr < 7; ctr++)
		
		cout << "\n";
		
	} // end of for (int week = 0; week < 3; week++)
	cout << dashes << endl;
	
	cout << "\tAverage temperature: " << avgTemperature << endl;
	
} // end of void populateTemperature()


/*
	name: 	populateTemperature()
	input: 	parameter(arguments): flaot array
	output: None
	process: loop for 7 days to get the temperature
	objectives: temperature for a week
*/
void populateTemperature(float temperature[][7])
{
	string message;
	string weekDays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
	
	for (int week = 0; week < 3; week++)
	{
		cout << "\tEnter the temperature for each day of the week#: " << week + 1<< endl;
		
		for (int day = 0; day < 7; day++)
		{
			message = "\t\t" + weekDays[day] + ": ";
			temperature[week][day] = getFloatData(message);
		} // end of for (int ctr = 0; ctr < 7; ctr++)
		
	}  // end of 	for (int week = 0; week < 3; week++)
	
} // end of void populateTemperature()

/*
	name: 	getCharData()
	input: 	parameter(arguments): string
	output: return char
	process: gets and entry char
	objectives: gets char
*/
char getCharData(string display)
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
		cout << "\t\tERR message! Enter D, W, E" << endl;
	}	
} // end of getStringData()

/*
	name: 	getStringData()
	input: 	parameter(arguments): string
	output: return string
	process: gets and entry string
	objectives: gets string
*/
string getStringData(string display)
{
	string value;
	
	cout << display;
	getline(cin, value);
	
	return value;
	
} // end of getStringData()


/*
	name: 	getIntegerData()
	input: 	parameter(arguments): string
	output: return int
	process: gets integer data from users
	objectives: integer entry
*/
int getIntegerData(string display)
{
	int value;
	
	while (true)
	{
		cout << display;
		
		while (!(cin >> value))
		{
			cout << "\t\tERR message! Enter numbers ONLY" << endl;
			cin.clear(); 			// clears the cin
			cin.ignore(120, '\n'); // clears the inout upto 120 chars or entered
			cout << display;
		}
		
		// input constraint
		if (value > 0 && value <= 10)
		{
			return value;	
		}
		cout << "\t\tERR message! Enter values between 1 and 10" << endl;
		
	} // end of while (true)

	
} // end of getIntegerData()

/*
	name: 	getFloatData()
	input: 	parameter(arguments): string
	output: return float
	process: gets float data from users
	objectives: integer entry
*/
float getFloatData(string display)
{
	float value;
	
	while (true)
	{
		cout << display;
		
		while (!(cin >> value))
		{
			cout << "\t\tERR message! Enter numbers ONLY" << endl;
			cin.clear(); 			// clears the cin
			cin.ignore(120, '\n'); // clears the inout upto 120 chars or entered
			cout << display;
		}
	
		if (value > 0 && value <= 110)
		{
			return value;
		}
		cout << "\t\tERR message! Enter values between 1 and 10" << endl;
	}
} // end of getFloatData()

/*
	name: 	displayResult()
	input: 	parameter(arguments): examScoreOne, examScoreTwo, examScoreThree, averageExamScore
	output: return None ... void
	process: displays the results
	objectives: Displays the rsults of the avreage
*/
void displayResults(string name, float examScoreOne, float examScoreTwo, float examScoreThree, float averageExamScore)
{
	cout << "\n\tResult" << endl;
    cout << "--------------------------" << endl;
    cout << "\tName: " << name << endl;
    cout << "\tExam one is " << examScoreOne << endl;
    cout << "\tExam two is " << examScoreTwo << endl;
    cout << "\tExam three is " << examScoreThree << endl;
    cout << "\tThe average exam score is " << averageExamScore << endl;
    
} // end of displayResults()

/*
	name: 	projectEnd()
	input: 	parameter(arguments): None
	output: return None ... void
	process: displays
	objectives: Displays the end of project
*/
void projectEnd()
{
	cout << "\n--------------------------------------------" << endl;
	cout << "\tEnd of project" << endl;
	cout << "--------------------------------------------" << endl;
	
} // end of projectEnd()

/*
	name: 	projectStart()
	input: 	parameter(arguments): None
	output: return None ... void
	process: displays
	objectives: Displays the start of project
*/

void projectStart()
{
	cout << "--------------------------------------------" << endl;
	cout << "\tProject # 76" << endl;
	cout << "\tAuthor: Ally Baba" << endl;
	cout << "\tDate: " << endl;
	cout << "\tObjectives: Files read/write/append" << endl;
	cout << "--------------------------------------------" << endl;
	
} // end of projectStart()
