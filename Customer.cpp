#include "Customer.h"

void Customer::buyTicket() {
    try{
        auto select_eloadas=plays->getEloadas(plays->getTaroloPointer()->find(plays->getPlay())->second);
        auto spaces=select_eloadas.spaces;
        if(select_eloadas.free_spaces==0)
            throw string("Nincs szabad hely erre az eloadasra");
        //helyek megjelenítése
        for(vector<int> sor:spaces){
            for(int oszlop:sor)
                cout<<oszlop;
            cout<<endl;
        }
        unsigned row,column;
        auto terem=spaces;
        int jegyek=0;
        int osszeg=0;


        cout<<"sorok es oszlopok bekeres, ha nem kerbe tobbet, akkor allitsa a sort 0-ra"<<endl<<endl;
        do{
            cout<<"kivalasztott sor: ";
            cin>>row;
            if(row!=0){
                cout<<"kivalasztott oszlop: ";
                cin>>column;
                if(column<select_eloadas.tickets.size()&& column>0 &&jegyek<select_eloadas.free_spaces && terem[row][column-1]!=0){
                    terem[row][column-1]=0;
                    jegyek++;
                    osszeg+=select_eloadas.tickets[row][column-1].getPrice();
                }
                else
                    cout<<"Hibas adat, probalja ujra"<<endl;
            }
        }while(row>0 && column<=select_eloadas.tickets.size() && row<=select_eloadas.tickets.size());
        for(vector<int> sor:terem){
            for(int oszlop:sor)
                cout<<oszlop;
            cout<<endl;
        }
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

        for(vector<int> sor:select_eloadas.spaces){
            for(int oszlop:sor)
                cout<<oszlop;
            cout<<endl;
        }

    }catch(string s){
        cout<<s<<endl;
    }




}

Customer::Customer(Plays *plays):plays(plays)
{

}

void Customer::writeReview(const string &name, const string &label, const string &comment) {
    GBook->addReview(name,label,comment);
}
