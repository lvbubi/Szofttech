#include "Payment.h"

Payment::Payment()
{
	ifstream bemenet("bank_accounts.txt");
	string account_number, password, name, birthDate;
	int money;
	if(bemenet.is_open())
		while (!bemenet.eof()) {
			bemenet >> account_number;
			bemenet >> password;
			bemenet >> name;
			bemenet >> birthDate;
			bemenet >> money;
			CustomerDatas.push_back(pair<C_Datas,int>(C_Datas(name, birthDate, account_number, password),money));
		}
}

bool Payment::Pay(const C_Datas &checkID,int money) {

	list<pair<C_Datas,int>>::iterator C_Data = CustomerDatas.begin();

	for(;C_Data!=CustomerDatas.end();C_Data++)
		if (C_Data->first == checkID) {
			if (C_Data->second >= money) {
				C_Data->second -= money;
				cout << "Sikeres fizetes";
				return true;
			}
			else {
				cout << "Nincs eleg penz a szamlan";
				return false;
			}
		}
		cout << "Nem letezo/hibas adatok";
	return false;
}
