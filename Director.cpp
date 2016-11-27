#include "Director.h"

void Director::showStatictics(Play* play) {
	throw "Not yet implemented";
}

void Director::login() {
	throw "Not yet implemented";
}

void Director::listPlaysBy(string& mode) {
	vector<Eloadas>* eloadasok = plays->getPlays();
	vector<Play> *szindarabok = plays->getSzindarabok();
	//szindarabok->;
	//asd->push_back(Eloadas);

	vector<Eloadas> e = *eloadasok;
	std::sort(e.begin(), e.end(),
		[](Eloadas const &a, Eloadas const &b) {
		return a.play->getIncome < b.play->getIncome;
	});
	for (auto lol : *eloadasok);
}
