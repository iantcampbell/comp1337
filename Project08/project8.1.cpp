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

int main()
{
	// Displays start of project 
	projectStart();
	
	// START YOUR CODING BELOW
	
	int employeeCount = 0;
	Employee myEmployee[100];
	
	// testing variables
	
	
	employeeCount = populateEmployee(myEmployee);
	
	for (int index = 0; index < employeeCount; index++)
	{
		cout << setw(10) << myEmployee[index].getID();
        cout << setw(35) << myEmployee[index].getName();
        cout << setw(10) << myEmployee[index].getPayRate();
        cout << setw(15) << myEmployee[index].getDependents();
        cout << setw(10) << myEmployee[index].getType();
        cout << endl;
	}
	// Displays end of project
	projectEnd();
	
    return 0;
    
}// end of main	

int populateEmployee(Employee myEmployee[])
{
    ifstream fileRead;
    fileRead.open("employee.txt");
    
    cout << endl;
    cout << "FILE OPEN" << endl;
    cout << endl;
    
    int employeeCount = 0;
    int id;
    string sname;
    char name[20];
    float payRate;
    int dependents;
    int type;
    bool validEmployee = true;
    int ctr = 0;
    
	string line;
	
    if (!(fileRead))
    {
        cout << "File does not exist!!" << endl;
    }	
	else
	{
		while (!(fileRead.eof()))
		{
			if (fileRead.eof())
			{
				fileRead.close();
				return employeeCount;
			}
			fileRead >> id;
			fileRead >> sname;
			fileRead >> payRate;
			fileRead >> dependents;
			fileRead >> type;
			
			cout << "ID: " << id << endl;
			cout << "Name: " << name << endl;
			cout << "Pay: " << payRate << endl;
			cout << "Dependents: " << dependents << endl;
			cout << "Type: " << type << endl;
			cout << endl;
			
			//validEmployee = myEmployee[employeeCount].setEmployee(id, name, payRate, dependents, type);
			
			if (validEmployee)
			{
				employeeCount++;
			}
			if (ctr == 5)
			{
				break;
			}
			ctr++;
			
		}
		
		fileRead.close();
		return employeeCount;
	}
}
