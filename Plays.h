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

public:

    Plays();
	void listPlays();
    void addPlay(Play & play);

	Play* selectPlay();
};

#endif //PLAYS_H