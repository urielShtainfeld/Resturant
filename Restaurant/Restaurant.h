#ifndef __Restaurant_H
#define __Restaurant_H

#include "Table.h"
#include "Chef.h"
#include "Menu.h"
#include "Stock.h"
#include "Table.h"
#include "Ingredient.h"
#include "Order.h"
#include "Waiter.h"

class Restaurant
{
public:
	const static int MAX_NUM_TABLES = 30;
	const static int MAX_NAME_LENGTH = 20;

private:
	char name[MAX_NAME_LENGTH];
	Chef theChef;
	Menu menu;
	Stock stock;
	Table tables[MAX_NUM_TABLES];
	Ingredient* ingredients;
	int logicalSizeIngredients;
	int physicaclSizeIngredients;
	Restaurant(const Restaurant& other);

public:
	Restaurant(const char* name, const Chef& chef, const Menu& menu, const Stock& stock, const Ingredient* ingredients, int sizeIngredients);
	~Restaurant(){delete []ingredients;}

	// Getters
	const char* getName() const {return name;}
	
	const Chef& getChef() const {return theChef;}
	Chef& getChef() {return theChef;}
	
	const Menu& getMenu() const {return menu;}
	Menu& getMenu() {return menu;}
	
	const Stock& getStock() const {return stock;}
	Stock& getStock() {return stock;}
	
	const Table* getTables() const {return tables;}
	Table* getTables() {return tables;}
	
	const Ingredient* getAllIngredients() const {return ingredients;}
	Ingredient* getAllIngredients() {return ingredients;}
	
	int getSizeIngredients() const { return logicalSizeIngredients; }

	// Setters
	void setTheChef(const Chef& chef){this->theChef = chef;}

	// Methods
	const Order& seatCustomers(int size);
	void showMenu(){ menu.print(); }
	void takeOrder(const Order& order, Waiter& waiter);
	void addDishToMenu(const Dish& dish);
	void prepareOrder(const Order& order, const Butchery& butchery) const throw(const char*);
	void stocktaking() const {stock.print();}
	void fillStock(const sIngredientAndQuantity* ingredientsAndQuantities, int sizeIngredientsAndQuantities);
	void printOrderToTable(const Table& table, const Waiter& waiter) const;
};

#endif // __Restaurant_H