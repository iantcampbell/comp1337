#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int getIntegerData(string);
bool myView(int);

int main()
{
	int inputValue;
	bool output;
	
	while (true)
	{
		inputValue = getIntegerData("What is the value? ");
		
		output = myView(inputValue);
		
		cout << "output: " << output << endl;
	}
} // end of main()

bool myView(int numberToEvaluate)
{
	bool returnValue;
	
	returnValue = true;
	if (numberToEvaluate % 3 != 0)
	{
		returnValue = false;
	}
	else if (numberToEvaluate % 3 != 0)
	{
		returnValue = false;
	}
	
	return returnValue;	
	
} // end of myView


int getIntegerData(string prompt)
{
	int value;
	
	cout << prompt;
	cin >> value;
	
	return value;
} // end of getIntegerData()

/**

------- QUESTION 4 --------
float calculateAreaOfSheetrock(float, float);
float getFloatData(string);
	
int main()
{
	float length;
	float width;
	float areaRectangle;
	
	length = getFloatData("Enter the length of the sheetrock: ");
	width = getFloatData("Enter the width of the sheetrock: ");
	
	areaRectangle = length * width;
	cout << fixed << setprecision(2) << areaRectangle << endl;
	
	system("PAUSE"); // pause DOS
	return 0;
} // end of main()

float getFloatData(string prompt)
{
	float value;

	cout << prompt;
	cin >> value;

	return value;

} // end of getFloatData()
/**/

/** 

------- QUESTION 6 --------


int getView(int);

int main()
{
	int number;
	int result;
	
	number = 2;
	result = getView(number);
	
	cout << result;
	
	system("PAUSE"); // pause DOS
	return 0;
}

int getView(int a)
{
	int function;
	
	function = 3*a*(a+4);
	return function;
}

/**/


// void myView(float);

//void myView(float averageGrade)
//{
//	
//    cout << "My average grade is '" << fixed << setprecision(2) << averageGrade << endl;
//
//} // end of getCharData()

/**
int main()
{
	int neutral;
	int base;
	int acidic;
	float rateOfPH;
	
	rateOfPH = 10.2;
	
	if (rateOfPH < 7)
	{
		neutral = 0;
		base = 1;
		acidic = 0
	}
	else if (rateOfPH > 7)
	{
		neutral = 0;
		base = 0;
		acidic = 1;
	}
	else
	{
		neutral = 1;
		base = 0;
		acidic = 0;
	}	
}
/**/



/**

---------- Question 9 -------------

int getIntegerData(string);
void myView(int, int&, int&);

int main()
{
	int adultCount = 0;
	int nonAdultCount = 0;
	int inputAge;
	
	
	while (true)
	{
		inputAge = getIntegerData("What is the persons age? ");
		
		myView(inputAge, adultCount, nonAdultCount);
		
		cout << "Adults: " << adultCount << endl;
		cout << "Childern: " << nonAdultCount << endl;
	}
}

void myView(int age, int& adultCount, int& nonAdultCount)
{
	int adultAge = 21;

	
	if (adultAge < age)
	{
		adultCount++;
	}
	else
	{
		nonAdultCount++;
	}
	
} // end of myView

int getIntegerData(string prompt)
{
int value;

cout << prompt;
cin >> value;

return value;
} // end of getIntegerData()
/**/