#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Plays.h"
#include <functional>
class Director {

private:
	Plays* plays;

protected :


public:
    void showStatictics() const; //A kivalasztott eloadas statisztikai adatainak megtekintese
	Director(Plays *plays);
	void showAllStatistics()const;
	void listPlaysBy(string& mode);
	bool start();
};

#endif //DIRECTOR_H
