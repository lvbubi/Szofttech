#ifndef ADMIN_H
#define ADMIN_H

#include "GuestBook.h"
#include "Plays.h"
#include "Play.h"

class Admin {

private:
    Plays* plays;
    GuestBook* GBook;


public:
    Admin(Plays * plays,GuestBook* Gbook);

	void checkReviews();

    void addPlay();

	void removePlay();

	void editPlay();

};
#endif // ADMIN_H
