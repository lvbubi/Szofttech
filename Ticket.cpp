#include "Ticket.h"

Ticket::Ticket()
{

}

Ticket::Ticket(int row, int column, Play *play, string date)
    :row(row),column(column),play(play),date(date)
{
    //price=play->getPrice();
}

int Ticket::getPrice() {
	return this->price;
}

void Ticket::setPrice(int price) {
	this->price = price;
}

void Ticket::getRow() {
	throw "Not yet implemented";
}

void Ticket::setRow(int row) {
	this->row = row;
}

void Ticket::getColumn() {
	throw "Not yet implemented";
}

void Ticket::setColumn(int column) {
	this->column = column;
}

void Ticket::getDatas() {
	throw "Not yet implemented";
}
