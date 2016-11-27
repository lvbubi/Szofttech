#include "Payment.h"

Payment::Payment()
{
	ifstream bemenet("bank_accounts.txt");
	C_Datas account;
	int money;
	if(bemenet.is_open())
		while (!bemenet.eof()) {
			bemenet >> account.account_number;
			bemenet >> account.password;
			bemenet >> account.name;
			bemenet >> account.birthDate;
			bemenet >> money;
			CustomerDatas.push_back(pair<C_Datas,int>(account,money));
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
