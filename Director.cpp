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
	auto MapPointer = plays->getTaroloPointer();


	//MapPointer->erase(MapPointer->find(plays->getPlay()));//kiv�lasztott Szindarab t�rl�se (kulcs)

	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////// KULCS MODOSITAS////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	auto it = MapPointer->find(plays->getPlay());//KULCS KIVALASZTASA, ELTAROLASA ITERATORBA

	pair < Play, list<Eloadas>> tmp = *it;		 //TMP L�TREHOZ�SA ITERATORBOL
	tmp.first.setName("A remeny hal meg utoljara");//TMP M�DOS�T�SA

	///!!!!! M�DOS�TANI KELL A list�ban l�v� el�ad�sok neveit!!!!!!
	plays->setNameOfEloadasok(tmp.second, "A remeny hal meg utoljara");//EZ A FUGGVENY VEGIGITERAL a listan
	//plays->listEloadasok(tmp.second);
	
	MapPointer->erase(it);						 //KULCS-P�R T�RL�SE A MAPB�L
	MapPointer->insert(tmp);					 //TMP BEILLESZT�SE
	///////////////////////////////////////////////////////////////////////////////////////////////////////


	//it = MapPointer->find(plays->getPlay()); //KULCS KIV�LASZT�SA
	//auto &eloadas=plays->getEloadas(it->second);// A KIVALASZTOTT KULCS ELOADASAINAK KIIRATASA
	

	//plays->listSzindarabok();//szindarabok kiiratasa
	int j = 0;
	it = MapPointer->begin();//az �sszes el�ad�s ki�r�sa
	for (; it != MapPointer->end(); it++) {
		cout << ++j << ".) Szindarab:";
		it->first.PlayKiir();
		plays->listEloadasok(it->second);
	}
}


void Director::showStatictics()const  {

    //a kiv�lasztott el�ad�s statisztikai adatainak megtekint�se
    //a rendszer megejelen�ti az el�ad�s nev�t �s id�pontjait
    const Play *akt=&(plays->getPlay());        //a const miatt kell a const(szindarab kivalasztva)

    auto par= *(plays->getTarolo()).find(*akt);//kikeress�k a sz�ndarabhoz tartoz� el�ad�sokat
    cout<<akt->getName()<<" idpontjai: "<<endl;            //majd megjelen�tj�k
    auto it=par.second.begin();
    int i=1;
    while(it!=par.second.end()){
        cout<<i++<<".)";
        cout<<it->date<<endl;
        it++;
    }
    //az igazgato kivalaszt egy idopontot
    unsigned idx;

    cout<<"Adjon egy indexet: ";
    cin>>idx;
    //4.1 �s 4.2
    while(idx>par.second.size()){
        cout<<"hibas index/datum, probalja ujra: ";
        cin>>idx;
    }
    it=par.second.begin();

    for(int i=1;i<idx;i++){
        it++;
    }
    //az idoponthoz tartozo statisztikai adatok megjelenitese
    cout<<"cost: "<<akt->getCost()/par.second.size()<<" Ft";
    cout<<" income: "<<it->free_spaces*akt->getPrice()<<" Ft";
    cout<<" price: "<<akt->getPrice()<<" Ft";
}

void Director::listPlaysBy(string& mode) {


    auto mappointer=plays->getTaroloPointer();
    auto it=mappointer->begin();
    vector<Play>e;
    for(const auto &par:*mappointer)
        e.push_back(par.first);
    function<int(const Play &a, const Play &b)> compare;
    switch(1){
    case 1: compare=[]( const Play &a,  const Play &b) {
    return (a.getPrice() < b.getPrice());
    };
    case 2: compare=[]( const Play &a,  const Play &b) {
            return (a.getPrice() < b.getPrice());
        };
    case 3: compare=[]( const Play &a,  const Play &b) {
            return (a.getPrice() < b.getPrice());

        };
    }




    //std::sort(lista,[](const Play a, const Play b){return a.getPrice()<b.getPrice();});

    std::sort(e.begin(), e.end(),
        compare);

    for(auto& szindarab:e)
        szindarab.PlayKiir();


    list<pair<Play,list<Eloadas>>>parok;
    for(const auto &par:*mappointer)
        parok.push_back(par);

    auto faszom=plays->getEloadas(parok.front().second);
    cout<<endl<<endl<<"free spaces: "<<faszom.free_spaces<<endl<<"sold_spaces: "<<faszom.sold_spaces<<endl<<endl;

}
