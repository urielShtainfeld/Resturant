
#ifndef __WaiterAdaptee_H
#define __WaiterAdaptee_H

#include "Order.h"
#include "Employee.h"
#include "LinkedList.h"
class WaiterAdaptee : public Employee
{
public:
	const static int MAX_NUM_ORDERS = 10;

private:
	LinkedList<Order> orders;
	WaiterAdaptee(const WaiterAdaptee& other);

public:
	//WaiterAdaptee() = default;
	WaiterAdaptee(const Employee& employee);

	// Getters
	const LinkedList<Order> getAllOrders() const { return orders; }
	//const Order& getOrderByOrderId(long orderId) const;
	Order& getOrderByOrderId(long orderId);

	// Methods
	void takeOrder(const Order& order);
	int serveBill(const Order& order);
};

#endif // __WaiterAdaptee_H
