#ifndef PLAYS_H
#define PLAYS_H

#include <vector>
#include <fstream>
#include "Play.h"
#include "Ticket.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
using namespace std;


struct Eloadas {
	vector<vector<Ticket>> tickets; //kicst sem bonyolult aaaahh nem
	vector<vector<int>> spaces;
	int free_spaces;
	int sold_spaces;
	string date;
	string nev;
};


class Plays{



private:
	map<Play, list<Eloadas>> Tarolo;
	void szindarabok_beolvas();
	void eloadasok_beolvas();
	void jegyek_helyek_beolvas(ifstream &bemenet, Eloadas &eloadas);
public:
	Plays();
	void listEloadas(const Eloadas & eloadas)const;
	void listEloadasok(const list<Eloadas> &eloadasok)const;
	void listSzindarabok()const;//a listazas csak az altalanos adatokat tartalmazza, az arak meg ezek majd az igazgatora vonatkoznak pl
	void listPlays()const;

	bool friend operator< (const Play& lhs, const Play& rhs);

	const Play& getPlay()const;
	Eloadas & getEloadas(list<Eloadas> &eloadasok);

	map<Play, list<Eloadas>> &getTarolo();
	map<Play, list<Eloadas>> *getTaroloPointer();

	void setNameOfEloadasok(list<Eloadas> &eloadasok,const string &nev);
};

#endif //PLAYS_H
