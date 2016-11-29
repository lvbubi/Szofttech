#include "Customer.h"

void Customer::buyTicket() {
    try{
		auto &szindarab = plays->getPlay();
		auto &pair = plays->getTaroloPointer()->find(szindarab);

		if(pair->second.size()==0)
			throw string(szindarab.getName()+" nevu szindarabhoz nincsen eloadas.");

        auto select_eloadas=plays->getEloadas(pair->second);
        auto spaces=select_eloadas.spaces;
        if(select_eloadas.free_spaces==0)
            throw string("Nincs szabad hely erre az eloadasra");
        //helyek megjelenítése
		plays->showAuditorium(select_eloadas.spaces);

        unsigned int row,column;
        auto terem=spaces;
        int osszeg=0;
		


        cout<<"sorok es oszlopok bekeres, ha nem kerbe tobbet, akkor allitsa a sort 0-ra"<<endl<<endl;
        do{
            
			do {
				cout << "\nkivalasztott sor: ";
				cin >> row;
			} while (row >= select_eloadas.tickets.size());//túlindexelés lekezelése


            if(row>0 && row < select_eloadas.tickets.size()){    
				do {
					cout << "\nkivalasztott oszlop: ";
					cin >> column;
				} while (column > select_eloadas.tickets[row].size());//túlindexelés lekezelése

				column--;
				if(column < select_eloadas.tickets[row].size() && terem[row][column]!=0){
					terem[row][column]=0;
					osszeg+=szindarab.getPrice();
					plays->showAuditorium(terem);
				}
				else
					cout<<"Hibas adat, probalja ujra"<<endl;
            }
        }while(row>0);//kilépési feltétel
        //adatok bekerese

        string name;
        string birthDate;
        string account_number;
        string password;
        cout<<"nev: ";
        cin>>name;
        cout<<endl<<"szul.datum: ";
        cin>>birthDate;
        cout<<endl<<"azonosito: ";
        cin>>account_number;
        cout<<endl<<"jelszo: ";
        cin>>password;
        C_Datas customerId(name,birthDate,account_number,password);
        if(Payment().Pay(customerId,osszeg))
            select_eloadas.spaces=terem;

		plays->showAuditorium(select_eloadas.spaces);

    }catch(string s){
        cout<<s<<endl;
    }

	int osszeg;
	cin >> osszeg;

}

Customer::Customer(Plays *plays):plays(plays)
{

}

void Customer::writeReview(const string &name, const string &label, const string &comment) {
    GBook->addReview(name,label,comment);
}
