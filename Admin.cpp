
#include "Admin.h"


Admin::Admin(Plays * plays, GuestBook *GBook):plays(plays),GBook(GBook)
{
}

void Admin::checkReviews() {
    try{
    unsigned i=0;
    auto reviews=GBook->getReviews();
    //ha nincs ellenorizendo velemeny azt le kell kezelni
    bool allchecked=true;
    for(auto review:reviews){
        if(!review.getChecked())
            allchecked=false;
    }
    if(allchecked)
        throw string("nincs uj bejegyzes/velemeny");

    for(auto review:reviews){
        if(review.getChecked()==false){
        cout<<++i<<".)"<<endl;
            review.print();
            cout<<endl;
        }
    }

    cout<<"valassza ki a engedelyezendo velemenyt"<<endl;

    do{
    cout<<"valasztas: ";
    cin>>i;
    cout<<endl;
    }while(i<=0 && i>GBook->getReviews().size());

    auto it=GBook->getReviews().begin();

    for(unsigned j=0;j<i;j++){
        it++;
    }

    it->setChecked(true);

    }catch(string s){
            cout<<s<<endl;
    }
}

void Admin::addPlay() {

    system(CLEAR);
    Play szindarab;
    list<Eloadas> eloadasok;
    string tmp;
    int tmp2;
    string description;


    cout << "Creating new Play: " << endl;
    cout << "---------------------" << endl;
    cout << "Play's name: " << endl;
    cin >> tmp ;
    szindarab.setName(tmp);
    cout << "Play's price: " << endl;
    cin >> tmp2 ;
    szindarab.setPrice(tmp2);
    cout << "Play's cost: " << endl;
    cin >> tmp2 ;
    szindarab.setCost(tmp2);
    cout << "Play's short descripton: " << endl;

    description=plays->makeDescription();

    szindarab.setData(description);


    pair<Play,list<Eloadas>> newPair;

    newPair = make_pair(szindarab,eloadasok);

    plays->addPair(newPair);



}

void Admin::removePlay() {


    cout << "Removing play: " << endl;
    cout << "-----------------" <<endl;
    cout <<"Which one would you like to remove?" << endl;
    cout << "(it will remove evereything connected to that Play) " << endl;
    cout << "-----------------" <<endl;
    pair<Play,list<Eloadas>> dPair=plays->getPair();

    plays->removePair(dPair);

}

void Admin::editPlay() {
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////// KULCS MODOSITAS////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////



    vector<string> options= {"Name","Price","Cost","Data"};

    cout << "What would you like to edit? \n";
    cout << "------------------------------ " << endl;
    int j=0;
    for(string i : options)
    {
        cout << j+1 <<". " << i << endl;
        j++;
    }
    int cmd;
    cout << "Select: ";
    cin >> cmd;
    cout << "------------------------------ " << endl;


    auto position = plays->getPair();
    auto par = position;

    string tmp1;
    int tmp2;

    switch(cmd)
    {
        case 1:
            cout << "Change name to: ";
            cin >> tmp1;
            par.first.setName(tmp1);
            plays->setNameOfEloadasok(par.second, par.first.getName());//EZ A FUGGVENY VEGIGITERAL a listan
            plays->swapSzindarab(position,par);

            break;
        case 2:
             cout << "Change price to: ";
             cin >> tmp2;
             par.first.setPrice(tmp2);
            break;
        case 3:
             cout << "Change cost to: ";
             cin >> tmp2;
             par.first.setCost(tmp2);
            break;
        case 4:
             cout << "Change data to: ";
             tmp1=plays->makeDescription();
             par.first.setData(tmp1);
            break;

    }






///	plays->listSzindarabok();
//	plays->listPlays();
    //int szam;
    //	cin >> szam;
}

bool Admin::start()
{
    string admin_menu[] = {"Eloadas hozzaadas" ,"Eloadas modositas","Eloadas torles","Bejegyzesek jovahagyasa","Kilepes"};

    bool finished=false;
    int select;
    while(finished!=true){
        int i=1;
        for(string menupont:admin_menu)
            cout<<i++<<".)"<<menupont<<endl;
        cout<<"choose: ";
        cin>>select;
        switch(select){
        case 1:addPlay();break;
        case 2:editPlay();break;
        case 3:removePlay();break;
        case 4:checkReviews();break;
        case 5:
            finished=true;break;
        }
    }
    return finished;

}


