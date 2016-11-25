
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

//basszuk el a kódot lol
