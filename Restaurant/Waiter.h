#ifndef __WAITER_H
#define __WAITER_H

#include "Order.h"
#include "Employee.h"
#include "WaiterAdaptee.h"

class Waiter : public Employee
{
public:
	const static int MAX_NUM_ORDERS = 10;

private:
	Waiter(const Waiter& other);
	WaiterAdaptee* WA;
public:
	Waiter(const Employee& employee);

	// Getters
	const Order* getAllOrders() const;
	//const Order& getOrderByOrderId(long orderId) const;
	Order& getOrderByOrderId(long orderId);

	// Methods
	void takeOrder(const Order& order);
	int serveBill(const Order& order);
};

#endif // __WAITER_H
