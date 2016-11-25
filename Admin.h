#include "GuestBook.h"
#include "Plays.h"

class Admin {

private:
	GuestBook* GBook;
	Plays* plays;

public:
	void checkReviews();

	void addPlay();

	void removePlay();

	void editPlay();

	void login();
};
