#include "Plays.h"

void Plays::listSzindarabok()const  {

    auto it = szindarabok.begin();
    cout << "Szindarabok: " << endl;
    cout << "-------------" << endl;
    int i=0;
    while(it!=szindarabok.end())
    {
        cout << i + 1 << ".szindarab: \n";
            it->PlayKiir();
        it++;
        i++;
        cout << endl;
    }

}

void Plays::listPlays() const
{
    int i = 0;
    for (Eloadas e : plays) {
        cout << ++i << ".) Eloadas:\n";
        e.play->PlayKiir();
        cout << "Datum: " << e.date;
        cout << "\nSzabad helyek szama:" << e.free_spaces << endl;

    }
}

void Plays::addPlay(Play &play)
{
    szindarabok.push_back(play);
}


void Plays::szindarabok_beolvas()
{
    //Szindarabok beolvasasa
    ifstream input("szindarabok.txt");

    if (input.is_open())
    {

        string name, data;
        int price, cost, income;

        while (input >> name >> price >> cost >> income >> data)
        {
            Play tmp(name, price, cost, income, data);
            szindarabok.push_back(tmp); // szindarabok betoltese

        }

        input.close();
    }
    //Beolvasas vege
}

void Plays::eloadasok_beolvas()
{
		ifstream bemenet("terem.txt");
		string eloadas_nev;

		if (bemenet.is_open())//helyek beolvasasa, jegyek hozzadasa a megfelelo helyhez.
		{
			while (!bemenet.eof()) {
				Eloadas eloadas;//egy random eloadas, beolvasod/feltoltod random adatokkal a teszteleshez, a helyeket mar beolvassa
				int i;
				//Teemo_halala
				eloadas.play = nullptr;
				eloadas.free_spaces = 666;
				bemenet >> eloadas_nev;
				i = 0;
				for (int i = 0; i < szindarabok.size(); i++)//itt gecisokat szoptam... foreachn�l elsz�llt mert a for ut�n az ideiglenes v�ltoz� elt�nik, azt az pointert nem aj�nlot hozz�adni -.-
					if (szindarabok[i].getName() == eloadas_nev) {
						eloadas.play = &szindarabok[i];
						break;
					}

				if (eloadas.play == nullptr) {
					eloadas.play = &szindarabok[0];
					cout << "\n\nAz eloadast nem lehetet beazonos�tani, �gy a 0. eloadast kapta meg." << endl << endl;
				}

				bemenet >> eloadas.date;
				jegyek_helyek_beolvas(bemenet, eloadas);
				plays.push_back(eloadas);


			}
			bemenet.close();
		}
		plays.pop_back();//az utolsot ketszer adja hozza, vagy javitom vagy marad igy :D
	
}

void Plays::jegyek_helyek_beolvas(ifstream &bemenet, Eloadas &eloadas)
{
    string line;
    int i = 0, j = 0;
	eloadas.free_spaces = eloadas.sold_spaces = 0;
    while (!bemenet.eof())
    {
        getline(bemenet, line);
        if (line[0] == '*')//ha * akkor a jegyek beolvasasa befejezodott.
            break;

        eloadas.spaces.push_back(vector<int>(line.size()));
        eloadas.tickets.push_back(vector<Ticket>(line.size()));

        for (char c : line) {
			if (c - '0' == 0) {
				eloadas.tickets[i][j] = Ticket(i, j, eloadas.play, eloadas.date);
				eloadas.sold_spaces++;
			}
			else
				eloadas.free_spaces++;
            eloadas.spaces[i][j++] = c - '0';

        }
        i++;
        j = 0;
    }
}

vector<Eloadas>* Plays::getPlays()
{
	return &plays;
}

vector<Play>* Plays::getSzindarabok()
{
	return &szindarabok;
}

Plays::Plays()
{
    szindarabok_beolvas();
    eloadasok_beolvas();
}
