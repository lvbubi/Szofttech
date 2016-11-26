#ifndef REVIEW_H
#define REVIEW_H

#include <string>
using namespace std;
class Review {

private:
	string name;
	string label;
	string comment;
    bool checked=false;

public:
    Review(const string& name,const string&label,const string& comment);
	bool getChecked();

	void setChecked(bool checked);
    string getName() const;
    string getLabel() const;
    string getComment() const;
};
#endif //REVIEW_H
