#include "Play.h"


class Ticket {

private:
    int price;
    int row;
    int column;
    Play* play;
    string date;

public:
    Ticket();
    Ticket(int row, int column, Play*play, string date);
	int getPrice();

	void setPrice(int price);

	void getRow();

	void setRow(int row);

	void getColumn();

	void setColumn(int column);

	void getDatas();
};
