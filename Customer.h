#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "GuestBook.h"
#include "Plays.h"

class Customer {

private:
	GuestBook* GBook;
	Plays* plays;

public:
	void buyTicket(Play* play);

	void writeReview();
};

//basszuk el a k�dot lol
#endif //CUSTOMER_H