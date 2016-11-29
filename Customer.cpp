#include "Customer.h"

void Customer::buyTicket() {
    auto select_eloadas=plays->getEloadas(plays->getTaroloPointer()->find(plays->getPlay())->second);
    auto spaces=select_eloadas.spaces;
    spaces[0][0];
    for(vector<int> sor:spaces){
        for(int oszlop:sor)
            cout<<oszlop;
        cout<<endl;
    }

}

Customer::Customer(Plays *plays):plays(plays)
{

}

void Customer::writeReview(const string &name, const string &label, const string &comment) {
    GBook->addReview(name,label,comment);
}
