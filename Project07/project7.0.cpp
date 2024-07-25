/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		7
Status: 		WIP
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives

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
		
		void setDate()
		{
			year = getYear();
			month = getMonth();
			day = getDay();
		}
		
		// get the values stired in the private members... getters
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
};

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
				
				cout << error << "Please enter a year between 1900 and 2022."  << endl;
			}
		}
		
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
				
				cout << error << "Please enter a month between 1 and 12."  << endl;
			}
		}	
		
int Date::getDay()
		{
			int value;
			int maxDay;
			
			maxDay = getMaxDay();
			while (true)
			{
				value = getIntegerData("Enter the day: ");
				
				if (value >=1 && value <= maxDay)
				
				if (value >= 1 && value <= 28) // any day 1-28 always valid
				{
					return value;
				}
				else if (month == 1 || 3 || 5 || 7 || 8 || 10 || 12) // 31 day month
				{
					if (value <=31)
					{
						return value;	
					}
					cout << error << "Please enter a day between 1 and 31." << endl; // invalid entry on 31 day month
				}
				else if (month == 4 || 6 || 9 || 11) // 30 day month
				{
					if (value <=30)
					{
						return value;	
					}
					cout << error << "Please enter a day between 1 and 30." << endl; // invalid entry on 30 day month
				}
				else if (leapYear)// if leap year
				{
					if (value == 29) // if input is 29
					{
						return value;
					}
					else
					{
						cout << error << "Please enter a day between 1 and 29." << endl; // invalid entry on feb leap year
					}
				}
				else
				{
					cout << error << "Please enter a day between 1 and 28" << endl; // invalid entry on feb non leap year
				}
			}
		}
	
	
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
	Date myDate;
	cout << shortDashes << endl;
	cout << "Date Entry" << endl;
	cout << shortDashes << endl;
	myDate.setDate();
	
	cout << endl;
	cout << shortDashes << endl;
	cout << "Formatted" << endl;
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
    return 0;
    
}// end of main


