#include "Plays.h"

Plays::Plays()
{
	szindarabok_beolvas();
	eloadasok_beolvas();
	/////////////////////////////////////////////////////KULCSMÓDOSÍTÁS
	pair < Play, list<Eloadas>> par = *Tarolo.begin();
	par.first.setName("lol");
	Tarolo.erase(Tarolo.begin());
	Tarolo.insert(par);
	/////////////////////////////////////////////////////KULCSMÓDOSÍTÁS
}
map<Play, list<Eloadas>>& Plays::getTarolo() 
{
	return Tarolo;
}
void Plays::listSzindarabok()const  {

	cout << "Szindarabok: " << endl;
	cout << "-------------" << endl;
	int i = 0;
	auto it = Tarolo.begin();
	for (; it != Tarolo.end(); it++) {
		it->first.PlayKiir();
	}
}
void Plays::listEloadas(const Eloadas & eloadas) const
{
	cout << "Datum: " << eloadas.date;
	cout << "\nSzabad helyek szama:" << eloadas.free_spaces << endl;
}
void Plays::listEloadasok(const list<Eloadas>& eloadasok) const
{
	for (const Eloadas &e : eloadasok)
		listEloadas(e);
}

//BEOLVASAS
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
			Tarolo[tmp] = list<Eloadas>();
		}

		input.close();
	}
	//Beolvasas vege
}

void Plays::eloadasok_beolvas()
{
	ifstream bemenet("terem.txt");
	string eloadas_nev;
	bool van = false;

	

	if (bemenet.is_open())//helyek beolvasasa, jegyek hozzadasa a megfelelo helyhez.
	{
		while (!bemenet.eof()) {
			Eloadas eloadas;//egy random eloadas, beolvasod/feltoltod random adatokkal a teszteleshez, a helyeket mar beolvassa
			int i;
			//Teemo_halala
			eloadas.free_spaces = 666;
			bemenet >> eloadas_nev;
			i = 0;

			auto it = Tarolo.begin();
			while (it != Tarolo.end()) {
				if (it->first.getName() == eloadas_nev) {
					van = true;
					break;
				}
				it++;
			}

			bemenet >> eloadas.date;
			jegyek_helyek_beolvas(bemenet, eloadas);
			eloadas.nev = eloadas_nev;
			if (van)
				it->second.push_back(eloadas);
			van = false;
		}
		bemenet.close();
	}
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
				eloadas.tickets[i][j] = Ticket(i, j, eloadas.nev, eloadas.date);
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
//BEOLVASAS VEGE

void Plays::listPlays() const
{
	cout << "Eloadasok: " << endl;
	cout << "-------------" << endl;
    int i = 1;
	

	auto it = Tarolo.begin();
	for (; it != Tarolo.end(); it++) {
		cout << i++ << ".) Szindarab:" << endl;
		it->first.PlayKiir();
		listEloadasok(it->second);
		cout << endl;
	}

	cout << "-------------" << endl;
}

void Plays::addPlay(Play &play)
{

}
