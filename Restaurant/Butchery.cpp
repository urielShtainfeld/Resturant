#include "Butchery.h"

/*	=================== Constructor ==========================	*/
Butchery::Butchery() = default;
Butchery::Butchery(const Employee & employee) : Employee(employee)
{
	
}

/*	=================== Destructor ===========================
*	No need implementing, as there are no dynamic attributes.	*/
Butchery::~Butchery()
{
}

/*	=================== makeDish =============================	
*	Maybe more work need to be done... */
void Butchery::makeDish(const Dish & dish) const
{
	cout << "Making " << dish.getName() << " Dish"
		<< "\n..."
		<< "\n..."
		<< "\n..."
		<< "\nDone!\n";
}
