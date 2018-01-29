#include "StaffManager.h"

using namespace std;

void copyEmployeeUtil(vector<Employee*> *destList, vector<Employee*> *srcList);

//	================ Constructor =====================================
StaffManager::StaffManager(vector<Employee*> *employees, int sizeEmployees)
{
	this->employees = new vector<Employee*>;
	if (employees != nullptr && !employees->empty())
	{
		copyEmployeeUtil(this->employees, employees);
		this->logicalSizeEmployees = sizeEmployees;
		this->physicalSizeEmployees = sizeEmployees;
	}
}

//	================ Copy Constructor ================================
StaffManager::StaffManager(const StaffManager & other)
{
	this->employees = new vector<Employee*>;
	copyEmployeeUtil(this->employees, const_cast<vector<Employee*>*>(other.getAllEmployees()));
	this->logicalSizeEmployees = other.getSizeEmployees();
}

//	================ getEmployeeByEmployeeId Method ==================
Employee& StaffManager::getEmployeeByEmployeeId(long employeeId) throw(const char*)
{
	vector<Employee*>::iterator itr = this->employees->begin();
	vector<Employee*>::iterator itrEnd = this->employees->end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getEmployeeID() == employeeId)
		{
			return (**itr);
		}
	}
	throw "There is no such employee";
}

//	================ employ Method ===================================
void StaffManager::employ(const Employee*& employee)
{
	this->employees->push_back(const_cast<Employee*>(employee));
}

//	================ fire Method =====================================
void StaffManager::fire(const Employee*& employee) throw(const char*)
{
	vector<Employee*>::iterator itr = this->employees->begin();
	vector<Employee*>::iterator itrEnd = this->employees->end();
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getEmployeeID() == employee->getEmployeeID())
		{
			cout << "Employee: " << employee->getEmployeeID() << " " << employee->getName() << " Got fired!";
			this->employees->erase(itr);
			break;
		}
	}
	throw "There is no such employee";
}

//	================ ShoutOnEmployees Method =========================
void StaffManager::ShoutOnEmployees() const
{
	cout << "Start working you lazy asses!!";
}

//	================ Copy Employee List Util =========================
void copyEmployeeUtil(vector<Employee*> *destList, vector<Employee*> *srcList)
{
	for each (Employee* employee in *srcList)
	{
		destList->push_back(employee);
	}
}