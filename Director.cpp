#include "Director.h"

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
//	std::sort(e.begin(), e.end(),
//		[](Eloadas const &a, Eloadas const &b) {
//		return a.play->getIncome < b.play->getIncome;
//	});
	for (auto lol : *eloadasok);
}
