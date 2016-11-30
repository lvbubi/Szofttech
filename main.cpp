#include "Plays.h"
#include "Admin.h"
#include "Customer.h"
#include "Director.h"
#include <thread>
#include <chrono>
#include <Mmsystem.h>
#include <mciapi.h>
//these two headers are already included in the <Windows.h> header
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
	mciSendString("open \"music.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString("play mp3", NULL, 0, NULL);
	welcomeScreen();
	Payment payment;
    Plays plays;
	GuestBook guestbook;
    Director director(&plays);
	Admin admin(&plays);
	Customer customer(&plays, &guestbook,payment);

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
	for (char s : welcome) {
		cout << Colorize::yellowBold(s);
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}