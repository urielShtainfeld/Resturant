#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>

class Employee
{
public:
	static long idCounter;
	const static int MAX_NAME_SIZE = 20;

protected:
	char name[MAX_NAME_SIZE];
	int seniority;
	long bankAccountID;
	int salary;
	long employeeID;	

/*	The Copy constructor is beeing used in main, so private modifier commented out. 
*	Shallow copy is enough in my opinion.	*/
//private:
//	Employee(const Employee& other);

public:	
	Employee(const char* name = "", int seniority = 0, long bankAccountID = 0, int salary = 500);	
	virtual ~Employee();	

	// Getters
	const char* getName() const { return name; }
	int getSeniority() const { return seniority; }
	long getBankAccountID() const { return bankAccountID; }
	int getSalary() const { return salary; }
	long getEmployeeID() const { return employeeID; }

	// Setters
	void setName(const char* name);
	void setSeniority(int seniority) { this->seniority = seniority; }
	void setBankAccountID(int bankAccountID) { this->bankAccountID = bankAccountID; }
	void setSalary(int salary) { this->salary = salary; }

	// Methods
	void quit() const;
	const Employee& Employee::operator=(const Employee& other);
};


#endif // __EMPLOYEE_H

