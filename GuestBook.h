#ifndef GUESTBOOK_H
#define GUESTBOOK_H

#include <list>
#include "Review.h"
#include<fstream>

using namespace std;
class GuestBook {

private:
    list<Review> reviews;

public:
    GuestBook();
    void listReviews(bool checked);     //ez csak azokat a review-kat list�zza,amelyek m�r checkolva lettek(az admint csak a nem csekkolt,
                                        //mindenki m�st csak a csekkolt verzi� �rdekelheti

    void addReview(const string& name,const string&label,const string& comment);    //review hozz�ad�sa
    ~GuestBook();                   //ide m�g meg k�ne �rni a f�jlba �r�st
};
#endif //GUESTBOOK_H
