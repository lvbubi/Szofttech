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
    ofstream output("guestbook.txt");
	if (output.is_open()) {
		string name;
		string label;
		string comment;
		for (auto &review : reviews) {
			name = review.getName();
			name.erase(name.find_first_not_of(" \n\r\t") + 1);

			label = review.getLabel();
			label.erase(label.find_first_not_of(" \n\r\t") + 1);

			comment = review.getComment();
			comment.erase(comment.find_first_not_of(" \n\r\t") + 1);

			if (review.getChecked())
				output<<"checked\n";
			else output << "unchecked\n";
			output << name+"\n";
			output << label + "\n";
			output << comment;
			output << "*\n";
		}
		output << '#';
	}
	output.close();
}

list<Review> &GuestBook::getReviews()
{
    return reviews;
}

