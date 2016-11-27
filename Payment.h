#ifndef PAYMENT_H
#define PAYMENT_H
#include <fstream>
#include <list>
#include <iostream>
#include "C_Datas.h"
using namespace std;
class Payment {

private:
	list<pair<C_Datas,int>> CustomerDatas;
	
public:
	Payment();
	bool Pay(const C_Datas &checkID, int money);
};


#endif //PAYMENT_H