#include "Order.h"
#include <iostream>
using namespace std;

long Order::idCounter = 0;

Order::Order(const Dish** dishes, int sizeDishes, const Table* table, eOrderStatus status)
{
	setStatus(status);
	setTable(table);
	this->id = ++idCounter;
	for (int i = 0; i < sizeDishes; i++)
	{
		this->dishes.push_back(const_cast<Dish*>(dishes[i]));
	}
}

// Operators
const Order& Order::operator=(const Order& other)
{
	if (this == &other)
		return *this;
	this->id = other.getID();
	setTable(const_cast<const Table*>(other.table));
	setStatus(other.getStatus());

	for (int i = 0; i < other.dishes.size(); i++)
	{
		this->dishes.push_back(other.dishes[i]);
	}
	return *this;
}

// Methods
int Order::calcPrice() const
{
	int sum = 0;
	for (int i = 0; i < dishes.size(); i++)
	{
		sum += dishes[i]->getPrice();
	}
	return sum;
}
void Order::cancelDish(const char* dishName)
{
	for (int i = 0; i < dishes.size(); i++)
	{
		if (strcmp(dishes[i]->getName(), dishName) == 0)
		{
			dishes.erase(dishes.begin()+i);// = dishes[logicalSizeDishes - 1];
			return;
		}
	}
}
void Order::addDish(const Dish* dish)
{
	cout << "Adding " << dish->getName() << " to order" << endl;
	dishes.push_back(const_cast<Dish*>(dish));
}
void Order::print() const
{
	std::cout << " * * * * * Order Num : "<< this->id <<"* * * * * " << std::endl;

	for (int i = 0; i < dishes.size(); i++)
	{
		dishes[i]->print();
	}

	std::cout << "Total cost : " << this->calcPrice() << std::endl;
}

std::ostream & operator<<(std::ostream& os, const Order& order)
{
	os << "\nOrder number : " << order.getID();
	vector<Dish*> dishes;
	dishes = order.getDishes();
	for (int i = 0; i < order.getSizeDishes(); i++)
	{
		os << "Dish: " << ((Dish&)dishes[i]).getName() << "\n   Description : " << ((Dish&)dishes[i]).getDescription() << "\n   Price : " << ((Dish&)dishes[i]).getPrice();
	}
	os << "\nPrice: " << order.calcPrice();

	return os;
}
