#include "GuestBook.h"

GuestBook::GuestBook()
{
    ifstream input("guestbook.txt");

    if (input.is_open())
    {

        string name,label,comment;

        while (input >> name >> label >> comment)
        {
            Review tmp(name,label,comment);
            reviews.push_back(&tmp); // load reviews
        }

        input.close();
    }
}


GuestBook &GuestBook::getInstance()
{
    static GuestBook  instance;
    return instance;
}

void GuestBook::listReviews(bool checked) {

    cout<<endl<<"Reviews: "<<endl;
    for(auto review:reviews){
        if(checked==review->getChecked()){
        review->print();
        cout<<endl;
        }
    }
}

void GuestBook::addReview(const string &name, const string &label, const string &comment)
{
    Review tmp(name,label,comment);
    reviews.push_back(&tmp);
}

GuestBook::~GuestBook()
{

}
