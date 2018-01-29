#ifndef __BUTCHERY_H
#define __BUTCHERY_H
#include <iostream>
using namespace std;
#include "Employee.h"
#include "Dish.h"
class Dish;

class Butchery : public Employee
{
public:
	Butchery();
	Butchery(const Employee& employee);
	virtual ~Butchery();

	// Methods
	void makeDish(const Dish& dish) const;
};

#endif // __BUTCHERY_H
