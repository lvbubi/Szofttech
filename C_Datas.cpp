#include "C_Datas.h"

bool C_Datas::operator==(const C_Datas & c)
{
	if (c.name == name
	&&c.birthDate == birthDate
	&&c.account_number == account_number
	&&c.password == password)
	return true;
	return false;
}
