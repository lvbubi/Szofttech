#include "Director.h"

Director::Director(Plays *plays):plays(plays)
{
/*	vector<Eloadas> *eloadasok = plays->getPlays();
	vector<Play> *szindarabok = plays->getSzindarabok();

	for (auto &szindarab : *szindarabok)
		for (auto &eloadas : *eloadasok)//itt az el�ad�s egy m�solt objektum lesz, �s az eredetit szeretn�m m�dos�tani.
			if (eloadas.play->getName() == szindarab.getName())//ha a szindarab neve megyegyezik az eloadas nevevel (lehet t�bb el�ad�s egy szindarabhoz)
				szindarab.setIncome(szindarab.getIncome() + eloadas.sold_spaces*szindarab.getPrice());//akkor a szindarab incomeja n�vekszik.
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
    //sz�ndarab adaira vagyunk k�v�ncsiak
    //play->PlayKiir(); itt nem k�v�ncsi ezekre
	cout << "cost: " << play->getCost() << " Ft Income: " << play->getIncome() 
	<< " Ft Profit: " << play->getIncome() - play->getCost() << " Ft" << endl;
}

void Director::listPlaysBy(string& mode) {
//	std::sort(e.begin(), e.end(),
//		[](Eloadas const &a, Eloadas const &b) {
//		return a.play->getIncome < b.play->getIncome;
//	});
}
