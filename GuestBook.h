#ifndef GUESTBOOK_H
#define GUESTBOOK_H

#include <list>
#include "Review.h"
using namespace std;
class GuestBook {

private:
	list<Review*> Reviews;

public:
	void listReviews();
};
#endif //GUESTBOOK_H