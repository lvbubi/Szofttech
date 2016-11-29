#include "Plays.h"

Plays::Plays()
{
	szindarabok_beolvas();
	eloadasok_beolvas();


}
map<Play, list<Eloadas>>& Plays::getTarolo() 
{
	return Tarolo;
}

map<Play, list<Eloadas>>* Plays::getTaroloPointer()
{
	return &Tarolo;
}

void Plays::listSzindarabok()const  {
	system(CLEAR);
	cout << "Szindarabok: " << endl;
	cout << "-------------" << endl;
	int i = 1;
	auto it = Tarolo.begin();
	for (; it != Tarolo.end(); it++) {
		cout << i++ << ".) ";
		it->first.PlayKiir();
	}
}
const Play & Plays::getPlay() const
{
	system(CLEAR);
	// play kivalaszt
	listSzindarabok();
	auto it = Tarolo.begin();
	cout << "Szindarab Kivalasztasa: " << endl;
	cout << "-------------" << endl;
	unsigned int idx = 0;
	do {
		cout << "Kerek egy indexet";
		cin >> idx;
	} while (idx > Tarolo.size());
	it = Tarolo.begin();
    for (unsigned int i = 1; i < idx; i++)//proba hatahamegy
		it++;
	return it->first;
}
Eloadas & Plays::getEloadas(list<Eloadas> &eloadasok)
{
	system(CLEAR);
	listEloadasok(eloadasok);

    unsigned int idx;
	do {
		cout << "Kerek egy indexet";
		cin >> idx;
	} while (idx > eloadasok.size());

	auto it = eloadasok.begin();
    for (unsigned int i = 1; i < idx; i++)
		it++;
	return *it;
}
void Plays::listEloadas(const Eloadas & eloadas) const
{
	cout << "Eloadas: " << eloadas.nev << "\t";
	cout << "Datum: " << eloadas.date;
	cout << "\nSzabad helyek szama:" << eloadas.free_spaces << endl;
}
void Plays::listEloadasok(const list<Eloadas>& eloadasok) const
{
	system(CLEAR);
	cout << "Eloadasok Kilistazasa: " << endl;
	cout << "-------------" << endl;
	int i = 1;
	for (const Eloadas &eloadas : eloadasok) {
		cout << i++ << ".) ";
		listEloadas(eloadas);
	}

}


void Plays::listPlays() const
{
	system(CLEAR);
	cout << "listPlays: " << endl;
	cout << "-------------" << endl;
    int i = 1;
	

	auto it = Tarolo.begin();
	for (; it != Tarolo.end(); it++) {
		cout << "-------------" << endl;
		cout << i++ << ".) Szindarab:" << endl;
		it->first.PlayKiir();
        it->first.getIncome();
		listEloadasok(it->second);
		cout << endl;
	}

	cout << "-------------" << endl;
}

void Plays::showAuditorium(const vector<vector<int>>& spaces) const
{
	system(CLEAR);
	for (vector<int> sor : spaces) {
		for (int oszlop : sor)
			cout << oszlop;
		cout << endl;
	}
}


void Plays::setNameOfEloadasok(list<Eloadas>& eloadasok, const string & nev)
{
	for (Eloadas &eloadas : eloadasok)
		eloadas.nev = nev;
}

bool operator<(const Play & lhs, const Play & rhs)
{
	return (lhs.getName() < rhs.getName());
}

//BEOLVASAS
void Plays::szindarabok_beolvas()
{
	//Szindarabok beolvasasa
	ifstream input("szindarabok.txt");

	if (input.is_open())
	{
		string name, data;
		string line;
		int price, cost, income;
		while (!input.eof()) {
			data = "";
			input >> name >> price >> cost >> income;
			do {//beolvasssa a describtiont mig *ot nem kap
				data += "\n";
				getline(input, line);
				data += line;
			} while (line[0] != '*');
			data.pop_back();//* törlése
			data.pop_back();// "\n" törlése
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
							//Teemo_halala
			eloadas.free_spaces = 666;
			bemenet >> eloadas_nev;

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
