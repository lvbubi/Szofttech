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

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
using namespace std;


struct Eloadas {
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
	friend ostream & operator <<(ostream & os, const Eloadas & eloadas);//EGY ELOADAS KIIRASA
	friend ostream & operator <<(ostream & os, const list<Eloadas> &eloadasok);//ELOADASOK KIIRASA LISTABOL
	friend ostream & operator <<(ostream & os, const vector<vector<int>> &spaces);//Helyek megjelenitese
	map<Play, list<Eloadas>>::iterator begin();//begin a foreachez
	map<Play, list<Eloadas>>::iterator end(); //end a foreachez

	bool friend operator< (const Play& lhs, const Play& rhs);// a maphez!

	void listSzindarabok()const;//a listazas csak az altalanos adatokat tartalmazza, az arak meg ezek majd az igazgatora vonatkoznak pl
	void listPlays()const;
	
	////////////////////////////////////////////////
	//////////////getter funkciók///////////////////
	const Play& getPlay()const;
	Eloadas & getEloadas(list<Eloadas> &eloadasok);
	pair<Play, list<Eloadas>> getPair();

	////////////////////////////////////////////////
	////////////////Módosító függvények/////////////
	void swapSzindarab(pair<Play, list<Eloadas>> &position, pair<Play, list<Eloadas>> &swap);
	void setNameOfEloadasok(list<Eloadas> &eloadasok,const string &nev);
};

#endif //PLAYS_H
