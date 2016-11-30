
#include "Admin.h"


Admin::Admin(Plays * plays,GuestBook* Gbook):plays(plays),GBook(Gbook)
{
}

void Admin::checkReviews() {




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


    vector<string> options= {"Name","Price","Cost","Data"};

    bool finished=false;


    do{

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
             cout << "--------------" << endl;
             par.first.setPrice(tmp2);
             plays->swapSzindarab(position,par);
            break;
        case 3:
             cout << "Change cost to: ";
             cin >> tmp2;
              cout << "--------------" << endl;
             par.first.setCost(tmp2);
             plays->swapSzindarab(position,par);
            break;
        case 4:
             cout << "Change data to: ";
             tmp1=plays->makeDescription();
             cout << "--------------" << endl;
             par.first.setData(tmp1);
             plays->swapSzindarab(position,par);
            break;

    }

    string answer;
    cout << "Would you like to change something else ? ( Y / N ) " << endl;
    cin>>answer;
    cout << "--------------" << endl;
    if(answer=="N")
    {
        finished = true;
    }


    }while(finished!=true);



}


