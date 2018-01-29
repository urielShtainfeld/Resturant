#ifndef __DISH_H
#define __DISH_H

#include "IngredientAndQuantity.h"
#include <fstream>
#include <vector>
using std::vector;
class Dish
{
public:
	const static enum eDishType
	{
		FIRST,
		MAIN_COURSE,
		DESSERT
	};

	const static int MAX_DESCRIPTION_SIZE = 100;
	const static int MAX_NAME_SIZE = 30;

private:
	int price;
	char description[MAX_DESCRIPTION_SIZE];
	char name[MAX_NAME_SIZE];
	vector<sIngredientAndQuantity>  ingredientsAndQuantities;
	eDishType type;

public:
	Dish(vector<sIngredientAndQuantity>  ingredientsAndQuantities, int price = 0, const char* description = "", const char* name = "", eDishType type = MAIN_COURSE);
	Dish(int price = 0, const char* description = "", const char* name = "", eDishType type = MAIN_COURSE);
	Dish(const Dish& other){ *this = other; }
	//~Dish() {if (!ingredientsAndQuantities) delete []ingredientsAndQuantities;}

	// Getters
	int getPrice() const {return price;}
	const char* getDescription() const {return description;}
	const char* getName() const {return name;}
	const vector<sIngredientAndQuantity> getIngredientsAndQuantities() const { return ingredientsAndQuantities; }
	int getSizeIngredientsAndQuantities() const { return ingredientsAndQuantities.size(); }

	// Setters
	void setPrice(int price) {this->price = price; }
	void setDescription (const char* description);
	void setName (const char* name);
	void setEDishType (const eDishType type) throw(const char*);

	// Operators
	const Dish& operator=(const Dish& other);
	bool operator<(const Dish& other) const { return this->calcCalories() < other.calcCalories();}
	const int operator+(const Dish& other);
	friend int operator+(const Dish& dish, int price);
	friend int operator+(int price, const Dish& dish);	

	// Methods
	void addIngredients(vector<sIngredientAndQuantity>  ingredientsAndQuantities);
	double calcCalories() const;
	void print() const;
};

#endif // __DISH_H