#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Plays.h"

class Director {

private:
	Play* plays;
	string id;
	string pw;

public:
	void showStatictics(Play* play);

	void login();

	void listPlaysBy(string& mode);
};

#endif //DIRECTOR_H