using namespace std;
#include <fstream>
#include <iostream> 
#include <stdlib.h> 
#include <ctime>

int getResults();
int getResultsUserInts();
float getResultsEquation(int, int, int);
int getResultsTextFile();
int getIntegerData(string);
int main()
{
	srand(time(0));
	int value;
	value = getResults();
	cout << value;
}

int getResults()
{ 
	srand(time(0));
	int randomNumber = rand() % 10 + 1;
    return randomNumber;  
}

int getResultsUserInts()
{
	int userInteger;
	int oddIntegerCounter=0;
	
	userInteger = getIntegerData("Enter an integer: ");
	while (userInteger != -999)
	{
		if (userInteger%2 == 0)
		{
			oddIntegerCounter++;
		} // end of if
		
		userInteger = getIntegerData("Enter an integer: ");
		
	} // end of while
	
	return oddIntegerCounter;
}

// This function will return a integer value from the user
int getIntegerData(string prompt)
{
	float input;
	int value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> input)) // numeric check
		{
			cout << "\t\tError Message. Non numeric was entered"  << endl;
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
			cout << prompt;
		} // end of numeric check
		
		value = input;
			
		if (value-input != 0)
		{
			cout << "\t\tError Message: Non Integer was entered" << endl;;
		} // end of float check
		else
		{
			return value;
		} // end of else

	} // end of while (true)
} // end of int getFloatData()



float getResults(int a, int b, int c)
{
	return 3*((14*a*b)-(2*a*c))+(15*a*b*c);
}

int getResultsTextFile()
{
	int value;
	int total;
	ifstream readFile;
	
	readFile.open("data.txt");

	while (readFile >> value)
	{
		total = total + value;
	}
	return total;
}
