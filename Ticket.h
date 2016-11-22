class Ticket {

private:
	int price;
	int row;
	int column;
	Play* play;

public:
	int getPrice();

	void setPrice(int price);

	void getRow();

	void setRow(int row);

	void getColumn();

	void setColumn(int column);

	void getDatas();
};
