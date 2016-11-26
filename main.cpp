#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Plays.h"
#include <string>
#include "Admin.h"

//javaslom a build mappaba berakni txt-ket

using namespace std;

int main()
{
	//Admin admin;
	string mainmenu[] = { "Eloadasok megtekintese","Jegyvasarlas","Vendegkonyvbe iras","Fizetes","Kilepes" };
	Plays plays;
	bool exit = false;
	int select_menu;

	cout << "SzinhazApp: " << endl;
	cout << "----------- \n" << endl;
	plays.listSzindarabok();

	for (string s : mainmenu)//menu kiirasa
		cout << s << endl;
	cin >> select_menu;
	if (select_menu < 5);//Customer customer(&plays,&guestbook);

	while (!exit) {
		switch (select_menu) {
		case 1://customer.plays->listPlays();
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
		}
	}
	return 0;
}
