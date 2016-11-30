#ifndef ADMIN_H
#define ADMIN_H

#include "GuestBook.h"
#include "Plays.h"
#include "Play.h"

class Admin {

private:
     GuestBook* GBook;
     Plays* plays;

public:
	Admin(Plays * plays);

	void checkReviews();

    void addPlay();

	void removePlay();

	void editPlay();

};
#endif // ADMIN_H
