#ifndef PLAY_H
#define PLAY_H
#include <iostream>
#include <string>
#include "colorize.h"
using namespace std;

class Play {

private:
    //a szindarabban nem tarolunk jegyeket, idopontot, a szindarab fuggetlen dolog
    string name; //eloadas neve
    int price=0;  
    int cost=0;   // eloadas koltsege EZ CSAK AZ IGAZGATORA VONATKOZIK
    int income=0; // bevetel EZ IS CSAK AZ IGAZGATORA VONATKOZIK
    string data; // eloadas rovid leirasa

public:
    Play(const string &name,int price, int cost,int income,const string &data);
    Play();
	void PlayKiir()const;
    string getName() const;
    int getPrice() const;
    int getCost() const;
    int getIncome() const;
    string getData() const;

    void setName(const string &value);
    void setPrice(int value);
    void setCost(int value);
    void setIncome(int value);
    void setData(const string &value);

	bool operator ==(const Play &c);
};

#endif // PLAY_H
