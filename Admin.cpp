#include "Admin.h"


void Admin::checkReviews() {
	throw "Not yet implemented";
}

void Admin::addPlay() {
	vector<Eloadas>* eloadasok = plays->getPlays();
	vector<Play> *szindarabok = plays->getSzindarabok();
	//szindarabok->;
	//asd->push_back(Eloadas);
	
	vector<Eloadas> e = *eloadasok;
//	std::sort(e.begin(), e.end(),
//        [&]( Eloadas  a, Eloadas b) {
//		return a.play->getIncome < b.play->getIncome;
//	});
	for (auto lol : *eloadasok);

}

void Admin::removePlay() {
	throw "Not yet implemented";
}

void Admin::editPlay() {
	throw "Not yet implemented";
}

void Admin::login() {
	throw "Not yet implemented";
}

//paspapap
