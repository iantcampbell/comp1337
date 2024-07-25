#include <iostream>             // for cin, cout, endl
#include <iomanip>				// setw, setprecision, left/right, fixed
#include <cmath>				// sine, cosine, pow, trunc, round... 
#include <stdlib.h> 			// srand, rand
#include <ctime>				// time
#include <fstream>				// file reading/writing/appending
#include <string>				// string manipulation
#include <cstring>
#include <limits>
using namespace std;

struct House
{
	int houseId;
	string addresss;
	string city;
};

void getIncrease(int[5][7]);

int main()
{
	House *houseList;
	
	houseList -> houseId = 10;
	cout << houseList -> houseId << endl;
	
	houseList++;
	
	houseList -> houseId = 20;
	cout << houseList -> houseId << endl;
}
