#include "Plays.h"

Plays::Plays()
{
	szindarabok_beolvas();
	eloadasok_beolvas();


}

void Plays::swapSzindarab(pair<Play, list<Eloadas>> &position,pair<Play, list<Eloadas>>& swap)
{
	Tarolo.erase(Tarolo.find(position.first));	 //KULCS-PÁR TÖRLÉSE A MAPBÕL
	Tarolo.insert(swap);					 //TMP BEILLESZTÉSE
}

map<Play, list<Eloadas>>::iterator Plays::begin()
{
	return Tarolo.begin();
}

map<Play, list<Eloadas>>::iterator Plays::end()
{
	return Tarolo.end();
}

void Plays::listSzindarabok()const  {
	system(CLEAR);
	cout << "Szindarabok: " << endl;
	cout << "-------------" << endl;
	int i = 1;
	auto it = Tarolo.begin();
	for (; it != Tarolo.end(); it++) {
		cout << i++ << ".) ";
		cout << it->first;
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
	cout << eloadasok;

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

pair<Play, list<Eloadas>> Plays::getPair()
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
	} while (idx > Tarolo.size() || idx<=0);
	
	it = Tarolo.begin();
	for (unsigned int i = 1; i < idx; i++)//proba hatahamegy
		it++;

	pair<Play, list<Eloadas>> par=*it;
	return  par;
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
		cout << it->first;
        it->first.getIncome();
		cout << it->second;
		cout << endl;
	}

	cout << "-------------" << endl;
}



void Plays::setNameOfEloadasok(list<Eloadas>& eloadasok, const string & nev)
{
	for (Eloadas &eloadas : eloadasok)
		eloadas.nev = nev;
}

ostream & operator<<(ostream & os, const Eloadas & eloadas)
{
	os << "Eloadas: " << eloadas.nev << "\t";
	os << "Datum: " << eloadas.date;
	os << "\nSzabad helyek szama:" << eloadas.free_spaces << endl;
	return os;
}

ostream & operator<<(ostream & os, const list<Eloadas>& eloadasok)
{
	system(CLEAR);
	os << "Eloadasok Kilistazasa: " << endl;
	os << "-------------" << endl;
	int i = 1;
	for (const Eloadas &eloadas : eloadasok) {
		os << i++ << ".) ";
		os << eloadas;
	}
	return os;
}

ostream & operator<<(ostream & os, const vector<vector<int>>& spaces)
{
	system(CLEAR);
	for (vector<int> sor : spaces) {
		for (int oszlop : sor)
			os << oszlop;
		os << endl;
	}
	return os;
}

bool operator<(const Play & lhs, const Play & rhs)
{
	return (lhs.getName() < rhs.getName());
}

ostream & operator<<(ostream & os, const Play & play)
{
	os << Colorize::greenBold(("Name: ")) << Colorize::redBold(play.getName()) << " "
		<< Colorize::greenBold(("Price: ")) << Colorize::redBold(play.getPrice()) << " "
		<< Colorize::greenBold(("Short Describtion: ")) << Colorize::yellowBold(play.getData()) << endl;
	return os;
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

		for (char c : line) {
			if (c - '0' == 0) {
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
