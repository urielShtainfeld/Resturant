#include "WaiterAdaptee.h"

//Constractur
WaiterAdaptee::WaiterAdaptee(const Employee& employee) :Employee(employee)
{
	orders.ClearAll();
}

//Getters
Order& WaiterAdaptee::getOrderByOrderId(long orderId) throw(const char*)
{
	Node<Order> *runner = orders.GetHead();
	while (runner != NULL)
	{
		if (runner->GetVal().getID() == orderId)
		{
			return runner->GetVal();
		}
		runner = runner->GetNext();
	}

	throw "There is not such order";
}
//Methods
void WaiterAdaptee::takeOrder(const Order& order) throw(const char*)
{
	Node<Order> *runner = orders.GetHead();
	int i = 0;
	while (runner->GetNext() != NULL && i< MAX_NUM_ORDERS)
	{
		runner = runner->GetNext();
		i++;
	}
	orders.InsertAt(order, i);
	orders.PrintList();
}
int WaiterAdaptee::serveBill(const Order& order)
{
	int i = 0;
	Node<Order> *runner = orders.GetHead();
	while (runner != NULL)
	{
		if (runner->GetVal().getID() == order.getID())
		{
			orders.RemoveAt(i);
			break;
		}
		runner = runner->GetNext();
		i++;
	}
	return order.calcPrice();
}