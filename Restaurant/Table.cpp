#include "Table.h"
long Table::idCounter = 0;
Table::Table(int maxNumOfGuests, bool isTaken)
{
	this->id = ++idCounter;
	setIsTaken(isTaken);
	setMaxNumOfGuests(maxNumOfGuests);
}

const Table& Table::operator=(const Table& other)
{
	if (this == &other)
		return *this;
	this->id = ++Table::idCounter;
	setIsTaken(other.getIsTaken());
	setMaxNumOfGuests(other.getMaxNumOfGuests());
	return *this;
}