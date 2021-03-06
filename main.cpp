#include "Plays.h"
#include "Admin.h"
#include "Customer.h"
#include "Director.h"
#include <thread>
#include <chrono>
//#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void welcomeScreen();


int main()
{
	//mciSendString("open \"music.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	//mciSendString("play mp3", NULL, 0, NULL);
	thread t1(welcomeScreen);
	Payment payment;
    Plays plays;
	GuestBook guestbook;
    Director director(&plays);
	Admin admin(&plays,&guestbook);
	Customer customer(&plays, &guestbook,payment);
	bool exit = false;
	t1.join();
	cout << "\n\nNyomjon egy gombot a folytatashoz: ";
	string select_menu;
	cin >> select_menu;
	while (!exit) {
		switch (select_menu[0]-'0') {
		case 9:
			cout << "Jelszo: ";
			cin >> select_menu;
			if(select_menu=="admin")
				admin.start();
			exit = true;
			break;
		case 8:
			cout << "Jelszo: ";
			cin >> select_menu;
			if (select_menu == "director")
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
	for (char s : welcome) {
		cout << Colorize::yellowBold(s);
		this_thread::sleep_for(chrono::microseconds(2));
	}
}