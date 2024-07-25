#include "header.h"
using namespace std;

// Decleration of prototype 
int createRandomNumbers(int);

int main()
{
	srand(time(0));
	int number;
	
	for (int ctr = 0; ctr < 20; ctr++)
	{
		
		number = createRandomNumbers(20);
		cout << number << endl;
	}
	
	return 0;
}


int createRandomNumbers(int wordCount)
{ 
	int random;
	random = rand() % wordCount + 1; 
	return random;
}