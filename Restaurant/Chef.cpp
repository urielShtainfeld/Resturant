#include "Chef.h"
#include "StaffManager.h"
#include "Butchery.h"
#include "Ingredient.h"
#include "IngredientAndQuantity.h"

//	================ Constructor =============================
Chef::Chef() = default;
Chef::Chef(const Butchery & buthcery, const StaffManager & staffManager) : Butchery(buthcery), StaffManager(staffManager)
{
	// Nothing to initialize here....
}

//	================ approveDish Method ======================
bool Chef::approveDish(const Dish & dish) const
{
	//	This chef approves all dishes...
	cout << dish.getName() << " Is approved!";
	return true;
}


//	================ Ingrediens creation ======================
const Dish & Chef::inventNewDish() const
{
	// This chef invets the same dish each time....not very creative...

	//	Ingrediens creation 
	//vector<sIngredientAndQuantity>* ingredientsAndQuantities = new vector<sIngredientAndQuantity>;

	vector<sIngredientAndQuantity> ingredientsAndQuantities0;

	sIngredientAndQuantity ingredientsAndQuantities01;
	ingredientsAndQuantities01.ingredient = new Ingredient("Pasta", 20, 300);
	ingredientsAndQuantities01.quantity = 1;

	sIngredientAndQuantity ingredientsAndQuantities02;
	ingredientsAndQuantities02.ingredient = new Ingredient("Shrimps", 40, 200);
	ingredientsAndQuantities02.quantity = 1;

	sIngredientAndQuantity ingredientsAndQuantities03;
	ingredientsAndQuantities03.ingredient = new Ingredient("Mushrooms", 30, 100);
	ingredientsAndQuantities03.quantity = 1;

	sIngredientAndQuantity ingredientsAndQuantities04;
	ingredientsAndQuantities04.ingredient = new Ingredient("Cream Cheese", 25, 300);
	ingredientsAndQuantities04.quantity = 1;
		
	ingredientsAndQuantities0.push_back(ingredientsAndQuantities01);
	ingredientsAndQuantities0.push_back(ingredientsAndQuantities02);
	ingredientsAndQuantities0.push_back(ingredientsAndQuantities03);
	ingredientsAndQuantities0.push_back(ingredientsAndQuantities04);

	/*sIngredientAndQuantity* ingredientsAndQuantity = new sIngredientAndQuantity[4];
	ingredientsAndQuantity[0].ingredient = new Ingredient("Pasta", 20, 300);
	ingredientsAndQuantity[0].quantity = 1;
	ingredientsAndQuantity[1].ingredient = new Ingredient("Shrimps", 40, 200);
	ingredientsAndQuantity[1].quantity = 1;
	ingredientsAndQuantity[2].ingredient = new Ingredient("Mushrooms", 30, 100);
	ingredientsAndQuantity[2].quantity = 10;
	ingredientsAndQuantity[3].ingredient = new Ingredient("Cream Cheese", 25, 300);
	ingredientsAndQuantity[3].quantity = 1;*/

	//	Dish creation
	Dish* dish = new Dish(ingredientsAndQuantities0, 200, "Pasta with shrimps in cream cheese and mushroom souce.", "Pasta Del Mar", (Dish::eDishType)1);

	return *dish;
}
