#include <iostream>
using namespace std;


void getView();

int main()
{
	getView();
}

void getView()
{
	float temperature[10];
	
	for (int i=0; i<10; i++)
	{
		temperature[i] = 10.0;
	} // end of for

	for (int i=0; i<10; i++)
	{
		cout << temperature[i] << endl;
	} // end of for
} // end of getView