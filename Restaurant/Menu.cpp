#include "Menu.h"

// Getters
const Dish*& Menu::getDishByName(const char* name)
{
	const Dish* myDish;
	for (int i = 0; i < dishes.size(); i++)
	{
		if (strcmp(dishes[i].getName(), name) == 0)
		{
			myDish = &dishes[i];
			return myDish;
		}
	}
}

// Methods
void Menu::addDish(const Dish& dish)
{
	for (int i = 0; i < dishes.size(); i++)
	{
		if (strcmp(dishes[i].getName(), dish.getName()) == 0)
		{
			return;
		}
	}
	dishes.push_back(dish);
}
void Menu::removeDish(const char* dishName)
{
	vector<Dish>::iterator itr = dishes.begin();
	vector<Dish>::iterator itrEnd = dishes.end();

	while (itr != itrEnd)
	{
		if (strcmp(itr->getName(), dishName) == 0)
		{
			dishes.erase(itr);
			return;
		}
		++itr;
	}
}
void Menu::print() const
{
	std::cout << " * * * * * Menu * * * * * " << std::endl;

	for (int i = 0; i < dishes.size(); i++)
	{
		std::cout << i + 1 << ". ";
		dishes[i].print();
	}
}
