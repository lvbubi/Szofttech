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
    Admin(Plays * plays,GuestBook* GBook);

	void checkReviews();

    void addPlay();

	void removePlay();

	void editPlay();
    bool start();

};
#endif // ADMIN_H
