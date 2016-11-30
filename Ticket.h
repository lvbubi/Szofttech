#ifndef TICKET_H
#define TICKET_H
#include <string>
using namespace std;
class Ticket {

private:
    int price;
    int row;
    int column;
	string nev;
    string date;


public:
	Ticket();
    Ticket(int row, int column ,string nev, string date);
	int getPrice();

	void setPrice(int price);



	void setRow(int row);



	void setColumn(int column);


};
#endif //TICKET_H
