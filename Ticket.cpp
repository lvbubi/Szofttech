#include "Ticket.h"

Ticket::Ticket()
{
}

Ticket::Ticket(int row, int column, string nev, string date)
    :row(row),column(column),nev(nev),date(date)
{

}

int Ticket::getPrice() {
	return this->price;
}

void Ticket::setPrice(int price) {
	this->price = price;
}


void Ticket::setRow(int row) {
	this->row = row;
}


void Ticket::setColumn(int column) {
	this->column = column;
}

