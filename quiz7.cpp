
#include <iostream>             // for cin, cout, endl
#include <fstream>				// file reading/writing/appending
#include <string>				// string manipulation
using namespace std;

bool loopArray(int, int[10]);

int main()
{
	bool winner;
	int winningNumber = 23455;
	
	int luckyNumbers[10];
	luckyNumbers[0] = 13454;
	luckyNumbers[1] = 23455;
	luckyNumbers[2] = 34567;
	luckyNumbers[3] = 44456;
	luckyNumbers[4] = 34344;
	luckyNumbers[5] = 44444;
	luckyNumbers[6] = 22445;
	luckyNumbers[7] = 34532;
	luckyNumbers[8] = 44555;
	luckyNumbers[9] = 23444;
	
	winner = loopArray(winningNumber, luckyNumbers);
	cout << winner << endl;
}

bool loopArray(int winningNumber, int luckyNumbers[10])
{
	for (int index = 0; index < 10; index++)
	{
		if (winningNumber == luckyNumbers[index])
		{
			return true;
		}
	}
	return false;
}

int getIntegerData(string prompt)
{
	int value;
	
	while (true)
	{
		cout << prompt;
		while (!(cin >> value))
		{
			cin.clear(); // clear error buffer
			cin.ignore(120, '\n');  // c;lear upto 120 chars or it reaches an enter
			cout << prompt;
		} // 	while (!(cin >> value))
		if (value >= 0)
		{
			return value;
		}	
	} // end of while (true)
} // end of int getIntegerData()