#include "Waiter.h"
#include "LinkedList.h"
//Constractur
Waiter::Waiter(const Employee& employee)
{
	this->WA = new WaiterAdaptee(employee);
}

//Getters
const Order * Waiter::getAllOrders() const
{
	Order *orders = new Order[MAX_NUM_ORDERS];
	LinkedList<Order> LL = WA->getAllOrders();
	Node<Order> *runner = LL.GetHead();
	int i = 0;
	while (runner->GetNext() != NULL && i< MAX_NUM_ORDERS)
	{	
		orders[i] = runner->GetVal();
		runner = runner->GetNext();
		i++;
	}
	return orders;
}
Order& Waiter::getOrderByOrderId(long orderId)
{
	return(WA->getOrderByOrderId(orderId));
}
//Methods
void Waiter::takeOrder(const Order& order)
{
	WA->takeOrder(order);
}
int Waiter::serveBill(const Order& order)
{
	return WA->serveBill(order);
}