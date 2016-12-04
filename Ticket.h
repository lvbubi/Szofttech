#ifndef TICKET_H
#define TICKET_H
#include <fstream>
#include <string>
using namespace std;
class Ticket {

private:
    int price;
	pair<int, int> place;
	string nev;
    string date;
	string szindarab;
	static ofstream kimenet;
public:
	Ticket();
    Ticket(const pair<int,int> &place, int price , string szindarab,string nev, string date);

};
#endif //TICKET_H
