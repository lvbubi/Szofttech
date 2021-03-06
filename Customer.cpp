#include "Customer.h"
#include"stdio.h"

void Customer::buyTicket() {
    try{
		list<pair<int, int>> lefoglalt_helyek;
		auto &szindarab = plays->getPlay();
		auto par = plays->begin();

		for (; par->first.getName() != szindarab.getName(); par++);//l�ptet�s am�g a lek�rt el�ad�sig nem jutunk

		
		if(par->second.size()==0)
			throw string(szindarab.getName()+" nevu szindarabhoz nincsen eloadas.");

        auto &select_eloadas=plays->getEloadas(par->second);
        if(select_eloadas.free_spaces==0)
            throw string("Nincs szabad hely erre az eloadasra");
        //helyek megjelen�t�se
		plays->showSpaces(select_eloadas.spaces);

        unsigned int row,column;
        auto terem= select_eloadas.spaces;
        int osszeg=0;
		


        cout<<"sorok es oszlopok bekeres, ha nem kerbe tobbet, akkor allitsa a sort 0-ra"<<endl<<endl;
        do{
            
			do {
				cout << "\nkivalasztott sor: ";
				cin >> row;
			} while (row >= select_eloadas.spaces.size());//t�lindexel�s lekezel�se


            if(row>0 && row < select_eloadas.spaces.size()){
				do {
					cout << "\nkivalasztott oszlop: ";
					cin >> column;
				} while (column > select_eloadas.spaces[row].size());//t�lindexel�s lekezel�se

				column--;
				if(column < select_eloadas.spaces[row].size() && terem[row][column]!=0){
					terem[row][column]=0;
					osszeg+=szindarab.getPrice();

					lefoglalt_helyek.push_back(pair<int, int>(row,column));
					plays->showSpaces(terem);
				}
				else
					cout<<"Hibas adat, probalja ujra"<<endl;
            }
        }while(row>0);//kil�p�si felt�tel
        //adatok bekerese
		system(CLEAR);
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

		if (fizetes.Pay(C_Datas(name, birthDate, account_number, password), osszeg)) {
			select_eloadas.spaces = terem;
			for (const auto &lefogalt_hely : lefoglalt_helyek)
				Ticket(lefogalt_hely, szindarab.getPrice(), szindarab.getName(), name, select_eloadas.date);
		}

		std::this_thread::sleep_for(chrono::seconds(2));
        plays->showSpaces(select_eloadas.spaces);

    }catch(string s){
        cout<<s<<endl;
    }
}

Customer::Customer(Plays *plays, GuestBook *GBook, Payment & payment):plays(plays),GBook(GBook),fizetes(payment)
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
            cout<<i++<<".) "<<menupont<<endl;
        cout<<"choose: ";
        cin>>select;
		system(CLEAR);
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
		system(CLEAR);

    }

    return finished;
}
