#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "GuestBook.h"
#include "Plays.h"
#include "Payment.h"
class Customer {

private:
	GuestBook* GBook;
	Plays* plays;
	Payment fizetes;
public:
	void buyTicket(Play* play);

	void writeReview();
};

//basszuk el a kódot lol
#endif //CUSTOMER_H