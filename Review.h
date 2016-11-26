#ifndef REVIEW_H
#define REVIEW_H

#include <string>
using namespace std;
class Review {

private:
	string name;
	string label;
	string comment;
	bool checked;

public:
	bool getChecked();

	void setChecked(bool checked);
};
#endif //REVIEW_H