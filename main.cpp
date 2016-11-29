#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Plays.h"
#include <string>
#include "Admin.h"
#include "Payment.h"
#include <cstdlib>
#include <algorithm>
#include "Director.h"
#include <functional>
#include"Customer.h"
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
using namespace std;

int main()
{
    Plays plays;
Director director(&plays);

Customer customer(&plays);
customer.buyTicket();

    /*cout << "SzinhazApp: " << endl;
	cout << "----------- \n" << endl;

	string mainmenu[] = { "Eloadasok megtekintese","Jegyvasarlas","Vendegkonyvbe iras","Fizetes","Kilepes" };
	Plays plays;
    string valami="valami";
	bool exit = false;
	int select_menu;
	Director director(&plays);

    director.start();
    //director.listPlaysBy(valami);
   //plays.listPlays();
    //director.showAllStatistics();
    director.showStatictics();
    cout<<"anyad";
	//plays.listSzindarabok();
	//plays.listPlays();
	for (string s : mainmenu)//menu kiirasa
		cout << s << endl;
	cin >> select_menu;
	system(CLEAR);
	if (select_menu < 5);//Customer customer(&plays,&guestbook);
	while (!exit) {
		switch (select_menu) {
		case 1:plays.listPlays();
			break;
		case 2://buy ticket
			break;
		case 3://vendegkonyv
			break;
		case 4://fizetes
			break;
		case 5:exit = true;
			break;
		case 666:
			//admin belepes, if pw==pw id==id{
			//Admin admin(&plays);
			//(ciklus)admin.tovabbi fuggvenyek;
			
			break;
		case 777:
			//igazgato belepesif pw==pw id==id{
			//Director directior(&plays,&guestbook);
			//(ciklus)director.tovabbi fuggvenyek;
			//}
			break;
		}
		if (!exit) {
			for (string s : mainmenu)
                cout << s << endl;
            cin >> select_menu;
			system(CLEAR);
        }
	}
	C_Datas random;
	random.account_number = "1111-18179-11118-11181";
	random.password = "FakePassword";
	random.name = "NevemSenki";
	random.birthDate = "1999.12.12";
	Payment fizetes;
    fizetes.Pay(random, 10000000);*/
	return 0;
}
