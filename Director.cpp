#include "Director.h"

<<<<<<< HEAD
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
=======
void Director::showStatictics(Play* play) {
    //színdarab adaira vagyunk kíváncsiak
    play->PlayKiir();
    cout<<endl;
    cout<<"cost: "<<play->getCost()<<" Ft Income: "<<play->getIncome()<<" Ft Profit: "<<play->getIncome()-play->getCost()<<" Ft";
    cout<<endl;

    vector<Eloadas>* eloadasok = plays->getPlays();
    vector<Eloadas> e = *eloadasok;
    Play* pointer=play;     //csak a play play miatt kell


    cout<<"A(z)"<<play->getName()<<" szindarab eloadasainak adatai:"<<endl;

    for(auto eloadas:e){
        int i=0;
        if(eloadas.play==pointer){
        cout << ++i << ".) Eloadas:\n";
        cout << "Datum: " << eloadas.date;
        cout << "\nSzabad helyek szama:" << eloadas.free_spaces << endl;
        }
    }
>>>>>>> origin/master
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
<<<<<<< HEAD
	std::sort(e.begin(), e.end(),
		[](Eloadas const &a, Eloadas const &b) {
		return a.play->getIncome() < b.play->getIncome();
	});
=======
//	std::sort(e.begin(), e.end(),
//		[](Eloadas const &a, Eloadas const &b) {
//		return a.play->getIncome < b.play->getIncome;
//	});
>>>>>>> origin/master
	for (auto lol : *eloadasok);
}
