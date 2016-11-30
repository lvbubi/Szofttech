#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "GuestBook.h"
#include "Plays.h"
#include "Payment.h"
#include "C_Datas.h"
class Customer {

private:
	Plays* plays;
    GuestBook* GBook;
	Payment fizetes;
public:
    void buyTicket();
    Customer(Plays * plays,GuestBook* GBook, Payment & payment);
    void writeReview(const string &name, const string &label, const string &comment);
    bool start();
};

//basszuk el a kódot lol
#endif //CUSTOMER_H
