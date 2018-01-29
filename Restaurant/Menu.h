#ifndef __MENU_H
#define __MENU_H

#include "Dish.h"
#include <vector>
using std::vector;

class Menu
{
private:
	vector<Dish> dishes;
	Menu(const Menu& other);

public:
	const static int PHYSICAL_SIZE_GAP = 5;

	Menu(){};
	//~Menu(){delete []dishes;}	

	// Getters
	const vector<Dish> getAllDishes() const { return dishes; }
	int getSizeDishes() const {return dishes.size(); }
	const Dish*& getDishByName(const char* name);

	// Operators
	const Menu& operator+=(const Dish& dish){this->addDish(dish); return *this;}

	// Methods
	void addDish(const Dish& dish);
	void removeDish(const char* dishName);
	void print() const;	
};

#endif // __MENU_H