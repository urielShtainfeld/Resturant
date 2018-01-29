#ifndef __STAFF_MAMAGER_H
#define __STAFF_MAMAGER_H

#include <vector>
#include <iostream>
#include <iterator>
#include "Employee.h"
#include "Waiter.h"
#include "Butchery.h"


class StaffManager
{
private:
	vector<Employee*> *employees;
	int logicalSizeEmployees;
	int physicalSizeEmployees;
	
	/*	Copy constructor needed	*/
//StaffManager(const StaffManager& other); // Why hidden ??

public:	
	StaffManager(vector<Employee*> *employees = nullptr, int sizeEmployees = 0);
	StaffManager(const StaffManager& other);
	virtual ~StaffManager() { /*delete []employees;*/ }

	// Getters
	const vector<Employee*>* getAllEmployees() const { return employees; }
	int getSizeEmployees() const { return logicalSizeEmployees; }
//	const Employee& getEmployeeByEmployeeId(long employeeId) const; //Why two declarations with same signature ??
	Employee& getEmployeeByEmployeeId(long employeeId);

	// Methods
	void employ(const Employee*& employee);
	void fire(const Employee*& employee);
	void ShoutOnEmployees() const;
};

#endif // __STAFF_MAMAGER_H

