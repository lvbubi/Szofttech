#include "GuestBook.h"

GuestBook::GuestBook()
{
    ifstream input("guestbook.txt");

    if (input.is_open())
    {
        string checked;
        string fname;
        string lname;
        string name,label,comment;
        string word;

        input>>checked;
        while (checked[0]!='#')
        {

            input>>fname;
            input>>lname;
            name=fname+" "+lname;
            getline(input,word);
            getline(input,label);
            do{
                getline(input,word);
                if(word[0]!='*')
                comment+=word+"\n";
            }while(word[0]!='*');

            Review tmp(name,label,comment);
            if(checked=="checked")
                tmp.setChecked(true);
            else
                tmp.setChecked(false);

            reviews.push_back(tmp); // load reviews
            comment="";

            input>>checked;
        }

        input.close();
    }
}



void GuestBook::listReviews(bool checked) {

    cout<<endl<<"Reviews: "<<endl;
    for(auto review:reviews){
        if(checked==review.getChecked()){
            review.print();
            cout<<endl;
        }
    }
}

void GuestBook::addReview(const string &name, const string &label, const string &comment)
{

    Review tmp(name,label,comment);
    reviews.push_back(tmp);
}

GuestBook::~GuestBook()
{
	ofstream output("kimenet.txt");
	if (output.is_open()) {
		for (auto &review : reviews) {
			if (review.getChecked())
				output<<"checked\n";
			else output << "unchecked\n";
			output << review.getName()+"\n";
			output << review.getLabel() + "\n";
			output << review.getComment();
			output << "*\n";
		}
		output << '#';
	}
	output.close();
}
