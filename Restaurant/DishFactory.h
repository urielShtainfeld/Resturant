#pragma once
#ifndef __DISHFACTORY_H
#define __DISHFACTORY_H
#include <iostream>
#include "Dish.h"
using namespace std;

class DishFactory
{
public:
	// Factory Creation Related
	static DishFactory* getInstance();
	~DishFactory();

	// Methods
	Dish* getDishInstance(int calories, const char* description, const char* name) { return new Dish(calories, description, name);}

private:
	DishFactory();
	static DishFactory dishFactory;
};
#endif