#include <iostream>
using namespace std;

#include "Restaurant.h"
#include "DishFactory.h"

// Methods signatures
int initEmployees(vector<Employee*> *employees);
int initDishes(Dish** dishes, Ingredient*& ingredients);
void initStock(Stock& stock, Ingredient*& ingredients, int numOfIngredients);
void initTables(Table* tables, const int numOfTables);
int initIngredients(Ingredient*& ingredients);
void setOrder(Order &order, Menu& menu);
int fillStock(Ingredient* ingredients, int numOfIngredients, sIngredientAndQuantity*& ingredientsAndQuantities);

void main()
{
	vector<Employee*> *employees = new vector<Employee*>();
	Dish** dishes = new Dish*[5];
	Stock stock;
	Ingredient* ingredients;

	// Initialize the parameters of the 'Maze' restaurant
	int numOfEmployees = initEmployees(employees);
	int numOfIngredients = initIngredients(ingredients);
	initStock(stock, ingredients, numOfIngredients);
	int numOfDishes = initDishes(dishes, ingredients);
	Chef chefRamsay(Butchery(Employee("Ramsay", 20, 852, 50000)), StaffManager(employees, numOfEmployees));
	Menu *menu = new Menu();
	for (int i = 0; i < numOfDishes; i++)
	{
		menu->addDish(*dishes[i]);
	}

	// Define 'Maze' restaurant
	Restaurant maze("Maze", chefRamsay, *menu, stock, ingredients, numOfIngredients);

	// Init the tables
	initTables(maze.getTables(), maze.MAX_NUM_TABLES);

	//-----------------------------------------------First flow-----------------------------------------------//
	// Customers come to the 'Maze' restaturant and being seat, they take a look at the menu and one of the waiters take their order, 
	// the order is being prepared by one of the butcheries and at the end the order is being printed with the final price of it
	Order* order = const_cast<Order*>(&maze.seatCustomers(5));
	maze.showMenu();
	setOrder(*order,*menu);
	maze.takeOrder(*order, (Waiter&)(maze.getChef().getEmployeeByEmployeeId(3)));
	maze.prepareOrder(*order, (Butchery&)(maze.getChef().getEmployeeByEmployeeId(0)));
	maze.printOrderToTable(order->getTable(), (Waiter&)(maze.getChef().getEmployeeByEmployeeId(3)));
	//order->print();
	//-----------------------------------------------Second flow-----------------------------------------------//
	// Take a look at the stock and fill the ended ingredients
	maze.stocktaking();
	sIngredientAndQuantity* ingredientsAndQuantities;
	int numOfIngredientsAndQuantities = fillStock(maze.getAllIngredients(), maze.getSizeIngredients(), ingredientsAndQuantities);
	maze.fillStock(ingredientsAndQuantities, numOfIngredientsAndQuantities);
	maze.getStock()++;

	//-----------------------------------------------Third flow-----------------------------------------------//
	// Chef Ramsay invent new dish, that is being added to the menu
	//maze.addDishToMenu(chefRamsay.inventNewDish());
	system("pause");
}

int initEmployees(vector<Employee*> *employees)
{
	employees->push_back(new Butchery(Employee("Ben", 2, 456, 1500)));
	employees->push_back(new Butchery(Employee("Maya", 4, 741, 4500)));
	employees->push_back(new Waiter(Employee("Charlie", 1, 123, 1000)));
	employees->push_back(new Waiter(Employee("Adam", 3, 789, 2000)));
	return 4;
}

