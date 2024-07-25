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

int main()
{
    int value;  // integer
    int *ptr; // * stores the address of the value it is pointing to
    
    ptr = &value;
    
    value = 200;
    
    cout << " answer 1" << value << endl;
    cout << "  answer 2 " << & value << endl;
    
    cout << "  answer 3 " << ptr << endl;
    cout << "  answer 4" << *ptr << endl;
    cout << "  answer 5" << &ptr << endl;
    
   return 0;   
   
}// end of main()