#pragma once
#ifndef __Waiter_H
#define __Waiter_H

#include "Order.h"
#include "Employee.h"
#include "LinkedList.h"
class Waiter : public Employee
{
public:
	const static int MAX_NUM_ORDERS = 10;

private:
	LinkedList<Order> orders;
	Waiter(const Waiter& other);

public:
	//Waiter() = default;
	Waiter(const Employee& employee);

	// Getters
	const LinkedList<Order> getAllOrders() const { return orders; }
	//const Order& getOrderByOrderId(long orderId) const;
	Order& getOrderByOrderId(long orderId);

	// Methods
	void takeOrder(const Order& order);
	int serveBill(const Order& order);
};

#endif // __Waiter_H