int initDishes(Dish** dishes, Ingredient*& ingredients)
{
	int numOfDishes = 5;
	DishFactory* dishFactory = DishFactory::getInstance();

	// The classic dish
	dishes[0] = dishFactory->getDishInstance(130, "Excellent beef served with creamed potatoes", "The classic");
	vector<sIngredientAndQuantity> ingredientsAndQuantities0;
	sIngredientAndQuantity ingredientsAndQuantities01;
	ingredientsAndQuantities01.ingredient = &ingredients[1]; // Beef
	ingredientsAndQuantities01.quantity = 250;
	sIngredientAndQuantity ingredientsAndQuantities02;
	ingredientsAndQuantities02.ingredient = &ingredients[0]; // Potato
	ingredientsAndQuantities02.quantity = 2;
	sIngredientAndQuantity ingredientsAndQuantities03;
	ingredientsAndQuantities03.ingredient = &ingredients[8]; // Cream
	ingredientsAndQuantities03.quantity = 100;
	ingredientsAndQuantities0.push_back(ingredientsAndQuantities01);
	ingredientsAndQuantities0.push_back(ingredientsAndQuantities02);
	ingredientsAndQuantities0.push_back(ingredientsAndQuantities03);
	dishes[0]->addIngredients(ingredientsAndQuantities0);

	//	The Italian dish
	dishes[1] = dishFactory->getDishInstance(60, "Great pasta with creamy tomatoes sauce", "The Italian");
	vector<sIngredientAndQuantity> ingredientsAndQuantities1;
	sIngredientAndQuantity ingredientsAndQuantities10;
	ingredientsAndQuantities10.ingredient = &ingredients[7]; // Pasta
	ingredientsAndQuantities10.quantity = 250;
	sIngredientAndQuantity ingredientsAndQuantities11;
	ingredientsAndQuantities11.ingredient = &ingredients[5]; // Tomato
	ingredientsAndQuantities11.quantity = 2;
	sIngredientAndQuantity ingredientsAndQuantities12;
	ingredientsAndQuantities12.ingredient = &ingredients[8]; // Cream
	ingredientsAndQuantities12.quantity = 100;
	sIngredientAndQuantity ingredientsAndQuantities13;
	ingredientsAndQuantities13.ingredient = &ingredients[2]; // Cheese
	ingredientsAndQuantities13.quantity = 50;
	ingredientsAndQuantities1.push_back(ingredientsAndQuantities10);
	ingredientsAndQuantities1.push_back(ingredientsAndQuantities11);
	ingredientsAndQuantities1.push_back(ingredientsAndQuantities12);
	ingredientsAndQuantities1.push_back(ingredientsAndQuantities13);
	dishes[1]->addIngredients(ingredientsAndQuantities1);

	// Chocolate cake
	dishes[2] = dishFactory->getDishInstance(42, "Hot chocolate cake", "Amazing chocolate cake");
	vector<sIngredientAndQuantity> ingredientsAndQuantities2;
	sIngredientAndQuantity ingredientsAndQuantities20;
	ingredientsAndQuantities20.ingredient = &ingredients[4]; // Egg
	ingredientsAndQuantities20.quantity = 1;
	sIngredientAndQuantity ingredientsAndQuantities21;
	ingredientsAndQuantities21.ingredient = &ingredients[9]; // Chocolate
	ingredientsAndQuantities21.quantity = 100;
	sIngredientAndQuantity ingredientsAndQuantities22;
	ingredientsAndQuantities22.ingredient = &ingredients[8]; // Cream
	ingredientsAndQuantities22.quantity = 150;
	sIngredientAndQuantity ingredientsAndQuantities23;
	ingredientsAndQuantities23.ingredient = &ingredients[2]; // Milk	
	ingredientsAndQuantities23.quantity = 100;
	ingredientsAndQuantities2.push_back(ingredientsAndQuantities20);
	ingredientsAndQuantities2.push_back(ingredientsAndQuantities21);
	ingredientsAndQuantities2.push_back(ingredientsAndQuantities22);
	ingredientsAndQuantities2.push_back(ingredientsAndQuantities23);
	dishes[2]->addIngredients(ingredientsAndQuantities2);

	// Tomatoes salad
	dishes[3] = dishFactory->getDishInstance(35, "Sliced tomatoes with cheese, served with hot bread", "Tomatoes salad");
	vector<sIngredientAndQuantity> ingredientsAndQuantities3;
	sIngredientAndQuantity ingredientsAndQuantities30;
	ingredientsAndQuantities30.ingredient = &ingredients[5]; // Tomato
	ingredientsAndQuantities30.quantity = 2;
	sIngredientAndQuantity ingredientsAndQuantities31;
	ingredientsAndQuantities31.ingredient = &ingredients[2]; // Cheese
	ingredientsAndQuantities31.quantity = 70;
	sIngredientAndQuantity ingredientsAndQuantities32;
	ingredientsAndQuantities32.ingredient = &ingredients[6]; // Bread
	ingredientsAndQuantities32.quantity = 1;
	ingredientsAndQuantities3.push_back(ingredientsAndQuantities30);
	ingredientsAndQuantities3.push_back(ingredientsAndQuantities31);
	ingredientsAndQuantities3.push_back(ingredientsAndQuantities32);
	dishes[3]->addIngredients(ingredientsAndQuantities3);

	// Carpaccio
	dishes[4] = dishFactory->getDishInstance(30, "Thin sliced beef with cheese", "Carpaccio");
	vector<sIngredientAndQuantity> ingredientsAndQuantities4;
	sIngredientAndQuantity ingredientsAndQuantities40;
	ingredientsAndQuantities40.ingredient = &ingredients[1]; // Beef
	ingredientsAndQuantities40.quantity = 100;
	sIngredientAndQuantity ingredientsAndQuantities41;
	ingredientsAndQuantities41.ingredient = &ingredients[2]; // Cheese
	ingredientsAndQuantities41.quantity = 40;
	ingredientsAndQuantities4.push_back(ingredientsAndQuantities40);
	ingredientsAndQuantities4.push_back(ingredientsAndQuantities41);
	dishes[4]->addIngredients(ingredientsAndQuantities4);
	return numOfDishes;
}
void initStock(Stock& stock, Ingredient*& ingredients, int numOfIngredients)
{
	for (int i = 0; i < numOfIngredients; i++)
	{
		Ingredient* pIngredient = &(ingredients[i]);
		stock.addIngredient(pIngredient, 1000);
	}
}

