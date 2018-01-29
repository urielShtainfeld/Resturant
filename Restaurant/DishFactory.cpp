#include "DishFactory.h"

DishFactory DishFactory::dishFactory;

DishFactory::DishFactory() {}

DishFactory * DishFactory::getInstance()
{
	return &dishFactory;
}

DishFactory::~DishFactory() {}
