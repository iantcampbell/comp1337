/* 
-------------------------------------------------------------------------
Name:     		Ian Campbell
Date: 			July 20, 2024
Project #:		8
Status: 		Completed
Class:			COSC 1337 (MW)
-------------------------------------------------------------------------
Objectives
Write an object oriented program to load employee data from a file.
Then output a file with weekly payroll data from a separate file of hours worked.
Pay attention to input validation, error handling, and format.
-------------------------------------------------------------------------
*/

#include "header.h"


class Employee
{
	private:
		int id;
		char name[25];
		float payRate; // per hour
		int dependents;
		int type;
		
	public:
		
		// initialize
		Employee()
		{
			id = 0;
			name[0] = '\0';
			payRate = 0;
			dependents = 0;
			type = 0;
		}
		
		// setters
		setEmployee(int setID, char* setName, float setPayRate, int setDependents, int setType)
		{
			bool validEmployee;
			validEmployee = false;
			
			if (setID > 0 && strlen(setName) > 0 && setPayRate >= 0 && setDependents >= 0 && (setType == 0 || setType == 1))
			{
				id = setID;
				strcpy(name, setName);
				payRate = setPayRate;
				dependents = setDependents;
				type = setType;
				
				validEmployee = true;
			}
			
			return validEmployee; // returns true if employee data was valid
		}
		
		// getters
		int getID()
		{
			return id;
		}
		
		char* getName()
		{
			return name;
		}
		
		float getPayRate()
		{
			return payRate;
		}
		
		int getDependents()
		{
			return dependents;
		}
		
		int getType()
		{
			return type;
		}
};

int loadEmployeeFile(Employee*);
void processTransactionFile(Employee*, int);
int getIndex(Employee*, int, int);
float getGrossPay(Employee*, int, float);
float getInsurance(Employee*, int);
string getName(Employee*, int);

int main()
{
	
	
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	int employeeCount;
	Employee *myEmployee; // pointer of a struct
	myEmployee = new Employee[100];
	
	employeeCount = loadEmployeeFile(myEmployee); // build employee data array and returns count of employees
	
	if (employeeCount > 0) // employee array exists
	{
		processTransactionFile(myEmployee, employeeCount); // processes transaction file building payroll file 
	}
	else // bad employee file
	{
		cout << "Invalid employee file" << endl;
	}
	
	return 0;
} // end of main

/*
	name: loadEmployeeFile
	input: Student Employee*
	output: int
	process: process employee file keeping track of valid and invalid employee data
	objectives: build employee array from file
*/
int loadEmployeeFile(Employee* myEmployee)
{
	//variables
	int id;
	char name[20];
	float payRate;
	int dependents;
	int type;
	
	bool validEmployee;
	validEmployee = false;
	int employeeCounter = 0;
	int lineCounter = 0;
	
	ifstream fileRead;
    fileRead.open("employee.txt");
    
    if (!(fileRead)) // invalid file
    {
    	cout << "CRITICAL ERROR: Failure Reading employee.txt in populateEmployee()" << endl;
        return 0;
    } // end of invalid file
    else // valid file
    {
    	cout << endl;
		cout << "Reading employee.txt" << endl;
		cout << endl;
		
		// CAUSING INFINITE LOOP
		while (!(fileRead.eof())) // read to end of file 
		{
			lineCounter++;
			
			// get strings using tab and end line delimiters
			fileRead >> id; // reading an int
			fileRead.ignore('\t');
			fileRead.getline(name, 20, '\t'); // reading a char[]
			
			fileRead >> payRate; // reading a float
			fileRead >> dependents; // reading an int
			fileRead >> type; // reading a int
			if (fileRead.eof())
            {
                break;
            }
			//load employee
			validEmployee = myEmployee -> setEmployee(id, name, payRate, dependents, type);
			
			if (validEmployee) // if employee load was valid
			{
				employeeCounter++;
				myEmployee++;
			}
			else // if employee load was invalid
			{
				cout << "ERROR: Invalid employee in employee.txt on line: " << lineCounter << endl;;
			}
		}// end of read file
		
		cout << "Loaded " << employeeCounter << " of " << lineCounter << " employee records from employee.txt" << endl;
		cout << endl;
		fileRead.close();
		return employeeCounter;
	} // end of valid file
} // end of loadEmployeeFile()

