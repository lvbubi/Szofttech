#ifndef GUESTBOOK_H
#define GUESTBOOK_H

#include <list>
#include "Review.h"
#include<fstream>

using namespace std;
class GuestBook {

private:
    list<Review*> reviews;
    GuestBook();                        //singleton osztály, ebbõl tuti nem lesz több, itt történik meg a beolvasás is
public:
    static GuestBook& getInstance();
    void listReviews(bool checked);     //ez csak azokat a review-kat listázza,amelyek már checkolva lettek(az admint csak a nem csekkolt,
                                        //mindenki mást csak a csekkolt verzió érdekelheti

    void addReview(const string& name,const string&label,const string& comment);    //review hozzáadása
    ~GuestBook();                   //ide még meg kéne írni a fájlba írást, illetve a felszabadítást
};
#endif //GUESTBOOK_H
