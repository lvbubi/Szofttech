#include "Director.h"

Director::Director(Plays *plays):plays(plays)
{

}

void Director::showAllStatistics() const
{
    auto MapPointer = plays->getTaroloPointer();


    //MapPointer->erase(MapPointer->find(plays->getPlay()));//kiválasztott Szindarab törlése (kulcs)

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////// KULCS MODOSITAS////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    auto it = MapPointer->find(plays->getPlay());//KULCS KIVALASZTASA, ELTAROLASA ITERATORBA

    pair < Play, list<Eloadas>> tmp = *it;		 //TMP LÉTREHOZÁSA ITERATORBOL
    tmp.first.setName("A remeny hal meg utoljara");//TMP MÓDOSÍTÁSA

    ///!!!!! MÓDOSÍTANI KELL A listában lévõ elõadások neveit!!!!!!
    plays->setNameOfEloadasok(tmp.second, "A remeny hal meg utoljara");//EZ A FUGGVENY VEGIGITERAL a listan
    //plays->listEloadasok(tmp.second);

    MapPointer->erase(it);						 //KULCS-PÁR TÖRLÉSE A MAPBÕL
    MapPointer->insert(tmp);					 //TMP BEILLESZTÉSE
    ///////////////////////////////////////////////////////////////////////////////////////////////////////


    //it = MapPointer->find(plays->getPlay()); //KULCS KIVÁLASZTÁSA
    //auto &eloadas=plays->getEloadas(it->second);// A KIVALASZTOTT KULCS ELOADASAINAK KIIRATASA


    //plays->listSzindarabok();//szindarabok kiiratasa
    int j = 0;
    it = MapPointer->begin();//az összes elõadás kiírása
    for (; it != MapPointer->end(); it++) {
        cout << ++j << ".) Szindarab:";
        it->first.PlayKiir();
        plays->listEloadasok(it->second);
    }
}


void Director::showStatictics()const  {

    //a kiválasztott elõadás statisztikai adatainak megtekintése
    //a rendszer megejeleníti az elõadás nevét és idõpontjait
    const Play *akt=&(plays->getPlay());        //a const miatt kell a const(szindarab kivalasztva)

    auto par= *(plays->getTarolo()).find(*akt);//kikeressük a színdarabhoz tartozó elõadásokat
    cout<<akt->getName()<<" idpontjai: "<<endl;            //majd megjelenítjük
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
    //4.1 és 4.2
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
    cout<<" price: "<<akt->getPrice()<<" Ft"<<endl<<endl;
}

void Director::listPlaysBy(const mode &_mode) {

    auto mappointer=plays->getTaroloPointer();
    auto it=mappointer->begin();
    vector<Play>e;
    for(const auto &par:*mappointer)
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




    //std::sort(lista,[](const Play a, const Play b){return a.getPrice()<b.getPrice();});




    list<pair<Play,list<Eloadas>>>parok;
    for(const auto &par:*mappointer)
        parok.push_back(par);

    auto faszom=plays->getEloadas(parok.front().second);
    cout<<endl<<endl<<"free spaces: "<<faszom.free_spaces<<endl<<"sold_spaces: "<<faszom.sold_spaces<<endl<<endl;

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
        switch(select){
        case 1:showStatictics();break;
        case 2:
            i=1;
            for(string menupont:almenu)
                cout<<i++<<".)"<<menupont<<endl;
            cout<<"choose: ";
            cin>>select;
            switch(select){
            case 1:showAllStatistics();break;
            case 2:listPlaysBy(profit);break;
            case 3:listPlaysBy(bevetel);break;
            case 4:listPlaysBy(ar);break;
            }

        case 3:cout<<"Viszontlatasra, szep napot!"<<endl;
            finished=true;break;
        }
    }
    return finished;
}
