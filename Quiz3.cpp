using namespace std;
#include <iostream>

void getView();
void getViewInt();
void getViewCount();
char getStringData(string);
int getIntegerData(string);

int main()
{
	getIntegerData("Enter a number ");
	//getStringData("Enter A, B, or C: ");
	//getView();
	//getViewCount();
	//getViewInt();
	
}// end of main

// This function will get a float value from the user
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
		else if (value < 1 || value >= 10) // range check
		{
			cout << "\t\tError Message: Outside valid range" << endl;	
		} // end of range check
		else
		{
			return value;
		} // end of else

	} // end of while (true)
} // end of int getFloatData()



char getStringData(string prompt)
{
	char value;
	
	while (true)
	{
		cout << prompt;
		cin >> value;
	
		value = toupper(value);

		if (value == 'A' || value == 'B' || value == 'C')
		{
			return value;	
		}
		cout << "\t\tERR message! Not a recognized option: Enter A, B, C" << endl;
	}	
} // end of getStringData()


void getView()
{
	int counter = 1;
	
	while (counter < 51)
	{
		if (counter%3==0 && counter%5==0)
		{
			cout << counter << endl;
		} // end of if
		
		counter++;
		
	} // end of while
} // end of getView()

void getViewInt()
{
	for (int counter = 1; counter < 51; counter++)
	{
		if (counter%3==0 && counter%5==0)
		{
			cout << counter << endl;
		}		
	}

}

void getViewCount()
{
	int count = 0;
	
	for (int counter = 1; counter < 51; counter++)
	{
		if (counter%3==0 && counter%5==0)
		{
			count++;
		}		
	}
	
	cout << count;

}

