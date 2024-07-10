/* 
-------------------------------------------------------------------------
Name:     		Ian Campbell	
Date: 			June 24th, 2024
Project #:		Exam 1 Project
Status: 		Completed
Class:			COSC 1337 (MW)

-------------------------------------------------------------------------
Projct Objectives:

The AllyBaba Calculator is a program designed to help users perform basic math operations including addition, subtraction, multiplication, division, and modulus.
Once an operation is selected, the program randomly generates a math problem.
Once an you are done solving problems and exit the program it gives you a summary of your score.

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
char getMenuSelection(string);
void mainMenu();
void createRandomNumbers(int&, int&, int&);
void createEquation(char, int, int, int, int&);
void grade(int, int, int&, int&);
void summary(int, int, string);

int main()
{
	// Displays start of project 
	projectStart();
	
	// write your code below
	
	// Variable Declarations
	bool loopMenu = true; // return to main menu while true
	char menuSelection;
	string name;
	int a;
	int b;
	int c;
	int correctAnswer;
	int answer;
	bool correct;
	int correctCounter = 0;
	int questionCounter = 0;
	
	// Get students name
	cout << endl;
	name = getStringData("Enter student name: ");
	cout << endl;
	cout << endl;
	
	// Main Menu
	while (loopMenu) // Menu
	{
		mainMenu();
		menuSelection = getMenuSelection("\t\tEnter your selection: ");
		
		if (menuSelection == 'E') // exit
		{
			loopMenu = false;
		} // end of exit if
		else // give question
		{
			createRandomNumbers(a, b, c);
			createEquation(menuSelection, a, b, c, correctAnswer);
			answer = getIntegerData("\tEnter the answer:\t");
			grade(answer, correctAnswer, questionCounter, correctCounter);
		} // end of question if
		
	} // end of while(loopMenu)
	
	// Display final summary
	summary(questionCounter, correctCounter, name);
	
		
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main

/*
	name: 	mainMenu()
	input: 	parameter(arguments): none
	output: 
	process: display
	objectives: display
*/
void mainMenu()
{
	cout << "Arithmetic Quiz" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "\t+\tAddition" << endl;
	cout << "\t-\tSubtraction" << endl;
	cout << "\t*\tMultiplication" << endl;
	cout << "\t/\tDivision" << endl;
	cout << "\t%\tModulus" << endl;
	cout << "\tE\tExit" << endl;
	cout << "--------------------------------------------" << endl;

} // end of mainMenu()


/*
	name: 	getMenuSelection()
	input: 	parameter(arguments): string
	output: returns char
	process: get input and confirm it's valid
	objectives: confirms char value is a valid menu choice
*/
char getMenuSelection(string prompt)
{
	char value; 
	
	while (true) 
	{	
		value = getCharData(prompt);
		
		if (value == '+' || value == '-' || value == '*' || value == '/' || value == '%' || value == 'E') // valid value check
		{
			return value;
		} // end of valid value check
		cout << "\t\tERR message! Not a recognized menu option: Enter +, -, *, /, %, or E" << endl;
	} // end of while true
}


/*
	name: 	createRandomNumbers()
	input: 	parameter(arguments): ints&, int&, int&
	output: returns 3 random ints in the form of reference variables
	process: srand/rand to generate random numbers 1-20
	objectives: generate 3 random numbers
*/
void createRandomNumbers(int& a, int&b, int&c)
{ 
	cout << endl;
	srand(time(0));
	a = rand() % 20 + 1;
	b = rand() % 20 + 1;
	c = rand() % 20 + 1;  
}


