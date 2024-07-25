/* 
-------------------------------------------------------------------------
Name:     		
Date: 			
Project #:		8
Status: 		WIP
Class:			COSC 1337
-------------------------------------------------------------------------
Objectives

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
		
		// 
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
		
		float getGrossPay(float hoursWorked)
		{
			float grossPay;
			
			if (type == 0) // union
			{
				if (hoursWorked <= 40)
				{
					grossPay = hoursWorked * payRate;
					return grossPay;
				}
				else // overtime
				{
					grossPay = (40 * payRate) + ((hoursWorked-40) * payRate);
					return grossPay;
				}
			}
			else // type == 1
			{
				grossPay = hoursWorked * payRate;
				return grossPay;
			}
		}
};

int populateEmployee(Employee[]);
int verifyID(string, int);
float verifyPayRate(string, int);
int verifyDependents(string, int);
int verifyType(string, int);
void processTransactions(Employee[], int);
float verifyPayRate(string, int);
int getIndex(int, int);
float verifyHoursWorked(string, int);

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	int employeeCount = 0;
	Employee myEmployee[100];
	
	employeeCount = populateEmployee(myEmployee);
	
	cout << endl;
	cout << "Employee Count " << employeeCount << endl;
	cout << endl;
	// testing variables
}

int populateEmployee(Employee myEmployee[])
{
	//variables to load processed input into Employee array
	int id;
	char name[20];
	float payRate;
	int dependents;
	int type;
	
	// variables for file processing/validation
	string line;
	string sID;
	string sName;
	string sPayRate;
	string sDependents;
	string sType;
	
	bool validName;
	bool validEmployee;
	int employeeCounter = 0;
	int lineCounter = 0;
	
	ifstream fileRead;
    fileRead.open("employee.txt");
    
    // start of error report
    ofstream fileWrite;
    fileWrite.open("errorReport.txt"); 
    
    fileWrite << "Error Report" << endl;
    fileWrite << dashes << endl;
    fileWrite << endl;
    
    fileWrite << "The following employees could not be processed." << endl;
    fileWrite << endl;
    
    
    cout << endl;
    cout << "FILE OPEN" << endl;
    cout << endl;
    
    if (!(fileRead))
    {
    	cout << "Failure Reading File in populateEmployee()" << endl;
    	fileWrite << endl;
    	fileWrite << dashes << endl;
    	fileWrite << "CRITICAL ERROR" << endl;
        fileWrite << "Could not find file employee.txt" << endl;
        fileWrite << dashes << endl;
        fileWrite << endl;
        return 0;
    }	
	else
	{
		cout << endl;
		cout << "Reading File in populateEmployee()" << endl;
		cout << endl;
		while (!(fileRead.eof()))
		{
			
			
			validEmployee = false;
			lineCounter++;
			
			getline(fileRead, sID, '\t');
			fileRead.getline(name, 20, '\t');
			getline(fileRead, sPayRate, '\t');
			getline(fileRead, sDependents, '\t');
			getline(fileRead, sType, '\n');
			
			cout << "sID: " << sID << endl;
			cout << "sName: " << sName << endl;
			cout << "sPayRate: " << sPayRate << endl;
			cout << "sDependents: " << sDependents << endl;
			cout << "sType: " << sType << endl;
			cout << endl;
			
			id = verifyID(sID, lineCounter);
			payRate = verifyPayRate(sPayRate, lineCounter);
			dependents = verifyDependents(sDependents, lineCounter);
			type = verifyType(sType, lineCounter);
			
			cout << "id: " << id << endl;
			cout << "name: " << name << endl;
			cout << "payRate: " << payRate << endl;
			cout << "dependents: " << dependents << endl;
			cout << "type: " << type << endl;
			cout << "length: " << strlen(name) << endl;
			
			cout << endl;
			
			validEmployee = myEmployee[employeeCounter].setEmployee(id, name, payRate, dependents, type);
			cout << "validEmployee: " << validEmployee << endl;
			if (validEmployee)
			{
				employeeCounter++;
			}
			else
			{
				fileWrite << "Invalid employee on line: " << lineCounter << endl;;
			}
		}
		
		fileWrite << endl;
		fileWrite << "Successfully loaded " << employeeCounter << " employees." << endl;
		fileWrite << endl;
		fileWrite << endl;
		fileWrite.close();
		fileRead.close();
		
		return employeeCounter;
	}
}

int verifyID(string sID, int lineCount)
{
	int id;
	
	try
	{
		id = stoi(sID);
	}
	catch(...)
	{
		cout << "ID could not convert on line " << lineCount << endl;
		return -1; // returns invalid value
	}
	
	return id;
}

float verifyPayRate(string sPayRate, int lineCount)
{
	float payRate;
	
	try
	{
		payRate = stof(sPayRate);
	}
	catch(...)
	{
		cout << "Pay rate could not convert on line " << lineCount << endl;
		return -1; // returns invalid value
	}
	
	return payRate;
}

int verifyDependents(string sDependents, int lineCount)
{
	int dependents;
	
	try
	{
		dependents = stoi(sDependents);
	}
	catch(...)
	{
		cout << "Dependents could not convert on line " << lineCount << endl;
		return -1; // returns invalid value
	}
	
	return dependents;
}

int verifyType(string sType, int lineCount)
{
	int type;
	
	try
	{
		type = stoi(sType);
	}
	catch(...)
	{
		cout << "Dependents could not convert on line " << lineCount << endl;
		return -1; // returns invalid value
	}
	
	return type;
}

void processTransactions(Employee myEmployee[], int employeeCount)
{
	int id;
	string sID;
	float hoursWorked;
	string sHoursWorked;
	float tax;
	float insurance;
	float grossPay;
	float netPay;
	int index;
	
	bool validTransaction = false;
	int lineCounter = 0;
	
	ifstream fileRead;
    fileRead.open("transaction.txt");
    
    
	ofstream errorWrite;
	ofstream payrollWrite;
	
	errorWrite.open("errorReport.txt"); //opens appending error file
	errorWrite << dashes << endl;
    errorWrite << endl;
    errorWrite << "The following Transactions could not be processed." << endl;
    errorWrite << endl;
	
	payrollWrite.open("payrollReport.txt"); //opens fresh
	payrollWrite << "payrollReport.txt" << endl;
	payrollWrite << endl;
	payrollWrite << dashes << endl;
	payrollWrite << "Monthly Payroll Report" << endl;
	payrollWrite << dashes << endl;
	
	payrollWrite << setw(10) << "ID";
    payrollWrite << setw(25) << "Name";
    payrollWrite << setw(15) << "Tax";
    payrollWrite << setw(15) << "Insurance";
    payrollWrite << setw(15) << "Gross Pay";
    payrollWrite << setw(15) << "Net Pay";
    payrollWrite << endl;
    
	if (!(fileRead))
    {
    	cout << "Failure Reading File in processTransactions()" << endl;
    	errorWrite << endl;
    	errorWrite << dashes << endl;
    	errorWrite << "CRITICAL ERROR" << endl;
        errorWrite << "Could not find file transaction.txt" << endl;
        errorWrite << dashes << endl;
        errorWrite << endl;
    }
	else
	{
		cout << endl;
		cout << "Reading File in processTransactions()" << endl;
		cout << endl;
		
		while (!(fileRead.eof()))
		{
			validTransaction = false;
			lineCounter++;
			
			getline(fileRead, sID, '\t');
			getline(fileRead, sHoursWorked, '\n');
			
			id = verifyID(sID, lineCounter);
			hoursWorked = verifyHoursWorked(sID, lineCounter);
			
			index = getIndex(myEmployee, id, employeeCount);
			
			if (index == -1)
			{
				// couldn't find ID
			}
			else
			{
				grossPay = myEmployee[index].getGrossPay();
				insurance = myEmployee[index].getDependents() * 30;
				tax = grossPay * 0.15;
				netPay = grossPay - insurance - tax;
				
				payrollWrite << setw(10) << id;
   	     		payrollWrite << setw(25) << myEmployee[index].getName();
        		payrollWrite << setw(15) << tax;
        		payrollWrite << setw(15) << insurance;
        		payrollWrite << setw(15) << grossPay;
        		payrollWrite << setw(15) << netPay;
        		payrollWrite << endl;
			}
		}
		
	}
}

float verifyPayRate(string sHoursWorked, int lineCount)
{
	float hoursWorked;
	
	try
	{
		hoursWorked = stof(sHoursWorked);
	}
	catch(...)
	{
		cout << "Hours worked could not convert on line " << lineCount << endl;
		return -1; // returns invalid value
	}
	
	return hoursWorked;
}

int getIndex(Employee* myEmployee, int id, int employeeCount)
{
	for (int index; index < employeeCount, index++)
	{
		if (myEmployee[index].getID == id)
		{
			return index;
		}
	}
	
	return -1; // invalid index, couldn't find ID 
}
