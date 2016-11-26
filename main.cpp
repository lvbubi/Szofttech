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
    Plays plays;
    cout << "SzinhazApp: " << endl;
    cout << "----------- \n" << endl;




    plays.listSzindarabok(); //Szidarabok kiirasa
	plays.listPlays();
	int asd;
	cin >> asd;




    return 0;
}
