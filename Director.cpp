#include "Director.h"

Director::Director(Plays *plays):plays(plays)
{

}

void Director::showAllStatistics() const
{

    auto it=plays->begin();
    for(;it!=plays->end();it++){
        cout<<Colorize::greenBackground(it->first.getName())<<" ar: "<<it->first.getPrice()<<Colorize::yellowBold(" Ft")
          <<" bevetel:"<<it->first.getIncome()<<Colorize::yellowBold(" Ft")<<"kiadas: "<<it->first.getCost()<<
            Colorize::yellowBold(" Ft")<<"profit: "<<((it->first.getIncome())-(it->first.getCost()))<<Colorize::yellowBold(" Ft")<<endl;
        cout<<endl;
    }
}


void Director::showStatictics()const {

	//a kiválasztott elõadás statisztikai adatainak megtekintése
	//a rendszer megejeleníti az elõadás nevét és idõpontjait

	auto par = plays->getPair();
	const Play * akt = &par.first;       //a const miatt kell a const(szindarab kivalasztva)
	if (par.second.size() > 0) {
		cout << akt->getName() << " idpontjai: " << endl;            //majd megjelenítjük
		auto it = par.second.begin();
		int i = 1;
		while (it != par.second.end()) {
			cout << i++ << ".)";
			cout << it->date << endl;
			it++;
		}
		//az igazgato kivalaszt egy idopontot
		unsigned idx;

		cout << "Adjon egy indexet: ";
		cin >> idx;
		//4.1 és 4.2
		while (idx > par.second.size()) {
			cout << "hibas index/datum, probalja ujra: ";
			cin >> idx;
		}
		it = par.second.begin();

		for (unsigned int i = 1; i < idx; i++) {
			it++;
		}
		system(CLEAR);
		//az idoponthoz tartozo statisztikai adatok megjelenitese
		cout << "cost: " << akt->getCost() / par.second.size() << " Ft";
		cout << " income: " << it->free_spaces*akt->getPrice() << " Ft";
		cout << " price: " << akt->getPrice() << " Ft" << endl << endl;


	}
	else cout << "Nincsen eloadas a kivaslasztott szindarabhoz"<<endl;
}
void Director::listPlaysBy(const mode &_mode) {


    vector<Play>e;
    for(const auto &par:*plays)
        e.push_back(par.first);
    function<int(const Play &a, const Play &b)> compare;
    switch(_mode){
    case profit: compare=[&]( const Play &a,  const Play &b) {
            return ((a.getIncome()-a.getCost()) < (b.getIncome()-b.getCost()));};
            std::sort(e.begin(),e.end(),compare);
            for(auto eloadas:e){
                cout<<eloadas.getName()<<" profit: "<<eloadas.getIncome()-eloadas.getCost()<<" Ft"<<endl<<endl;
            }
            break;

    case bevetel: compare=[&]( const Play &a,  const Play &b) {
            return (a.getIncome() < b.getIncome());};
            std::sort(e.begin(),e.end(),compare);
            for(auto eloadas:e){
                cout<<eloadas.getName()<<" bevetel: "<<eloadas.getIncome()<<" Ft"<<endl<<endl;
            }
            break;

    case ar: compare=[&]( const Play &a,  const Play &b) {
            return (a.getPrice() < b.getPrice());};
            std::sort(e.begin(),e.end(),compare);
            for(auto eloadas:e){
                cout<<eloadas.getName()<<" ar: "<<eloadas.getPrice()<<" Ft"<<endl<<endl;
            }
            break;


    }
}

bool Director::start()
{
    string director_menu[] = { "Eloadas statisztikai adatainak megtekintese","Eloadasok kilistazasa","Kilepes" };
    string almenu[]={"Osszes listazasa","Listazas profit szerint","Listazas bevetel szerint","Listazas ar szerint"};

    bool finished=false;
    int select;
    while(finished!=true){
        int i=1;
        for(string menupont:director_menu)
            cout<<i++<<".)"<<menupont<<endl;
        cout<<"choose: ";
        cin>>select;
		system(CLEAR);
        switch(select){
        case 1:showStatictics();break;
        case 2:
            i=1;
            for(string menupont:almenu)
                cout<<i++<<".)"<<menupont<<endl;
            cout<<"choose: ";
            cin>>select;
			system(CLEAR);
            switch(select){
            case 1:showAllStatistics();break;
            case 2:listPlaysBy(profit);break;
            case 3:listPlaysBy(bevetel);break;
            case 4:listPlaysBy(ar);break;
            }
			break;
        case 3:cout<<"Viszontlatasra, szep napot!"<<endl;
            finished=true;break;
        }
    }
    return finished;
}
