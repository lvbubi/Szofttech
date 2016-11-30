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
    friend inline ostream & operator <<(ostream & os, const Eloadas & eloadas){//EGY ELOADAS KIIRASA
    os << "Eloadas: " << eloadas.nev << "\t";
    os << "Datum: " << eloadas.date;
    os << "\nSzabad helyek szama:" << eloadas.free_spaces << endl;
    return os;
    }

	friend inline ostream & operator <<(ostream & os, const list<Eloadas> &eloadasok) {//ELOADASOK KIIRASA LISTABOL
		system(CLEAR);
		os << "Eloadasok Kilistazasa: " << endl;
		os << "-------------" << endl;
		int i = 1;
		for (const Eloadas &eloadas : eloadasok) {
			os << i++ << ".) ";
			os << eloadas;
		}
		return os;
	}
};


class Plays{



private:
	map<Play, list<Eloadas>> Tarolo;
	void szindarabok_beolvas();
	void eloadasok_beolvas();
	void jegyek_helyek_beolvas(ifstream &bemenet, Eloadas &eloadas);
public:
	Plays();
	Plays(Plays &&) = default;
    friend inline ostream & operator <<(ostream & os, const vector<vector<int>> &spaces){//Helyek megjelenitese
    system(CLEAR);
    for (vector<int> sor : spaces) {
        for (int oszlop : sor)
            os << oszlop;
        os << endl;
    }
    return os;
    }
	map<Play, list<Eloadas>>::iterator begin();//begin a foreachez
	map<Play, list<Eloadas>>::iterator end(); //end a foreachez

	friend bool operator< (const Play& lhs, const Play& rhs);// a maphez!

	void listSzindarabok()const;//a listazas csak az altalanos adatokat tartalmazza, az arak meg ezek majd az igazgatora vonatkoznak pl
	void listPlays()const;
	
	////////////////////////////////////////////////
	//////////////getter funkci�k///////////////////
	const Play& getPlay()const;
	Eloadas & getEloadas(list<Eloadas> &eloadasok);
	pair<Play, list<Eloadas>> getPair();

	////////////////////////////////////////////////
	////////////////M�dos�t� f�ggv�nyek/////////////
	void swapSzindarab(pair<Play, list<Eloadas>> &position, pair<Play, list<Eloadas>> &swap);
	void setNameOfEloadasok(list<Eloadas> &eloadasok,const string &nev);
};

#endif //PLAYS_H
