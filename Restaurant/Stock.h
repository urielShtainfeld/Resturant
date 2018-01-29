#ifndef __STOCK_H
#define __STOCK_H

#include "IngredientAndQuantity.h"
#include "Ingredient.h"
#include <vector>
using std::vector;

class Stock
{
private:
	vector<sIngredientAndQuantity> ingredientsAndQuantities;
	
	Stock(const Stock& other);

public:
	const static int LOW_STOCK_TRESHOLD = 3;
	Stock(const vector<sIngredientAndQuantity> ingredientsAndQuantities);
	Stock(){};
	//~Stock(){delete []ingredientsAndQuantities;}

	//Getters
	const vector<sIngredientAndQuantity> getAllIngredientsAndtQuantities() const { return ingredientsAndQuantities; }
	const sIngredientAndQuantity& getIngredientAndQuantityByIngredientName(const char* ingredientName) const throw(const char*);
	sIngredientAndQuantity& getIngredientAndQuantityByIngredientName(const char* ingredientName);
	const Ingredient*& getIngredientByIngredientName(const char* ingredientName);
	int getSizeIngredientsAndQuantities() const { return ingredientsAndQuantities.size(); }

	// Operators
	const Stock& operator++(); // For case of stock++
	const Stock& operator++(int); // For case of ++stock

	//Methods
	void addIngredient(const Ingredient* ingredient,int quantity = 1);
	void removeIngredient(const Ingredient* ingredient, int quantity = 1);
	bool isIngredientAboutToEnd(const Ingredient* ingredient) const;
	const Ingredient** getEndedIngredients() const;
	void print() const;
};

#endif // __STOCK_H

