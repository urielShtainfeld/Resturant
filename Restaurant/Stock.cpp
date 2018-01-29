#include "Stock.h"

Stock::Stock(const vector<sIngredientAndQuantity> ingredientsAndQuantities)
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

//Getters
const sIngredientAndQuantity& Stock::getIngredientAndQuantityByIngredientName(const char* ingredientName) const throw(const char*)
{
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		if (strcmp(ingredientsAndQuantities[i].ingredient->getName(), ingredientName)==0)
		{
			return ingredientsAndQuantities[i];
		}
	}
	throw "There is no such Ingredient";
}
sIngredientAndQuantity& Stock::getIngredientAndQuantityByIngredientName(const char* ingredientName) throw(const char*)
{
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		if (strcmp(ingredientsAndQuantities[i].ingredient->getName(), ingredientName) == 0)
		{
			return ingredientsAndQuantities[i];
		}
	}
	throw "There is no such Ingredient";
}
const Ingredient*& Stock::getIngredientByIngredientName(const char* ingredientName) throw(const char*)
{
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		if (strcmp(ingredientsAndQuantities[i].ingredient->getName(), ingredientName) == 0)
		{
			return ingredientsAndQuantities[i].ingredient;
		}
	}
	throw "There is no such Ingredient";
}

// Operators
const Stock& Stock::operator++()
{// For case of stock++
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		ingredientsAndQuantities[i].quantity++;
	}
	return *this;
}
const Stock& Stock::operator++(int)
{// For case of ++stock
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		ingredientsAndQuantities[i].quantity++;
	}
	return *this;
}

//Methods
void Stock::addIngredient(const Ingredient* ingredient, int quantity)
{
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		if (strcmp(ingredientsAndQuantities[i].ingredient->getName(), ingredient->getName())==0)
		{
			ingredientsAndQuantities[i].quantity += quantity;
			return;
		}
	}
	sIngredientAndQuantity nIngredientAndQuantity;
	nIngredientAndQuantity.ingredient = ingredient;
	nIngredientAndQuantity.quantity = quantity;
	ingredientsAndQuantities.push_back(nIngredientAndQuantity);
	
}
void Stock::removeIngredient(const Ingredient* ingredient, int quantity)
{//remove one ingrediant from stock
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		if (strcmp(ingredientsAndQuantities[i].ingredient->getName(), ingredient->getName()) == 0 && ingredientsAndQuantities[i].quantity > 0)
		{
			ingredientsAndQuantities[i].quantity -= quantity;
			return;
		}
	}
}
bool Stock::isIngredientAboutToEnd(const Ingredient* ingredient) const
{
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		if (strcmp(ingredientsAndQuantities[i].ingredient->getName(), ingredient->getName()) == 0 && ingredientsAndQuantities[i].quantity <= LOW_STOCK_TRESHOLD)
		{
			return true;
		}
	}
	return false;
}
const Ingredient** Stock::getEndedIngredients() const
{
	const Ingredient** ingredients;
	
	int endedIngrediantsSum = 0;
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		if (ingredientsAndQuantities[i].quantity == 0)
		{
			endedIngrediantsSum++;
		}
	}

	ingredients = new const Ingredient*[endedIngrediantsSum];
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		if (ingredientsAndQuantities[i].quantity == 0)
		{
			ingredients[i] = ingredientsAndQuantities[i].ingredient;
		}
	}
	return ingredients;
}
void Stock::print() const
{
	std::cout << " * * * * *  Stock * * * * * " << std::endl;
	for (int i = 0; i < ingredientsAndQuantities.size(); i++)
	{
		std::cout << "Product: " << ingredientsAndQuantities[i].ingredient->getName() << ", Quantity: " << ingredientsAndQuantities[i].quantity << std::endl;
	}
}