/*
	name: processTransactionFile
	input: Employee*, int
	output: none
	process: iterates transaction file building payroll output file
	objectives: process transaction file into payroll file
*/
void processTransactionFile(Employee* myEmployee, int employeeCount)
{
	
	// variables
	int id;
	float hoursWorked;
	float tax;
	float insurance;
	float grossPay;
	float netPay;
	string name;
	
	float totalGross;
	float totalNet;
	
	int index; // used to jump to correct employee record for ID
	
	int transactionCounter = 0;
	int lineCounter = 0;
	
	// open transaction file
	ifstream fileRead;
    fileRead.open("transaction.txt");
    
    // build payroll file
	ofstream payrollWrite;
	payrollWrite.open("payrollReport.txt"); //opens report file to write
	
	payrollWrite << "payrollReport.txt" << endl;
	payrollWrite << endl;
	payrollWrite << dashes << endl;
	payrollWrite << "Monthly Payroll Report" << endl;
	payrollWrite << dashes << endl;
	
	payrollWrite << setw(10) << "ID";
    payrollWrite << setw(25) << "Name";
    payrollWrite << setw(15) << "Tax ($)";
    payrollWrite << setw(15) << "Insurance ($)";
    payrollWrite << setw(15) << "Gross Pay ($)";
    payrollWrite << setw(15) << "Net Pay ($)";
    payrollWrite << endl;
    payrollWrite << endl;
    
    if (!(fileRead)) // bad transaction file
    {
    	cout << "CRITICAL ERROR: Failure Reading transaction.exe in processTransactionFile()" << endl;
    }
    else // process transaction file
    {
    	cout << dashes << endl;
    	cout << endl;
    	cout << "Reading transaction.exe" << endl;
    	cout << endl;
    	
    	while (!(fileRead.eof())) // read transaction file
    	{
			lineCounter++;
			
			fileRead >> id;
			fileRead >> hoursWorked;
			
			index = getIndex(myEmployee, id, employeeCount);
			
			if (index >= 0 && hoursWorked > 0) // found ID in Employee array
			{
				
				grossPay = getGrossPay(myEmployee, index, hoursWorked);
				insurance = getInsurance(myEmployee, index);
				tax = grossPay * 0.15;
				netPay = grossPay - tax - insurance;
				name = getName(myEmployee, index);
				totalGross += grossPay;
				totalNet += netPay;
				
				// line data for table
				payrollWrite << setw(10) << id;
   	     		payrollWrite << setw(25) << name;
        		payrollWrite << fixed << setprecision(2) << setw(15) << tax;
        		payrollWrite << fixed << setprecision(2) << setw(15) << insurance;
        		payrollWrite << fixed << setprecision(2) << setw(15) << grossPay;
        		payrollWrite << fixed << setprecision(2) << setw(15) << netPay;
        		payrollWrite << endl;
        		
        		transactionCounter++;
			} // end of if index >= 0
			else // invalid employee id
			{
				cout << "ERROR: Couldn't process transaction in processTransactionFile() on line " << lineCounter << endl;
			} // end of invalid employee id
		} // end of read transaction file
		
		// summary
		payrollWrite << dashes << endl;
		payrollWrite << "Payroll transactions processed: " << transactionCounter << endl;
		payrollWrite << "Total Gross Pay: $" << totalGross << endl;
		payrollWrite << "Total Net Pay: $" << totalNet << endl;
		cout << endl;
		cout << "Processed " << transactionCounter << " of " << lineCounter << " payroll transactions from transactions.txt" << endl;
	}
	
	payrollWrite.close();
	fileRead.close();
} // end of processTransactionFile()

/*
	name: getIndex()
	input: Employee*, int, int
	output: int
	process: loop employee array until ID found and return index
	objectives: finds index of employee ID 
*/
int getIndex(Employee* myEmployee, int id, int employeeCount)
{
	for (int index; index < employeeCount; index++)
	{
		if (myEmployee -> getID() == id)
		{
			return index;
		}
		myEmployee++;
	}
	return -1;
} // end of getIndex()

/*
	name: getGrossPay()
	input: Employee*, int, float
	output: float
	process: calculates pay for an employee from the array data and hours worked 
	objectives: get gross pay
*/
float getGrossPay(Employee* myEmployee, int index, float hoursWorked)
{
	float grossPay;
	int type;
	int payRate;
	
	myEmployee += index;
	type = myEmployee -> getType();
	payRate = myEmployee -> getPayRate();
	
	if (type == 0) // overtime union pay 
	{
		if (hoursWorked <= 40)
		{
			grossPay = hoursWorked * payRate;
		}
		else
		{
			grossPay = 40 * payRate + (hoursWorked - 40) * payRate;
		}
	}
	else // fixed pay
	{
		grossPay = hoursWorked * payRate;
	}
	
	return grossPay;
} // end of getGrossPay()

/*
	name: getInsurance()
	input: Employee*, int
	output: float
	process: calculate insurance cost from employee array info
	objectives: get insurance cost
*/
float getInsurance(Employee* myEmployee, int index)
{
	float insurance;
	int dependents; 
	
	myEmployee += index;
	dependents = myEmployee -> getDependents();
	insurance = 30 * dependents;
	return insurance;
} // end of getInsurance()

/*
	name: getName()
	input: Employee*, int
	output: string
	process: gets name from employee array
	objectives: get name for output file
*/
string getName(Employee* myEmployee, int index)
{
	string name;
	myEmployee += index;
	name = myEmployee -> getName();
	return name;
} // end of getName()