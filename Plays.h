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
protected:

	void listEloadas(const Eloadas & eloadas)const;
	void listEloadasok(const list<Eloadas> &eloadasok)const;
	bool friend operator< (const Play& lhs, const Play& rhs);
public:
	Plays();
	map<Play, list<Eloadas>> &getTarolo();
	void listSzindarabok()const;//a listazas csak az altalanos adatokat tartalmazza, az arak meg ezek majd az igazgatora vonatkoznak pl
	void listPlays()const;
    void addPlay(Play & play);
};

#endif //PLAYS_H
