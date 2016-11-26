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

Play* Plays::selectPlay() {
	throw "Not yet implemented";
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
	Eloadas eloadas;//egy random eloadas, beolvasod/feltoltod random adatokkal a teszteleshez, a helyeket mar beolvassa
	//Teemo_halala
	eloadas.play = nullptr;
	eloadas.free_spaces = 666;
	int i = 0, j = 0;
	ifstream bemenet("terem.txt");
	string eloadas_nev;
	string line;

	if (bemenet.is_open())//helyek beolvasasa, jegyek hozzadasa a megfelelo helyhez.
	{
		while (!bemenet.eof()) {
			bemenet >> eloadas_nev;
			for (int i = 0; i < szindarabok.size(); i++)//itt gecisokat szoptam... foreachnél elszállt mert a for után az ideiglenes változó eltûnik, azt az pointert nem ajánlot hozzáadni -.-
				if (szindarabok[i].getName() == eloadas_nev) {
					eloadas.play = &szindarabok[i];
					break;
				}
			if (eloadas.play == NULL);//throw exception, hibas fajl, nincs ilyen play a rendszerben.

			bemenet >> eloadas.date;
			getline(bemenet, line);
			while (line[0] != '*')
			{
				eloadas.spaces.push_back(vector<int>(line.size()));//egy sor a he
				eloadas.tickets.push_back(vector<Ticket>(line.size()));

				for (char c : line) {
					if (c - '0' == 0)
						eloadas.tickets[i][j] = Ticket(i, j, eloadas.play, eloadas.date);
					eloadas.spaces[i][j++] = c - '0';

				}
				i++;
				j = 0;
				getline(bemenet, line);
			}
			plays.push_back(eloadas);
		}
		bemenet.close();
	}
	plays._Pop_back_n(1);//az utolsot ketszer adja hozza, vagy javitom vagy marad igy :D
}


Plays::Plays()
{
	szindarabok_beolvas();
	eloadasok_beolvas();   
}
