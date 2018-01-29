#include "Restaurant.h"

Restaurant::Restaurant(const char* name, const Chef& chef, const Menu& menu, const Stock& stock, const Ingredient* ingredients, int sizeIngredients)
{
	strcpy(this->name, name);
	this->setTheChef(chef);
	this->logicalSizeIngredients = sizeIngredients;
	
	//init menu
	for (int i = 0; i < menu.getSizeDishes(); i++)
	{
		this->menu.addDish(menu.getAllDishes()[i]);
	}


	//ingridiants
	this->ingredients = new Ingredient[sizeIngredients];
	for (int i = 0; i < sizeIngredients; i++)
	{
		this->ingredients[i] = ingredients[i];
	}

	for (int i = 0; i < stock.getSizeIngredientsAndQuantities(); i++)
	{
		this->stock.addIngredient(stock.getAllIngredientsAndtQuantities()[i].ingredient, stock.getAllIngredientsAndtQuantities()[i].quantity);
	}

}

// Methods
const Order& Restaurant::seatCustomers(int size) throw(const char*)
{
	for (int i = 0; i < MAX_NUM_TABLES; i++)
	{
		if (tables[i].getMaxNumOfGuests() >= size)
		{
			tables[i].setIsTaken(true);
			const Table *myTable = &tables[i];
			Order *order = new Order();
			order->setTable(myTable);
			return *order;
		}
	}
	
	throw "the number of guests are bigger than the biggest table,\n you need to split them to more than one table";
}
void Restaurant::takeOrder(const Order& order, Waiter& waiter)
{
	waiter.takeOrder(order);
}
void Restaurant::addDishToMenu(const Dish& dish)
{
	menu.addDish(dish);
}
void Restaurant::prepareOrder(const Order& order, const Butchery& butchery) const throw(const char*)
{
	for (int i = 0; i < order.getSizeDishes(); i++)
	{
		butchery.makeDish(*(order.getDishes()[i]));
	}
	for (int i = 0; i < order.getSizeDishes(); i++)
	{
		for (int j = 0; j < order.getDishes()[i]->getSizeIngredientsAndQuantities(); j++)
		{
			if (order.getDishes()[i]->getIngredientsAndQuantities()[j].quantity > stock.getIngredientAndQuantityByIngredientName(order.getDishes()[i]->getIngredientsAndQuantities()[j].ingredient->getName()).quantity)
			{
				throw "Not enough Ingrediants - Please refill";
			}
			else
			{
				const_cast<Stock&>(stock).removeIngredient(order.getDishes()[i]->getIngredientsAndQuantities()[j].ingredient, order.getDishes()[i]->getIngredientsAndQuantities()[j].quantity);
			}
		}
	}
}
void Restaurant::fillStock(const sIngredientAndQuantity* ingredientsAndQuantities, int sizeIngredientsAndQuantities)
{
	for (int i = 0; i < sizeIngredientsAndQuantities; i++)
	{
		stock.addIngredient(ingredientsAndQuantities[i].ingredient, ingredientsAndQuantities[i].quantity);
	}
}
void Restaurant::printOrderToTable(const Table& table, const Waiter& waiter) const
{
	for (int i = 0; i < Waiter::MAX_NUM_ORDERS; i++)
	{
		if (waiter.getAllOrders()[i].getTable().getId() == table.getId())
		{
			waiter.getAllOrders()[i].print();
			return;
		}
	}
}
