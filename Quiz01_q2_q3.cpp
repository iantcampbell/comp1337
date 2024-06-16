#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void calculation(int, int);
//------------------------------------
int main()
{

    //Declare the variable and its data types
    int valueOne;
    int valueTwo;

    // Get the user's entry for length and width'
    valueOne = 1;
    valueTwo = 2;

    // calculation
    calculation(valueOne, valueTwo);

    cout << valueOne<< " and " << valueTwo << endl;
    system("PAUSE"); // optional to pause DOS
    return 0;

}// end of main()

void calculation(int valueOne, int valueTwo)
{
    valueOne = valueOne + valueTwo;
    valueTwo = valueTwo + valueOne;
}// end of calculation

