#include "Customer.h"
#include"stdio.h"

void Customer::buyTicket() {
    try{
		auto &szindarab = plays->getPlay();
		auto pair = plays->begin();

		for (; pair->first.getName() != szindarab.getName(); pair++);//léptetés amíg a lekért elõadásig nem jutunk

		
		if(pair->second.size()==0)
			throw string(szindarab.getName()+" nevu szindarabhoz nincsen eloadas.");

        auto select_eloadas=plays->getEloadas(pair->second);
        auto spaces=select_eloadas.spaces;
        if(select_eloadas.free_spaces==0)
            throw string("Nincs szabad hely erre az eloadasra");
        //helyek megjelenítése
		plays->showSpaces(select_eloadas.spaces);

        unsigned int row,column;
        auto terem=spaces;
        int osszeg=0;
		


        cout<<"sorok es oszlopok bekeres, ha nem kerbe tobbet, akkor allitsa a sort 0-ra"<<endl<<endl;
        do{
            
			do {
				cout << "\nkivalasztott sor: ";
				cin >> row;
			} while (row >= select_eloadas.spaces.size());//túlindexelés lekezelése


            if(row>0 && row < select_eloadas.spaces.size()){
				do {
					cout << "\nkivalasztott oszlop: ";
					cin >> column;
				} while (column > select_eloadas.spaces[row].size());//túlindexelés lekezelése

				column--;
				if(column < select_eloadas.spaces[row].size() && terem[row][column]!=0){
					terem[row][column]=0;
					osszeg+=szindarab.getPrice();
					plays->showSpaces(terem);
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

        plays->showSpaces(select_eloadas.spaces);

    }catch(string s){
        cout<<s<<endl;
    }

	int osszeg;
	cin >> osszeg;

}

Customer::Customer(Plays *plays, GuestBook *GBook):plays(plays),GBook(GBook)
{

}

void Customer::writeReview(const string &name, const string &label, const string &comment) {


    GBook->addReview(name,label,comment);
}

bool Customer::start()
{
    string customer_menu[] = { "Jegyvasarlas","Vendegkonybe iras","Kilepes" };

    bool finished=false;
    int select;
    string fname;
    string lname;
    string name;
    string label;
    string comment;
    string word;
    char a;

    while(finished!=true){
        int i=1;
        cout<<endl;
        for(string menupont:customer_menu)
            cout<<i++<<".)"<<menupont<<endl;
        cout<<"choose: ";
        cin>>select;
        switch(select){
         case 1:buyTicket();break;
         case 2:

            cout<<"nev: ";
            cin>>fname;
            cin>>lname;
            name=fname+" "+lname;
            cout<<name;
            cout<<"\ncim: ";
            do{
            cin>>word;
            label+=word+" ";
            }while(word[0]!='*');
            cout<<"\n velemeny: ";
            do{
            a=getchar();
            comment+=a;
            }while(a!='*');
            cout<<"name: "<<name<<endl<<endl;
            cout<<"title: "<<label<<endl<<endl;
            cout<<"tobbi: "<<comment;
            writeReview(name,label,comment);
            break;
        case 3: finished=true;break;
        }

    }

    return finished;
}
