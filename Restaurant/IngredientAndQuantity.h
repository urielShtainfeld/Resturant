#ifndef __INGREDIENT_AND_QUANTITY_H
#define __INGREDIENT_AND_QUANTITY_H

#include "Ingredient.h"

struct sIngredientAndQuantity
{
	int quantity;
	const Ingredient* ingredient;
};

#endif //__INGREDIENT_AND_QUANTITY_H