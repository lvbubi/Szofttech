#include <vector>
#include <fstream>
#include "Play.h"
#include "Ticket.h"
#include <iostream>
using namespace std;

class Plays{

struct Eloadas{
    Play* play;
    vector<vector<Ticket>> tickets;
    vector<vector<int>> spaces;
    int free_spaces;
    string date;
};

private:
    vector<Eloadas> plays;
    vector<Play> szindarabok;//itt eltaroljuk az osszes eloadast ami van, egy szindarabok fajbol beolvassuk majd

public:

    Plays();
	void listPlays();

	Play* selectPlay();
};
