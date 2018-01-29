#ifndef __TABLE_H
#define __TABLE_H
class Table
{
public:
	static long Table::idCounter;

private:
	long id;
	int maxNumOfGuests;
	bool isTaken;	

public:
	Table(int maxNumOfGuests = 0, bool isTaken = false);
	Table(const Table& other){ *this = other; }

	// Getters
	long getId() const { return id; }
	int getMaxNumOfGuests() const { return maxNumOfGuests; }
	bool getIsTaken() const { return isTaken; }

	// Setters
	void setIsTaken(bool isTaken) {this->isTaken = isTaken;}
	void setMaxNumOfGuests(int maxNumOfGuests){ this->maxNumOfGuests = maxNumOfGuests; }

	// Operators
	const Table& operator=(const Table& other);
};
#endif