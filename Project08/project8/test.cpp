/*
    Ally Baba
    Assignment Number: Class work#220
    File Name:         220CWBasic.cpp
    Course/Section:    COSC 1337 Section <mW>
    completeed Date    July 2024
    Instructor:        Baab Ally
--------------------------------------------------------
Project Objectives:
create employee database
employeeID (int)- must be larger than 0>> name >> wage >> dependent(int =0+) >> type(0 for hrly 1 for mgmt)

*/

// Compiler directives Header
#include "header.h"
using namespace std;

class Employee
{
private:
    int employeeID;
    string name;
    float wage;
    int dependent;
    int type;

    //derived
    float grossPay;
    // insurance
    // tax
    // net pay

public:
    Employee() // default
    {
        employeeID = 0;
        name = "";
        wage = 0;
        dependent = 0;
        type = 0;
        
        // default to 0 for the derived data
        grossPay = 0;
    }

    // setters
    bool setData(int eEmployeeID, string eName, float eWage, int eDependent, int eType)
    {
        bool flag;
        flag = false;

        if (eName.size() > 0 && eWage >= 0 && (eType == 0 || eType == 1) && eEmployeeID > 0 && eDependent >= 0)
        {
            employeeID = eEmployeeID;
            name = eName;
            wage = eWage;
            dependent = eDependent;
            type = eType;

            flag = true;
        }
        return flag;
    }

    void setDependentData(float eHoursWorked)
    {

        grossPay = findGrossPay(eHoursWorked);
        // assign values to derived using a method
    }

    // getters
    int getEmployeeID()
    {
        return employeeID;
    }
    string getName()
    {
        return name;
    }
    float getWage()
    {
        return wage;
    }
    int getDependent()
    {
        return dependent;
    }
    int getType()
    {
        return type;
    }
    float getGrossPay()
    {
        return grossPay;
    }
    // new getters
    

    // methods
    float findGrossPay(float hoursWorked)
    {
        float grossPay;
        if (type == 1)
        {
            grossPay = wage * hoursWorked;
        }
        else
        {
            if (hoursWorked <= 40)
            {
                grossPay = wage * hoursWorked;
            }
            else
            {
                grossPay = 40 * wage + (hoursWorked - 40) * wage * 1.5;
            }
        }
         return grossPay;
    }
    // more methdios to find insyrance pay, tax pay, net pay
};

void populateEmployee(int &, Employee[]);
void displayEmployee(int, Employee[]);
void writeEmployee(int, Employee[]);
void calculateGrossPay(int , Employee []);

// project prototype

int main()
{
    cout << fixed << setprecision(2);

    // Start of Project
    projectStart(); // calling the function
    
    // preread the file and see hoew many employees in the file
    // dynamically created the array

    Employee myEmployee[25]; // created object for 25 employees

    int employeeCount;

    employeeCount = 0;

    populateEmployee(employeeCount, myEmployee);

    if (employeeCount == 0)
    {
        cout << "Nobody Works!" << endl;
        return 0;
    }

    cout << "\tNumber of Employees: " << employeeCount << endl;

    //writeEmployee(employeeCount, myEmployee);

    calculateGrossPay(employeeCount, myEmployee);
    
    displayEmployee(employeeCount, myEmployee);
    writeEmployee(employeeCount, myEmployee);

    // End of Project
    projectEnd();

    return 0;

} // end of main()

void calculateGrossPay(int employeeCount, Employee myEmployee[])
{
	// read the transaction file which has the id and hoursworked
	// id not found.. write to a error file
	// hrs are negative, write to the error file
	
    int hoursWorked;
    int employeeID;
    bool flag;
    flag = false;

    employeeID = getIntegerData("\tEnter Employee ID: ");
    
    for (int ctr=0; ctr < employeeCount; ctr++)
    {
        if (employeeID == myEmployee[ctr].getEmployeeID())
        {
            cout << "\tEmployee Found " << employeeID << endl;
            hoursWorked = getFloatData("\tEnter How Many Hours Worked: ");
            myEmployee[ctr].setDependentData(hoursWorked);
            cout << "\tTotal Wages: " << myEmployee[ctr].getGrossPay() << endl;

            flag = true;
        }
    }
    if (!(flag))
    {
        cout << "\tEmployee Does Not Exist" << endl;
    }



}

void displayEmployee(int employeeCount, Employee myEmployee[])
{
    cout << dashes << endl;
    cout << setw(10) << "ID";
    cout << setw(35) << "Name";
    cout << setw(10) << "Wage";
    cout << setw(15) << "Dependent";
    cout << setw(10) << "Type";
    cout << setw(10) << "Gpay";
    cout << endl;
    cout << dashes << endl;

    for (int ctr = 0; ctr < employeeCount; ctr++)
    {
        cout << setw(10) << myEmployee[ctr].getEmployeeID();
        cout << setw(35) << myEmployee[ctr].getName();
        cout << setw(10) << myEmployee[ctr].getWage();
        cout << setw(15) << myEmployee[ctr].getDependent();
        cout << setw(10) << myEmployee[ctr].getType();
        cout << setw(10) << myEmployee[ctr].getGrossPay();
        cout << endl;
    }
    cout << dashes << endl;
}

// for writing in file
void writeEmployee(int employeeCount, Employee myEmployee[])
{
    ofstream fileWrite;
    fileWrite.open("payroll.txt");
    fileWrite << dashes << endl;
    fileWrite << setw(10) << "ID";
    fileWrite << setw(35) << "Name";
    fileWrite << setw(10) << "Wage";
    fileWrite << setw(15) << "Dependent";
    fileWrite << setw(10) << "Type";
    fileWrite << endl;
    fileWrite << dashes << endl;

    for (int ctr = 0; ctr < employeeCount; ctr++)
    {
        fileWrite << setw(10) << myEmployee[ctr].getEmployeeID();
        fileWrite << setw(35) << myEmployee[ctr].getName();
        fileWrite << setw(10) << myEmployee[ctr].getWage();
        fileWrite << setw(15) << myEmployee[ctr].getDependent();
        fileWrite << setw(10) << myEmployee[ctr].getType();
        fileWrite << setw(10) << myEmployee[ctr].getGrossPay();
        fileWrite << endl;
    }
    fileWrite << dashes << endl;

    fileWrite.close();
}

// read the file and display the file
void populateEmployee(int &employeeCount, Employee myEmployee[])
{
    ifstream fileRead;
    fileRead.open("employee.txt");
    int employeeID;
    string name;
    float wage;
    int dependent;
    int type;
    bool flag;
    flag = false;
    
    if (!(fileRead))
    {
        cout << "File does not exist!!" << endl;
    }
    else
    {
        while (!(fileRead.eof()))
        {
            fileRead >> employeeID;
            getline(fileRead, name, '\t'); // reading strings with spaces, comma seperates the name and the next variable
            if (fileRead.eof())
            {
                break;
            }
            fileRead >> wage;      // reading a float
            fileRead >> dependent; // reading an int
            fileRead >> type;      // reading a type/int

            flag = myEmployee[employeeCount].setData(employeeID, name, wage, dependent, type);
            if (flag)
            {

                employeeCount = employeeCount + 1;
            }
        }
        fileRead.close();
    }
}

// project load the items and price from the txtx file
