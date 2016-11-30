#include <iostream>
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

using namespace std;

int main()
{

    Plays plays;
    GuestBook gbook;
    Director director(&plays);
   // director.start();
    Admin admin(&plays,&gbook);





    //customer.buyTicket();
    cout << "SzinhazApp: " << endl;
    cout << "----------- \n" << endl;

    string mainmenu[] = { "Eloadasok megtekintese","Jegyvasarlas","Vendegkonyvbe iras","Fizetes","Kilepes" };
    string valami="valami";
    bool exit = false;
    int select_menu;


  
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
                plays.listSzindarabok();
            break;
        case 3://vendegkonyv
            break;
        case 4://fizetes
            break;
        case 5:exit = true;
            break;
        case 666:
          //  admin belepes, if pw==pw id==id{
          //  Admin admin(&plays);
          //  (ciklus)admin.tovabbi fuggvenyek;
           // admin.editPlay();
            admin.checkReviews();
			
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
	return 0;
}
