#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Plays.h"

class Director {

private:
	Plays* plays;
	string id;
	string pw;

public:
	Director(Plays *plays);

	void showAllStatistics()const;

	void showStatictics(Play* play) const;

	void login();

	void listPlaysBy(string& mode);
};

#endif //DIRECTOR_H