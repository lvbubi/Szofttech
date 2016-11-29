#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Plays.h"
#include <functional>
class Director {

private:
	Plays* plays;

protected :
	void showStatictics(Play* play) const;//egyetlen eloadas statisztikaja! (az amit megkap parameterkent)

public:
	Director(Plays *plays);
	void showAllStatistics()const;
	void listPlaysBy(string& mode);
	bool start();
};

#endif //DIRECTOR_H
