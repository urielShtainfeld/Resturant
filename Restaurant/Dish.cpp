#include "Dish.h";

Dish::Dish(vector<sIngredientAndQuantity>  ingredientsAndQuantities, int price, const char* description, const char* name, eDishType type)
{
	setPrice(price);
	setDescription(description);
	setName(name);
	setEDishType(type);
	addIngredients(ingredientsAndQuantities);
}
Dish::Dish(int price, const char* description, const char* name, eDishType type)
{
	setPrice(price);
	setDescription(description);
	setName(name);
	setEDishType(type);
	ingredientsAndQuantities = {};
}

//Setters
void Dish::setDescription(const char* description)
{
	strcpy_s(this->description, description);
}

void Dish::setName(const char* name)
{
	strcpy_s(this->name, name);
}
void Dish::setEDishType(const eDishType type) throw(const char*)
{
	if (type < FIRST || type > DESSERT)
		throw "There is no such dish type";
	this->type = type;
}

// Operators
const Dish& Dish::operator=(const Dish& other)
{
	if (this == &other)
		return *this;
	setPrice(other.price);
	setDescription(other.description);
	setName(other.name);
	setEDishType(other.type);
	addIngredients(other.ingredientsAndQuantities);
	return *this;
}

const int Dish::operator+(const Dish& other) 
{
	setDescription(strcat(this->description,other.getDescription()));
	setName(strcat(this->name, other.getName()));
	setPrice(this->getPrice() + other.getPrice());
	addIngredients(other.ingredientsAndQuantities);
	return this->getPrice();
}
int operator+(const Dish& dish, int price)
{
	return price+dish.getPrice();
}
int operator+(int price, const Dish& dish)
{
	return price + dish.getPrice();
}

// Methods
void Dish::addIngredients(vector<sIngredientAndQuantity>  ingredientsAndQuantities)
{
	if (ingredientsAndQuantities.empty())
	{
		return;
	}
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		this->ingredientsAndQuantities.push_back(ingredientsAndQuantities[i]);
	}
}
double Dish::calcCalories() const
{
	double res = 0;
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		res += ingredientsAndQuantities[i].ingredient->getCaloricValue() * ingredientsAndQuantities[i].quantity;
	}
	return res;
}
void Dish::print() const
{
	std::cout<< "Dish: " << getName() << "\n   Description : " << getDescription() << "\n   Price : " << getPrice() << std::endl;
}