void initTables(Table* tables, const int numOfTables)
{
	for (int i = 0; i < numOfTables; i += 2)
	{
		tables[i].setMaxNumOfGuests(i + 2);
		tables[i + 1].setMaxNumOfGuests(i + 2);
	}
}

int initIngredients(Ingredient*& ingredients)
{
	int numOfIngredients = 10;
	ingredients = new Ingredient[numOfIngredients];

	ingredients[0] = Ingredient("Potato", 4, 20);
	ingredients[1] = Ingredient("Beef", 12, 50);
	ingredients[2] = Ingredient("Cheese", 3, 15);
	ingredients[3] = Ingredient("Milk", 2, 10);
	ingredients[4] = Ingredient("Egg", 1, 11);
	ingredients[5] = Ingredient("Tomato", 1, 10);
	ingredients[6] = Ingredient("Bread", 4, 30);
	ingredients[7] = Ingredient("Pasta", 5, 40);
	ingredients[8] = Ingredient("Cream", 6, 35);
	ingredients[9] = Ingredient("Chocolate", 7, 32);

	return numOfIngredients;
}

void setOrder(Order& order, Menu& menu)
{
	order.addDish(menu.getDishByName("The classic"));
	order.addDish(menu.getDishByName("The Italian"));
	order += menu.getDishByName("Carpaccio");	
	order += menu.getDishByName("Amazing chocolate cake");
}

int fillStock(Ingredient* ingredients, int numOfIngredients, sIngredientAndQuantity*& ingredientsAndQuantities)
{
	ingredientsAndQuantities = new sIngredientAndQuantity[numOfIngredients];
	for (int i = 0; i < numOfIngredients; i++)
	{
		ingredientsAndQuantities[i].ingredient = &ingredients[i];
		ingredientsAndQuantities[i].quantity = 2;
	}

	return numOfIngredients;
}