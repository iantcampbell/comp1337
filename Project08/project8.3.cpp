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
};

int populateEmployee(Employee[]);
int verifyID(string, int);
float verifyPayRate(string, int);
int verifyDependents(string, int);
int verifyType(string, int);

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
    
    cout << endl;
    cout << "FILE OPEN" << endl;
    cout << endl;
    
    if (!(fileRead))
    {
        cout << "File does not exist!!" << endl;
        return 0;
    }	
	else
	{
		cout << "File reading!!" << endl;
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
				cout << "Invalid employee on line " << lineCounter << endl;
			}
		}
		
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