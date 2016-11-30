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
#include "GuestBook.h"

using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void welcomeScreen();


int main()
{
	welcomeScreen();
    Plays plays;
	GuestBook guestbook;
    Director director(&plays);
	Admin admin(&plays);
	Customer customer(&plays, &guestbook);

	bool exit = false;
	cout << "\n\nNyomjon egy gombot a folytatashoz: ";
	string select_menu;
	cin >> select_menu;
	while (!exit) {
		switch (select_menu[0]-'0') {
		case 9:
			//admin.start();
			exit = true;
			break;
		case 8:
			director.start();
			exit = true;
			break;
		default:
			customer.start();
			exit = true;
			break;
		}
	}	
	return 0;
}


void welcomeScreen() {
	ifstream input("welcome.txt");
	string welcome = "";
	string line = "";
	if (input.is_open()) {
		while (getline(input, line))
			welcome += line + "\n";
	}
	cout << Colorize::yellowBold(welcome);
}