#include <list>
#include "Review.h"
using namespace std;
class GuestBook {

private:
	list<Review*> Reviews;

public:
	void listReviews();
};
