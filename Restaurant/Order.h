#ifndef __ORDER_H
#define __ORDER_H

#include "Dish.h"
#include "Table.h"
#include <vector>
using std::vector;
class Order
{
public: 
	const static enum eOrderStatus
	{
		BEING_TAKEN,
		IN_PREPARATION,
		SERVED
	};
	static long idCounter;

private:
	long id;
	vector<Dish*> dishes;
	const Table* table;
	eOrderStatus status;

public:
	Order(const Dish** dishes = NULL, int sizeDishes = 0, const Table* table = NULL, eOrderStatus status = BEING_TAKEN);
	Order(const Order& other){ *this = other; }
	//~Order() { delete []dishes; }

	// Getters
	const vector<Dish*> getDishes() const { return dishes; }
	int getSizeDishes() const { return dishes.size(); }
	const Table& getTable() const { return *table; }
	eOrderStatus getStatus() const { return status; }
	long getID() const { return id; }

	// Setters
	void setTable(const Table*& table) {this->table = table; }
	void setStatus(eOrderStatus status) { this->status = status; }
	void resetOrder() { this->id = 0; }

	// Operators
	const Order& operator=(const Order& other);
	const Order& operator+=(const Dish* dish){this->addDish(dish); return *this; }

	// Methods
	int calcPrice() const;
	void cancelDish(const char* dishName);
	void addDish(const Dish* dish);
	void print() const;

};
std::ostream & operator<<(std::ostream& os, const Order & order);
#endif // __ORDER_H