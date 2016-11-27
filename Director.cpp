#include "Director.h"

Director::Director(Plays *plays):plays(plays)
{
	vector<Eloadas> *eloadasok = plays->getPlays();
	vector<Play> *szindarabok = plays->getSzindarabok();

	vector<Play>::iterator szindarab = szindarabok->begin();
	for (; szindarab != szindarabok->end(); szindarab++)//végigmegyünk minden szindarabon
		for (vector<Eloadas>::iterator eloadas = eloadasok->begin(); eloadas != eloadasok->end();eloadas++) {//majd végigmegyünk minden eloadason
			if(eloadas->play->getName()==szindarab->getName())//ha a szindarab neve megyegyezik az eloadas nevevel (lehet több elõadás egy szindarabhoz)
				szindarab->setIncome(szindarab->getIncome()+ eloadas->sold_spaces*szindarab->getPrice());//akkor a szindarab incomeja növekszik.
		}
}

void Director::showAllStatistics() const
{
	vector<Play> *szindarabok = plays->getSzindarabok();

	vector<Play>::iterator szindarab = szindarabok->begin();
	for (; szindarab != szindarabok->end(); szindarab++)
		showStatictics(&(*szindarab));//mivel iterator ezert elobb csillag majd aztan tudjuk atadni a memoriacimet
}

void Director::showStatictics(Play* play)const {
	play->PlayKiir();
	cout << play->getIncome() << endl;
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
		return a.play->getIncome() < b.play->getIncome();
	});
	for (auto lol : *eloadasok);
}
