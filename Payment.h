#include <list>
#include "C_Datas.h"
using namespace std;
class Payment {

private:
	list<C_Datas> CustomerDatas;

public:
	bool Pay(C_Datas checkID);
};
