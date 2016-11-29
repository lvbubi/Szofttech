#include "C_Datas.h"

C_Datas::C_Datas()
{

}

C_Datas::C_Datas(const string &name, const string &birthDate, const string &account_number, const string &password)
    :name(name),birthDate(birthDate),account_number(account_number),password(password)
{
}

bool C_Datas::operator==(const C_Datas & c)
{
	if (c.name == name
	&&c.birthDate == birthDate
	&&c.account_number == account_number
	&&c.password == password)
	return true;
	return false;
}
