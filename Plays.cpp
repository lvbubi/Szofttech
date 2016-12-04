#include "Plays.h"

Plays::Plays()
{
	szindarabok_beolvas();
	eloadasok_beolvas();


}

Plays::~Plays()
{
	szindarabok_kiir();
	eloadasok_kiir();
}

void Plays::swapSzindarab(pair<Play, list<Eloadas>> &position,pair<Play, list<Eloadas>>& swap)
{
	Tarolo.erase(Tarolo.find(position.first));	 //KULCS-P�R T�RL�SE A MAPB�L
	Tarolo.insert(swap);					 //TMP BEILLESZT�SE
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
    //system(CLEAR);
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
        cout << "Kerek egy indexet ";
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
    for (unsigned int i = 1; i < idx; i++)
		it++;

	pair<Play, list<Eloadas>> par=*it;
    return  par;
}

string Plays::makeDescription()
{
    string description;
    char end;
        bool finished = false;

        while(finished!=true)
        {
            end= getchar();
            if(end!='*')
            {
                description+=end;
            }
            else
            {
                finished=true;

            }
        }

    return description;

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

void Plays::addPair(pair<Play,list<Eloadas>> &ujEloadas )
{
    Tarolo.insert(pair<Play,list<Eloadas>>(ujEloadas));
}

void Plays::removePair(pair<Play, list<Eloadas> > &dpair)
{

    Tarolo.erase(dpair.first);
}

bool operator<(const Play & lhs, const Play & rhs)
{
	return (lhs.getName() < rhs.getName());
}

ostream & operator<<(ostream & os, const Play & play)
{
	os << Colorize::greenBold(("Name: ")) << Colorize::redBold(play.getName()) << " "
		<< Colorize::greenBold(("Price: ")) << Colorize::redBold(play.getPrice()) << " "
		<< Colorize::greenBold(("\nShort Describtion: ")) << Colorize::yellowBold(play.getData()) << endl<<endl;
	return os;
}

void Plays::szindarabok_kiir()const
{
	string kiiras = "";
	ofstream output("szindarabok.txt");
	if (output.is_open())
	{
		for (auto &par : Tarolo) {
			output << par.first.getName() << '\t';
			output << par.first.getPrice() << '\t';
			output << par.first.getCost() << '\t';
			int income = 0;
			for (auto &eloadas : par.second) {
				income+=eloadas.sold_spaces*par.first.getPrice();
			}
			output << income ;
			output << par.first.getData().erase(0,1) << endl<< '*'<<endl;//sortores kiszedese a sztring elejerol (erase)
		}
	}
	output.close();
}

void Plays::eloadasok_kiir() const
{
	ofstream output("terem.txt");
	string fajlbair = "";
	if(output.is_open())
	for (auto &par : Tarolo)
		for (auto &eloadas : par.second) {
			fajlbair += par.first.getName() + '\t';
			fajlbair += eloadas.date;
			for (auto sor : eloadas.spaces) {
				for (int oszlop : sor)
					fajlbair+='0'+oszlop;
				fajlbair += '\n';
			}
			fajlbair+="*\n";
		}
	fajlbair.pop_back();
	output << fajlbair;
	output.close();
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
				data += '\n';
				getline(input, line);
				data += line;
				
			} while (line[0] != '*');
			data.pop_back();//* t�rl�se
			data.pop_back();// "\n" t�rl�se
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
