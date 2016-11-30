
#include "Admin.h"


Admin::Admin(Plays * plays):plays(plays)
{
}

void Admin::checkReviews() {
	throw "Not yet implemented";
}

void Admin::addPlay() {

}

void Admin::removePlay() {
	throw "Not yet implemented";
}

void Admin::editPlay() {
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////// KULCS MODOSITAS////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	auto position = plays->getPair();
	auto par = position;
	par.first.setName("A remeny hal meg utoljara");//TMP MÓDOSÍTÁSA
												   ///!!!!! MÓDOSÍTANI KELL A listában lévõ elõadások neveit!!!!!!
	plays->setNameOfEloadasok(par.second, "A remeny hal meg utoljara");//EZ A FUGGVENY VEGIGITERAL a listan
	plays->swapSzindarab(position,par);
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	plays->listSzindarabok();
	plays->listPlays();
	int szam;
	cin >> szam;
}


//paspapap
