#ifndef C_DATAS_H
#define C_DATAS_H

#include <string>

using namespace std;


class C_Datas {

public:
	string name;
	string birthDate;
	string account_number;
	string password;
	bool operator ==(const C_Datas &c);
};
#endif //C_DATAS_H