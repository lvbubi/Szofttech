#include "Director.h"

Director::Director(Plays *plays):plays(plays)
{
/*	vector<Eloadas> *eloadasok = plays->getPlays();
	vector<Play> *szindarabok = plays->getSzindarabok();

	for (auto &szindarab : *szindarabok)
		for (auto &eloadas : *eloadasok)//itt az elõadás egy másolt objektum lesz, és az eredetit szeretném módosítani.
			if (eloadas.play->getName() == szindarab.getName())//ha a szindarab neve megyegyezik az eloadas nevevel (lehet több elõadás egy szindarabhoz)
				szindarab.setIncome(szindarab.getIncome() + eloadas.sold_spaces*szindarab.getPrice());//akkor a szindarab incomeja növekszik.
*/
}

void Director::showAllStatistics() const
{
/*	int i = 1;
	vector<Play> *szindarabok = plays->getSzindarabok();

	vector<Play>::iterator szindarab = szindarabok->begin();
	for (; szindarab != szindarabok->end(); szindarab++) {
		cout << i++<<".) "<<szindarab->getName()<<"  ";
		showStatictics(&(*szindarab));//mivel iterator ezert elobb csillag majd aztan tudjuk atadni a memoriacimet
	}*/
}


void Director::showStatictics(Play* play)const  {
    //színdarab adaira vagyunk kíváncsiak
    //play->PlayKiir(); itt nem kíváncsi ezekre
	cout << "cost: " << play->getCost() << " Ft Income: " << play->getIncome() 
	<< " Ft Profit: " << play->getIncome() - play->getCost() << " Ft" << endl;
}

void Director::listPlaysBy(string& mode) {
//	std::sort(e.begin(), e.end(),
//		[](Eloadas const &a, Eloadas const &b) {
//		return a.play->getIncome < b.play->getIncome;
//	});
}
