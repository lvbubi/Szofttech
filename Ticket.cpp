#include "Ticket.h"

ofstream Ticket::kimenet("jegyek.txt");

Ticket::Ticket()
{
}


Ticket::Ticket(const pair<int,int> &place,int price,string szindarab, string nev, string date)
    :place(place),nev(nev),date(date),price(price),szindarab(szindarab)
{
	if (kimenet.is_open()) {
		kimenet << "Szindarab: " << szindarab << endl;
		kimenet << "Datum: " << date << endl;
		kimenet << "Ar: " << price << endl;
		kimenet << "Sor: " << place.first+1 << " Oszlop: " << place.second+1 << endl;
		kimenet << "Customer: " << nev << endl<<'*'<<endl;
	}
}
