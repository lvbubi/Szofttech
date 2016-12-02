
#include "Admin.h"


Admin::Admin(Plays * plays, GuestBook *GBook):plays(plays),GBook(GBook)
{
}

void Admin::checkReviews() {
	system(CLEAR);
    unsigned i=0;
    auto reviews=GBook->getReviews();
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
	system(CLEAR);

    cout << "Removing play: " << endl;
    cout << "-----------------" <<endl;
    cout <<"Which one would you like to remove?" << endl;
    cout << "(it will remove evereything connected to that Play) " << endl;
    cout << "-----------------" <<endl;
    pair<Play,list<Eloadas>> dPair=plays->getPair();

    plays->removePair(dPair);

}

void Admin::editPlay() {
	system(CLEAR);
    int cmd;
	cout << "What would you like to edit? \n";
	cout << "------------------------------ " << endl;
    auto &position = plays->getPair();
    auto par = position;//kell az es kulonben nem modosul
	bool exit = false;
    string tmp1;
    int tmp2;
	vector<string> options = { "Name","Price","Cost","Data","Exit" };

	do {
		system(CLEAR);
		cout << par.first;
		int j = 0;
		for (string i : options)
		{
			cout << j + 1 << ". " << i << endl;
			j++;
		}
		cout << "Select: ";
		cin >> cmd;
		system(CLEAR);
		cout << "------------------------------ " << endl;
		cout << par.first;
		switch (cmd)
		{
		case 1:
			cout << "Change name to: ";
			cin >> tmp1;
			par.first.setName(tmp1);
			plays->setNameOfEloadasok(par.second, par.first.getName());//EZ A FUGGVENY VEGIGITERAL a listan
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
			tmp1 = plays->makeDescription();
			par.first.setData(tmp1);
			break;
		case 5:exit = true; break;
		}
	} while (!exit);
	plays->swapSzindarab(position, par);//itt módosítsuk
}

void Admin::start()
{
	string menu[] = { "Check Reviews","Szindarab hozzaadasa", "Szindarab módosítasa","Szindarab torlese","Eloadas hozzaadasa","Exit" };
	bool exit = false;
	string select_menu;
	int i = 1;

	do {
		for (string s : menu) 
			cout << i++ << ".) " << s << endl;
		i = 1;
		cin >> select_menu;
		switch (select_menu[0] - '0') {
		case 1:checkReviews(); break;
		case 2:addPlay(); break;//kezeld le mikor létezõ szindarabot adnál hozzá (ugyan az a név ne lehessen)
		case 3:editPlay(); break;
		case 4:removePlay(); break;
		case 5:break;//add eloadas
		case 6:exit = true; break;
		}
	} while (!exit);
}


