#ifndef __CHEF_H
#define __CHEF_H

#include "Butchery.h"
#include "StaffManager.h"
#include "Dish.h"

class Chef : public Butchery, public StaffManager
{

public:
	Chef();
	Chef(const Butchery& buthcery , const StaffManager& staffManager);

	// Methods
	bool approveDish(const Dish& dish) const;
	const Dish& inventNewDish() const; // The returned dish must be allocated dynamicly
};

#endif // __CHEF_H
