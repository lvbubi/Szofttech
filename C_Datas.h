#ifndef C_DATAS_H
#define C_DATAS_H

#include <string>

using namespace std;


class C_Datas {

private:
	string name;
	string birthDate;
	string account_number;
	string password;
public:
    C_Datas();
    C_Datas(const string& name,const string & birthDate,const string & account_number,const string & password);
	bool operator ==(const C_Datas &c);
};
#endif //C_DATAS_H
