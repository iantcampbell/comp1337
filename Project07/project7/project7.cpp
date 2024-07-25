/* 
-------------------------------------------------------------------------
Name:     		Ian Campbell
Date: 			July 14th, 2024
Project #:		7
Status: 		WIP
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives
Write a class called Date that stores int of day, month, year
validate inputs
output date in different formats
-------------------------------------------------------------------------
*/

// Compiler directives Header
#include "header.h"
using namespace std;

// blueprint.. template.. blank form.. class
class Date
{
	private:
		int day = 1; // 1 to 31 (inclusive).
		int month = 1; // 1 to 12 (inclusive).
		int year = 2020; // 1900 to 2022 (inclusive).
		
		int getYear();
		int getMonth();
		int getDay();
		bool checkLeapYear();
		string getMonthName();
		int getMaxDay();
		
		
	public:
		// setting the private data members .. setters
		void setDate() // sets date by getting values from user
		{
			year = getYear();
			month = getMonth();
			day = getDay();
		}
		
		// print specific format of values stored
		void printFormatOne() 
		{
			cout << month << "/" << day << "/" << year;
		}
		
		void printFormatTwo()
		{
			string monthName;
			monthName = getMonthName();
			cout << monthName << " " << day << ", " << year;
		}
		
		void printFormatThree()
		{
			string monthName;
			monthName = getMonthName();
			cout << day << " " << monthName << " " << year;
		}
		
		// return date string in different formats, better approach
		string returnFormatOne() 
		{
			string formattedDate;
			formattedDate = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
			return formattedDate;
		}
		
		string returnFormatTwo()
		{
			string monthName;
			string formattedDate;
			monthName = getMonthName();
			formattedDate = monthName + " " + to_string(day) + ", " + to_string(year);
			return formattedDate;
		}
		
		string returnFormatThree()
		{
			string monthName;
			monthName = getMonthName();
			string formattedDate;
			formattedDate = to_string(day) + " " + monthName + " " + to_string(year);
			return formattedDate;
		}
};


/*
	name: DATE::getYear()
	input: 
	output: int
	process: gets year from user and validates range
	objectives: get year from user
*/
int Date::getYear()
		{
			int value;
			
			while (true)
			{
				value = getIntegerData("Enter the year: ");
				
				if (value >= 1900 && value <= 2022)
				{
					return value;
				}
				
				cout << endl;
				cout << error << "Please enter a year between 1900 and 2022."  << endl;
				cout << endl;
			}
		}
	
	
/*
	name: DATE::getMonth()
	input: 
	output: int
	process: gets month from user and validates range
	objectives: get month from user
*/	
int Date::getMonth()
		{
			int value;
			
			while (true)
			{
				value = getIntegerData("Enter the month: ");
				
				if (value >= 1 && value <= 12)
				{
					return value;
				}
				
				cout << endl;
				cout << error << "Please enter a month between 1 and 12."  << endl;
				cout << endl;
			}
		}	
	
/*
	name: DATE::getDay()
	input: 
	output: int
	process: gets day from user and validates range
	objectives: get day from user
*/	
int Date::getDay()
		{
			int value;
			int maxDay;
			
			maxDay = getMaxDay();
			while (true)
			{
				value = getIntegerData("Enter the day: ");
				
				if (value >=1 && value <= maxDay)
				{
					return value;
				}
				
				cout << endl;
				cout << getMonthName() << " has " << maxDay << " days." << endl;
				cout << "Please enter a day between 1 and " << maxDay << "." << endl;
				cout << endl;
			}
		}

/*
	name: DATE::checkLeapYear()
	input: 
	output: bool true if leap year
	process: validates leap years and returns true if year is one
	objectives: check if year entered is leap year
*/	
bool Date::checkLeapYear()
		{
			if ((year % 4 == 0 && year % 100 !=0 ) || (year % 400 == 0))
			{
				return true;
			}
			else
			{
				return false;
			}
		}	

/*
	name: DATE::getMonthName()
	input: 
	output: string
	process: gets the name of the month entered in string form
	objectives: get string version of month
*/		
string Date::getMonthName()
		{
			string monthNames[13];
			monthNames[0] = "INVALID MONTH";
			monthNames[1] = "January";
			monthNames[2] = "February";
			monthNames[3] = "March";
			monthNames[4] = "April";
			monthNames[5] = "May";
			monthNames[6] = "June";
			monthNames[7] = "July";
			monthNames[8] = "August";
			monthNames[9] = "September";
			monthNames[10] = "October";
			monthNames[11] = "November";
			monthNames[12] = "December";
			return monthNames[month];
		}

/*
	name: DATE::getMaxDay()
	input: 
	output: int
	process: calculates max number of days in the month and returns as int
	objectives: find max number of days in month
*/	
int Date::getMaxDay()
		{
			bool leapYear;
			leapYear = checkLeapYear();
			
			if (leapYear && month == 2)
			{
				return 29;
			}
			
			int monthNames[13];
			monthNames[0] = 0;
			monthNames[1] = 31;
			monthNames[2] = 28;
			monthNames[3] = 31;
			monthNames[4] = 30;
			monthNames[5] = 31;
			monthNames[6] = 30;
			monthNames[7] = 31;
			monthNames[8] = 31;
			monthNames[9] = 30;
			monthNames[10] = 31;
			monthNames[11] = 30;
			monthNames[12] = 31;
			
			return monthNames[month];
		}	
// project prototypes

int main()
{
	projectStart();
	
	Date myDate; // create object
	
	cout << endl;
	cout << "Date Entry" << endl;
	cout << shortDashes << endl;
	
	myDate.setDate(); // gets date from user
	
	
	// prints different date formats
	string formattedDate;
	 
	cout << endl;
	cout << shortDashes << endl;
	cout << "Formatted, date returned as string and printed" << endl;
	cout << shortDashes << endl;
	cout << endl;
	
	cout << "----------DATE----------" << endl;
	formattedDate = myDate.returnFormatOne();
	cout << "\tFormat one:\t" << formattedDate << endl;
	
	formattedDate = myDate.returnFormatTwo();
	cout << "\tFormat two:\t" << formattedDate << endl;
	
	formattedDate = myDate.returnFormatThree();
	cout << "\tFormat three:\t" << formattedDate << endl;
	cout << endl;
    
    
	// prints different date formats 
	cout << endl;
	cout << shortDashes << endl;
	cout << "Formatted, output from function call" << endl;
	cout << shortDashes << endl;
	cout << endl;
	
	cout << "----------DATE----------" << endl;
	cout << "\tFormat one:\t";
	myDate.printFormatOne();
	cout << endl;
	
	cout << "\tFormat two:\t";
	myDate.printFormatTwo();
	cout << endl;
	
	cout << "\tFormat three:\t";
	myDate.printFormatThree();
	cout << endl;
    
    projectEnd();
    return 0;
}// end of main


