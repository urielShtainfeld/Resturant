#include "Employee.h"

long Employee::idCounter = 0;
/*	=================== Constructor ==========================	*/
Employee::Employee(const char * name, int seniority, long bankAccountID, int salary) : seniority(seniority), bankAccountID(bankAccountID), salary(salary)
{
	strcpy(this->name, name);
	this->employeeID = idCounter++;
}

/*	=================== Destructor =========================== 
*	No need implementing, as there are no dynamic attributes.	*/
Employee::~Employee()
{
}

/*	=================== Setter ===============================	*/
void Employee::setName(const char * name)
{
	strcpy(this->name, name);
}

/*	=================== Quit =================================
*	Don't understand how the method should work, as this class has no reference to anything.	
*	Maybe should print something.
*	Pending for later in implementation. */
void Employee::quit() const
{
	/* To be continued... */
}
const Employee& Employee::operator=(const Employee& other)
{
	if (this == &other)
		return *this;
	this->employeeID = other.getEmployeeID();
	this->setBankAccountID(other.getBankAccountID());
	this->setName(other.getName());
	this->setSalary(other.getSalary());
	this->setSeniority(other.getSeniority());

//	if (dynamic_cast<Waiter*>(const_cast<Employee*>(&other)))
	{
		//for (int i = 0; i < Waiter::MAX_NUM_ORDERS; i++)
		{
			//dynamic_cast<Waiter*>(this) = static_cast<Waiter>(other).orders[i];
		}
	}

	return *this;
}

