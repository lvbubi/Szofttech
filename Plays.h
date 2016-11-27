#ifndef PLAYS_H
#define PLAYS_H

#include <vector>
#include <fstream>
#include "Play.h"
#include "Ticket.h"
#include <iostream>
using namespace std;
struct Eloadas {
	Play* play;
	vector<vector<Ticket>> tickets; //kicst sem bonyolult aaaahh nem
	vector<vector<int>> spaces;
	int free_spaces;
	string date;
};


class Plays{



private:
    vector<Eloadas> plays;
    vector<Play> szindarabok;//itt eltaroljuk az osszes eloadast ami van, egy szindarabok fajbol beolvassuk majd
	void szindarabok_beolvas();
	void eloadasok_beolvas();
	void jegyek_helyek_beolvas(ifstream &bemenet, Eloadas &eloadas);
public:
	vector<Eloadas> *getPlays();//DIRECTORNAK HA ELOADASOKAT SZERETNE MODOSITANI
	vector<Play> *getSzindarabok();//DIRECTORNAK HA SZINDARABOKAT SZERETNE MODOSITANI
    Plays();
	void listSzindarabok()const;//a listazas csak az altalanos adatokat tartalmazza, az arak meg ezek majd az igazgatora vonatkoznak pl
	void listPlays()const;
    void addPlay(Play & play);
};

#endif //PLAYS_H