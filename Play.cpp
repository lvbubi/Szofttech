#include "Play.h"


string Play::getName() const
{
    return name;
}

int Play::getPrice() const
{
    return price;
}

int Play::getCost() const
{
    return cost;
}

int Play::getIncome() const
{
    return income;
}

string Play::getData() const
{
    return data;
}



void Play::setName(const string &value)
{
    name = value;
}

void Play::setPrice(int value)
{
    price = value;
}

void Play::setCost(int value)
{
    cost = value;
}

void Play::setIncome(int value)
{
    income = value;
}

void Play::setData(const string &value)
{
    data = value;
}

Play::Play(const string &name, int price, int cost, int income, const string &data)
    :name(name),price(price),cost(cost),income(income),data(data)
{

}

Play::Play()
{

}