/*
	name: 	createEquation()
	input: 	parameter(arguments): char, int, int, int, int&
	output: returns correct answer as reference variable
	process: generates equation based on menu selection and 3 ints
	objectives: generate equation and save correct answer
*/
void createEquation(char menuSelection, int a, int b, int c, int& correctAnswer)
{ 
		if (menuSelection == '+')
		{
			cout << "\tOperation:\tAddition" << endl;
			cout << endl;
			cout << "\tExpression:\t" << a << " + " << b << " + " << c << endl;
			correctAnswer = a + b + c;
			cout << "\tAnswer:\t" << correctAnswer << endl;
		} // end of addition
		else if (menuSelection == '-')
		{
			cout << "\tOperation:\tSubtraction" << endl;
			cout << endl;
			cout << "\tExpression:\t" << a << " - " << b << " - " << c << endl;
			correctAnswer = a - b - c;
			cout << "\tAnswer:\t" << correctAnswer << endl;
		} // end of subtraction
		else if (menuSelection == '*')
		{
			cout << "\tOperation:\tMultiplication" << endl;
			cout << "\tExpression:\t" << a << " * " << b << " * " << c << endl;	
			correctAnswer = a * b * c;
			cout << "\tAnswer:\t" << correctAnswer << endl;
		} // end of multiplication
		else if (menuSelection == '/')
		{
			cout << "\tOperation:\tDivision" << endl;
			cout << "\tExpression:\t" << a << " / " << b << " / " << c << endl;
			correctAnswer = a / b / c;
			cout << "\tAnswer:\t" << correctAnswer << endl;
		} // end of division (Division answer is almost always 0 because of ints? seems intended but not useful based on program description)
		else
		{
			cout << "\tOperation:\tModulus" << endl;
			cout << "\tExpression:\t" << a << " % " << b << " % " << c << endl;
			correctAnswer = a % b % c;
			cout << "\tAnswer:\t" << correctAnswer << endl;
		} // end of modulus
}

/*
	name: 	grade()
	input: 	parameter(arguments): int, int, int&, int&
	output: updates reference variable counters
	process: compares users answer to correct, updates counters
	objectives: grade users answer against correct and track totals
*/
void grade(int answer, int correctAnswer, int& questionCounter, int& correctCounter)
{
	cout << endl;
	questionCounter++;
	
	if (answer == correctAnswer)
	{
		correctCounter++;
		cout << "\tAnswer:\tGreat! You are correct." << endl;
	}
	else
	{
		cout << "\tAnswer:\tSorry! You are incorrect" << endl;
		cout << "\t\tIt should be " << correctAnswer << endl;
	}
	cout << endl;
	cout << "--------------------------------------------" << endl;
}

/*
	name: 	grade()
	input: 	parameter(arguments): int, int, string
	output: none
	process: calculates final percent correct and outputs summary
	objectives: display summary
*/
void summary(int questionCounter, int correctCounter, string name)
{
	cout << endl;
	float percent;
	float total = questionCounter;
	float correct = correctCounter;
	percent = correct / total * 100;
	
	cout << "--------------------------------------------" << endl;
	cout << "\tQuiz Summary" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "\tStudnet Name: \t\t\t" << name << endl;
	cout << "\t\tNumber of Quiz:\t\t" << questionCounter << endl;
	cout << "\t\tPassing Percentage:\t" << round(percent) << "%" << endl;
	cout << "--------------------------------------------" << endl;
}

// This function will get a char value from the user
char getCharData(string prompt)
{
	char value;
	
	while (true)
	{
		cout << prompt;
		cin >> value;
	
		value = toupper(value);
		
		cin.clear(); // clear error buffer
		cin.ignore(120, '\n');  // clear upto 120 chars or it reaches an enter
		return value;

	}	

} // end of getCharData

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
	string name;
	cout << "-------------------------------------------------"  << endl;
	cout << "AllyBaba Arithmetic Calculator " << endl;
	cout << "Written by: Ian Campbell" << endl;
	cout << "Date: June 24th, 2024" << endl;
	cout << "-------------------------------------------------"  << endl;
	cout << "Arithmetic Quiz" << endl;
	cout << "-------------------------------------------------"  << endl;
	cout << "Project Objectives" << endl;
	cout << endl;
	cout << "\tThe AllyBaba Calculator is a program designed to help users perform basic math operations" << endl;
	cout << "\tincluding addition, subtraction, multiplication, division, and modulus." << endl;
	cout << endl;
	cout << "\tOnce an operation is selected, the program randomly generates a math problem." << endl;
	cout << endl;
	cout << "\tOnce an you are done solving problems and exit the program it gives you a summary of your score." << endl;
	cout << "-------------------------------------------------"  << endl;

} // end of projectStart()

// The function will display the end of the project 
void projectEnd()
{
	cout << "-------------------------------------------------"  << endl;
	cout << "\tEnd of Exam 1 Project" << endl;
	cout << "-------------------------------------------------"  << endl;
} // end of projectEnd()


