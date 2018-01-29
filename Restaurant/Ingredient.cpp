#include "Ingredient.h"

Ingredient::Ingredient(const char* name, int price, double caloricValue)
{
	setName(name);
	setPrice(price);
	setCaloricValue(caloricValue);
}

//Setters
void Ingredient::setName(const char* name)
{
	strcpy(this->name, name);
}

// Operators
const Ingredient& Ingredient::operator=(const Ingredient& other)
{
	if (this == &other)
		return *this;
	setName(other.getName());
	setPrice(other.getPrice());
	setCaloricValue(other.getCaloricValue());
	return *this;
}

// Methods
void Ingredient::print() const
{
	std::cout << "Ingredient: Name:" << getName() << " , Price:" << getPrice() << " , CaloricValue:"<< getCaloricValue() << std::endl;
}
