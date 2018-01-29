#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class Node
{
private:
	T m_val;
	Node<T> *m_next;
public:
	Node();
	Node(T valueToInsert);
	T& GetVal() { return m_val; };
	void SetVal(T value) { m_val = value; }
	Node<T>* GetNext() { return m_next; };
	void SetNext(Node<T> *next) { m_next = next; };
	Node<T>* CreateNewNode();
};

template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>& other);
	~LinkedList();
	Node<T>* GetHead() const { return m_head; }
	void InsertAt(T valueToInsert, int index = 0);
	void RemoveAt(int index = 0);
	T& GetElement(int index) const;
	void PrintList() const;
	void ClearAll();


private:
	Node<T> *m_head;
};

template <class T> Node<T>::Node()
{

	m_next = NULL;
}

template <class T> Node<T>::Node(T valueToInsert) : m_val(valueToInsert) { }


template <class T> Node<T>* Node<T>::CreateNewNode()
{
	Node<T> *temp = new Node<T>();
	temp->SetVal(this->GetVal());
	return temp;
}

template <class T> LinkedList<T>::LinkedList()
{
	m_head = new Node<T>();
}

template <class T> LinkedList<T>::LinkedList(const LinkedList& other)
{
	Node<T> *runner = other.m_head->GetNext();
	Node<T> *last = m_head;
	while (runner != NULL)
	{
		last->SetNext(runner->CreateNewNode());
		last = last->GetNext();
		runner = runner->GetNext();
	}
	last->SetNext(NULL);
}

template <class T> LinkedList<T>::~LinkedList()
{
	ClearAll();
}

template <class T> void LinkedList<T>::InsertAt(T valueToInsert, int index)
{
	Node<T> *temp, *runner;
	runner = m_head;
	for (int i = 0; i < index + 1 && runner != NULL; i++)
	{
		temp = runner;
		runner = runner->GetNext();
	}

	Node<T> *newNode = new Node<T>(valueToInsert);
	temp->SetNext(newNode);
	newNode->SetNext(runner);
}

template <class T>
T& LinkedList<T>::GetElement(int index) const
{
	int i = 0;
	Node<T> *runner = m_head->GetNext();
	for (int i = 0; i < index && runner != NULL; i++)
		runner = runner->GetNext();

	return runner->GetVal();
}

template <class T>
void LinkedList<T>::PrintList() const
{
	Node<T> *runner = m_head->GetNext();
	int i = 0;
	while (runner != NULL)
	{
		std::cout << "(" << i++ << ") " << runner->GetVal() << std::endl;
		runner = runner->GetNext();
	}
}

template <class T> void LinkedList<T>::RemoveAt(int index)
{
	Node<T> *runner = m_head, *temp;
	for (int i = 0; i < index + 1 && runner->GetNext() != NULL; i++)
	{
		temp = runner;
		runner = runner->GetNext();
	}
	temp->SetNext(runner->GetNext());
	delete runner;
}


template <class T> void LinkedList<T>::ClearAll()
{
	Node<T> *toDelete, *runner;
	runner = m_head->GetNext();
	while (runner != NULL)
	{
		toDelete = runner;
		runner = runner->GetNext();
		delete toDelete;
	}
}
#endif